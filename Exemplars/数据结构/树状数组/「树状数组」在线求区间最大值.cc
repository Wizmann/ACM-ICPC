struct BiTreeRMQ
{
    int baum[SIZE],num[SIZE];
    inline int lowbit(int x)
    {
        return x&(-x);
    }
    void init()
    {
        for(int i=1;i<SIZE;i++)
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
    int query(int a,int b)
    {
        int ans=num[b];
        while(a != b)
        {
            for (b = b - 1; b - lowbit(b) >= a; b -= lowbit(b))
            {
                ans=min(ans,baum[b]);
            }
            ans = min(ans, num[b]);
        }
        return ans;
    }

    void modify(int pos,int val)
    {
        num[pos]=val;
        for(int i=pos;i<SIZE;i+=lowbit(i))
        {
            baum[i]=num[i];
            for(int j=1;j<lowbit(i);j<<=1)
            {
                baum[i]=min(baum[i],baum[i-j]);
            }
        }
    }
};
