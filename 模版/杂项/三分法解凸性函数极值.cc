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
