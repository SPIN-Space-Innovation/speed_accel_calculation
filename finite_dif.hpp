#pragma once

#include <iostream>
#include <cmath>

const int n = 8;

void velocity_(double height[n], double velocity[n], double dt){
    for (int i = 0; i < n; i++)
    {
        if (i <= 3)
        {
            velocity[i] = ((-49/20)*a[i] + 6*a[i+1] + (-15/2)*a[i+2] + (20/3)*a[i+3] + (-15/4)*a[i+4] + (6/5)*a[i+5] + (-1/6)*a[i+6])/dt;
        }
        if (i>3 && i<=n-4)
        {
            velocity[i] = ((1/280)*a[i-4] + (-4/105)*a[i-3] + (1/5)*a[i-2] + (-4/5)*a[i-1] + (4/5)*a[i+1] + (-1/5)*a[i+2] + (4/105)*a[i+3] + (-1/280)*a[i+4])/dt;
        }
        else{
            velocity[i] = ((-1/3)*a[i-3] + (3/2)*a[i-2] + (-3)*a[i-1] + a[i])/dt;
        }
    }
    
}

void acceleration_(double height[n], double acceleration[n], double dt){
    for (int i = 0; i < n; i++)
    {
        if (i <= 3)
        {
            acceleration[i] = ((469/90)*a[i] + (-223/10)*a[i+1] + (879/20)*a[i+2] + (-949/18)*a[i+3] + 41*a[i+4] + (-201/10)*a[i+5] + (	1019/180)*a[i+6] + (-7/10)*a[i+7])/dt;
        }
        if (i>3 && i<=n-4)
        {
            acceleration[i] = ((-1/560)*a[i-4] + (8/315)*a[i-3] + (-1/5)*a[i-2] + (8/5)*a[i-1] +(-205/72)*a[i] + (8/5)*a[i+1] + (-1/5)*a[i+2] + (8/315)*a[i+3] + (-1/560)*a[i+4])/dt;
        }
        else{
            velocity[i] = ((-1)*a[i-3] + 4*a[i-2] + (-5)*a[i-1] + 2*a[i])/dt;
        }
    }
    
}