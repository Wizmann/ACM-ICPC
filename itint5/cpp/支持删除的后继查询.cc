int n;
vector<int> father;

void init(int N) {
    n = N;
    father.resize(N + 1);
    for (int i = 0; i < N + 1; i++) {
        father[i] = i;
    }
}

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    return father[x] = find_father(father[x]);
}


void removeNum(int x) {
    father[x] = find_father(x + 1);
}
int query(int x) {
    int res = find_father(x);
    if (res == n) {
        return -1;
    }
    return res;
}
