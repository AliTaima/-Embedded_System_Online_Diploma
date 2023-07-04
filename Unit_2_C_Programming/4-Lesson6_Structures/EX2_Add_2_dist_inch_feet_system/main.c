#include <stdio.h>
#include <stdlib.h>

struct distance
{
    int feet;
    float inch;
};
int main()
{
    struct distance dist1, dist2, sum;
    printf("----------------Information for 1st distance----------\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);
    printf("----------------Information for 2nd distance----------\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);
    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;
    if(sum.inch >= 12)
    {
        sum.inch -= 12;
        sum.feet ++;
    }
    printf("\n\nSum of distance = %d '-%.1f\"", sum.feet, sum.inch);
    return 0;
}
