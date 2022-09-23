#include "mbed.h"
// #include "Declarations.h"
// #include "odometriKRAI/odometriKRAI.h"

// #include "Motor/Motor.h"
// #include "encoderKRAI/encoderKRAI.h"
#include "encoderHAL/encoderHAL.h"
#include "encoderHAL/EncoderMspInitF4.h"
// #include "CMPS12_KRAI/CMPS12_KRAI.h"
// #include "JoystickPS3.h"
// #include "odometriKRAI.h"
// #include "millis.h"
// #include "Servo.h"

#define  PI 3.14159265358979
#define  WHEEL_RAD 0.075
#define  S_TO_US 1000000
#define  ENC_MOTOR_PULSE 538
#define  ENC_MOTOR_SAMP_US_DEF 20000

// #define motorD_L PB_12
// #define motorD_R PA_12
// #define motorD_PWM PA_11

// #define motorC_R PA_14
// #define motorC_L PA_13
// #define motorC_PWM PA_15

// #define motorB_R PC_1
// #define motorB_L PC_0
// #define motorB_PWM PB_0

// #define motorA_R PA_11
// #define motorA_L PB_12
// #define motorA_PWM PC_9

// #define motorD_L PB_12 // BL
// #define motorD_R PA_12
// #define motorD_PWM PA_11

// #define MOT_THROW_L_PWM   PB_9    // Motor C
// #define MOT_THROW_L_FOR   PB_12
// #define MOT_THROW_L_REV   PA_11

// #define MOT_THROW_R_PWM  PA_15   // Motor B
// #define MOT_THROW_R_FOR  PA_13
// #define MOT_THROW_R_REV  PA_14

// #define ENC_CLAW_L_CHA   PC_13   // ENC_INT_3
// #define ENC_CLAW_L_CHB   PC_10
// #define PULSE_CLAW_L     488

// #define ENC_CLAW_R_CHA   PC_15    // ENC_INT_4
// #define ENC_CLAW_R_CHB   PC_3

// #define ENC_INTA_CHA PC_10
// #define ENC_INTA_CHB PC_13

// #define ENC_INTB_CHA PC_14
// #define ENC_INTB_CHB PC_2

// #define ENC_INTC_CHA PC_15
// #define ENC_INTC_CHB PC_3

// #define ENC_INTD_CHA PC_10
// #define ENC_INTD_CHB PC_13

// #define ENC_INT5_CHA PA_13
// #define ENC_INT5_CHB PA_12

// #define ENC_INT6_CHA PB_7
// #define ENC_INT6_CHB PB_6

// #define SPI_SCK PA_5
// #define SPI_SS PA_4
// #define SPI_MISO PA_6
// #define SPI_MOSI PA_7
//
//Servo Servo1(PC_6);//OK
//Servo Servo3(PC_7); //OK
//Servo Servo4(PC_9); //OK
//Servo Servo5(PC_8); //OK

// Motor a_motor           (motorA_PWM, motorA_R, motorA_L);
// Motor b_motor           (motorB_PWM, motorB_R, motorB_L);
// Motor c_motor           (motorC_PWM, motorC_R, motorC_L);
// Motor d_motor           (motorD_PWM, motorD_R, motorD_L);
// Motor e_motor           (motorE_PWM, motorE_R, motorE_L);

// encoderKRAI encA        (ENC_INTA_CHA, ENC_INTA_CHB, 538, X4_ENCODING);
// encoderKRAI encB        (ENC_INTB_CHA, ENC_INTB_CHB, 538, X4_ENCODING);
// encoderKRAI encC        (ENC_INTC_CHA, ENC_INTC_CHB, 538, X4_ENCODING);
// encoderKRAI encD        (ENC_INTD_CHA, ENC_INTD_CHB, 538, X4_ENCODING);
// encoderKRAI encE        (ENC_INT5_CHA, ENC_INT5_CHB, 538, encoderKRAI::X4_ENCODING);
// encoderKRAI encF        (ENC_INT6_CHA, ENC_INT6_CHB, 538, encoderKRAI::X4_ENCODING);

//joysticknucleo stick2(PA_0, PA_1);

//I2C i2c2 (PB_3,PB_10);

// CMPS12_KRAI cmps12(PC_9, PA_8, 0xC0);

//SPI spi_m(SPI_MOSI, SPI_MISO, SPI_SCK); // mosi, miso, sclk
//DigitalOut cs_m(SPI_SS);
//Serial pc(USBTX, USBRX,115200);

// encoderHAL enc_eks1(TIM3);
// encoderHAL enc_eks2(TIM4);
//double pulse_eks1;
//double pulse_eks2;

// #define UART_RX PA_1
// #define UART_TX PA_0

/* ENCODER */
encoderHAL encX(TIM3);
encoderHAL encY(TIM4);

