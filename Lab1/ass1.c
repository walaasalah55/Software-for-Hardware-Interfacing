#include <stdio.h>
#include <stdlib.h>

/* (Final Velocity) Write a program than asks the user to enter the initial velocity and acceleration of an object, and the time that has elapsed, places them in the variables u, a, and t, and prints the final velocity, v, and distance traversed, s */


int main()
{
    int u;
    int a;
    int t;

    printf("Enter the initial velocity:\n");
    scanf("%d",&u);
    printf("Enter the acceleration:\n");
    scanf("%d",&a);
    printf("Enter the time:\n");
    scanf("%d",&t);
    int v=u+a*t;
    int s=u*t+(.5*a*t*t);
    printf("The final velocity is %d\n",v);
    printf("The distance is %d\n",s);
    return 0;
}


