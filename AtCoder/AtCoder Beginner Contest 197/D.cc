#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long llint;

const int INF = 0x3f3f3f3f;
const llint INFLL = 0x3f3f3f3f3f3f3f3fLL;

void print() { cout << "\n"; }

template <typename...T, typename X>
void print(X&& x, T... args) { cout << x << " "; print(args...); }

int input() { return 0; }

template <typename...T, typename X>
int input(X& x, T&... args) {
    if (!(cin >> x)) return 0;
    return input(args...) + 1;
}

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

struct Point
{
    double x,y;
    Point(){}
    Point(double i_x,double i_y)
    {
        x=i_x;y=i_y;
    }
    Point operator - (const Point &p) const
    {
        return Point(x-p.x,y-p.y);
    }
    
    Point operator * (double val) const
    {
        return Point(x*val,y*val);
    }
    
    Point operator + (const Point &p) const
    {
        return Point(x+p.x,y+p.y);
    }
    friend bool operator == (const Point& pa,const Point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};


Point rotate(Point v,Point cc,double angle,double scale)
{
    Point ret=cc;
    v.x-=cc.x;v.y-=cc.y;
    cc.x=scale*cos(angle);
    cc.y=scale*sin(angle);
    ret.x+=v.x*cc.x-v.y*cc.y;
    ret.y+=v.x*cc.y+v.y*cc.x;
    return ret;
}


int main() {
    int n;
    input(n);

    double x1, y1;
    input(x1, y1);

    double x2, y2;
    input(x2, y2);

    double xm = (x1 + x2) / 2;
    double ym = (y1 + y2) / 2;
    double angle = (360. / n) / 360 * 2 * pi;

    auto p = rotate(Point(x1, y1), Point(xm, ym), angle, 1.0);
    print(p.x, p.y);

    return 0;
}

/*
^^^TEST^^^
4
1 1
2 2
-----
2.00000000000 1.00000000000
$$$TEST$$$


^^^TEST^^^
6
5 3
7 4
------
5.93301270189 2.38397459622
$$$TEST$$$


*/
