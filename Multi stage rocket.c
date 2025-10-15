#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Function to calculate delta-v for one stage
double rocket_delta_v(double m0, double mf, double ve)
{
    if (mf <= 0 || m0 <= mf)
    {
        printf("Error: Final mass must be positive and less than initial mass.\n");
        return -1;
    }
    return ve*log(m0/mf);
}
int main()
{
    int stages, i;
    double m0, mf, Isp, g0=9.80665, ve, delta_v, total_delta_v=0.0;

    printf("=== Multi-Stage Rocket Equation Calculator ===\n");
    printf("Enter number of stages: ");
    scanf("%d", &stages);

    for (i=1; i <= stages; i++)
    {
        printf("Enter initial mass of stage (kg): ");
        scanf("%lf", &m0);

        printf("Enter final mass of stage (kg): ");
        scanf("%lf", &mf);

        printf("Enter specific impulse (Isp) of engine (seconds): ");
        scanf("%lf", &Isp);

        // Convert Isp to exhaust velocity
        ve= Isp * g0;

        //Calculate delta_v
        delta_v = rocket_delta_v(m0, mf, ve);

        if (delta_v == -1)
        {
            printf("Skipping Stage %d due to input error.\n", i);
            continue;
        }
        printf("Stage %d delta_v: %.2f m/s\n", i, delta_v);
        total_delta_v += delta_v;
    }
        printf("\n=== Final Results ===\n");
        printf("Total delta_v: %.2f m/s\n", total_delta_v);

        if (total_delta_v < 9400)
        {
            printf("Note: Insufficient for Low Earth Orbit insertion (⁓9.4 km/s).\n");
        }
        else
        {
            printf("Note: Sufficient for Low Earth Orbit insertion.\n");
        }

    return 0;
}

