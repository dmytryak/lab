#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
double x1,x2,delta,F;
unsigned int N,n;
unsigned int variant;
printf("Enter variant (1 or 2)\n");
    scanf("%d",&variant);
while(variant!= 1  &&  variant!= 2)
{
printf("Read the instruction carefully!\n");
    scanf("%d",&variant);
}
system("cls");
if(variant == 1)
    {
    printf("\tEnter x1: ");
        scanf("%lf",&x1);
    printf("\n\tEnter x2: ");
        scanf("%lf",&x2);
    printf("\n\tEnter N(N can take values >1): ");
        scanf("%d",&N);
    while(N<=2)
            {
            printf("Read the instruction carefully!\n");
                scanf("%d",&N);
            }
    printf("\t_________________________________________________\n");
    printf("\t|\tN\t|\tX\t|\tF(x)\t|\n");
    printf("\t_________________________________________________\n");
       delta=(x2-x1)/(N-1);
    for(n=1;n<=N;n++)
    {
        F=(-x1*x1*x1/25)+(10*x1*x1)-15000;
    printf("\n\t|\t%d\t|\t%.2f\t|\t%.2f|\n",n,x1,F);
    printf("\t_________________________________________________\n");
    x1=x1+delta;
    if(n%10==0)
    {
        printf("\nPress any key to continue...");
        getch();
    }

    }
    }
if (variant==2){
    printf("\tEnter x1: ");
        scanf("%lf",&x1);
    printf("\n\tEnter x2(): ");
        scanf("%lf",&x2);
    printf("\n\tEnter delta: ");
        scanf("%lf",&delta);
    int n=1;

    printf("\t_________________________________________________\n");
    printf("\t|\tN\t|\tX\t|\tF(x)\t|\n");
    printf("\t_________________________________________________\n");

    while(x1<=x2)

    {
     F=(-x1*x1*x1/25)+(10*x1*x1)-15000;
    printf("\n|%5.d|%18.f|%21.f|\n",n,x1,F);
    if(n%10==0)
    {


        printf("\nPress any key to continue...");
        getch();
    }


    x1=x1+delta;
    n++;
    }
  }
    return 0;
}
