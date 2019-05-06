#include<iostream>
using namespace std;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y,int m,int d)
	{
		year=y;
		month=m;
		day=d;
	}
	Date AddDays(int);
	void show();
	void AddOneDay();
	int CalDays();
	int IsLeapYear(int);
	int IsEndOfMonth();
	friend int Days0fTwoDate(Date,Date);
};
void Date::show()
{
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}
int Date::IsLeapYear(int y)
{
	//闰年为能被400整除或者能被4和100同时整除的年份
	if(year%400==0||(year%4==0&&year%100==0))
		return 1;
	else
		return 0;
}
int Date::IsEndOfMonth()
{
	switch(month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		return (day==31);
	case 2:
		if(IsLeapYear(year))
			return (day==29);
		else
			return (day==28);
	default:
		return (day==30);
	}
}
int Date::CalDays()
{
	int days;
	//1900为处理年，计算当前年至处理年的天数
	int years=year-1900;
	days=years*365;

	int start;
	//处理当前年之前的闰年情况
	for(start=1900;start<year;start++)
		if(IsLeapYear(start))
			days++;
	//处理当前年中的当月之前天数
	switch(month)
	{
	case 12: days+=30;
	case 11: days+=31;
	case 10: days+=30;
	case 9:  days+=31;
	case 8:  days+=31;
	case 7:  days+=30;
	case 6:  days+=31;
	case 5:  days+=30;
	case 4:  days+=31;
	case 3:
		{
			if(IsLeapYear(year))
				days+=29;
			else
				days+=28;
		}
	case 2:  days+=31;
	}

	//处理当月的天数
	days+=day-1;

	return days;
}
void Date::AddOneDay()
{
	if(IsEndOfMonth())
	{
		//越年情况
		if(month==12)
		{
			year++;
			month=1;
			day=1;
		}
		////年内情况
		else
		{
			month++;
			day=1;
		}
	}
	////月内情况
	else
		day+=1;
}
int Days0fTwoDate(Date d1,Date d2)
{
	int day1=d1.CalDays();
	int day2=d2.CalDays();
	return day2-day1;
	
}
Date Date::AddDays(int days)
{
	//在本对象基础上增加天数
	Date d=*this;

	int start;
	for(start=0;start<days;start++)
		d.AddOneDay();
	return d;
}

int main(void)
{
	Date d1(2019,4,3);
	Date d2(2019,5,6);
	cout<<Days0fTwoDate(d1,d2);
	Date d3=d1.AddDays(6);
	d3.show();
}