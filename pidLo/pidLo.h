#ifndef PIDLO_H
#define PIDLO_H
#include "math.h"

class pidLo
{
public:
    pidLo(float p, float i, float d, float _Ts, float _max_out, float _vff, float _freq_lpf, float _maxIntegral);

    float createpwm(float setpoint, float feedback, float max);

    void setTunings(float p, float i, float d);

    void setKp(float p);

    void setKd(float d);

    void reset();

private:
    float kp;
    float ki;
    float kd;
    float ts;
    float vff;
    float freq_lpf;
    float max_integral;
    float max_out;

    float error;
    float integ;
    float deriv;

    float last_error;
    float last_out;
};

#endif