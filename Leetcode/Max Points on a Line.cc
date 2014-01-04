/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        for (auto iter = points.begin();
                iter != points.end();
                ++iter) {
            ans = max(ans, calc(points, *iter));
        }
        return ans;
    }
    
    int calc(vector<Point> &points, const Point& p) {
        map<pair<int, int>, int> mp;
        int base = 0;
        for (auto iter = points.begin();
                iter != points.end();
                ++iter) {
            int x = iter -> x - p.x;
            int y = iter -> y - p.y;
            if (!x && !y) base++;
            else if (!x) {
                mp[make_pair<int, int>(0, 1)]++;
            }
            else if (!y) {
                mp[make_pair<int, int>(1, 0)]++;
            } else {
                long long t = x * y;
                x = abs(x);
                y = abs(y);
                int g = gcd(x, y);
                x /= g;
                y /= g;
                x *= t < 0? -1 : 1;
                mp[make_pair<int, int>(int(x), int(y))]++;
            }
        }
        
        int ans = 0;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            ans = max(ans, iter->second);
        }
        return base + ans;
    }
    
    int gcd(int x, int y) {
        if (x % y == 0) return y;
        else return gcd(y, x % y);
    }
};
