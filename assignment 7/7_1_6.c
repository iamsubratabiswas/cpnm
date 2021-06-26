/*
Write a menu-driven program for implementing Interpolation using Lagrange's formula, Newton’s 
forward difference formula, and Newton’s backward difference formula.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double ufindf(double u, int n)
{
	double res = u;
	for(int i=1;i<n;i++)
		res *= (u-i);

	return res;
}

double ufindb(double u, int n)
{
	double res = u;
	for(int i=1;i<n;i++)
		res *= (u+i);

	return res;
}

int fact(int n)
{
	int f=1;
	for(int i=2;i<=n;i++)
		f *= i;

	return f;

}

double newton_forward(double* x, double* y,int n, double xfind)
{
	double ytable[n][n];
	for(int i=0;i<n;i++)
		ytable[i][0]=y[i];

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
			ytable[j][i] = ytable[j+1][i-1] - ytable[j][i-1];

	}
	double yfind = ytable[0][0];
	double u = (xfind-x[0])/(x[1]-x[0]);
	for(int i=1;i<n;i++)
		yfind = yfind + (ufindf(u,i)*ytable[0][i])/fact(i);

	return yfind;

}

double newton_backward(double* x, double* y,int n, double xfind)
{
	double ytable[n][n];
	for(int i=0;i<n;i++)
		ytable[i][0]=y[i];

	for(int i=1;i<n;i++)
	{
		for(int j=n-1;j>=i;j--)
			ytable[j][i] = ytable[j][i-1] - ytable[j-1][i-1];

	}
	double yfind = ytable[n-1][0];
	double u = (xfind-x[n-1])/(x[1]-x[0]);
	for(int i=1;i<n;i++)
		yfind = yfind + (ufindb(u,i)*ytable[n-1][i])/fact(i);

	return yfind;

}

double lagrange(double* x, double* y, int n, double xfind)
{
	double yfind = 0;
	for(int i=0;i<n;i++)
	{
		double t = y[i];
		for(int j=0;j<n;j++)
		{
			if(j!=i)
			{
				t = t*(xfind-x[j])/(x[i]-x[j]);
			}
		}

		yfind += t;
	}

	return yfind;

}

int main(void)
{
	int n,ch;
	printf("ENTER NUMBER OF DATA POINTS: ");
	scanf("%d",&n);
	double x[n];
	double y[n];
	double xfind,yfind;
	for(int i=1;i<=n;i++)
	{
		printf("ENTER x%d: ",i);
		scanf("%lf",&x[i]);
		printf("ENTER y%d: ",i);
		scanf("%lf",&y[i]);
	}
	printf("ENTER x AT WHICH U WANT TO FIND VALUE: ");
	scanf("%lf",&xfind);
	printf("ENTER 1 TO USE NEWTON'S FORWARD DIFFERENCE FORMULA\n");
	printf("ENTER 2 TO USE NEWTON'S BACKWARD DIFFERENCE FORMULA\n");
	printf("ENTER 3 TO USE LAGRANGE'S FORMULA\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			yfind = newton_forward(x,y,n,xfind);
			break;
		case 2:
			yfind = newton_backward(x,y,n,xfind);
			break;
		case 3:
			yfind = lagrange(x,y,n,xfind);
			break;
		default:
			printf("INVALID CHOICE.\n");
	}
	if(ch>=1&&ch<=3)
		printf("VALUE OF y FOUND TO BE: %lf",yfind);

	return EXIT_SUCCESS;


}