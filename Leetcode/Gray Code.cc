class Solution {
public:
    static const int SIZE = 3000;
    vector<int> grayCode(int n) {
        char visit[SIZE] = {0};
        vector<int> v;
        int x = 0;
        v.push_back(x);
        visit[0] = 1;

        for (int i = 1; i < (1 << n); i++) {
            for(int j = 0; j < 32; j++) {
                int y = x ^ (1 << j);
                if (!visit[y]) {
                    v.push_back(y);
                    visit[y] = 1;
                    x = y;
                    break;
                }
            }
        }
        return v;
    }
};
