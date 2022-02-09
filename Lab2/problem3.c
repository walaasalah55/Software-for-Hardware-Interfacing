#include <stdio.h>
#include <stdlib.h>

/* The Fibonacci series 0, 1, 1, 2, 3, 5, 8, 13, 21, … begins with the terms 0 and 1 and has the property that each succeeding term is the sum of the two preceding terms. Write a code that print the number of series terms after reading it from a user input.*/

int main()
{
    int term1=0;
    int term2=1;
    int newterm;
    int i;
    int n;

    printf("Enter the number of terms:\n");
    scanf("%d",&n);
    printf("%d",term1);
    printf(", %d",term2);
    for (i=1; i<=n-2; i++)
    {
        newterm =term1+term2;
        term1=term2;
        term2=newterm;
        printf(", %d",newterm);
    }
    return 0 ;
}

