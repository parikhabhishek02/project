/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_sctimer.h"
#include "fsl_gpio.h"
#include "peripherals.h"

#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define SCTIMER_CLK_FREQ CLOCK_GetFreq(kCLOCK_BusClk)
#define LEFT_MOTOR_SPEED1 kSCTIMER_Out_7
#define LEFT_MOTOR_DIRECTION1 kSCTIMER_Out_2
#define RIGHT_MOTOR_SPEED2 kSCTIMER_Out_4
#define RIGHT_MOTOR_DIRECTION2 kSCTIMER_Out_5
#define MOTOR_PORT 0U
#define left_motor_speed_up_PIN 18U
#define left_motor_dir_PIN 19U
#define right_motor_speed_up_PIN 20U
#define right_motor_dir_PIN 21U





/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void) {
	uint32_t dutycycle_left=60,dutycycle_right=60,a=3,b=3;

		/* Define the init structure for the output LED pin*/
	    gpio_pin_config_t left_motor_speed_up = {
	        kGPIO_DigitalInput, 1,
	    };



	    gpio_pin_config_t right_motor_speed_up = {
	   	        kGPIO_DigitalInput, 1,
	   	    };


	    gpio_pin_config_t left_motor_dir = {
	   	        kGPIO_DigitalInput, 1,
	   	    };
	    gpio_pin_config_t right_motor_dir = {
	   	        kGPIO_DigitalInput, 1,
	   	    };

	 sctimer_config_t sctimerInfo;
		    sctimer_pwm_signal_param_t pwmParam_left1,pwmParam_left2,pwmParam_right1,pwmParam_right2;
		    uint32_t event_left1,event_left2,event_right1,event_right2;
		    uint32_t sctimerClock;

    /* Board pin, clock, debug console init */
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /* enable clock for GPIO*/
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    GPIO_PortInit(GPIO, MOTOR_PORT);
    GPIO_PinInit(GPIO, MOTOR_PORT, left_motor_speed_up_PIN, &left_motor_speed_up);


    GPIO_PinInit(GPIO, MOTOR_PORT, right_motor_speed_up_PIN, &right_motor_speed_up);


    GPIO_PinInit(GPIO, MOTOR_PORT, left_motor_dir_PIN, &left_motor_dir);
    GPIO_PinInit(GPIO, MOTOR_PORT, right_motor_dir_PIN, &right_motor_dir);

    GPIO_PinRead(GPIO, MOTOR_PORT, left_motor_speed_up_PIN);

    GPIO_PinRead(GPIO, MOTOR_PORT, left_motor_dir_PIN);
    GPIO_PinRead(GPIO, MOTOR_PORT, right_motor_speed_up_PIN);

    GPIO_PinRead(GPIO, MOTOR_PORT, right_motor_dir_PIN);

    sctimerClock = SCTIMER_CLK_FREQ;



    /* Default configuration operates the counter in 32-bit mode */
    SCTIMER_GetDefaultConfig(&sctimerInfo);

    /* Initialize SCTimer module */
    SCTIMER_Init(SCT0, &sctimerInfo);



    /* Configure first PWM with frequency 24kHZ from LEFT MOTOR FIRST SIGNAL output */
            pwmParam_left1.output = LEFT_MOTOR_SPEED1;
            pwmParam_left1.level = kSCTIMER_HighTrue;
            pwmParam_left1.dutyCyclePercent = 10;


               /* Configure first PWM with frequency 24kHZ from LEFT MOTOR SECOND SIGNAL output */
            pwmParam_left2.output = LEFT_MOTOR_DIRECTION1;
            pwmParam_left2.level = kSCTIMER_HighTrue;
            pwmParam_left2.dutyCyclePercent = 1;

                  /* Configure first PWM with frequency 24kHZ from RIGHT MOTOR FIRST SIGNAL output */
            pwmParam_right1.output = RIGHT_MOTOR_SPEED2;
            pwmParam_right1.level = kSCTIMER_HighTrue;
            pwmParam_right1.dutyCyclePercent = 10;

            /* Configure first PWM with frequency 24kHZ from RIGHT MOTOR SECOND SIGNAL output */
            pwmParam_right2.output = RIGHT_MOTOR_DIRECTION2;
            pwmParam_right2.level = kSCTIMER_HighTrue;
            pwmParam_right2.dutyCyclePercent = 1;

    /* Schedule events in current state; State 0 */
    /* Schedule events for generating a 24KHz PWM with 10% duty cycle from first Out in the current state */
     /* Initialize SCTimer module */
        SCTIMER_Init(SCT0, &sctimerInfo);

        SCTIMER_SetupPwm(SCT0, &pwmParam_left1, kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &event_left1);
        SCTIMER_SetupPwm(SCT0, &pwmParam_left2, kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &event_left2);

        SCTIMER_SetupPwm(SCT0, &pwmParam_right1, kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &event_right1);
        SCTIMER_SetupPwm(SCT0, &pwmParam_right2, kSCTIMER_CenterAlignedPwm, 24000U, sctimerClock, &event_right2);



    /* Start the timer, use counter L as we are operating counter in 32-bit mode */
    SCTIMER_StartTimer(SCT0, kSCTIMER_Counter_L);


    /* Force the counter to be placed into memory. */

    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {

    	if(GPIO_PinRead(GPIO, MOTOR_PORT, left_motor_speed_up_PIN)==0)
    	{
    		while(GPIO_PinRead(GPIO, MOTOR_PORT, left_motor_speed_PIN)==0);
    		dutycycle_left=dutycycle_left+5;
    		if(dutycycle_left>100)
    			dutycycle_left=60;
    		a=0;

    	}






    	if(GPIO_PinRead(GPIO, MOTOR_PORT, right_motor_speed_up_PIN)==0)
    	    	{
    		while(GPIO_PinRead(GPIO, MOTOR_PORT, right_motor_speed_PIN)==0);
    		dutycycle_right=dutycycle_right+5;
    		 if(dutycycle_right>=100)
    		    dutycycle_right=60;
    		 b=0;
    	    	}







    	if(GPIO_PinRead(GPIO, MOTOR_PORT, left_motor_dir_PIN)==0)
    	{
    		while(GPIO_PinRead(GPIO, MOTOR_PORT, left_motor_dir_PIN)==0);
    		a=a+1;
    		if (a>2)
    		{
    			a=0;

    		}

    	}

    	if(GPIO_PinRead(GPIO, MOTOR_PORT, right_motor_dir_PIN)==0)
    	    	{
    		while(GPIO_PinRead(GPIO, MOTOR_PORT, right_motor_dir_PIN)==0);
    		b=b+1;
    		  if (b>2)
    		   {
    		   	b=0;

    		    }}
    if(a==0){
    	SCTIMER_UpdatePwmDutycycle(SCT0,LEFT_MOTOR_SPEED1,dutycycle_left,event_left1);
    	SCTIMER_UpdatePwmDutycycle(SCT0,LEFT_MOTOR_DIRECTION1,1,event_left2);
    }
    if(a==1)
    {
    	SCTIMER_UpdatePwmDutycycle(SCT0,LEFT_MOTOR_SPEED1,1,event_left1);
    	SCTIMER_UpdatePwmDutycycle(SCT0,LEFT_MOTOR_DIRECTION1,dutycycle_left,event_left2);

    }

    if(b==0){
    	SCTIMER_UpdatePwmDutycycle(SCT0,RIGHT_MOTOR_SPEED2,dutycycle_right,event_right1);
    	SCTIMER_UpdatePwmDutycycle(SCT0,RIGHT_MOTOR_DIRECTION2,1,event_right2);
    }
    if(b==1){
        	SCTIMER_UpdatePwmDutycycle(SCT0,RIGHT_MOTOR_SPEED2,1,event_right1);
        	SCTIMER_UpdatePwmDutycycle(SCT0,RIGHT_MOTOR_DIRECTION2,dutycycle_right,event_right2);
        }


}
return 0;
}
