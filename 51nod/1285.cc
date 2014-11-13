#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main() {
    freopen("input.txt", "r", stdin);
    int n, t;
    vector<int> vec;
    
    input(n);
    for (int i = 0; i < n; i++) {
        input(t);
        vec.push_back(t);
    }
    
    vector<int> peaks;
    peaks.resize(n);
    int peak_cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (vec[i] > vec[i - 1] && vec[i] > vec[i + 1]) {
            peaks[i] = 1;
            peak_cnt++;
        }
    }
    
    if (!peak_cnt) {
        print(0);
        exit(0);
    }
    
    for (int i = 1; i < n; i++) {
        peaks[i] += peaks[i - 1];
    }
    
    for (int i = 1; i < n; i++) {
        int dis = i + 1;
        if (n % dis != 0) {
            continue;
        }
        bool flag = false;
        int pre = -1;
        for (int j = i; j < n; j += dis) {
            if (peaks[j] > pre) {
                pre = peaks[j];
                flag = true;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            print(n / dis);
            break;
        }
    }

    return 0;
}
