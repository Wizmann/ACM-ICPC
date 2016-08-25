//多边形与圆的面积交（精度较高）
const point ZERO(0,0);
struct circle
{
	point c;
	double r;
	circle(){}
	circle(const point &ic,double ir)
	{
		c=ic;r=ir;
	}
	
	void __cap_add(const point& u,const point& v,point* p,int& ind)
	{
		double a=pointMulDis(v,u);
		double b=-2*dotmult(v,ZERO,u);
		double c=mul(u.x)+mul(u.y)-mul(r);
		double d=mul(b)-4*a*c;
		p[ind++]=u;
		if(zero(d)<0) return;	
		d=sqrt(d);
		double t1=(-b+d)/(2*a);
		double t2=(-b-d)/(2*a);
		if(t1>t2) swap(t1,t2);
		if(zero(t1)>0 && zero(t1-1)<0) p[ind++]=u+(v-u)*t1;
		if(zero(t2)>0 && zero(t2-1)<0 && zero(t1-t2)!=0) p[ind++]=u+(v-u)*t2;
	}

	double __cap_area(const point& u,const point& v)
	{
		if(zero(hypot((u.x + v.x)/2.0,(u.y + v.y)/2.0)-r)<0)
		{
			return xmult(u,v,ZERO)/2;
		}
		else 
		{
			double t=get_angle(v,u,ZERO);
			return mul(r)*t/2;
		}
	}
	double cross_area_polygen(const polygen &poly)
	{
		point st[SIZE<<1];
		int ind=0;
		for(int i=0;i<poly.sz;i++)
		{
			int j=(i+1)%poly.sz;
			__cap_add(poly.p[i]-c,poly.p[j]-c,st,ind);
		}
		double res=0;
		for(int i=0;i<ind;i++)
		{
			int j=(i+1)%ind;
			//print(st[i].x<<' '<<st[i].y);
			res+=__cap_area(st[i],st[j]);
		}
		return fabs(res);
	}
		
};

//多边形与圆的面积交（精度较低）
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
	
	//unstable
	int cross_segment(segment s,point &a,point &b)
	{
		line l=makeline(s);
		int res=cross_line(l,a,b);
		if(res==2)
		{
			if(onSegment(s,a) && onSegment(s,b)) return 2;
			else if(onSegment(s,a)) return 1;
			else if(onSegment(s,b))
			{
				swap(a,b);
				return 1;
			}
			else return 0;
		}
		else if(res==1)
		{
			if(onSegment(s,a)) return 1;
			else return 0;
		}
		else return 0;
	}
	

	double get_cross_area_triangle(point p1,point p2)
	{
		point a,b;
		line l=line(p1,p2);
		int nc=cross_line(l,a,b);
		segment s(p1,p2);
		if(nc<2)
		{
			double ang=get_angle(p1,p2,c);
			return fabs(pi*r*r*ang/(2*pi));
		}
		else
		{
			bool ain=s.onSegment(a);
			bool bin=s.onSegment(b);
			if(!inCircle(p1)) swap(p1,p2);
			if(!ain&&!bin)
			{
				if(inCircle(p1) && inCircle(p2)) return fabs(xmult(p1,p2,c)/2);
				else
				{
					double ang=get_angle(p1,p2,c);
					return fabs(pi*r*r*ang/(2*pi));
				}
			}
			else if(ain&&bin)
			{
				double res=fabs(xmult(a,b,c)/2);
				if(pointDis(p1,a)>pointDis(p1,b)) swap(a,b);
				double ang=fabs(get_angle(p1,a,c))+fabs(get_angle(p2,b,c));
				res+=pi*r*r*ang/(2*pi);
				return res;
			}
			else if(ain||bin)
			{
				if(!ain) swap(a,b);
				double res=fabs(xmult(a,p1,c)/2);
				double ang=fabs(get_angle(p2,a,c));
				res+=pi*r*r*ang/(2*pi);
				return res;
			}
			else return 0;
		}
	}


	double get_cross_area(const polygen &poly)//圆与多边形的交（精度较低）
	{
		double res=0;
		for(int i=0;i<poly.sz;i++)
		{
			int j=(i+1)%poly.sz;
			int sig=1;
			if(zero(xmult(poly.p[i],poly.p[j],c))<=0) sig=1;
			else sig=-1;
			res+=sig*get_cross_area_triangle(poly.p[i],poly.p[j]);
			//print(sig*get_cross_area_triangle(poly.p[i],poly.p[j]));
		}
		return fabs(res);
	}
};
