#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++) {
       cin >> topic[topic_i];
    }
    
    int maxi = 0;
    int maxi_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                cnt += (topic[i][k] == '1') | (topic[j][k] == '1');
            }
            if (cnt > maxi) {
                maxi = cnt;
                maxi_cnt = 1;
            } else if (cnt == maxi) {
                maxi_cnt++;
            }
        }
    }
    
    print(maxi);
    print(maxi_cnt);
    
    return 0;
}

