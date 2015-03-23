#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

class CombinationLockDiv1 {
public:
    int minimumMoves(vector <string> P, vector <string> Q) {
        string A;
        A = accumulate(P.begin(), P.end(), A);
        string B;
        B = accumulate(Q.begin(), Q.end(), B);
        return minimalMoves(A, B);
    }
private:
    int minimalMoves(string& A, string& B) {
        A = A + string("0");
        B = B + string("0");
        int n = A.size();
        multiset<int> st;

        for (int i = 0; i < n - 1; i++) {
            int diff_a = (A[i] - A[i + 1] + 10) % 10;
            int diff_b = (B[i] - B[i + 1] + 10) % 10;
            int diff = (diff_a - diff_b + 10) % 10;
            if (diff) {
                st.insert(diff);
            }
        }

        int res = 0;
        while (st.size() > 1) {
            res++;

            int mini = *st.begin();
            int maxi = *st.rbegin();

            st.erase(st.find(mini));
            st.erase(st.find(maxi));

            mini--;
            maxi++;

            if (mini != 0) {
                st.insert(mini);
            }
            if (maxi % 10 != 0) {
                st.insert(maxi);
            }
        }

        if (!st.empty()) {
            int u = *st.begin();
            res += min(u, 10 - u);
        }

        return res;
    }
};
