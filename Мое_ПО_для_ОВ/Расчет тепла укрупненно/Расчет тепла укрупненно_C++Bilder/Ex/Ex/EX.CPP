#include <conio.h>
#include <stdio.h>

double interp(double (*parr)[5])
{
	return parr[0][2];
}
void main()
{
	double a[2][5]={
						{1,2,13},
						{4,5,6}
					};
	printf ("\n%lf",interp(a));
	getch();


}