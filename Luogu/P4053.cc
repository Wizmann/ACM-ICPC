#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

struct Task {
    int cost, ddl;
};

int main() {
    int n;
    input(n);
    vector<Task> tasks;

    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        tasks.push_back({a, b});
    }
    sort(tasks.begin(), tasks.end(), [](const Task& t1, const Task& t2) {
        return t1.ddl < t2.ddl;
    });

    int cur = 0;
    int cnt = 0;
    priority_queue<int> pq;
    for (const auto& t: tasks) {
        if (cur + t.cost <= t.ddl) {
            cur += t.cost;
            pq.push(t.cost);
            cnt++;
        } else {
            if (!pq.empty() && t.cost < pq.top() && cur - pq.top() + t.cost <= t.ddl) {
                cur -= pq.top();
                pq.pop();
                cur += t.cost;
                pq.push(t.cost);
            }
        }
    }

    print(cnt);

    return 0;
}




/*
^^^TEST^^^
4
100 200
200 1300
1000 1250
2000 3200
---
3
$$$TEST$$$

^^^TEST^^^
4
1000 1000
1 1001
2 1001
3 100001
---
3
$$$TEST$$$

^^^TEST^^^
4
5 5
100 100
100 200
100 300
---
3
$$$TEST$$$

^^^TEST^^^
3
100 100
5 101
5 102
---
2
$$$TEST$$$
 */
