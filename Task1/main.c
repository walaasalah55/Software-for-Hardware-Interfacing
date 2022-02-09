#include <stdio.h>
#include <stdlib.h>

/*Without using functions, you are required to write a code to calculate the exponential function using Taylor series. Your program is required to ask the use to enter the exponent and the number of iteration and then print the exponential result.*/ 

int main()
{
    int n,i;
    double x;
    double term=1.0;
    double result=1.0;

    printf("Enter the exponent:\n");
    scanf("%lf",&x);
    printf("Enter the number of iteration:\n");
    scanf("%d",&n);

    if (n==0)
    {
      result =1.0;
    }
    for (i=1; i<=n; i++)

    {term=(x/i)*(term);
     result += term;
    }

printf("The exponential result:%f\n",result);
}
