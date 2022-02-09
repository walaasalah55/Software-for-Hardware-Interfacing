#include <stdio.h>
#include <stdlib.h>

/* Write a program that inputs three different integers from the keyboard, then prints the sum, the average, the product, the smallest and the largest of these numbers */

int main()
{
    int a;
    int b;
    int c;

    printf("Enter the first integer:\n");
    scanf("%d",&a);
    printf("Enter the second integer:\n");
    scanf("%d",&b);
    printf("Enter the third integer:\n");
    scanf("%d",&c);

    int sum=a+b+c;
    int avg=sum/3;
    int product=a*b*c;
    int temp1=(a>b)?(a):(b);
    int largest=temp1>c? (temp1):(c);
    int temp2=(a<b)?(a):(b);
    int smallest=temp2<c? (temp2):(c);
    printf("The sum is %d\n",sum);
    printf("The avg is %d\n",avg);
    printf("The product is %d\n",product);
    printf("The largest is %d\n",largest);
    printf("The smallest is %d\n",smallest);
    return 0;
}

