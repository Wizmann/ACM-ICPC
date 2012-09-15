//判定正负零，消除误差的影响
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

//点类
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

//线段
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
};


//直线
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
	
	double distopoint(const point &p)//点到直线的距离
	{
		return fabs(p.x*a+p.y*b+c)/sqrt(mul(a)+mul(b));
	}
};


struct circle
{
	point c;
	double r;
	circle(){}
	circle(const point& ic,double ir)
	{
		c=ic;r=ir;
	}

	int line_in_circle(line l)
	{
		if(zero(l.distopoint(c)-r)==0) return 1;
		else if(zero(l.distopoint(c)-r)<0) return 2;
		else return 0;
	}
	
	bool inCircle(const point& p)
	{
		return zero(pointDis(p,c)-r)<=0;
	}

	int cross_line(line l,point& a,point& b)//圆与直线的交
	{
		int ncr=line_in_circle(l);
		if(ncr==0)
		{
			a=b=point(-inf,-inf);
			return 0;
		}
		else
		{
			line v=l.make_vertical(c);
			point cr;
			lineIntersect(l,v,cr);
			if(ncr==1)
			{
				a=cr;
				b=point(inf,inf);
				return 1;
			}
			else
			{
				double dis=sqrt( (mul(r)-mul(pointDis(c,cr))) / (mul(v.a)+mul(v.b)) );
				double mx=v.a*dis;
				double my=v.b*dis;
				a=point(cr.x+mx,cr.y+my);
				b=point(cr.x-mx,cr.y-my);
				return 2;
			}
		}
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

//线段延长
segment extendSegment(point p1,point p2,int flag,double ext)
{
	//flag==0时，不延长;
	//flag==1时，从p1向p2延长
	//flag==2时，从p2向p1延长
	//flag==3时，双向延长
	segment res;
	double d=0;
	res.p1=p1;
	res.p2=p2;
	if(fabs(p1.x-p2.x)>eps) d=ext/fabs(p1.x-p2.x);
	if(d==0||fabs(p1.y-p2.y)>eps) d=ext/fabs(p1.y-p2.y);
	if(flag & 1)
	{
		res.p2.x+= (p2.x-p1.x)*d;
		res.p2.y+= (p2.y-p1.y)*d;
	}
	if(flag & 2)
	{
		res.p1.x+= (p1.x-p2.x)*d;
		res.p1.y+= (p1.y-p2.y)*d;
	}
	return res;
}

//点的移位
//以点v为圆心，逆时针旋转点p一定的角度，并将(v->p)扩大scale倍
point rotate(point v,point cc,double angle,double scale)
{
	point ret=cc;
	v.x-=cc.x;v.y-=cc.y;
	cc.x=scale*cos(angle);
	cc.y=scale*sin(angle);
	ret.x+=v.x*cc.x-v.y*cc.y;
	ret.y+=v.x*cc.y+v.y*cc.x;
	return ret;
}

bool onSegment(segment s,point p)
{
	return zero(xmult(s.p2,p,s.p1))==0 &&
			zero((p.x-s.p1.x)*(p.x-s.p2.x))<=0 &&
			zero((p.y-s.p1.y)*(p.y-s.p2.y))<=0;
}

inline double pointDis(point p1,point p2)
{
	return sqrt(mul(p1.x-p2.x)+mul(p1.y-p2.y));
}

inline double pointMulDis(point p1,point p2)
{
	return mul(p1.x-p2.x)+mul(p1.y-p2.y);
}

//点在线段的异侧，不含点在线段上的情况
//Unstable
int oppSide(point p1,point p2,segment s)
{
	return xmult(s.a,p1,s.b)*xmult(s.a,p2,s.b)<0;
}
