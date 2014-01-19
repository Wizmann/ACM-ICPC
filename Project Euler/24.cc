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
const int TIME = 1000000;

int _find_greater(const vector<int>& vec, int x)
{
    int n = vec.size();
    for (int i = n - 1; i > x; i--) {
        if (vec[i] > vec[x]) {
            return i;
        }
    }
    return -1;
}


void _next_permutation(vector<int>& vec)
{
    bool done = false;
    int n = vec.size();

    for (int i = n - 2; i >= 0; i--) {
        int ii = i + 1;
        if (vec[i] < vec[ii]) {
            int p = _find_greater(vec, i);
            swap(vec[i], vec[p]);
            reverse(vec.begin() + ii, vec.end());
            done = true;
            break;
        }
    }

    if (!done) {
        reverse(vec.begin(), vec.end());
    }
}

int main()
{
    vector<int> vec;
    for (int i = 0; i < SIZE; i++)  {
        vec.push_back(i);
    }
    
    int t = TIME % (1LL * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10) - 1;
    while (t--) {
        _next_permutation(vec);
        

    }

    for (int i = 0; i < SIZE; i++) {
        printf("%d", vec[i]);
    }
    puts("");
    
    return 0;
}