int xTemp;
int yTemp;

// odometriKRAI odom(&encX, &encY);

FileHandle *mbed::mbed_override_console(int fd)
{
    static BufferedSerial serial_port(USBTX, USBRX, 115200);
    return &serial_port;
}

// uint32_t samplingPrint = 0;

int main(){
    while(1) {
        xTemp = encX.getPulses(1);                            /* butuh 1.5us */
        yTemp = encY.getPulses(1);                            /* butuh 1.5us */
        printf("%d %d\n", xTemp, yTemp);
        // odom.updatePosition();
        
        // if (us_ticker_read() - samplingPrint > ENC_MOTOR_SAMP_US_DEF) {
        //     printf("%d %f\n", encA.getPulses(), encA.getPulses()*2*PI*WHEEL_RAD*S_TO_US/(ENC_MOTOR_PULSE*ENC_MOTOR_SAMP_US_DEF));
        //     // encA.reset();
        //     samplingPrint = us_ticker_read();
        // }
        // printf("HALOOOOO\n");
        // d_motor.speed(0);
        // a_motor.speed(1);
        // b_motor.speed(+0.2);
        // c_motor.speed(+0.2);
        // d_motor.speed(+0.2);
        // wait(1000);
        // a_motor.speed(-0);
        // b_motor.speed(-0.05);
        // wait(1000);
        // b_motor.speed(-0);
        // c_motor.speed(-0.5);
        // wait(1000);
        // c_motor.speed(-0);
        // d_motor.speed(-0.5);
        // wait(1000);

//        e_motor.speed(-0.2);
        //Servo1 =1.0;
//        Servo3 =1.0;
//        Servo4 =1.0;
//        Servo5 =1.0;
        //startMillis();
        //pulse_eks1 += (double)enc_eks1.getPulses(1);
//        pulse_eks2 += (double)enc_eks2.getPulses(1);
//        pc.printf("%.3f , %.3f\n", pulse_eks1, pulse_eks2);

    }
}

/***************************************************************************
 * Title      : MAIN PROGRAM ROBOT TR
 * Author     : KRAI ITB 2020
 *
 * 
 ***************************************************************************/


/* LIBRARY */
// #include <random>
// #include "mbed.h"
// #include "Motor/Motor.h"
// #include "pidLo/pidLo.h"
// #include "encoderKRAI/encoderKRAI.h"

// #define PI 3.14

// #define SAMP_PID_BOHS 20000
// #define SAMP_ENC_BOHS 15000
// #define SAMP_DEBUG_BOHS 30000

// static BufferedSerial serial_port(USBTX, USBRX, 115200);
// FileHandle *mbed::mbed_override_console(int fd)
// {
//     return &serial_port;
// }
// unsigned char temp;
// uint32_t samplingPIDBOHS = 0;
// uint32_t samplingEncoderBOHS = 0;
// uint32_t samplingDebugBOHS = 0;
// uint32_t lastSamplingRandBOHS = 0;
// uint32_t samplingRandBOHS = 0;

// pidLo pid_motor (0.3, 0.05, 0, 0.02, 0.3, 0, 1000, 100);
// encoderKRAI encA        (PC_14, PC_0, 538, X4_ENCODING);
// Motor a_motor           (PB_0, PC_3, PC_2);

// // float pulse_A;
// float omega, pwm;
// float omega_target = 2.25;
// float arrTeta[] = {1.57, -1.57, 1.8, -1.8, 2, -2, 2.25, -2.25};

// int main(){
//     samplingRandBOHS = us_ticker_read() % 5000000;
//     while (1) {
//         if (_serial.readable()){
//             _serial.read(&temp, sizeof(temp));
//             printf("\n%c", temp);
//         }
//         if (us_ticker_read() - samplingPIDBOHS > 20000){
//             pwm = pid_motor.createpwm(omega_target, omega, 0.5);
//             a_motor.speed(pwm);
//             samplingPIDBOHS = us_ticker_read();
//         }
        
//         if (us_ticker_read() - samplingEncoderBOHS > 15000){
//             omega = ((float)encA.getPulses()*2*PI*1000000)/(538*15000);
//             encA.reset();
//             samplingEncoderBOHS = us_ticker_read();
//         }

//         if (us_ticker_read() - samplingDebugBOHS > 30000){
//             printf("\n %f, %f, %f", pwm, omega, omega_target);
//             samplingDebugBOHS = us_ticker_read();
//         }

//         if (us_ticker_read() - lastSamplingRandBOHS > samplingRandBOHS){
//             omega_target = arrTeta[(int)rand() % 8];
//             lastSamplingRandBOHS = us_ticker_read();
//             samplingRandBOHS = us_ticker_read() % 5000000;
//         }
//     }
//     return 1;
// }
