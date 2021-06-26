/*
CODE NEEDS REVIEW
For the following table of values:
x 1 2 3
4
f(x) 1 8 27 64
Find 𝑓(2.5) using all three methods and comment on your answer
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
	double x[4] = {1,2,3,4};
	double y[4] = {1,8,27,64};

	printf(" RESULT FROM NEWTON'S FORWARD DIFFERENCE METHOD: %lf\n",newton_forward(x,y,4,2.5));
	printf(" RESULT FROM NEWTON'S BACKWARD DIFFERENCE METHOD: %lf\n",newton_backward(x,y,4,2.5));
	printf("RESULT FROM LAGRANGE'S METHOD: %lf\n",lagrange(x,y,4,2.5));

	return EXIT_SUCCESS;
}