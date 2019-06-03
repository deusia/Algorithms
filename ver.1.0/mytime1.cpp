#include<iostream>
#include "mytime.h"
Time::Time()
{
	hours=minutes=0;
}

Time::Time(int h,int m)
{
	hours=h;
	minutes=m;
}

void Time::addMin(int m)
{
	minutes+=m;
	hours+=minutes/60;
	minutes%=60;
}

void Time::addHr(int h)
{
	hours+=h;
}

void Time::Reset(int h,int m)
{
	hours=h;
	minutes=m;
}

Time Time::sum(const Time & t)const
{
	Time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours+sum.minutes/60;
	sum.minutes%=60;

	return sum;
}

Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours+sum.minutes/60;
	sum.minutes%=60;

	return sum;
}

Time Time::operator-(const Time & t) const
{
	Time sum;
	int temp1;
	int temp2;
	
	temp1=minutes+60*hours;
	temp2=t.minutes+60*t.hours;
	if(temp1>temp2)
	{
		sum.hours=(temp1-temp2)/60;
		sum.minutes=(temp1-temp2)%60;
	}
	else
	{
		sum.hours=(temp2-temp1)/60;
		sum.minutes=(temp2-temp1)%60;
	}

	return sum;
}

void Time::Show() const
{
	std::cout<<hours<<" hours,"<<minutes<<" minutes."<<std::endl;
}
