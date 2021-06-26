/*An experiment gave the following table of values for the dependent variable y for a set of known 
values of x. Obtain an appropriate least squares fit for the data. 
x 1 2 3 4 5 6 7 8
9
y 5.5 7.0 9.6 11.5 12.6 14.4 17.6 19.5 20.5*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double* params(double* x, double* y, int n)
{
	double sx=0,sy=0,sxy=0,sx2=0;
	for(int i=0;i<n;i++)
	{
		sx += x[i];
		sx2 += x[i]*x[i];
		sxy += x[i]*y[i];
		sy += y[i];
	}
	double* parameters = (double*)malloc(2*sizeof(double));
	parameters[1] = (n*sxy - sx*sy)/(n*sx2-sx*sx);
	parameters[0] = (sy/n) - parameters[1]*(sx/n);
	return parameters;
}

int main(void)
{
	int n = 10;
	double x[10] = {1,2,3,4,5,6,7,8,9};
	double y[10] = {5.5,7.0,9.6,11.5,12.6,14.4,17.6,19.5,20.5};
	double* parameters = params(x,y,n);
	printf("LEAST SQUARES FIT: y = %lf + %lf * x\n",parameters[0],parameters[1]);
	return EXIT_SUCCESS;

}