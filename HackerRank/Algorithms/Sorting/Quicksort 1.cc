#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void partition(vector <int>&  ar) {
    int n = ar.size();
    if (n == 0) {
        return;
    }
    int pivot = *ar.begin();
    int ptr = 0;
    
    int l = 0;
    int r = n - 1;
    
    while (l <= r) {
        while (l <= r && (
                ar[l] < pivot || (ar[l] == pivot && ptr == 0))) {
            l++;
            ptr ^= ar[l] == pivot;
        }
        while (l <= r && (
                ar[r] > pivot || (ar[r] == pivot && ptr == 1))) {
            r--;
            ptr ^= ar[r] == pivot;
        }
        if (l <= r) {
            swap(ar[l], ar[r]);
            l++;
            r--;
        }
    }
    swap(ar[0], ar[r]);
    // return r;
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

    partition(_ar);
    
    for (auto i: _ar) {
        printf("%d ", i);
    }
    puts("");
   
   return 0;
}
