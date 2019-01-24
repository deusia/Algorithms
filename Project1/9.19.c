#include<stdio.h>
#include<windows.h>
double power(double num, int index);
double outcome = 1.0;
int main(void)
{
	int index;
	double num;
	int n;

	printf("enter \"1\" to begin\n");
	while (scanf_s("%d", &n) == 1)
	{
		printf("enter a number:");
		scanf_s("%lf", &num);

		printf("enter a index:");
		scanf_s("%d", &index);

		printf("the outcome is %lf\n:",
			power(num,index));
		printf("enter\"1\"to contine(q to quit):");
	}
	printf("Done!!!\n");
	system("pause");
	return 0;
}
double power(double num, int index)
{
	if (index > 0)
	{
		int i;
		for (i = 0; i < index; i++)
			outcome *= num;
		return outcome;
	}
	else if (index < 0)
	{
		int k;
		for (k = 0; k < (-index); k++)
		outcome *= 1/num;
		return outcome;
	}
	else
		return 1;

}
