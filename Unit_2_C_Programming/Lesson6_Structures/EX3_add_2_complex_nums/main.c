#include <stdio.h>
#include <stdlib.h>
struct complex
{
    float real;
    float imag;

};
struct complex calc_complex(struct complex n1, struct complex n2);
int main()
{
    struct complex num1, num2, sum;
    printf("For 1st complex number\n\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("\n\nFor 2nd complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f", &num2.real, &num2.imag);
    sum = calc_complex(num1, num2);
    printf("Sum = %.1f + %.1f\i", sum.real, sum.imag);
    return 0;
}


struct complex calc_complex(struct complex n1, struct complex n2)
{
    struct complex s;
    s.real = n1.real + n2.real;
    s.imag = n1.imag + n2.imag;
    return s;
}
