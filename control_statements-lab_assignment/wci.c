#include <stdio.h>
#include <math.h>

int main() {
    float v, t, WCI;
    printf("Enter the wind speed (mph): ");
    scanf("%f", &v);
    printf("Enter the temperature (deg. F): ");
    scanf("%f", &t);

    if(v >= 0 && v <= 4)
        WCI = t;
    else if(v >= 45)
        WCI = 1.6 * t - 55;
    else
        WCI = 91.4 + (91.4 - t) * ((0.0203 * v) - (0.304 * sqrt(v)) - 0.474);

    printf("Wind Chill Index (WCI): %.2f\n", WCI);
    return 0;
}
