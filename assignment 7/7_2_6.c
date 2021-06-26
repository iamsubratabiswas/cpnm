/*Write a program to solve the following differential equations by (i) Euler method, (ii) Runge-Kutta 
second order method. Compare your solutions. In each method estimate the truncation error and 
choose an appropriate step size.
𝑑𝑦
𝑑𝑥 = 2𝑥𝑦, 𝑦(0) = 0.5, solution for 1 ≥ 𝑥 ≥ 0
𝑑𝑦
𝑑𝑥 = 𝑥
2 + 𝑦
2
, 𝑦(0) = 1, 𝑠𝑜𝑙𝑢𝑡𝑖𝑜𝑛 𝑓𝑜𝑟 1 ≥ 𝑥 ≥ 0
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-5
double func1( double x,  double y)
{
	return 2*x*y;
}

 double func2( double x, double y)
{
	return x*x+y*y;
}

 double errcalc1( double x0, double y0, double h, double yh)
{
	 double x=x0,y=y0;
	 double n = 1/h;
	for(int i=0;i<n;i++)
	{
			 double dy1 = 2*x*y;
		 double dy2 = 2*x*dy1 + 2*y;
		 double dy3 = 4*dy1 + 2*x*dy2;
		y += dy1*h + 0.5*dy2*h*h + (1/6)*dy3*h*h*h;
		x+=h;	
	}
	return fabs((y-yh)/y)*100;

	
}

 double errcalc2( double x0, double y0, double h,  double yh)
{
 	double x=x0,y=y0,n=1/h;
	for(int i=0;i<n;i++)
	{
		 double dy1 = x*x + y*y;
		 double dy2 = 2*x + 2*y*dy1;
		 double dy3 = 2 + 2*dy1*dy1 + 2*y*dy2;
		y += dy1*h + 0.5*dy2*h*h + (1/6)*dy3*h*h*h;
		x+=h;
	}
	return fabs((y-yh)/y)*100;	
}


 double euler(double y0, double x0, double h, double (*func)( double, double))
{
	 double y = y0,x=x0;
	 double n = 1/h;
	for(int i=0;i<n;i++)
	{
		y = y + func(x,y)*h;
		x+=h;
	}

	return y;
}

 double rk2( double y0, double x0, double h, double (*func)(double, double))
{
	 double y=y0,x=x0;
	double n = 1/h;
	for(int i=0;i<n;i++)
	{
		y=y+(0.5*func(x,y)+0.5*func(x+h,y+func(x,y)*h))*h;
		x +=h;
	}
	return y;
}

int main(void)
{
	printf("1. The differential equation we solve is: dy/dx = 2xy\n");
	printf("We utilise a step size = 0.1\n");
	double eq1sol1 = euler(0.5,0,0.001,func1);
	double eq1err1 = errcalc1(0,0.5,0.001,eq1sol1);
	double eq1sol2 = rk2(0.5,0,0.001,func1);
	double eq1err2 = errcalc1(0,0.5,0.001,eq1sol2);
	printf("Solving by Euler's Method we get y(1) = %lf\n",eq1sol1);
	printf("The truncation erron on this is = %lf %%\n",eq1err1);
	printf("Solving by Runge-Kutta 2nd order method (Heun's method), we get y(1) = %lf\n",eq1sol2);
	printf("The truncation error on this is = %lf %%\n",eq1err2);
	printf("2. The differential equation we solve is: dy/dx = x^2 + y^2\n");
	printf("We utilise a step size = 0.1\n");
	double eq2sol1 = euler(1,0,0.5,func2);
	double eq2err1 = errcalc2(0,1,0.5,eq2sol1);
	double eq2sol2 = rk2(1,0,0.5,func2);
	double eq2err2 = errcalc2(0,1,0.5,eq2sol2);
	printf("Solving by Euler's Method we get y(1) = %lf\n",eq2sol1);
	printf("The truncation error on on this is = %lf %%\n",eq2err1);
	printf("Solving by Runge-Kutta 2nd order method (Heun's method), we get y(1) = %lf\n",eq2sol2);
	printf("The truncation error on this is = %lf %%\n",eq2err2);
}
