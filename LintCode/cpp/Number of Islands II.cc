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
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int m, int n, vector<Point>& operators) {
        _n = n;
        _m = m;
        _grid_num = n * m;
        init();
        
        vector<int> res;
        
        int ans = 0;
        for (const auto& point: operators) {
            int y = point.y;
            int x = point.x;
            island_vec[get_nr(y, x)] = true;
            
            vector<Point> adjacent_points;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) != 1) {
                        continue;
                    }
                    int ny = y + i;
                    int nx = x + j;
                    if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                        if (is_island(ny, nx)) {
                            adjacent_points.push_back({nx, ny});
                        }
                    }
                }
            }

            unordered_set<int> islands;
            for (const auto& adjacent_point: adjacent_points) {
                int island_nr = find_father(
                    get_nr(adjacent_point.y, adjacent_point.x)
                );
                
                islands.insert(island_nr);
            }
            
            if (islands.empty()) {
                ans++;   
            } else {
                ans -= islands.size() - 1;
            }
            res.push_back(ans);
            
            for (const auto& adjacent_point: adjacent_points) {
                island_union(adjacent_point, point);
            }
        }
        return res;
    }
private:
    void init() {
        father.resize(_grid_num);
        island_vec.resize(_grid_num);
        for (int i = 0; i < _grid_num; i++) {
            father[i] = i;
            island_vec[i] = false;
        }
    }
    int get_nr(int y, int x) {
        return y * _m + x;
    }
    int find_father(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find_father(father[x]);
    }
    bool is_island(int y, int x) {
        return island_vec[get_nr(y, x)];
    }
    void island_union(Point a, Point b) {
        father[find_father(get_nr(a.y, a.x))] = find_father(get_nr(b.y, b.x));
    }
private:
    int _n;
    int _m;
    int _grid_num;
    vector<int> father;
    vector<bool> island_vec;
};
