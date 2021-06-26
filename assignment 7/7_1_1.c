/*Write a menu-driven program for finding roots of a nonlinear equation using Bisection, Regula 
Falsi and Newton-Raphson method.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 1e-5
#define MAX_ITER 2000

double func(double x)
{
	return x*x*x -3*x*x + 2*x + 1;
}

double diff(double x)
{
	return 3*x*x - 6*x + 2;
}

int newton_raphson()
{
	double x,prev_x;
	printf("ENTER INITIAL GUESS: ");
	scanf("%lf",&x);
	int i=0;
	while(i<MAX_ITER)
	{
		if(func(x)==0)
		{
			printf("ROOT FOUND AT: %lf\n",x);
			return 1;
		}
		x = x - func(x)/diff(x);
		if(i>0 && fabs((x-prev_x)/x)<EPS)
		{
			printf("ROOT FOUND AT: %lf\n",x);
			return 1;
		}
		i++;prev_x=x;
	}
	printf("UNFORTUNATELY ROOT COULD NOT BE FOUND WITHIN MAXIMUM NO. OF ITERATIONS.\n");
	return 0;
}

int regula_falsi()
{
	double a,b,c,prev_c;
	printf("ENTER UPPER BOUND: ");
	scanf("%lf", &b);
	printf("ENTER LOWER BOUND: ");
	scanf("%lf", &a);
	int i=0;
	if(func(a)*func(b)>0)
	{
		printf("INVALID BOUNDS\n");
		return 0;
	}
	while(i<MAX_ITER)
	{
		
		c = (b*func(a)-a*func(b))/(func(a)-func(b));        
	//	printf("%lf\n",c);
		if(func(c)==0)
		{
			printf("ROOT FOUND AT: %lf",c);
			return 1;
		}
		if(func(c)*func(b)<0)
		{
			a=c;
		}
		else
			b=c;
		
		if(i>0 && fabs((c-prev_c)/c)<EPS)
		{
			printf("ROOT FOUND AT: %lf\n",c);
			return 1;
		}
		prev_c=c;i++;

	}
	printf("UNFORTUNATELY ROOT COULD NOT BE FOUND WITHIN MAXIMUM NO. OF ITERATIONS. %lf %lf\n",a,b);
	return 0;
}

int bisection()
{
	double a,b,c,prev_c;
	printf("ENTER UPPER BOUND: ");
	scanf("%lf", &b);
	printf("ENTER LOWER BOUND: ");
	scanf("%lf", &a);
	int i=0;
	if(func(a)*func(b)>0)
	{
		printf("INVALID BOUNDS\n");
		return 0;
	}
	while(i<MAX_ITER)
	{
		c = (b+a)/2;
		if(func(c)==0)
		{
			printf("ROOT FOUND AT: %lf",c);
			return 1;
		}
		if(func(c)*func(b)<0)
		{
			a=c;
		}
		else
			b=c;
		
		if(fabs((c-prev_c)/c)<EPS)
		{
			printf("ROOT FOUND AT: %lf\n",c);
			return 1;
		}
		prev_c=c; i++;

	}
	printf("UNFORTUNATELY ROOT COULD NOT BE FOUND WITHIN MAXIMUM NO. OF ITERATIONS.\n");
	return 0;
}

int main(void)
{
	int c,res;
	printf("CHOOSE YOUR METHOD TO FIND ROOTS OF THE EQUATION x^3 - 3x^2 + 2x + 1 = 0\n");
	printf("ENTER 1 TO USE BISECTION METHOD.\n");
	printf("ENTER 2 TO USE REGULA FALSI.\n");
	printf("ENTER 3 TO USE NEWTON-RAPHSON METHOD.\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d",&c);

	switch(c)
	{
		case 1:
			res = bisection();break;
		case 2:
			 res = regula_falsi();break;
		case 3:
			 res = newton_raphson();break;
		default:
			printf("YOUR CHOICE IS INVALID.\n");
	}
	return EXIT_SUCCESS;
}