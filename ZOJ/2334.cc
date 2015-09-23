#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

template <typename T, typename Comparator=less<T> >
class LeftistHeap {
    struct Node {
        T value;
        int depth;
        Node* left;
        Node* right;
    };
public:
    LeftistHeap(): _root(nullptr) {}

    void empty() {
        return _root == nullptr;
    }

    void add(const T& item) {
        if (_root == nullptr) {
            _root = new Node({
                    item, 0, nullptr, nullptr
            });
            return;
        }
        LeftistHeap lh;
        lh.add(item);
        merge(lh);
    }

    void merge(LeftistHeap<T, Comparator>& lh) {
        Node* a = _root;
        Node* b = lh._root;
        _root = do_merge(a, b);
    }

    int top(T& item) {
        if (_root == nullptr) {
            return -1;
        }
        item = _root->value;
        return 0;
    }
    
    int pop(T& item) {
        if (_root == nullptr) {
            return -1;
        }
        item = _root->value;
        auto new_root = do_merge(_root->left, _root->right);
        delete _root;
        _root = new_root;
        return 0;
    }
private:
    int get_depth(Node* a) {
        if (a == nullptr) {
            return -1;
        }
        return a->depth;
    }

    Node* do_merge(Node* a, Node* b) {
        if (a == nullptr) {
            return b;
        }
        if (b == nullptr) {
            return a;
        }

        if (Comparator()(a->value, b->value)) {
            swap(a, b);
        }
        
        a->right = do_merge(a->right, b);
        a->depth = min(get_depth(a->left), get_depth(a->right)) + 1;
        if (get_depth(a->left) < get_depth(a->right)) {
            swap(a->left, a->right);
        }
        return a;
    }
private:
    Node* _root;
};

int n, q;
vector<LeftistHeap<int> > monkeys;
vector<int> father;

void init() {
    monkeys.clear();
    monkeys.resize(n + 1);
    father.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    if (father[x] == x) {
        return x;
    } else {
        return father[x] = find_father(father[x]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int a, b;
    while (input(n)) {
        init();
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a);
            monkeys[i].add(a);
        }
        input(q);
        while (q--) {
            scanf("%d%d", &a, &b);
            a = find_father(a);
            b = find_father(b);
            if (a == b) {
                puts("-1");
            } else {
                father[b] = a;
                
                int xx = -1;
                int yy = -1;
                
                monkeys[a].pop(xx);
                monkeys[a].add(xx / 2);
                monkeys[b].pop(yy);
                monkeys[b].add(yy / 2);
                
                monkeys[a].merge(monkeys[b]);
                int maxi = -1;
                monkeys[a].top(maxi);
                printf("%d\n", maxi);
            }
        }
    }
    return 0;
}

