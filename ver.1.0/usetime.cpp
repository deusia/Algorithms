#include<iostream>
#include"mytime.h"
using namespace std;
int main(void)
{
  Time t1(3,15);
  Time t2(5,13);
  Time total=t1+t2;
  Time difference=t1-t2;

  t1.Show();
  t2.Show();
  total.Show();
  difference.Show();
}