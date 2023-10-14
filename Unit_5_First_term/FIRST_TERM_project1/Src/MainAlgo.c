#include <stdint.h>
#include <stdio.h>
#include "MainAlgo.h"
#include "AlarmMonitor.h"
#include "driver.h"
#include "PressureSensor.h"
int threshold = 20;
int Pval;
void init(void)
{
    GPIO_INITIALIZATION();
    StopAlarm();
}

void app(void)
{
    Pval = getPressureVal();
    Delay(1100000); // delay between each reading
    if (HighPressureDetected())
    {
        StartAlarm();
        Delay(1000000); // delay to set alarm
        StopAlarm();
    }
}
