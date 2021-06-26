/*
Write a function integrate to find the integration of a function f within the limits a and b by 
Trapezoidal and Simpson's 1/3rd integration method. f, a and b should be provided as arguments of 
the function integrate. Write the main function to take the name of the integrand function and the 
limits of integration as command line arguments

PROGRAM TO INTEGRATE HARD CODED ALGEBRAIC FUNCTION WITHIN BOUNDS a AND b. THE BOUNDS AND METHOD OF INTEGRATION
ARE ENTERED BY USER AS COMMAND LINE ARGUMENTS. PLEASE ENTER:
simpsons IF U WANT TO INTEGRATE BY SIMPSON'S 1/3RD METHOD
trapezoidal IF U WANT TO INTEGRATE BY TRAPEZOIDAL METHOD
STEP SIZE ALSO USER INPUT AS OF NOW. TO BE CLARIFIED.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double f(double x)
{
	return 3*x*x + 4*x + 1;
}



double trapezoidal(double a, double b, double h)
{
	double integ=f(a)+f(b);
	double n = (b-a)/h;
	for(int i=1;i<n;i++)
	{
		integ += 2*f(a+i*h);
	}
	integ *= (b-a)/(2*n);

	return integ;
}

double simpsons(double a, double b, double h)
{
	double integ = f(a)+f(b);
	double n = (b-a)/h;
	for(int i=1;i<n;i++)
	{
		if(i%2!=0)
			integ += 4*f(a+i*h);
		else
			integ += 2*f(a+i*h);
	}
	integ *= (b-a)/(3*n);

	return integ;
}

double integrate(double(*func)(double x, double y, double z),double a, double b, double h)
{
	
	return func(a,b,h);
}

int main(int argc, char* argv[argc+1])
{
	char *s; 
	s = argv[1];
	double a = strtod(argv[2],0);
	double b = strtod(argv[3],0);
	double h = strtod(argv[4],0);
	double res = 0;
	if(strcmp(s,"simpsons")==0)
		res = integrate(simpsons,a,b,h);
	else if(strcmp(s,"trapezoidal")==0)
		res = integrate(trapezoidal,a,b,h);
	else
		printf("YOU ENTERED ERRONEOUS NAME OF METHOD. EXITING PROGRAM.\n");
	
	printf("RESULT OF INTEGRATING  3x^2 + 4x + 1 from %lf to %lf = %lf\n",a,b,res);
	
	return EXIT_SUCCESS;
}
