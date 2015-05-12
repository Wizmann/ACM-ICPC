class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        for (auto iter = A.begin(); iter != A.end(); /* pass */) {
            if (*iter == elem) {
                iter = A.erase(iter);
            } else {
                ++iter;
            }
        }
        return A.size();
    }
};
