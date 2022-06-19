/********************************************************/
/*          Library untuk pembacaan Encoder             */
/*                  Adopsi dari QEI                     */
/*  Bismillahirahmanirrahim                             */
/*  Encoder yang sudah dicoba :                         */
/*  1. Autonics                                         */
/*  2. Encoder bawaan Motor                             */
/*                                                      */
/*  ______________________                              */
/*  |______Autonics______|                              */
/*  | Out A = Input 1    |                              */
/*  | Out B = Input 2    |                              */
/*  | 5V                 |                              */
/*  |_Gnd________________|                              */
/*                                                      */
/********************************************************/

#include "encoderKRAI.h"

encoderKRAI::encoderKRAI(PinName channelA, PinName channelB, int pulsesPerRev, Encoding encoding) 
    : channelA_(channelA), channelB_(channelB)
{
    this->pulses_       = 0;
    this->revolutions_  = 0;
    this->pulsesPerRev_ = pulsesPerRev;
    this->encoding_     = encoding;

    //Workout what the current state is.
    int chanA = channelA_.read();
    int chanB = channelB_.read();

    //2-bit state.
    this->currState_ = (chanA << 1) | (chanB);
    this->prevState_ = this->currState_;

    //X2 encoding uses interrupts on only channel A.
    //X4 encoding uses interrupts on      channel A,
    //and on channel B.
    this->channelA_.rise(callback(this, &encoderKRAI::encode));
    this->channelA_.fall(callback(this, &encoderKRAI::encode));

    //If we're using X4 encoding, then attach interrupts to channel B too.
    if (encoding == X4_ENCODING) {
        this->channelB_.rise(callback(this, &encoderKRAI::encode));
        this->channelB_.fall(callback(this, &encoderKRAI::encode));
    }
}

void encoderKRAI::reset(void) {
    this->pulses_      = 0;
    this->revolutions_ = 0;
}

int encoderKRAI::getPulses(void) {
    return this->pulses_;
}

int encoderKRAI::getRevolutions(void) {
    this->revolutions_ = this->pulses_ / this->pulsesPerRev_;
    return this->revolutions_;
}

/***************************************
 *  Perhitungan Pulse Encoder
 ***************************************/

void encoderKRAI::encode(void) {
    int change = 0;
    int chanA  = channelA_.read();
    int chanB  = channelB_.read();

    //2-bit state.
    this->currState_ = (chanA << 1) | (chanB);

    if (this->encoding_ == X2_ENCODING) {
        //11->00->11->00 is counter clockwise rotation or "forward".
        if ((this->prevState_ == 0x3 && this->currState_ == 0x0) ||
                (this->prevState_ == 0x0 && this->currState_ == 0x3)) {

            this->pulses_++;
        }
        //10->01->10->01 is clockwise rotation or "backward".
        else if ((this->prevState_ == 0x2 && this->currState_ == 0x1) ||
                 (this->prevState_ == 0x1 && this->currState_ == 0x2)) {
            this->pulses_--;
        }

    } else if (this->encoding_ == X4_ENCODING) {
        //Entered a new valid state.
        if (((this->currState_ ^ this->prevState_) != INVALID) && (this->currState_ != this->prevState_)) {
            //2 bit state. Right hand bit of prev XOR left hand bit of current
            //gives 0 if clockwise rotation and 1 if counter clockwise rotation.
            change = (this->prevState_ & PREV_MASK) ^ ((this->currState_ & CURR_MASK) >> 1);

            if (change == 0) {
                change = -1;
            }

            this->pulses_ -= change;
        }
    }

    this->prevState_ = this->currState_;
}