#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


const double eps = 1e-6;
const double pi = acos(-1);
const double inf = 1e20;

inline int zero(double x)
{
    if(x<-eps) return -1;
    else if(fabs(x)<eps) return 0;
    else return 1;
}

inline double mul(double x)
{
    return x*x;
}

struct point
{
    double x,y;
    point(){}
    point(double i_x,double i_y)
    {
        x=i_x;y=i_y;
    }
    point operator - (const point &p) const
    {
        return point(x-p.x,y-p.y);
    }
    
    point operator * (double val) const
    {
        return point(x*val,y*val);
    }
    
    point operator + (const point &p) const
    {
        return point(x+p.x,y+p.y);
    }
    friend bool operator == (const point& pa,const point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};

//返回vector(op->sp)与vector(op->ep)的向量积
//abs(xmult(sp,ep,op)) = 2* 三角形面积（sp,ep,op)
//xmult(sp,ep,op) = |op->sp| * |op->ep| * sin(sop) -> 边op->sp到边op->ep的夹角
//正负性用右手定则判定，从手指从op->sp握到op->ep方向
inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

inline double pntDis(const point &a,const point &b)
{
    return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}


struct segment
{
    point p1,p2;
    segment(){}
    segment(const point &ip1,const point &ip2)
    {
        p1=ip1;p2=ip2;
    }
    double distopoint(const point &c)//点到线段的最小距离
    {
        double x=mul(p1.x-c.x)+mul(p1.y-c.y);
        double y=mul(p2.x-c.x)+mul(p2.y-c.y);
        double z=mul(p1.x-p2.x)+mul(p1.y-p2.y);
        if(x+z-y<0 || y+z-x<0) return sqrt(min(x,y));
        return fabs(xmult(c,p1,p2)/sqrt(z));
    }
    double distoline(const point &c)//点到线段所在直线的最小距离
    {
        return fabs(xmult(c,p1,p2))/pntDis(p1,p2);
    }    
};


struct line
{
    double a,b,c;
    line(){}
    line(double i_a,double i_b,double i_c)
    {
        a=i_a;b=i_b;c=i_c;
    }
    
    //判定直线相等
    friend bool operator == (const line x,const line y)
    {
        double d;
        if(!zero(y.a)) d=x.a/y.a;
        else if(!zero(y.b)) d=x.b/y.b;
        else if(zero(y.c))
        {
            if(!zero(x.b)||!zero(x.a)) return true;
            else if(zero(x.c)) return true;
            else return false;
        }
        else return false;

        if(x.a==d*y.a&&x.b==d*y.b&&x.c==d*y.c) return true;
        else return false;
    }
    
    //求过p点的，垂直于l的直线
    line make_vertical(const point &p)
    {
        line res=(*this);
        swap(res.a,res.b);
        res.b*=-1;
        res.c=-(res.a*p.x+res.b*p.y);

        return res;
    }
    
    //点到直线的距离,精度问题！！！
    //可以采用点到线段所在直线的长度代替，见Segment类
    double distopoint(const point &p)
    {
        return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
    }
};


//返回vector(op->sp)与vector(op->ep)的数量积
//dotmult(sp,ep,op) = |op->sp| * |op->ep| * cos(sop) -> 边op->sp到边op->ep的夹角
double dotmult(point sp,point ep,point op)
{
    return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}

//求向量的夹角，从(sp->op)到(ep->op)，较精确
double getangle(const point &sp,const point &ep,const point &op)
{
    double a=atan2(sp.y-op.y,sp.x-op.x);
    double b=atan2(ep.y-op.y,ep.x-op.x);
    if(b-a>pi) a+=2*pi;
    if(a-b>pi) b+=2*pi;
    return a-b;
}


line makeLine(point p1,point p2)
{
    line res;
    int sig=1;
    res.a=p2.y-p1.y;
    if(zero(res.a)<0)
    {
        sig=-1;
        res.a=sig*res.a;
    }
    res.b=sig*(p1.x-p2.x);
    res.c=sig*(p1.y*p2.x-p2.y*p1.x);
    return res;
}

line makeLine(segment s)
{
    return makeLine(s.p1,s.p2);
}

bool lineIntersect(line l1,line l2,point &p)
{
    double d=l1.a*l2.b-l2.a*l1.b;
    if(fabs(d)<eps) return false;
    else
    {
        p.x = (l2.c*l1.b-l1.c*l2.b)/d;
        p.y = (l2.a*l1.c-l1.a*l2.c)/d;
        return true;
    }
}

bool segIntersect(segment l1,segment l2,point &p)//线段相交，包括特殊的情况
{
    if((max(l1.p1.x,l1.p2.x)>=min(l2.p1.x,l2.p2.x))&&
       (max(l1.p1.y,l1.p2.y)>=min(l2.p1.y,l2.p2.y))&&
       (max(l2.p1.x,l2.p2.x)>=min(l1.p1.x,l1.p2.x))&&
       (max(l2.p1.y,l2.p2.y)>=min(l1.p1.y,l1.p2.y))&&//快速排斥实验
       (xmult(l1.p1,l2.p1,l2.p2)*xmult(l1.p2,l2.p1,l2.p2)<=eps)&&
       (xmult(l2.p1,l1.p1,l1.p2)*xmult(l2.p2,l1.p1,l1.p2)<=eps))//跨立实验
    {
        lineIntersect(makeLine(l1),makeLine(l2),p);
        return true;
    }
    else return false;
}


// Complete the solve function below.
string solve(int x1, int y1, int x2, int y2, int xm, int ym) {
    segment light(point(0, 0), point(xm, ym));
    segment wall(point(x1, y1), point(x2, y2));

    point p;

    return segIntersect(light, wall, p)? "NO": "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string x1Y1X2Y2XmYm_temp;
        getline(cin, x1Y1X2Y2XmYm_temp);

        vector<string> x1Y1X2Y2XmYm = split_string(x1Y1X2Y2XmYm_temp);

        int x1 = stoi(x1Y1X2Y2XmYm[0]);

        int y1 = stoi(x1Y1X2Y2XmYm[1]);

        int x2 = stoi(x1Y1X2Y2XmYm[2]);

        int y2 = stoi(x1Y1X2Y2XmYm[3]);

        int xm = stoi(x1Y1X2Y2XmYm[4]);

        int ym = stoi(x1Y1X2Y2XmYm[5]);

        string result = solve(x1, y1, x2, y2, xm, ym);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

