/*Use the above program to find 3 roots of the equation xtan(x)=c where c is a user-input constant. 
Use both bisection method and Newton-Raphson method.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPS 1e-5
#define MAX_ITER 2000
double c=0;
double func(double x)
{
	return x*tan(x)-c;
}

double diff(double x)
{
	return tan(x) + x/(cos(x)*cos(x));
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

void rootfinder(int (*func)())
{
	int i=0;
	while(i<3)
	{
		printf("FOR ROOT NO. %d:\n",(i+1));
		int res = func();
		if(res)
			i++;
	}
}

int main(void)
{

	printf("ENTER VALUE OF c: ");
	scanf("%lf",&c);
	printf("USING BISECTION METHOD:\n");
	rootfinder(bisection);
	printf("USING NEWTON-RAPHSON METHOD:\n");
	rootfinder(newton_raphson);


	return EXIT_SUCCESS;
}