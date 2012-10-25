point getBaryCenter(point a,point b,point c)
{
	segment u,v;
	point p;
	u.p1.x=(a.x+b.x)/2;
	u.p1.y=(a.y+b.y)/2;
	u.p2=c;
	v.p1.x=(a.x+c.x)/2;
	v.p1.y=(a.y+c.y)/2;
	v.p2=b;
	lineIntersect(makeLine(u),makeLine(v),p);
	return p;
}

void getBaryCenter(point &p)
{
	int sz=poly.size();
	point t;
	double t1=0,t2;
	p.x=p.y=0;
	for(int i=1;i<sz-1;i++)
	{
		t2=xmult(poly[0],poly[i],poly[i+1]);
		if(zero(t2)!=0)
		{
			t=getBaryCenter(poly[0],poly[i],poly[i+1]);
			p.x+=t.x*t2;
			p.y+=t.y*t2;
			t1+=t2;
		}
	}
	if(zero(t1)!=0)
	{
		p.x/=t1;
		p.y/=t1;
	}
}


//多边形是否稳定
bool stable(point a,point b,point bc)
{
	segment seg(a,b);
	line l=makeLine(a,b);
	line v=l.make_vertical(bc);
	point p;
	lineIntersect(l,v,p);
	if(onSegment(seg,p))
	{
		if(p==a || p==b) return false;
		else return true;
	}
	return false;
}
