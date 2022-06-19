#ifndef _DECLARATIONS_H_
#define _DECLARATIONS_H_

#include "encoderHAL/encoderHAL.h"
#include "encoderHAL/EncoderMspInitF4.h"
#include "CMPS12_KRAI/CMPS12_KRAI.h"
#include "odometriKRAI/odometriKRAI.h"

encoderHAL encX(TIM3);
encoderHAL encY(TIM4);

CMPS12_KRAI cmps12(PB_3, PB_10, 0xC0);

odometriKRAI odom(&encX, &encY, &cmps12);

#endif