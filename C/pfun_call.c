#include <stdio.h>
#include <math.h>

float caculate(float a, float b, float (*fun)(float, float));
float f1(float a, float b);
float f2(float a, float b);

float f1(float a, float b)
{
    return (b + 0.5 * pow(b, 2)) - (a + 0.5 * pow(a, 2));
}

float f2(float a, float b)
{
    return (pow(b, 2) + 3 * b) - (pow(a, 2) + 3 * a);
}

float caculate(float a, float b, float (*fun)(float,float))
{
    return (*fun)(a,b);
}

    int main(void)
{
    float x = 2, y = 4;
    float z;

    z = caculate(x,y,f1);
    printf("%f\n", z);

    z = caculate(x,y,f2);
    printf("%f\n",z);
    return 0;
}