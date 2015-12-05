#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

int find_min(const string& str, int ptr, char c) {
    int idx = -1;
    char mini = str[ptr];
    int n = str.size();
    
    for (int i = n - 1; i >= ptr; i--) {
        if (str[i] > c && str[i] <= mini) {
            mini = str[i];
            idx = i;
        }
    }
    return idx;
}

void get_permutations(string& line, vector<string>& perms) {
    int n = line.size();
    sort(line.begin(), line.end());
    while (true) {
        perms.push_back(line);
        
        bool flag = false;
        for (int i = n - 2; i >= 0; i--) {
            if (line[i] < line[i + 1]) {
                flag = true;
                int idx = find_min(line, i + 1, line[i]);
                swap(line[i], line[idx]);
                reverse(line.begin() + i + 1, line.end());
                break;
            }
        }
        
        if (!flag) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> perms;
        get_permutations(line, perms);
        
        int n = perms.size();
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                printf(",");
            }
            printf("%s", perms[i].c_str());
        }
        puts("");
    }
    return 0;
}
