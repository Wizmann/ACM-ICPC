const int SIZE = 555;

inline int lowbit(int x){return (x)&(-x);}

struct BIT
{
    int baum[SIZE];
    inline void init(){memset(baum,0,sizeof(baum));}
    
    inline void add(int pos,int val)
    {
        while(pos<SIZE)
        {
            baum[pos]+=val;
            pos+=lowbit(pos);
        }
    }
    inline int sum(int pos)
    {
        int res=0;
        while(pos>0)
        {
            res+=baum[pos];
            pos-=lowbit(pos);
        }
        return res;
    }
    inline int sum(int a,int b)
    {
        return sum(b)-sum(a-1);
    }
};

struct BIT_2D
{
    BIT baum[SIZE];
    inline void init()
    {
        for(int i=0;i<SIZE;i++) baum[i].init();
    }
    inline void add(int y,int x,int val)
    {
        while(y<SIZE)
        {
            baum[y].add(x,val);
            y+=lowbit(y);
        }
    }
    inline int sum(int y1,int x1,int y2,int x2)
    {
        int res=0;
        while(y2>0)
        {
            res+=baum[y2].sum(x1,x2);
            y2-=lowbit(y2);
        }
        y1--;
        while(y1>0)
        {
            res-=baum[y1].sum(x1,x2);
            y1-=lowbit(y1);
        }
        return res;
    }
};


class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix_) {
        bimat.init();
        matrix = matrix_;
        n = matrix.size();
        if (n == 0) {
            return;
        }
        m = matrix[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bimat.add(i + 1, j + 1, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        bimat.add(row + 1, col + 1, -matrix[row][col]);
        bimat.add(row + 1, col + 1, val);
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return bimat.sum(row1 + 1, col1 + 1, row2 + 1, col2 + 1);
    }
private:
    BIT_2D bimat;
    vector<vector<int> > matrix;
    int n, m;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
