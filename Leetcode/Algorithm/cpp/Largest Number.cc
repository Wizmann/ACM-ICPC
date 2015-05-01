class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), [](const int a, const int b)->bool {
            string str_a = to_string(a) + to_string(b);
            string str_b = to_string(b) + to_string(a);
            long long aa = strtoll(str_a.c_str(), nullptr, 10);
            long long bb = strtoll(str_b.c_str(), nullptr, 10);
            return aa > bb;
        });
        string res;
        for (auto& i: num) {
            res += to_string(i);
        }
        if (res[0] == '0') {
            return res.substr(res.rfind("0"));
        } else {
            return res;
        }
    }
};
