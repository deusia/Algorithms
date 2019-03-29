#include<iostream>
#include<cstdio>
#define PI 3.14
using namespace std;
class Box
{
private:
	double length, width, high;
public:
	void cir_init(double a, double b, double c);
	void cir_print();
	double area_cal(double r);
};
void Box::cir_init(double a,double b,double c)
{
	length=a;
	width=b;
	high=c;
}
void Box::cir_print()
{
	cout << "lenth=" << length << endl;
	cout << "width=" << width << endl;
	cout << "high=" << high << endl;
}
double Box::area_cal(double r)
{
	return length * width*high;
}
int main(void)
{
	Box c1;
	double a, b, c;
	cout << "Enter the lenth:";
	cin >> a;
	cout << "Enter the width";
	cin >> b;
	cout << "Enter the high:";
	cin >> c;
	cout << endl;
	c1.cir_init(a,b,c);
	cout << "the volume is:" << c1.area_cal(c) << endl;
	cout << endl;
	c1.cir_print();
	system("pause");

}