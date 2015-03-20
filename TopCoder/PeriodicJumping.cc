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

class PeriodicJumping {
public:
    typedef long long llint;
    static const int INF = 0x3f3f3f3f;

    int minimalTime(int x, vector <int> jumpLengths) {
        x = abs(x);
        llint mini = x;
        llint maxi = x;
        llint sum = 0;
        for (auto len: jumpLengths) {
            sum += len;
        }

        llint step = (x / sum) * jumpLengths.size();
        maxi += (x / sum) * sum;
        mini = x - (x / sum) * sum;

        while (mini) {
            for (auto len: jumpLengths) {
                step++;
                if (mini <= len && len <= maxi) {
                    mini = 0;
                    break;
                }
                mini = min(abs(maxi - len),
                           abs(mini - len));
                maxi += len;
            }
        }
        return step;
    }
};

void TEST(int x, vector<int> jumpLengths, int ans) {
    auto pj = PeriodicJumping();
    vector<int> vec(jumpLengths); 
    int u = pj.minimalTime(x, jumpLengths); 
    if (ans != u) { 
        print("Answer is: " << ans << ". Response is: " << u); 
    } 
}

int main() {
    TEST(15, vector<int>({1,2,3,4,5,6,7,8,9,10}), 5);
    TEST(5, vector<int>({5}), 1);
    TEST(1, vector<int>({10}), 2);
    TEST(-10, vector<int>({2,3,4,500,6,7,8}), 11);
    TEST(-1000000000, vector<int>({1}), 1000000000);
    TEST(0, vector<int>({19911120}), 0);
    return 0;
}
