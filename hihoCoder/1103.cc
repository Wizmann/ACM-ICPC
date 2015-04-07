#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

const int SIZE = 1024 + 233;
const int COLORS = 3;

unordered_map<string, int> colormp = {
    {"RED", 0}, {"YELLOW", 1}, {"BLUE", 2}
};

char lecture[SIZE];
int colors[3];
stack<int> st;

bool is_color(const string& str) {
    return colormp.find(str) != colormp.end();
}

int string_to_color(const string& str) {
    return colormp[str];
}

bool is_end_color(const string& str) {
    return str[0] == '/';
}

int strlen_nospace(const string& str) {
    int res = 0;
    for (auto& c: str) {
        if (isalpha(c)) {
            res++;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%[^\n]", lecture);
    int n = strlen(lecture);
    char delim[] = "<>";
    
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && isalpha(lecture[i]) &&
                (lecture[i - 1] == '<' || isupper(lecture[i - 1]))) {
            lecture[i] ^= 32;
        }
    }

    for (char* token = strtok(lecture, delim); 
            token != nullptr; 
            token = strtok(nullptr, delim)) {
        if (is_color(token)) {
            int c = string_to_color(token);
            st.push(c);
        } else if (is_end_color(token)) {
            st.pop();
        } else if (!st.empty()) {
            int c = st.top();
            colors[c] += strlen_nospace(token);
        } else {
            // no color
        }
    }

    for (int i = 0; i < COLORS; i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", colors[i]);
    }
    puts("");
    
    while (!st.empty()) {}
    return 0;
}

