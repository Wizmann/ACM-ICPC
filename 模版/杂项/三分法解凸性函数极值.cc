//此函数的导数不能有为零的部分，否则会WA到屎
while(fabs(r-l)>eps)
{
	lt=(l+r)/2;
	rt=(lt+r)/2;
	ltVal=tri(lt);//三分法求值函数
	rtVal=tri(rt);
	if(ltVal<=rtVal) r=rt;//求最小值
	//if(ltVal>=rtVal) r=rt;//求最大值
	else l=lt;
}



//对结果tri(l)有要求的题目，应该使用fabs(tri(r)-tri(l))>eps进行限制
double slove()
{
	double r=1000,l=0,lt,rt,ltVal,rtVal;
	while(fabs(tri(r)-tri(l))>eps)
	{
		double mid=(r-l)/3;
		lt=l+mid;
		rt=r-mid;
		ltVal=tri(lt);
		rtVal=tri(rt);
		if(ltVal<rtVal) r=rt;
		else l=lt;
	}
	return tri(l);
}
