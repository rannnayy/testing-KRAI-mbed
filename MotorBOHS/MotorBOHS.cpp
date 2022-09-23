#include "MotorBOHS.h"

MotorBOHS::MotorBOHS(Motor *motorBOHS, encoderKRAI *encBOHS, pidLo *pidBOHS) {
    srand(static_cast <unsigned> (time(0)));
    this->motorBOHS = motorBOHS;
    this->encBOHS = encBOHS;
    this->pidBOHS = pidBOHS;
    this->randTime = LOW_TIME + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/(HIGH_TIME - LOW_TIME)));
    this->lastTime = us_ticker_read();
}

void MotorBOHS::motorBOHSSamp() {
    this->motorBOHS->speed(this->pwm);
}

void MotorBOHS::encoderBOHSSamp() {
    this->MoveBOHS();
    this->curr_speed = (float)this->encBOHS->getPulses()*2*PI*WHEEL_RAD*S_TO_US/(ENC_MOTOR_PULSE*ENC_MOTOR_SAMP_US_DEF);

    this->encBOHS->reset();
}

void MotorBOHS::pidBOHSSamp() {
    this->pwm = this->pidBOHS->createpwm(this->pwm_rand, this->curr_speed, max_pwm);
}

void MotorBOHS::MoveBOHS() {
    if (us_ticker_read() - lastTime >= randTime) {
        this->pwm_rand = LOW_LIMIT + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HIGH_LIMIT-LOW_LIMIT)));
        printf("%f\n", this->pwm_rand);
        
        this->randTime = LOW_TIME + static_cast <int> (rand()) /( static_cast <int> (RAND_MAX/(HIGH_TIME - LOW_TIME)));
        this->lastTime = us_ticker_read();
    }
}

void MotorBOHS::DebugBOHS() {
    motorBOHS->speed(0.1);
}