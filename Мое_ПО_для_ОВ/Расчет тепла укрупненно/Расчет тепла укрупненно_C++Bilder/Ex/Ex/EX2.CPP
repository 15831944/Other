#include <alloc.h>
#include <conio.h>
#include <stdio.h>

void interp(double *parr[2])
{
	printf ("\n%lf",parr[1][1]);

}
void main()
{
   /*	double b[2][12]={
						{1,2,3},
						{4,5,6}
					 };*/
	//declaration array
	double ** a=(double**)malloc(sizeof(double*)*12);
	for (int i=0;i<2;i++)
		a[i]=(double*)malloc(sizeof(double)*2);
	a[0][0]=1;
	a[0][1]=2;
	a[0][2]=3;
	a[1][0]=12;
	a[1][1]=13;
	a[1][2]=14;

 	interp(a);
	getch();


}