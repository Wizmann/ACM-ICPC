#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x 

typedef long long llint;

string months[] = {"January", 
        "February", 
        "March", 
        "April", 
        "May", 
        "June", 
        "July", 
        "August", 
        "September", 
        "October", 
        "November" , 
        "December"};
        
struct Date {
    llint yy, mm, dd;
    
    Date() {}
    Date(llint iyy, string imm, llint idd): yy(iyy), dd(idd) {
        for (int i = 0; i < 12; i++) {
            if (imm == months[i]) {
                mm = i + 1;
            }
        }
    }
};

llint year_diff(llint a, llint b) {
    if (a >= b) {
        return 0;
    }
    llint ans = 0;
    llint aa = (a + 3) / 4 * 4;
    llint bb = (b / 4) * 4;
    if (aa <= bb) {
        ans += (bb - aa) / 4 + 1;
    }
    
    aa = (a + 99) / 100 * 100;
    bb = (b / 100) * 100;
    
    if (aa <= bb) {
        ans -= (bb - aa) / 100 + 1;
    }
    
    aa = (a + 399) / 400 * 400;
    bb = (b / 400) * 400;
    if (aa <= bb) {
        ans += (bb - aa) / 400 + 1;
    }
    
    return ans;
}

bool is_leap(const Date& d) {
    return (d.yy % 4 == 0 && d.yy % 100 != 0) || (d.yy % 400 == 0);
}

llint solve(const Date& da, const Date& db) {
    llint ans = 0;
    ans += year_diff(da.yy + 1, db.yy - 1);
    
    if (da.yy < db.yy && is_leap(da) && da.mm < 3) {
        ans++;
    }
    
    if (da.yy < db.yy && is_leap(db) && (db.mm >= 3 || (db.mm == 2 && db.dd == 29))) {
        ans++;
    }
    
    if (da.yy == db.yy && is_leap(da) && da.mm < 3 && (db.mm >= 3 || (db.mm == 2 && db.dd == 29))) {
        ans++;
    }
    
    return ans;
}

int main() {
    int T;
    string mm, temp;
    int yy, dd, cas = 1;
    input(T);
    while (T--) {
        Date a, b;
        input(mm >> dd >> temp >> yy);
        a = Date(yy, mm, dd);
        input(mm >> dd >> temp >> yy);
        b = Date(yy, mm, dd);
        printf("Case #%d: %lld\n", cas++, solve(a, b));
    }
    return 0;
}
        
