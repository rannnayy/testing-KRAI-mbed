#ifndef _MOTOR_BOHS_H_
#define _MOTOR_BOHS_H_

#include "mbed.h"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include "../Motor/Motor.h"
#include "../encoderKRAI/encoderKRAI.h"
#include "../pidLo/pidLo.h"

#define HIGH_LIMIT 0.1
#define LOW_LIMIT -0.1
#define HIGH_TIME 20000
#define LOW_TIME 5000
#define max_pwm 1.0

#define  PI 3.14159265358979
#define  WHEEL_RAD 0.075
#define  S_TO_US 1000000
#define  ENC_MOTOR_PULSE 538
#define  ENC_MOTOR_SAMP_US_DEF 20000

class MotorBOHS
{
    private:
        Motor* motorBOHS;
        encoderKRAI* encBOHS;
        pidLo* pidBOHS;

        float pwm_rand, pwm, curr_speed;
        uint8_t lastTime;
        uint8_t randTime;
    public:
        MotorBOHS(Motor *motorBOHS, encoderKRAI *encBOHS, pidLo *pidBOHS);
        void motorBOHSSamp();
        void encoderBOHSSamp();
        void pidBOHSSamp();
        void MoveBOHS();
        void DebugBOHS();
};

#endif