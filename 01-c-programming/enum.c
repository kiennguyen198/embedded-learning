#include <stdio.h>

typedef enum
{
    LIGHT_RED,
    LIGHT_GREEN,
    LIGHT_YELLOW
}   TrafficLightState;

static void run_traffic_light(TrafficLightState *state)
{
    switch(*state)
    {
        case LIGHT_RED:
            printf("RED: Stop\n");
            *state=LIGHT_GREEN;
            break;

        case LIGHT_GREEN:
            printf("GREEN: Go\n");
            *state=LIGHT_YELLOW;
            break;

        case LIGHT_YELLOW:
            printf("YELLOW: Slow down\n");
            *state=LIGHT_RED;
            break;
        
        default:
            printf("Invalid state\n");
            *state=LIGHT_RED;
            break;   
    }
}

int main(void)
{
    TrafficLightState state=LIGHT_RED;
    for (int i=0;i<6;i++)
    {
        run_traffic_light(&state);
    }
}