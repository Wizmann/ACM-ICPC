/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, int> > pairs;
        for (auto item: airplanes) {
            int a = item.start;
            int b = item.end;
            pairs.push_back({a, 1});
            pairs.push_back({b, -1});
        }
        sort(pairs.begin(), pairs.end());
        
        int ans = 0;
        int cnt = 0;
        for (auto item: pairs) {
            if (item.second == 1) {
                cnt++;
            } else {
                cnt = max(0, cnt - 1);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
