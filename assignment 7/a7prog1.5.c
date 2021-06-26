/*Using the above program solve the following system of equations :
i. 𝑥 + 𝑦 + 𝑧 = 6 ii. 𝑥1 + 𝑥2 + 𝑥3 = 3 iii. 2𝑥1 + 4𝑥2 + 2𝑥3 = 15
 𝑥 + 𝑦 − 𝑧 = 0 2𝑥1 + 3𝑥2 + 𝑥3 = 6 2𝑥1 + 𝑥2 + 2𝑥3 = −5
 𝑥 − 𝑦 + 𝑧 = 2 𝑥1 − 𝑥2 − 𝑥3 = −3 4𝑥1 + 𝑥2 − 2𝑥3 = 0*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 1e-5

double* gauss(double** arr, double* res,int n)
{
	//Forward elimination:
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			//Finding coefficient:
			double c = arr[j][i]/arr[i][i];
			for(int k=0;k<n;k++)
			{
				arr[j][k] -= arr[i][k]*c;

			}
			//Applying identical operation to result vector
			for(int l=i+1;l<n;l++)
				res[l] -= res[i]*c;
		}
	}

	//To store our answers
	double* ans = (double*)calloc(n*sizeof(double),0);
	//Back substitution
	for(int i=n-1;i>=0;i--)
	{
		double off=0;
		for(int j=i+1;j<n;j++)
		{
			off += ans[j]*arr[i][j];
		}
		ans[i] = (res[i]-off)/arr[i][i];
	} 
	return ans;
}

double* gauss_pivot(double** arr, double* res,int n)
{
	//Forward elimination:
	for(int i=0;i<n;i++)
	{
		//Pivoting:
		int idx=i,val=fabs(arr[i][i]);
		for(int m=i+1;m<n;m++)
		{
			if(fabs(arr[m][i])>val)
			{
				val=fabs(arr[m][i]);
				idx=m;
			}
		}
		double temp;
		//Pivoting result vector
		temp=res[i];
		res[i]=res[idx];
		res[idx]=temp;
		//Pivoting coefficient matrix
		for(int itr=0;itr<n;itr++)
		{
			temp=arr[i][itr];
			arr[i][itr]=arr[idx][itr];
			arr[idx][itr]=temp;
		}

		for(int j=i+1;j<n;j++)
		{
			double c = arr[j][i]/arr[i][i];
			for(int k=0;k<n;k++)
			{
				arr[j][k] -= arr[i][k]*c;

			}
			for(int l=i+1;l<n;l++)
				res[l] -= res[i]*c;
		}
	}

	//Stores our answer
	double* ans = (double*)calloc(n*sizeof(double),0.0);
	//Back substitution:
	for(int i=n-1;i>=0;i--)
	{
		double off=0;
		for(int j=i+1;j<n;j++)
		{
			off += ans[j]*arr[i][j];
		}
		ans[i] = (res[i]-off)/arr[i][i];
	} 
	return ans;
}

double* jacobi(double** arr, double* res,int n, int num_iter)
{
	double* ans = (double*)calloc(n*sizeof(double),0.0);
	double* prev = (double*)calloc(n*sizeof(double),0.0);
	int i=0;

	while(i<num_iter)
	{
		for(int it=0;it<n;it++)
		{
			double off=0;
			for(int j=it+1;j<n;j++)
			{
				off += arr[it][j]*prev[j];
			}
			ans[it] = (res[it]-off)/(arr[it][it]+EPS);
		}

		
		int flag=1;
		for(int it=0;it<n;it++)
		{
			if(fabs((ans[i]-prev[i])/ans[i])>EPS)
			{
				flag=0;
				break;

			}

		}

		if(flag==1)
			break;
		else
		{
			for(int it=0;it<n;it++)
				prev[i]=ans[i];
		}
		i++;
	}
	return ans;

}

int main(void)
{
	int n=3,ch,f,num_iter,arr[3][3],res[3];
	printf("ENTER 1 TO SOLVE SYSTEM OF EQUATIONS 1\n");
	printf("ENTER 2 TO SOLVE SYSTEM OF EQUATIONS 2\n");
	printf("ENTER 3 TO SOLVE SYSTEM OF EQUATIONS 3\n");
	printf("ENTER CHOICE: ");
	scanf("%d",&f);
	
	 switch(f)
    {
        case 1:
        {
            float arr[3][3]={{1,1,1},{1,1,-1},{1,-1,1}};
            float res[3]={6,0,2};
            break;
        }
        case 2:
        {
            float arr[3][3]={{1,1,1},{2,3,1},{1.-1,-1}};
            float res[3]={3,6,-3};
            break;
        }
        case 3:
        {
            float arr[3][3]={{2,4,2},{2,1,2},{4,1.-2}};
            float res[3]={15,-5,0};
            break;
        }
        default:
        {
            printf("wrong choice\n");
            break;
        }
    }
	
	printf("ENTER 1 TO SOLVE BY GAUSS ELIMINATION\n");
	printf("ENTER 2 TO SOLVE BY GAUSS ELIMINATION WITH PIVOTING\n");
	printf("ENTER 3 TO SOLVE BY JACOBI'S METHOD\n");
	printf("ENTER CHOICE: ");
	scanf("%d",&ch);
	double* ans = NULL;
	switch(ch)
	{
		case 1:
				ans = gauss(arr,res,n);
				break;
		case 2:
				ans = gauss_pivot(arr,res,n);
				break;
		case 3:
				printf("ENTER MAXIMUM NUMBER OF ITERATIONS: ");
				scanf("%d",&num_iter);
				ans = jacobi(arr,res,n,num_iter);
				break;
		default:
				printf("INVALID CHOICE\n");

	}
	if(ch>=1&&ch<=3)
	{
		printf("SOLUTIONS: \n");
		for(int i=0;i<n;i++)
		{
			printf("x%d = %lf\n",(i+1),ans[i]);
		}
	}

	return EXIT_SUCCESS; 
}

 