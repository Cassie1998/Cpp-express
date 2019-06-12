#include"date.h"
CDate::CDate(int dd, int mm, int yy):dfs("ddd"),dfl("DDD")    //初始化
{
	if((yy >= 1000 && yy <= 9999)&&(mm >= 1 && mm <= 12)&&(dd >= 1 && dd <= maxDay[(yy/4==0&&yy/100!=0)||(yy/400==0)][mm]))
	{
		y = new int(yy);
		m = new int(mm);
		d = new int(dd);
	}else throw "create CDate object error";
}
CDate::CDate():dfs("ddd"),dfl("DDD")    //初始化
{
	time_t now;
	time(&now);
	struct tm *t_now;
	t_now = localtime(&now);
	y = new int(t_now -> tm_year + 1900);
	m = new int(t_now -> tm_mon + 1);
	d = new int(t_now -> tm_mday);
}
CDate::CDate(const CDate &other)
{
	//cout << "CDate::CDate(const CDate &other)" << endl;
	y = new int(*other.y);
	m = new int(*other.m);
	d = new int(*other.d);
}
CDate::~CDate()
{
	//cout << "CDate::~CDate()" << endl;
	delete y;
	delete m;
	delete d;
}
CDate CDate::addYear(int n)               //加n年
{
		*y += n;
		return *this;
}
CDate CDate::addMonth(int n)              //加n月
{
		*m += n;
		if(*m > 12){
			*m = *m % 12;
			(*y) ++;
		}
		return *this;
}
CDate CDate::addDay(int n)                //加n天
{
		*d += n;
		int dd = maxDay[(*y/4==0&&*y/100!=0)||(*y/400==0)][*m];
		if(*d > dd)
		{
			*d = *d % dd;
			(*m) ++;
		}
		return *this;
}
string CDate::format(string df)
{
		char c_df[20];
		if(df == dfs)
		{
			sprintf(c_df, "%d-%d-%d", *y, *m, *d);
			return string(c_df);
		}
		if(df == dfl)
		{
			sprintf(c_df, "%d年%d月%d日", *y, *m, *d);
			return string(c_df);
		}
		return string("");
}
int CDate::getDay() const
{
	return *d;
}
int CDate::getMonth() const
{
	return *m;
}
int CDate::getYear() const
{
	return *y;
}
bool CDate::isEquals(CDate date) const
{
	if((*y == *date.y) && (*m == *date.m) && (*d == *date.d))
		return true;
	else return false;
}
