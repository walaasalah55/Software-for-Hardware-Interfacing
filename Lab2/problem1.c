#include <stdio.h>
#include <stdlib.h>

/*Write a program to perform a generic rotate right and rotate left expression using bit masking. The code shall ask the user to enter an 8 bit number x, number of rotate cycles n and rotate option o. The software shall print the rotate value of x, n times based on the value of o */


int main()
{

    int x,n,o;
    unsigned char y;


    printf("Enter the number:\n");
    scanf("%d",&x);
    printf("Enter the num of rotate cycles:\n");
    scanf("%d",&n);
    printf("Enter the rotate option:\n");
    scanf("%d",&o);
//shift right
    if (o==1)
    {y=(x>>n)|(x<<(8-n));}
//shift left
    else if (o==0)
    {y=(x<<n)|(x>>(8-n));}

printf("The rotated value:%i\n",y);

return(0);
}


