class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key, int HASH_SIZE) {
        int n = key.size();
        long long res = 0;
        long long hash_p = 1;
        for (int i = n - 1; i >= 0; i--) {
            res = (res + static_cast<int>(key[i]) * hash_p) % HASH_SIZE;
            hash_p = (hash_p * HASH_CONST) % HASH_SIZE;
        }
        return res;
    }
private:
    static const int HASH_CONST = 33;
};

