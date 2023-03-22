#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

template <typename TKey, typename TValue>
class OrderedDict {
public:
    OrderedDict() = default;

    bool Contains(const TKey& key) {
        return mp.count(key);
    }

    TValue Get(const TKey& key) {
        if (!Contains(key)) {
            return TValue();
        }

        return mp[key]->second;
    }

    void Set(const TKey& key, const TValue& value) {
        if (Contains(key)) {
            auto iter = mp[key];
            lst.erase(iter);
        }

        lst.push_front({key, value});
        mp[key] = lst.begin();
    }

    bool Delete(const TKey& key) {
        if (!Contains(key)) {
            return false;
        }

        auto iter = mp[key];
        mp.erase(mp.find(key));
        lst.erase(iter);

        return true;
    }

    TValue First() {
        return lst.begin()->second;
    }

    typename list<pair<TKey, TValue>>::iterator Begin() {
        return lst.begin();
    }

    typename list<pair<TKey, TValue>>::iterator End() {
        return lst.end();
    }

    bool Empty() const {
        return mp.empty();
    }

    size_t Size() const {
        return mp.size();
    }

private:
    list<pair<TKey, TValue> > lst;
    map<TKey, typename list<pair<TKey, TValue>>::iterator> mp;
};

struct MemBlock {
    int rid;
    int cid;
    int pid;
    llint size;
};

class Buddy {
public:
    Buddy(int L_, int U_) : L(L_), U(U_) {
        for (int l = L; l <= U; l++) {
            pool.push_back(OrderedDict<int, int>());
        }
        pool[0].Set(0, 0);
    }

    MemBlock Allocate(int pid, llint size) {
        int rid = RowIdBySize(size);
        for (int i = rid; i >= 0; i--) {
            if (!pool[i].Empty()) {
                // print(i, rid);
                return DoAllocate(i, pool[i].First(), size, pid);
            }
        }
        assert(false);
        return {-1, -1, -1, -1};
    }

    void Deallocate(const MemBlock& mem) {
        int rid = mem.rid;
        int cid = mem.cid;
        
        DoDeallocate(rid, cid);
    }

    vector<MemBlock> GetFreeblocks() {
        vector<MemBlock> freeblocks;
        for (int i = 0; i < (int)pool.size(); i++) {
            for (auto iter = pool[i].Begin(); iter != pool[i].End(); ++iter) {
                int cid = iter->first;
                freeblocks.push_back({i, cid, -1, GetSizeByRowId(i)});
            }
        }
        return freeblocks;
    }

private:
    llint GetSizeByRowId(int r) const {
        return 1LL << (U - r);
    }

    int RowIdBySize(llint size) {
        size--;
        size |= size >> 1;
        size |= size >> 2;
        size |= size >> 4;
        size |= size >> 8;
        size |= size >> 16;
        size |= size >> 32;
        size++;

        int cnt = 0;
        while (size > (1LL << (L + cnt))) {
            cnt++;
        }

        return pool.size() - cnt - 1;
    }

    int GetPeer(int cid) {
        return ((cid - 1) ^ 1) + 1;
    }

    MemBlock DoAllocate(int rid, int cid, llint size, int pid) {
        assert(pool[rid].Contains(cid));

        llint blocksize = GetSizeByRowId(rid);
        if (rid < (int)pool.size() - 1 && size * 2 <= blocksize) {
            pool[rid].Delete(cid);
            pool[rid + 1].Set(cid * 2 + 1, cid * 2 + 1);
            pool[rid + 1].Set(cid * 2 + 2, cid * 2 + 2);
            return DoAllocate(rid + 1, cid * 2 + 1, size, pid);
        } else {
            pool[rid].Delete(cid);
            return {rid, cid, pid, size};
        }
    }

    void DoDeallocate(int rid, int cid) {
        int peer = GetPeer(cid);
        // print(cid, peer);

        if (rid != 0 && pool[rid].Contains(peer)) {
            pool[rid].Delete(peer);
            DoDeallocate(rid - 1, (cid - 1) / 2);
        } else {
            pool[rid].Set(cid, cid);
        }
    }
private:
    int L, U;
    vector<OrderedDict<int, int> > pool;
};

void ShowResult(vector<MemBlock>& memblocks, vector<string>& pnames) {
    map<int, MemBlock> mp;
    int max_cid = 0;
    for (auto block : memblocks) {
        if (block.rid == -1) {
            continue;
        }
        mp[block.cid] = block;
        max_cid = max(max_cid, block.cid);
    }
    std::function<void(int)> dfs;
    dfs = [&](int id) -> void {
        if (id > max_cid) {
            return;
        }

        if (mp.count(id)) {
            auto& block = mp[id];    
            if (block.pid == -1) {
                printf("Hole:%lld\n", block.size);
                // printf("(%d)Hole:%lld\n", block.cid, block.size);
            } else {
                printf("%s:%lld\n", pnames[block.pid].c_str(), block.size);
                // printf("(%d)%s:%lld\n", block.cid, pnames[block.pid].c_str(), block.size);
            }
        } else {
            dfs(id * 2 + 1);
            dfs(id * 2 + 2);
        }
    };

    dfs(0);
}

int main() {
    int T;

    input(T);

    for (int case_ = 0; case_ < T; case_++) {
        if (case_) {
            puts("");
        }
        int U, L;
        scanf("%d%d\n", &U, &L);

        Buddy b(L, U);
        map<string, int> mp;
        vector<string> pnames;
        vector<MemBlock> memblocks;

        string buffer;

        while (true) {
            getline(cin, buffer);
            // print(">>", buffer);

            if (buffer[0] == '\0') {
                auto items = b.GetFreeblocks();
                for (auto item: items) {
                    memblocks.push_back(item);
                }
                ShowResult(memblocks, pnames);
                break;
            }

            char pname[1024];
            int mem;
            sscanf(buffer.c_str(), "%s%d", pname, &mem);

            if (mp.count(pname) == 0) {
                pnames.push_back(pname);
                mp[pname] = pnames.size() - 1;
                memblocks.push_back({-1, -1, -1, -1});
            }

            assert(mp.count(pname));
            int pid = mp[pname];

            if (mem) {
                memblocks[pid] = b.Allocate(pid, mem);
            } else {
                b.Deallocate(memblocks[pid]);
                memblocks[pid] = {-1, -1, -1, -1};
            }
        }
    }

    return 0;
}

/*

^^^TEST^^^
4

10 2
A 2
C 64
A 0
E 64
F 64

10 2
A 2
C 64
A 0
C 0
E 64
F 64

10 2
A 128
B 512
B 0
A 0
C 256

10 2
A 64
B 64
C 64
D 64
B 0
C 0
E 64

-------------------
E:64
C:64
F:64
Hole:64
Hole:256
Hole:512

E:64
F:64
Hole:128
Hole:256
Hole:512

C:256
Hole:256
Hole:512

A:64
Hole:64
E:64
D:64
Hole:256
Hole:512
$$$TEST$$$

^^^TEST^^^
1
10 4
A 70
B 35
C 80
A 0
D 60
B 0
-------------------
Hole:128
Hole:64
D:60
C:80
Hole:128
Hole:512
$$$TEST$$$

*/
