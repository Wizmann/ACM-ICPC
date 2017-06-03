/**
 * Definition for a Point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 

const int SIZE = 5000;

const double eps=1e-8;
const double inf=1e100;

inline double mul(double x)
{
	return x*x;
}

inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

double pntDis(const Point &a,const Point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double xmult(const Point &sp,const Point &ep,const Point &op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}

double Area(const Point &a,const Point &b,const Point &c)
{
	return fabs(xmult(a,b,c))/2.0;
}

bool onSegment(Point p1, Point p2, Point p)
{
	return zero(xmult(p2,p,p1))==0 &&
			zero((p.x-p1.x)*(p.x-p2.x))<=0 &&
			zero((p.y-p1.y)*(p.y-p2.y))<=0;
}


namespace ConvexHull
{
	int sz;
	Point array[SIZE],stack[SIZE];
	Point *p;

	inline void push(Point n){*p=n;p++;}
	inline void pop(){p--;}
	inline void init(int isz)
	{
		sz=isz;
		memset(stack,0,sizeof(stack));
		p=stack;
	}

	int cmp(const Point &p1,const Point &p2)
	{
		if(xmult(p1,p2,array[0])>0) return 1;
		else if(zero(xmult(p1,p2,array[0]))==0 && pntDis(p1,array[0])<pntDis(p2,array[0])) return 1;
		else return 0;
	}

	int findtop()
	{
		int res=0;
		for(int i=1;i<sz;i++)
		{
			if(array[i].y<array[res].y) res=i;
			else if(array[i].y==array[res].y && array[i].x<array[res].x) res=1;
		}
		return res;
	}
	int graham()
	{
		int top=findtop();
		push(array[top]);
		swap(array[0],array[top]);
		sort(array+1,array+sz,cmp);
		
		push(array[1]);
		push(array[2]);
		for(int i=3;i<sz;i++)
		{
			while(zero(xmult(array[i],*(p-1),*(p-2)))>0) pop();
			push(array[i]);
		}
		return p-stack;
	}
		
	double maxTriangle(int num)
	{
		double ret=0,tmp;
		int p=1,q=2;
		stack[num]=stack[0];
		for(int i=0;i<num;i++)
		{
			while(Area(stack[i],stack[q],stack[p+1])>(tmp=Area(stack[i],stack[q],stack[p]))) p=(p+1)%num;
			ret=max(ret,tmp);
			while(Area(stack[i],stack[q+1],stack[p])>(tmp=Area(stack[i],stack[q],stack[p]))) q=(q+1)%num;
			ret=max(ret,tmp);
		}
		return ret;
	}
}

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int n = points.size();
        ConvexHull::init(n);
        int idx = 0;
        for (auto p: points) {
            ConvexHull::array[idx++] = p;
        }
        int m = ConvexHull::graham();
        vector<Point> res;
        for (auto p: points) {
            for (int i = 0; i < m; i++) {
                if (onSegment(ConvexHull::stack[i], ConvexHull::stack[(i + 1) % m], p)) {
                    res.push_back(p);
                    break;
                }
            }
        }
        return res;
    }
};
