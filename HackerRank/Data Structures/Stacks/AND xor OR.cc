#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int INF = 0x3f3f3f3f;

int get_ans(const vector<int>& st) {
    if (st.size() <= 1) {
        return -INF;
    }
    int n = st.size();
    return st[n - 1] ^ st[n - 2];
}

int solve(const vector<int>& nums) {
    vector<int> st;
    int res = -INF;

    for (const auto num: nums) {
        while (!st.empty() && num <= *st.rbegin()) {
            res = max(res, get_ans(st));
            st.pop_back();
        }
        st.push_back(num);
    }
    return res;
}

/*
 * Complete the andXorOr function below.
 */
int andXorOr(vector<int> a) {
    int maxi = 0;
    a.push_back(-1);
    maxi = max(maxi, solve(a));
    a.pop_back();
    reverse(a.begin(), a.end());
    a.push_back(-1);
    maxi = max(maxi, solve(a));
    a.pop_back();
    return maxi;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    int result = andXorOr(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
