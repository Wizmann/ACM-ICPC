#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x


template<typename T>
class SkipList {
private:
    struct SkipListNode;
public:
    int init();
    int init(int level);

    int insert(T* tp);

    size_t length();
    int destroy();
    SkipListNode* nth_element(size_t k);

private:
    SkipListNode *_head, *_tail;
    size_t _length;
    int _level_num;
private:
    template<typename ALLOC_TP>
    static ALLOC_TP* allocate() {
        // FIXME exception can be raised in this code
        //       but who ever cares
        return new ALLOC_TP();
    }
    template<typename ALLOC_TP>
    static ALLOC_TP* allocate(size_t size) {
        return new ALLOC_TP[size];
    }
    template<typename DEALLOC_TP>
    static int deallocate(DEALLOC_TP* ptr) {
        delete ptr;
        return 0;
    }
    size_t random_level() {
        int level = 1;
        while ((rand() & 0xFFFF) < (0xFFFF >> 1)) {
            level++;
        }
        return min(level, _level_num);
    }
    int skiplist_cmp(T* a, T* b) {
        if (!a) {
            return -1;
        }
        if (*a < *b) {
            return -1;
        }
        if (*a > *b) {
            return 1;
        }
        return 0;
    }
private:
    struct SkipListNode {
        T* value;
        SkipListNode *backward;
        struct SkipListLevel {
            SkipListNode *forward;
            size_t span;
            SkipListLevel(): forward(NULL), span(0) {}
        };
        vector<SkipListLevel> level;
        
        void init(size_t level_num) {
            level.reserve(level_num);
            for (size_t i = 0; i < level_num; i++) {
                level[i].forward = NULL;
                level[i].span = 0;
            }
        }
    };
private:
    static const size_t SKIPLIST_LEVEL_DFT = 32;
};

template<typename T>
int SkipList<T>::init() {
    return init(SKIPLIST_LEVEL_DFT);
}

template<typename T>
int SkipList<T>::init(int level) {
    _level_num = level;
    _head = _tail = NULL;
    _length = 0;
    SkipListNode* node = allocate<SkipListNode>();
    node->init(_level_num);
    node->value = NULL;
    _head = node;
    return 0;
}

template<typename T>
int SkipList<T>::insert(T* tp) {
    SkipListNode* node = allocate<SkipListNode>();
    node->init(_level_num);
    node->value = tp;

    SkipListNode* p = _head;
    unsigned rank[SKIPLIST_LEVEL_DFT];
    SkipListNode *update[SKIPLIST_LEVEL_DFT];
    for (int i = _level_num - 1; i >= 0; i--) {
        rank[i] = (i == _level_num - 1)? 0: rank[i + 1];
        while (p->level[i].forward && 
                skiplist_cmp(p->level[i].forward->value, node->value) < 0) {
            rank[i] += p->level[i].span;
            p = p->level[i].forward;
        }
        update[i] = p;
    }
    int level = random_level();
    for (int i = 0; i < level; i++) {
        // TODO thread safe?
        node->level[i].forward = update[i]->level[i].forward;
        update[i]->level[i].forward = node;

        node->level[i].span = update[i]->level[i].span - (rank[0] - rank[i]);
        update[i]->level[i].span = (rank[0] - rank[i]) + 1;
    }

    for (int i = level; i < _level_num; i++) {
        update[i]->level[i].span++;
    }
    node->backward = (update[0] == _head)? NULL: update[0];
    if (node->level[0].forward) {
        node->level[0].forward->backward = node;
    } else {
        _tail = node;
    }
    _length++;
    return 0;
}

template<typename T>
typename SkipList<T>::SkipListNode* SkipList<T>::nth_element(size_t k) {
    if (k > _length) {
        return NULL;
    }
    SkipListNode* p = _head;
    size_t pos = 0;
    for (int i = _level_num - 1; p && i >= 0; /* pass */) {
        if (pos == k) {
            return p;
        } else if (p->level[i].forward && pos + p->level[i].span <= k) {
            pos += p->level[i].span;
            p = p->level[i].forward;
        } else {
            i--;
        }
    }
    // print("ERROR");
    return NULL;
}

template<typename T>
int SkipList<T>::destroy() {
    SkipListNode* p = _head;
    while (p) {
        SkipListNode* next = p->level[0].forward;
        deallocate(p);
        p = next;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, q, v;
    int T;
    input(T);
    while (T--) {
        input (n >> q);
        vector<int> vec;
        vector<int> query;
        SkipList<int> sl = SkipList<int>();
        sl.init();
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            vec.push_back(v);
        }
        for (int i = 0; i < q; i++) {
            scanf("%d", &v);
            query.push_back(v);
        }
        for (int i = 0, j = 0; i < n && j < q; i++) {
            sl.insert(&vec[i]);
            // print(">> " << vec[i]);
            while (j < q && i + 1 == query[j]) {
                v = *(sl.nth_element(j+1)->value);
                printf("%d\n", v);
                j++;
            }
        }
        sl.destroy();
        if (T) {
            puts("");
        }
    }
    return 0;
}
