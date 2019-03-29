#include<iostream>
#include<cstdio>
#define PI 3.14
using namespace std;
class Circle
{
private:
	int x, y, r;
public:
	void cir_init(int a, int b, double c);
	void cir_print();
	double area_cal(double r);
};
void Circle::cir_init(int a,int b,double c)
{
	x=a;
	y=b;
	r=c;
}
void Circle::cir_print()
{
	printf("the coordinate is(%d,%d)\n", x, y);
	cout << "r=" << r<<endl;
}
double Circle::area_cal(double r)
{
	return PI * r*r;
}
int main(void)
{
	Circle c1;
	int a, b;
	double c;
	cout << "Enter the x:";
	cin >> a;
	cout << "Enter the y ";
	cin >> b;
	cout << "Enter the r:";
	cin >> c;
	cout << endl;
	c1.cir_init(a,b,c);
	cout << "the area is:" << c1.area_cal(c) << endl;
	cout << endl;
	c1.cir_print();
	system("pause");

}