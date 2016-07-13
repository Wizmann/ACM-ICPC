#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int calc(vector<vector<int>> arr, int y, int x) {
    return arr[y][x] + 
           arr[y - 1][x - 1] +
           arr[y - 1][x] +
           arr[y - 1][x + 1] + 
           arr[y + 1][x - 1] +
           arr[y + 1][x] +
           arr[y + 1][x + 1];
}


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    const int n = 6;
    int ans = -0x3f3f3f3f;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            ans = max(ans, calc(arr, i, j));
        }
    }
    cout << ans << endl;
    return 0;
}
