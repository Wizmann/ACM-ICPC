#define SIZE 128
#define eps 1e-9
#define ext 1e10

inline int zero(double x)
{
    if(x<-eps) return -1;
    else if(fabs(x)<eps) return 0;
    else return 1;
}

struct point
{
    double x,y;
    point(){}
    point(double i_x,double i_y)
    {
        x=i_x;y=i_y;
    }
    friend bool operator == (const point& pa,const point& pb)
    {
        return (zero(pa.x-pb.x)==0) && (zero(pa.y-pb.y)==0);
    }
};

struct segment
{
    point p1,p2;
    segment(){}
    segment(const point& i_p1,const point& i_p2)
    {
        p1=i_p1;p2=i_p2;
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
};

inline double xmult(point sp,point ep,point op)
{
    return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
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

bool onSegment(segment s,point p)
{
    return fabs(xmult(s.p2,p,s.p1))<eps && (p.x-s.p1.x)*(p.x-s.p2.x)<=0 && (p.y-s.p1.y)*(p.y-s.p2.y)<=0;
}

double pointDis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct polygen
{
    int n;
    double area;
    point array[SIZE+5];
    polygen(){}
    polygen(int i_n){n=i_n;}

	//求多边形的面积
    void getarea()
    {
        double tarea=0;
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            tarea+=array[i].x*array[j].y;
            tarea-=array[i].y*array[j].x;
        }
        tarea/=2;
        area=fabs(tarea);
    }
	
	//判断点是否在多边形内
    bool point_in(const point& a)
    {
        int cnt=0;
        segment shoot(a,point(1e10,a.y));
        for(int i=0;i<n;i++)
        {
            int ptr=-1;
            int j=(i+1)%n;

            segment edge(array[i],array[j]);
            if(onSegment(edge,a)) return true;

            if(zero(array[i].y-array[j].y)==0) continue;
            if(onSegment(shoot,array[i])) ptr=i;
            else if(onSegment(shoot,array[j])) ptr=j;

            if(ptr!=-1)
            {
                if(zero(array[ptr].y-max(array[i].y,array[j].y))==0) cnt++;
            }            
            else
            {
                point c;
                if(segIntersect(shoot,edge,c))  cnt++;
            }
        }
        //print(cnt);
        return cnt%2==1;
    }
};



//皮克定理，对于顶点都在整点上的简单多边形，求有多少整点在多边形内
//S=a+b÷2-1,
//其中a表示多边形内部的点数,b表示多边形边界上的点数,S表示多边形的面积

//需要有特殊判定的GCD函数
int gcd(int a,int b)
{
    if(a<b) return gcd(b,a);
    else if(b==0) return a;
    else if(a%b==0) return b;
    else return gcd(b,a%b);
}

int polygen_pick_theory()
{
    int edgePoint=0;
    int area=0;
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        area+=polygen[i].x*polygen[j].y-polygen[i].y*polygen[j].x;
        edgePoint+=gcd(abs(polygen[i].x-polygen[j].x),abs(polygen[i].y-polygen[j].y));
    }
    area=abs(area);
    return (area-edgePoint+2)/2;
}


//Graham算法求凸包
struct cmp//排序函数，极角序
{
    point p;
    cmp(const point &i_p)
    {
        p=i_p;
    }
    bool operator()(const point &a,const point &b)
	{
		if(fabs(xmult(a,b,p))<eps)	return pointDis(a,p)<pointDis(b,p);
		return xmult(a,b,p)>0;
	}
};

int findtop(point* array,int sz)
{
	int res=0;
	for(int i=0;i<sz;i++)
	{
		if(array[i].y<array[res].y) res=i;
		else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
	}
	return res;
}

int grahamScan(point* array,int sz)
{
	int top=findtop(array,sz);
	swap(array[0],array[top]);
	sort(array+1,array+sz,cmp(array[0]));
	
	top=1;
	for(int i=2;i<sz;i++)
	{
		while(top && xmult(array[i],array[top],array[top-1])>=0)
		{
			top--;
		}
		array[++top]=array[i];
	}
	return top+1;
}






//半平面交模版
struct polygen
{
	deque<point> pvec;
	
	//如果是顺时针序，则clockwise=true
	//否则是将其设为false
	void push_point(const point& i_p,bool clockwise=true)
	{
		if(clockwise) pvec.push_back(i_p);
		else pvec.push_front(i_p);
	}
	
	void KernelCut(segment s)
	{
		deque<point> core;
		int sz=(int)pvec.size();
		for(int i=0;i<sz;i++)
		{
			if(zero(xmult(pvec[i],s.p2,s.p1))>=0)
			{
				core.push_back(pvec[i]);
			}
			else
			{
				point cp;
				if(zero(xmult(pvec[i],s.p2,s.p1) * xmult(pvec[(i-1+sz)%sz],s.p2,s.p1))<0)
				{
					line l1=makeline(s);
					line l2=makeline(pvec[i],pvec[(i-1+sz)%sz]);
					lineIntersect(l1,l2,cp);
					core.push_back(cp);
				}
				
				if(zero(xmult(pvec[i],s.p2,s.p1) * xmult(pvec[(i+1)%sz],s.p2,s.p1))<0)
				{
					line l1=makeline(s);
					line l2=makeline(pvec[i],pvec[(i+1)%sz]);
					lineIntersect(l1,l2,cp);
					core.push_back(cp);
				}
			}
		}
		pvec=core;
	}

	void getKernel()
	{
		deque<point> backup;
		backup=pvec;
		int sz=backup.size();
		for(int i=0;i<sz;i++)
		{
			KernelCut(segment(backup[i],backup[(i+1)%sz]));
		}
	}
};
