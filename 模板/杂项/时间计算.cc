namespace DATE
{
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	struct date
	{
		int year,month,day,hour;
		date(){}
		date(int iyear,int imonth,int iday,int ihour)
		{
			year=iyear;month=imonth,day=iday;hour=ihour;
		}
	};
	
	const date START_TIME=date(2000,1,1,0);
	
	inline bool leap(int year)
	{
		return (year%4==0 && year%100!=0) || year%400==0;
	}


	int date2int(const date &a)
	{
		int ret=a.year*365+(a.year-1)/4-(a.year-1)/100+(a.year-1)/400;
		days[1]+=leap(a.year);
		for(int i=0;i<a.month-1;i++) ret+=days[i];
		days[1]=28;
		return ret+a.day;
	}

	int date2hour(const date& a)
	{
		int days=date2int(a)-date2int(START_TIME);
		return days*24+a.hour;
	}
}
