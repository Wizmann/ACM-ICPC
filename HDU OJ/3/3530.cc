/*$$$
[Description]
There is a sequence of integers. Your task is to find the longest subsequence that satisfies the following condition: 

The difference between the maximum element and the minimum element of the subsequence is no smaller than m and no larger than k.

[Solution]
One crucial conclusion for this problem:

If `MaxMinusMin(a[l...r]) < m`, it will not increase the value of `MaxMinusMin(a[l...r])` by popping any element from the subarray.

So there are two different way to achieve a solution:

* Use multiset<int> to maintain the max and min value in the subarray
* Use **two** monotone deques to maintain the max and min value in the subarray

[Tags]
monotone, multiset

[Difficulty]
3

[Url]
http://acm.hdu.edu.cn/showproblem.php?pid=3530

[Starred]
$$$*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int n, m, k;
vector<int> ns;

int main() {
    freopen("input.txt", "r", stdin);
    while (input(n >> m >> k)) {
        ns = vector<int>(n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ns[i]);
        }
        
        int ans = 0;
        deque<int> asc, des;
        int pos = -1;
        
        for (int i = 0; i < n; i++) {
            while (!asc.empty() && ns[asc.back()] >= ns[i]) {
                asc.pop_back();
            }
            asc.push_back(i);
            
            while (!des.empty() && ns[des.back()] <= ns[i]) {
                des.pop_back();
            }
            des.push_back(i);
            
            while (!des.empty() && !asc.empty() && ns[des.front()] - ns[asc.front()] > k) {
                if (asc.front() < des.front()) {
                    pos = asc.front();
                    asc.pop_front();
                } else {
                    pos = des.front();
                    des.pop_front();
                }
            }
            
            if (!des.empty() && !asc.empty() 
                    && ns[des.front()] - ns[asc.front()] <= k
                    && ns[des.front()] - ns[asc.front()] >= m) {
                ans = max(ans, i - pos);
            }
        }
        print(ans);
    }
    return 0;
}
