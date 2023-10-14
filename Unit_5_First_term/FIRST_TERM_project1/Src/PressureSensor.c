#include "PressureSensor.h"
extern threshold;
extern Pval;
int HighPressureDetected(void)
{
    Pval = getPressureVal();
    if (Pval > threshold)
        return 1;
    else
        return 0;
}
