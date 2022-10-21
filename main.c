#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    double x,y;
    printf("Enter x value:\n");
    scanf("%lf", &x);
    if (x>=-10 && x<-5){
        system("cls");
        printf("You chose equation y=pow(3,fabs(x-1))-fabs(x+1)/pow(exp(1),2) at x=%.2lf\n",x);
        y=pow(3,fabs(x-1))-fabs(x+1)/pow(exp(1),2);
        printf("Answer:y=%lf\n",y);
    }
    else if(x>=-1 && x<1){
        system("cls");
        printf("You chose equation  y=(2*fabs(sin(x/2)))/(cos(x-1)+5) at x=%.2lf\n",x);
        y=(2*fabs(sin(x/2)))/(cos(x-1)+5);
        printf("Answer:y=%lf\n",y);
    }
    else if(x>=5 && x<10){
        system("cls");
        printf("You chose equation y=0.5 at x=%.2lf\n",x);
        printf("Answer:y=0.5",y);
    }
    else{
        system("cls");
        printf("You chose equation y=x/100 at x=%.2lf\n",x);
        y=x/100;
        printf("Answer:y=%lf\n",y);
    }
    return 0;
}
