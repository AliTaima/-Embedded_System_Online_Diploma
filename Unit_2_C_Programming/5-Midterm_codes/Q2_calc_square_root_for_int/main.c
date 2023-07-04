#include <stdio.h>
#include <stdlib.h>
float square_root(int num);
int main()
{
    int num;
    float sqrt;
    printf("Enter a number: ");
    scanf("%d", &num);
    sqrt = square_root(num);
    printf("The root of %d is %.3f", num, sqrt);

    return 0;
}

float square_root(int num)
{
    float i;
    // add 0.001 to a number until reach to the number that multiply with it self to get the actual number
    for(i = 0.001;i*i<num; i+= 0.001);
    return i;
}
