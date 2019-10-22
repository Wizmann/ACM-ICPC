#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int MOD = 1000'000'000 + 7;

template <typename T>
class Matrix : public vector<vector<T> > {
public:
    Matrix() {}
    Matrix(T n) : vector<vector<T> >(n) {}
};

template <typename T>
Matrix<T> newMatrix(int n, int m) {
    Matrix<T> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i] = vector<T>(m, 0);
    }
    return mat;
}

template <typename T>
Matrix<T> matmul(
    const Matrix<T>& ma,
    const Matrix<T>& mb,
    int MOD
) {
    int n1 = ma.size();
    int m1 = ma[0].size();

    int n2 = mb.size();
    int m2 = mb[0].size();

    assert (m1 == n2);

    Matrix<T> res(n1);
    for (int i = 0; i < n1; i++) {
        res[i] = vector<T>(m2, 0);
    }

    for (int i = 0; i < n1; i++) {
        for (int k = 0; k < n2; k++) {
            if (ma[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m1; j++) {
                res[i][j] = (res[i][j] + 1LL * ma[i][k] * mb[k][j] % MOD) % MOD;
            }
        }
    }

    return res;
}

template <typename T>
Matrix<T> matpow(const Matrix<T>& ma, int p, int MOD) {
    int n = ma.size();
    int m = ma[0].size();

    assert (n == m);

    Matrix<T> a = ma;

    Matrix<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = vector<T>(n, 0);
        res[i][i] = 1;
    }

    while (p) {
        if (p & 1) {
            res = matmul(res, a, MOD);
        }
        a = matmul(a, a, MOD);
        p >>= 1;
    }
    return res;
}


// Complete the solve function below.
int solve(int a, int b, int n) {
    Matrix<int> m1 = newMatrix<int>(1, 2);
    m1[0][0] = a;
    m1[0][1] = b;

    Matrix<int> m2 = newMatrix<int>(2, 2);
    m2[0][0] = 0;
    m2[0][1] = 1;
    m2[1][0] = 1;
    m2[1][1] = 1;

    m2 = matpow(m2, n, MOD);
    m1 = matmul(m1, m2, MOD);

    return m1[0][0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string abn_temp;
        getline(cin, abn_temp);

        vector<string> abn = split_string(abn_temp);

        int a = stoi(abn[0]);

        int b = stoi(abn[1]);

        int n = stoi(abn[2]);

        int result = solve(a, b, n);

        fout << result << "\n";
    }

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

