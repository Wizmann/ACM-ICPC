while(fabs(r-l)>eps)
{
	lt=(l+r)/2;
	rt=(lt+r)/2;
	ltVal=tri(lt);//三分法求值函数
	rtVal=tri(rt);
	if(ltVal<=rtVal) r=rt;
	else l=lt;
}
