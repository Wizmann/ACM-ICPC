#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x


struct Node {
    int l;
    int r;
    int value;
};

int n;
int nums[SIZE];
int res[SIZE];
vector<Node> st;

int main() {
    freopen("input.txt", "r", stdin);
    input(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    nums[n] = -1;
    
    for (int i = 0; i <= n; i++) {
        int pre = i;
        while (!st.empty() && nums[i] < st.rbegin()->value) {
            // oh, it's my fault?
            int d = i - 1 - st.rbegin()->l;
            res[d] = max(res[d], st.rbegin()->value);
            pre = st.rbegin()->l;
            st.pop_back();
        }
        
        st.push_back({pre, i, nums[i]});
    }
    
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    puts("");
    
    return 0;
}
