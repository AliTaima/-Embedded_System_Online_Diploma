#include "AlarmMonitor.h"

void StartAlarm(void)
{
    Set_Alarm_actuator(0);
}
void StopAlarm(void)
{
    Set_Alarm_actuator(1);
}