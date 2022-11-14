#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned int method_select(void);
double F(double x);
void print_result(double a, double b, unsigned int n, double I);
double left_rectangle(double a, double b, unsigned int n);
double right_rectangle(double a, double b, unsigned int n);
double trapezoid(double a, double b, unsigned int n);
double Simpson(double a, double b, unsigned int n);

int main()
{
system("cls");
unsigned int num_of_method;
double a;
double b;
double I1,I2,eps;
unsigned int n,N;
printf("\n\tEnter lower bound(a):");
    scanf("%lf",&a);
printf("\tEnter higher bound(b):");
    scanf("%lf",&b);
printf("\tEnter the number of segments:");
    scanf("%u",&n);
printf("\tEnter eps:");
    scanf("%lf",&eps);
double I;

num_of_method = method_select();
if (num_of_method == 1)
    {
    I=left_rectangle(a,b,n);
    print_result(a,b,n,I);
    N=0;
    do{
        N=N+2;
        I1=left_rectangle(a,b,N);
        I2=left_rectangle(a,b,N+2);
    }while(fabs(I2-I1)>eps);
    printf("\t|N=%u |eps=%lf|I1=%.2lf |I2=%.2lf|\n\t*******************************************",N,eps,I1,I2);
    }
else if (num_of_method==2){
    I=right_rectangle(a,b,n);
    print_result(a,b,n,I);
    N=0;
    do{
        N=N+2;
        I1=left_rectangle(a,b,N);
        I2=left_rectangle(a,b,N+2);
    }while(fabs(I2-I1)>eps);
    printf("\t|N=%u |eps=%lf|I1=%.2lf |I2=%.2lf|\n\t*******************************************",N,eps,I1,I2);
    }
else if (num_of_method==3){
    I=trapezoid(a,b,n);
    print_result(a,b,n,I);
    N=0;
    do{
        N=N+2;
        I1=trapezoid(a,b,N);
        I2=trapezoid(a,b,N+2);
    }while(fabs(I2-I1)>eps);
    printf("\t|N=%u |eps=%lf|I1=%.2lf |I2=%.2lf|\n\t*******************************************",N,eps,I1,I2);
}
else if (num_of_method==4){
    I=Simpson(a,b,n);
    print_result(a,b,n,I);
    N=0;
    do{
        N=N+2;
        I1=Simpson(a,b,N);
        I2=Simpson(a,b,N+2);
    }while(fabs(I2-I1)>eps);
    printf("\t|N=%u |eps=%lf|I1=%.2lf |I2=%.2lf|\n\t*******************************************",N,eps,I1,I2);
}
return 0;
}

unsigned int method_select(void)
{
    unsigned int temp;
    printf("Choose your method:\n1left_rectangle\n2right_rectangle\n3trapezoid\n4Simpson\n");
    scanf("%u", &temp);
    while(temp<1 || temp>4){
        printf("\nPomilochka(((\n");
        scanf("%u", &temp);
    }
    return temp;
}

double F(double x)
{
    double y;
    return y=pow(x,3)/(pow(x,8)+1);
}
double left_rectangle(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h=(b-a)/n;
    x=a;
    for(k=0; k<=n-1;k++){
        sum=sum+F(x);
        x=x+h;
    }
    return sum*h;
}
double right_rectangle(double a, double b, unsigned int n)
{
double h;
    unsigned int k;
    double x;
    double sum = 0;
    h=(b-a)/n;
    x=a;
    for(k=1; k<=n;k++){
        sum=sum+F(x);
        x=x+h;
    }
    return sum*h;
}
double trapezoid(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h=(b-a)/n;
    x=a;
    for(k=1; k<=n;k++){
        sum=sum+F(x);
        x=x+h;
    }
    return (sum+F(x)/2)*h;

}
double Simpson(double a, double b, unsigned int n)
{
    double h;
    unsigned int k;
    double x;
    double sum = 0;
    h = ( b - a ) / n;
    x = a;
    for (k = 0; k <= n; k++ ) {
    if(k%2==0&&k<= (n-2))
        {
            sum = sum + 4*F(x);
        }
        else if(k%2==1&&k<=n-1)
        {
            sum = sum  + 2*F(x);
        }
        x = x + h;
    }
    return(h/3*sum);

    }

void print_result(double a, double b, unsigned int n, double I)
{
    system("cls");
    printf("\n\t______________________________________\n");
    printf("\t|a=%.2lf |b=%.2lf |n=%u |I=%.2lf |\n\t*******************************************\n",a,b,n,I);
}
