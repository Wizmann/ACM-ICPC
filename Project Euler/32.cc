#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define input(x) cin >> x
#define print(x) cout << x << endl

typedef long long llint;

const int SIZE = 9;

vector<int> v;

bool solve(int a, int b) {
    llint opa, opb, opc;
    opa = opb = opc = 0;
    for (int i = 0; i < a; i++) {
        opa = opa * 10 + v[i];
    }
    
    for (int i = a; i < a + b; i++) {
        opb = opb * 10 + v[i];
    }
    
    for (int i = a + b; i < (int)v.size(); i++) {
        opc = opc * 10 + v[i];
    }
    
    return opa * opb == opc;
}

llint show(int a, int b) {
    llint opa, opb, opc;
    opa = opb = opc = 0;
    for (int i = 0; i < a; i++) {
        opa = opa * 10 + v[i];
    }
    
    for (int i = a; i < a + b; i++) {
        opb = opb * 10 + v[i];
    }
    
    for (int i = a + b; i < (int)v.size(); i++) {
        opc = opc * 10 + v[i];
    }
    
    printf("%lld * %lld = %lld\n", opa, opb, opc);
    return opc;
}

int main()
{
    for (int i = 1; i <= SIZE; i++) {
        v.push_back(i);
    }
    llint ans = 0;
    set<llint> st;
    do {
        for (int i = 1; i < SIZE; i++) {
            for (int j = 1; i + j < SIZE; j++) {
                if (solve(i, j)) {
                    llint r = show(i, j);
                    if (st.find(r) == st.end()) {
                        ans += r;
                        st.insert(r);
                    }
                }
            }
        }
    } while(next_permutation(v.begin(), v.end()));
    print(ans);
    return 0;
}
