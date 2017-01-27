void kmp_get_next()
{
	next[0]=-1;
	for(int i=0,j=-1;i<len;i++,j++,next[i]=j)
	{
		while(j>=0 and str[i]!=str[j]) j=next[j];
	}
}

void kmp_do()
{
	int i=0,j=0;
	while(i<len and j<len)
	{
		if(j==-1 or mia[i]==str[j])
		{
			i++;j++;
		}
		else
		{
			j=next[j];
		}
	}
}
