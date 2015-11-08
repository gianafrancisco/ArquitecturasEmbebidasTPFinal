#include	"includes.h"
#include	"timers.h"
#include	<xlcd.h>
#include	<delays.h>
#include	<string.h>
#include	<stdlib.h>
#include 	"io_define.h"

void UserInit(void);


OS_STK	Start_TaskStk[100L];
OS_STK	Task1Stk[100L];
OS_STK	Task2Stk[100L];
OS_STK	Task3Stk[100L];
OS_STK	Task4Stk[100L];


OS_EVENT *SemaforoMotorON;
OS_EVENT *SemaforoMotorOFF;
OS_EVENT *SemaforoValvulaON;
OS_EVENT *SemaforoValvulaOFF;



//-----------------------------------------------------------------------------------------------------------------------
// functions required for XLCD
// min of 18 Tcy
void DelayFor18TCY(void)
{
	Delay10TCYx(2L);
}

//-----------------------------------------------------------------------------------------------------------------------
// min of 15ms
void DelayPORXLCD(void)
{
	Delay1KTCYx(15L);
}

//-----------------------------------------------------------------------------------------------------------------------
// min of 5ms
void DelayXLCD(void)
{
	Delay1KTCYx(5L);
}


//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
void Task1(void *pdata)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr;
#endif

	for(;;)
	{
		salidaLED_0 = 1;
		OSTimeDly(2);
		salidaLED_0 = 0;
		OSTimeDly(2);

	}
}

//-----------------------------------


//-----------------------------------------------------------------------------------------------------------------------

void TaskValvula(void *pdata)
{
		
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr;
#endif
	char *err;

	for(;;)
	{
		OSSemPend(SemaforoValvulaON,0,&err);
		salidaValvula = 1;
		OSSemPend(SemaforoValvulaOFF,0,&err);
		salidaValvula = 0;
	}
}


//-----------------------------------------------------------------------------------------------------------------------
void TaskSensores(void *pdata)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr;
#endif
    
    for (;;) {
		if(sensorS1 == 0)
		{
			OSTimeDly(1);
			if(sensorS1 == 0)
				OSSemPost(SemaforoMotorON);		// prender motor
		}
		if(sensorS2 == 0)
		{
			OSTimeDly(1);
			if(sensorS2 == 0)
			{

  			 OSSemPost(SemaforoMotorOFF);		// apagar motor
  			 OSSemPost(SemaforoValvulaON);		// apagar motor
			}

		}
		if(sensorS4 == 0)
		{
			OSTimeDly(10);
			if(sensorS4 == 0)
			{
				OSSemPost(SemaforoValvulaOFF);		// apagar motor
				OSSemPost(SemaforoMotorON);		// apagar motor
			}
		}

		if(sensorS3 == 0)
		{
			OSTimeDly(10);
			if(sensorS3 == 0)
			{
				OSSemPost(SemaforoMotorOFF);		// apagar motor	
			}
		}

		OSTimeDly(2);
    }
}

//-----------------------------------------------------------------------------------------------------------------------
void TaskMotor(void *pdata)
{
#if OS_CRITICAL_METHOD == 3                      /* Allocate storage for CPU status register           */
    OS_CPU_SR  cpu_sr;
#endif
	char *err;

    for (;;) {

		OSSemPend(SemaforoMotorON,0,&err);
		salidaMotor=1;
		OSSemPend(SemaforoMotorOFF,0,&err);
		salidaMotor=0;
    }
}

//---------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------
void Task_START(void *pdata)
{
	int		i_data;

	UserInit();

	// configure the input/output pins
	ADCON1 = 0b00001110;		// set the A/D register
	INTCON2 = 0b01111111;
	INTCON3 = 0b00000000;

	// enable interrupts
	OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_1);
	TMR0H = 0xD8;
	TMR0L = 0xA0;
	INTCONbits.GIEH = 1;

	// Initialize statistics task
//	OSStatInit();

	// Start up other tasks
	
	OSTaskCreate(Task1, (void *)0, &Task1Stk[0], 1);
	OSTaskCreate(TaskSensores, (void *)0, &Task3Stk[0], 2);
	OSTaskCreate(TaskValvula, (void *)0, &Task2Stk[0], 3);
	OSTaskCreate(TaskMotor, (void *)0, &Task4Stk[0], 4);


	PORTB = 0x00;

	TRISBbits.TRISB7 = 0;
	TRISBbits.TRISB6 = 0;
	TRISBbits.TRISB5 = 0;
	TRISBbits.TRISB4 = 0;
	TRISBbits.TRISB3 = 1;
	TRISBbits.TRISB2 = 1;
	TRISBbits.TRISB1 = 1;
	TRISBbits.TRISB0 = 1;

	TRISD = 0;		//todas salida

	i_data = *((int *)pdata);



	// task loop
	for(;;)
	{
		OSTimeDly(100);
	}
}


//-----------------------------------------------------------------------------------------------------------------------
void main (void)
{
	int i_test = 0xABCD;
	
	
    
	INTCONbits.GIEH = 0;
	OSInit();

	SemaforoMotorON  = OSSemCreate(0);
	SemaforoMotorOFF  = OSSemCreate(0);
	SemaforoValvulaON  = OSSemCreate(0);
	SemaforoValvulaOFF  = OSSemCreate(0);

    //Mbox1 = OSMboxCreate((void *)0);


	OSTaskCreate(Task_START, (void *)&i_test, &Start_TaskStk[0], 0);
	OSStart();
}



//-------------------------------------------
void UserInit(void)
{

	// Puertos IO

	TRISA = 0b00000000;
	TRISB = 0b00001111;
	TRISC = 0b10000000;	// Pines 6 Y 7 para puerto RS232; pin 4 como SDI 

	TRISD = 0b00000000; 
	TRISE = 0b00000000;
	ADCON1 = 0b00000111; // RA5 (SS) configurada como I/O DIGITAL
	
	LATA   = 0b11111111;
	LATB  =  0b11111111;
	ADCON1 = 0b00001111; // RA5 (SS) configurada como I/O DIGITAL
	CMCON  = 0b00000111;	// comparador apagado

	PORTA=0;
	PORTB=0b00000001;
	PORTC=0;
	PORTD=0;
	PORTE=0;

	PIR1 = 0;	/* clear any pending interrupts */
	



	//InitializeTMR0();

	
	//resistencias de pull - up  DESCONECTADAS (RBPU)
	INTCON2 = 0b10000000;
 	//INTCON2|=0x80;

}//end UserInit

//-------------------------------------------


