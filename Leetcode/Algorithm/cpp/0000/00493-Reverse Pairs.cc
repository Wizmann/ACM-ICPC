inline int lowbit(int x)
{
	return x&(-x);
}

class BiTree
{
public:
    BiTree(int size_): size(size_ + 100) {
        tree = vector<int>(size_ + 100, 0);
    }
    
	void add(int x,int val)
	{
		while(x < size)
		{
			tree[x] += val;
			x+=lowbit(x);
		}
	}
	
	int sum(int x)
	{
		int res=0;
		while(x > 0)
		{
			res+=tree[x];
			x-=lowbit(x);
		}
		return res;
	}
	
	int sum(int a,int b)//查询区间和
	{
		return sum(b)-sum(a-1);
	}
private:
    int size;
    vector<int> tree;
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<pair<int, int> > e;
        for (int i = 0; i < n; i++) {
            e.push_back({nums[i], i + 1});
        }
        
        sort(e.begin(), e.end());
        
        int p = 0;
        int q = 0;
        int ans = 0;
        BiTree bit(n);
        while (q < n) {
            while (p < n && 1LL * e[p].first * 2 < 1LL * e[q].first) {
                bit.add(e[p].second, 1);
                p++;
            }
            ans += bit.sum(e[q].second, n);
	    if (e[q].first < 0) {
		    ans--;
	    }
            q++;
        }
        return ans;
    }
};
