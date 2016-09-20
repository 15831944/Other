#include <conio.h>
#include <stdio.h>

double interp(double *parr[2])
{
	return parr[0][2];
}
void main()
{
	double a[2][12]={
						{1,2,3},
						{4,5,6}
					};
	printf ("%lf",interp(a[2]));
	getch();
}