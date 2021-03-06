// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"demotime.h"
Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes = minutes % 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::ReSet(int h, int m)
{
	hours = h;
	minutes = m;
}
Time Time::Sum(const Time & t)const
{
	Time sum;
	sum.minutes += minutes + t.minutes;
	sum.hours += hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator+(const Time & t)const
{
	Time sum;
	sum.minutes += minutes + t.minutes;
	sum.hours += hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
void Time::Show()const
{
	std::cout << "hours=" << hours << "  minutes=" << minutes << std::endl;
}
int main()
{
	using std::cout;
	using std::endl;
	Time planing;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	cout << "planing time:";
	planing.Show();
	cout << endl;

	cout << "coding time:";
	coding.Show();
	cout << endl;

	cout << "fixing time:";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) time:";
	total.Show();
	cout << endl;

	/*total = coding.operator[](fixing);
	cout << "coding.operator+(fixing) time:";
	total.Show();
	cout << endl;*/

	total = coding + fixing;
	cout << "coding+fixing time:";
	total.Show();
	cout << endl;

	//Time morefixing(4, 44);
	//cout << "morefixing time:";
	//morefixing.Show();
	//cout << endl;
	//total = coding + fixing + morefixing;
	//cout << "coding+fixing+morefixing time:";
	//total.Show();
	//cout << endl;
	getchar();
    return 0;
}

