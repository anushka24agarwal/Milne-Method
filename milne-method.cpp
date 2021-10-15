#include<stdio.h>
#include<math.h>

typedef struct values
{
  float x,y,sum;
}val;

float polyx(float a[], int degx, float x)
{
    float p;
    int i;

    p = a[degx];

    for (i = degx; i >= 1; i--) {
        p = (a[i - 1] + x * p);
    }

    return p;
}

float polyy(float b[], int degy, float y)
{
    float p;
    int i;

    p = b[degy];

    for (i = degy; i >= 1; i--) {
        p = (b[i - 1] + y * p);
    }

    return p;
}

int main()
{ 
int order_x,i,order_y,j;
float x,y,sum=0.0,h;
float yp4,yc4;
val s[5];

printf("\nEnter order of polynomial x : ");
scanf("%d",&order_x); 
float coefficient_x[order_x];


for(i=0;i<=order_x;i++)
{
  printf("\nEnter coefficients of polynomial at x^%d : ",i);
  scanf("%f",&coefficient_x[i]); 
}


printf("\nEnter order of polynomial y : ");
scanf("%d",&order_y);
float coefficient_y[order_y];


for(i=0;i<=order_y;i++)
{
  printf("\nEnter coefficients of polynomial at y^%d : ",i);
  scanf("%f",&coefficient_y[i]); 
}

// printing equation f(x,y)
      printf("\n f(x,y) = ");
      for(i=order_x;  i>=0; i--)
      {
        printf("%fx^%d + ",coefficient_x[i],i);
      }

      for(j=order_y;  j>=0; j--)
      {
        if(j!=0)
        printf("%fy^%d + ",coefficient_y[j],j);
        else
        printf("%fy^%d ",coefficient_y[j],j);
      }
      printf("\n");

// taking input of x and y values
for(int k=0; k<4; k++)
{
  printf("\nEnter values of x%d and y%d ", k,k);
  scanf("%f %f", &s[k].x, &s[k].y);
}

h=s[1].x-s[0].x;

for(int k=0; k<4; k++)
{
  s[k].sum=polyx(coefficient_x, order_x, s[k].x) + polyy(coefficient_y, order_y, s[k].y);
}

for(int t=0; t<4; t++)
{
  printf("\n Value of f%d is: ", t);
  printf("%f", s[t].sum);
}

printf("\n\n Step size h = %f \n",h);

s[4].x=s[3].x+h;

yp4=s[0].y + (4*h/3)*(2*s[1].sum - s[2].sum + 2*s[3].sum);
s[4].y=yp4;

s[4].sum=polyx(coefficient_x, order_x, s[4].x) + polyy(coefficient_y, order_y, s[4].y);

yc4=s[2].y + (h/3.0)*(s[2].sum + 4*s[3].sum + s[4].sum);

printf("\nValue using predictor formula is = %f", yp4);
printf("\nValue using corrector formula is = %f", yc4);
printf("\nValue of f4 = %f \n", s[4].sum);
printf("\n \n");
   return 0;
}

