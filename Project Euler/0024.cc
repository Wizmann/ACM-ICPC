#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 10;
int factorial[SIZE + 1];
vector<int> nums;

void init()
{
    int r = 1;
    factorial[0] = 1;
    for (int i = 1; i <= SIZE; i++) {
        factorial[i] = r;
        r *= (i + 1);
    }
    for (int i = 0; i < SIZE; i++) {
        nums.push_back(i);
    }
}

vector<int> solve(int n)
{
    vector<int> ans;
    n %= factorial[SIZE];

    for (int i = SIZE - 1; i >= 0; i--) {
        int v = n / factorial[i];
        ans.push_back(nums[v]);
        nums.erase(nums.begin() + v);
        n %= factorial[i];
    }
    return ans;
}


int main()
{
    init();
    int n = 1000000 - 1; // one MILLION
    vector<int> ans = solve(n);
    for (int i = 0; i < SIZE; i++) {
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}
