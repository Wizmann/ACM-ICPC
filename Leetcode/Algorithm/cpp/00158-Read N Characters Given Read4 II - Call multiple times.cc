const int N = 4;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    Solution() {
        l = 0;
        bufsize = 0;
    }

    int read(char *buf, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (l == bufsize) {
                bufsize = read4(buffer);
                l = 0;
            }
            if (l != bufsize) {
                buf[i] = buffer[l];
                l++;
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
private:
    int l, bufsize;
    char buffer[N];
};
