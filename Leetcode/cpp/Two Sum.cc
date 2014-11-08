class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        mp.clear();
        for(int i=0;i<(int)numbers.size();i++)
        {
            int x = numbers[i];
            mp[x]=i;
        }
        for(int i=0;i<(int)numbers.size();i++)
        {
            int x = numbers[i];
            int y = target - x;

            if(mp.find(y)!=mp.end())
            {
                vector<int> ans;
                ans.push_back(i+1);
                ans.push_back(mp[y]+1);
                return ans;
            }
        }
    }
    map<int, int> mp;
};