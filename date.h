#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
class CDate{
public:
	CDate(int dd,int mm=1,int yy=1999);
	CDate();
	CDate(const CDate &other); 
	~CDate();
	CDate addYear(int n);
	CDate addMonth(int n);
	CDate addDay(int n);
	string format(string df);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool isEquals(CDate date) const;
public:
	int *d, *m, *y;
	int maxDay[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	const string dfs = "ddd";
	const string dfl = "DDD";
};
