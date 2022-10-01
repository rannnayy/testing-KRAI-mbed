#include "mbed.h"
// #include "Declarations.h"
// #include "odometriKRAI/odometriKRAI.h"

// #include "Motor/Motor.h"
#include "encoderKRAI/encoderKRAI.h"
// #include "CMPS12_KRAI/CMPS12_KRAI.h"
// #include "JoystickPS3.h"
// #include "odometriKRAI.h"
// #include "millis.h"
// #include "Servo.h"

// #define motorBL_R PC_13
// #define motorBL_L PB_1
// #define motorBL_PWM PB_0

// #define motorFL_R PC_3
// #define motorFL_L PC_2
// #define motorFL_PWM PB_9

// #define motorBR_R PC_14
// #define motorBR_L PC_15
// #define motorBR_PWM PA_11

// #define motorFR_R PA_14
// #define motorFR_L PB_3
// #define motorFR_PWM PB_8

// #define motorD_R PC_11
// #define motorD_L PC_10
// #define motorD_PWM PB_10

// #define motorD_L PB_12 // BL
// #define motorD_R PA_12
// #define motorD_PWM PA_11

// #define motorA_R PA_14 // FL
// #define motorA_L PA_13
// #define motorA_PWM PA_15

// #define motorB_R PC_1 // FR
// #define motorB_L PC_0
// #define motorB_PWM PB_0

// #define motorC_R PB_14 // BR
// #define motorC_L PB_15 
// #define motorC_PWM PB_1

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

#define ENC_INTBL_CHA PC_5 // BL
#define ENC_INTBL_CHB PC_5

#define ENC_INTBL_CHA PC_0
#define ENC_INTBL_CHB PC_1

#define ENC_INTFL_CHA PB_14 // FL
#define ENC_INTFL_CHB PB_2

#define ENC_INTBR_CHA PC_8
#define ENC_INTBR_CHB PB_15

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

// Motor BR_motor           (motorBR_PWM, motorBR_R, motorBR_L);
// Motor FL_motor           (motorFL_PWM, motorFL_R, motorFL_L);
// Motor BL_motor           (motorBL_PWM, motorBL_R, motorBL_L);
// Motor FR_motor           (motorFR_PWM, motorFR_R, motorFR_L);
//Motor e_motor           (motorE_PWM, motorE_R, motorE_L);

encoderKRAI encA        (ENC_INTFL_CHA, ENC_INTFL_CHB, 538, X4_ENCODING);
encoderKRAI encB        (ENC_INTFR_CHA, ENC_INTFR_CHB, 538, X4_ENCODING);
encoderKRAI encC        (ENC_INTBR_CHA, ENC_INTBR_CHB, 538, X4_ENCODING);
encoderKRAI encD        (ENC_INTBL_CHA, ENC_INTBL_CHB, 538, X4_ENCODING);
// encoderKRAI encE        (ENC_INT5_CHA, ENC_INT5_CHB, 538, encoderKRAI::X4_ENCODING);
//encoderKRAI encF        (ENC_INT6_CHA, ENC_INT6_CHB, 538, encoderKRAI::X4_ENCODING);

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
// encoderHAL encX(TIM3);
// encoderHAL encY(TIM4);

// int xTemp;
// int yTemp;

// odometriKRAI odom(&encX, &encY);

FileHandle *mbed::mbed_override_console(int fd)
{
    static BufferedSerial serial_port(USBTX, USBRX, 115200);
    return &serial_port;
}

int main(){
    while(1) {
        // xTemp = encX.getPulses(1);                            /* butuh 1.5us */
        // yTemp = encY.getPulses(1);                            /* butuh 1.5us */
        // printf("%d %d\n", xTemp, yTemp);
        // odom.updatePosition();
        printf("%d %d %d %d\n", encA.getPulses(), encB.getPulses(), encC.getPulses(), encD.getPulses());
        // printf("HALOOOOO\n");
        // d_motor.speed(0);
        // BR_motor.speed(-0.5);
        // BL_motor.speed(-0.5);
        // BL_motor.speed(-0.5);
        // FR_motor.speed(-0.5);
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