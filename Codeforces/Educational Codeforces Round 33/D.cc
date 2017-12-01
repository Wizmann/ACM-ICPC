#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

template<typename T>
T inrange(T mini, T value, T maxi) {
    return max(mini, min(value, maxi));
}

typedef long long llint;

const int SIZE = 123456;

int n, d;
vector<int> ns;

int main() {
    input(n >> d);

    ns.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ns[i]);
    }

    multiset<int> st;
    for (int i = 0, sum = 0; i < n; i++) {
        sum += ns[i];
        st.insert(sum);
    }

    int cur = 0;
    int cnt = 0;
    for (int i = 0, sum = 0; i < n; i++) {
        sum += ns[i];

        if (ns[i] == 0) {
            int maxi = inrange(0, d - (*st.rbegin() - sum), d);
            if (cur > maxi) {
                cnt = -1;
                break;
            }
            if (cur < 0) {
                cur = maxi;
                cnt++;
            }
        }

        st.erase(st.find(sum));
        cur += ns[i];

        if (cur > d) {
            cnt = -1;
            break;
        }
    }
    print(cnt);

    return 0;
}
