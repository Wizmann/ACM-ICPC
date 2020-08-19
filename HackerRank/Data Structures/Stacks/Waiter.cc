#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the waiter function below.
 */
vector<int> waiter(vector<int> number, int q) {
    vector<int> res;
    vector<int> primes;
    int lp = 2;
    for (int i = 0; i < q; i++) {
        while (true) {
            bool is_prime = true;
            for (auto p: primes) {
                if (lp % p == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (!is_prime) {
                lp++;
            } else {
                primes.push_back(lp);
                lp++;
                break;
            }
        }
        int prime = *primes.rbegin();
        // cout << prime << endl;
        for (auto iter = number.begin(); iter != number.end(); /* pass */) {
            if (*iter % prime == 0) {
                res.push_back(*iter);
                iter = number.erase(iter);
            } else {
                ++iter;
            }
        }

        reverse(number.begin(), number.end());
    }
    
    reverse(number.begin(), number.end());

    for (auto num: number) {
        res.push_back(num);
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
