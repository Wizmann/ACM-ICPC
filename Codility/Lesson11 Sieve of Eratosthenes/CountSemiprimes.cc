vector<int> primes = {
    // list of primes which less or equal than 25000
};

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<int> seive(N + 1, 0);
    
    for (auto prime1: primes) {
        for (auto prime2: primes) {
            if (prime1 * prime2 > N) {
                break;
            }
            seive[prime1 * prime2] = 1;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        seive[i] += seive[i - 1];
    }
    
    int m = P.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(seive[Q[i]] - seive[P[i] - 1]);
    }
    return ans;
}
