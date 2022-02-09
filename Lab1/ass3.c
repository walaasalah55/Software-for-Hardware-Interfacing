#include <stdio.h>
#include <stdlib.h>

/* Write a program that asks the user to enter the total time elapsed, in seconds, since an event and converts the time to hours, minutes and seconds. The time should be displayed as hours:minutes:seconds. */

int main()
{
int t;
printf("Enter the time in secs:\n");
scanf("%d",&t);
int h=t/3600;
printf("%d",h);
int temp=t%3600;
int m=temp/60;
printf(":%d",m);
int s=temp%60;
printf(":%d",s);
return 0;
}

