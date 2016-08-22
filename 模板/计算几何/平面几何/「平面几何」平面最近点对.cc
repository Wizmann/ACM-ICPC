//平面最近点对
//调用minDisPointPair之前 **勿必将array内的点排序**!!!
//**sort(array,array+n,cmpX);**!!!!
bool cmpX(const point &a,const point &b)
{
	return a.x>b.x;
}
bool cmpY(const point &a,const point &b)
{
	return a.y<b.y;
}

point array[SIZE],ym[SIZE];

double minDisPointPair(int st,int end,point *ip)
{
	double res=inf;
	if(end-st<19)
	{
		for(int i=st;i<=end;i++)
		{
			for(int j=i+1;j<=end;j++)
			{
				res=min(res,pntDis(ip[i],ip[j]));
			}
		}
		return res;
	}
	else
	{
		int mid=(st+end)>>1;
		res=min(minDisPointPair(st,mid,ip),minDisPointPair(mid+1,end,ip));
		int yn=0;
		
		for(int i=st;i<=end;i++)
		{
			if(ip[i].x>=ip[mid].x-res && ip[i].x<=ip[mid].x+res) ym[yn++]=ip[i];
		}
		sort(ym,ym+yn,cmpY);
		for(int i=0;i<yn;i++)
		{
			for(int j=i+1;j<yn;j++)
			{
				if(ym[j].y-ym[i].y>=res) break;
				res=min(res,pntDis(ym[i],ym[j]));
			}
		}
		return res;
	}
}




//小内存版，速度略慢，已废弃
//最近点对，分治法，1e5个点大概需要1s左右

//排序函数，读入点集后应该先排序
//e.g.sort(array,array+n,cmp);
bool cmp(const point& a,const point& b)
{
    return a.x<b.x;
}
double minDisPointPair(int st,int end)
{
    double res=inf;
    if(end-st<=12)
    {
        for(int i=st;i<=end;i++)
        {
            for(int j=i+1;j<=end;j++)
            {
                res=min(res,pointDis(array[i],array[j]));
            }
        }
        return res;
    }
    else
    {
        int mid=(st+end)>>1;
        res=min(res,minDisPointPair(st,mid));
        res=min(res,minDisPointPair(mid+1,end));
        double left=array[mid].x-res;
        double right=array[mid].x+res;
        
        int a=lower_bound(array+st,array+end+1,point(left,-1),cmp)-array;
        int b=lower_bound(array+st,array+end+1,point(right,-1),cmp)-array;
        b=min(end,b);
        for(int i=a;i<=b;i++)
        {
            for(int j=i+1;j<=b;j++)
            {
                res=min(res,pointDis(array[i],array[j]));
            }
        }
        return res;
    }
}
