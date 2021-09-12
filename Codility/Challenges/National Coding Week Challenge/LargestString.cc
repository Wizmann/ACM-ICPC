void convert2(string &S, int start, int end) {
    for (int i = start; i + 2 < end; i++) {
        if (S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'b') {
            S[i] = 'b';
            S[i + 1] = 'a';
            S[i + 2] = 'a';
        }
    }
}

string solution(string &S) {
    int n = S.size();
    int end = n;
    for (int i = n - 2; i >= 0; i--) {
        if (S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'b') {
            S[i] = 'b';
            S[i + 1] = 'a';
            S[i + 2] = 'a';
            convert2(S, i + 2, end);
            end = i + 1;
        }
    }
    return S;
}
