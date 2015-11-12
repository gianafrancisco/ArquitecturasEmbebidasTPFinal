#include	"includes.h"
#include	"timers.h"
#include 	"io_define.h"
#include    "UCOS_II.H"
#include	<delays.h>
#include	<usart.h>
#include	<adc.h>
#include    <stdio.h>
#include    <stdlib.h>

typedef struct AdcMsg {
	INT16S adc0;
	INT16S adc1;
	INT16S adc2;
};

//#define txtSensorA	"Entradas: "
#define CRLF	"\r\n"
#define SPACE	" "
#define QSize	10
#define MEMORY_BLOCK_NUM    15
#define MEMORY_SIZE sizeof(struct AdcMsg)


INT8S NumeroSensores = 3;
void *QueueADC0Message[QSize];
OS_EVENT *STask1;
OS_EVENT *STaskTxSerial;
OS_EVENT *STeclado;
OS_EVENT *QueueADC0;

OS_MEM *dMemory;
INT8U   dMemoryData[MEMORY_BLOCK_NUM][MEMORY_SIZE];

OS_STK	Start_TaskStk[100L];
OS_STK	TaskSensoresStk[100L];
OS_STK	TaskTxSerialStk[150L];
OS_STK	TaskTecladoStk[100L];

void TaskSensores(void *pdata)
{    
#if OS_CRITICAL_METHOD == 3 
    OS_CPU_SR  cpu_sr;
#endif
    struct AdcMsg *m;
    INT16U value = 0;
    INT16U ValorTeclado = 0;
	INT8U err;
	for(;;)
	{
        
        m = (struct AdcMsg *) OSMemGet(dMemory,&err);
        if(err == OS_NO_ERR){
            OSSemPend(STeclado,0,&err);
            ValorTeclado = NumeroSensores;
            OSSemPost(STeclado);       
            m->adc0 = 0;
            m->adc1 = 0;
            m->adc2 = 0;
            switch(ValorTeclado){
                case 3:
                    Delay10TCYx(100);
                    SetChanADC(ADC_CH2);
                    ConvertADC();
                    while( BusyADC() );
                    value = ReadADC();
                    m->adc2 = value;
                case 2:
                    Delay10TCYx(100);
                    SetChanADC(ADC_CH1);
                    ConvertADC();
                    while( BusyADC() );
                    value = ReadADC();
                    m->adc1 = value;                    
                case 1:
                    Delay10TCYx(100);
                    SetChanADC(ADC_CH0);
                    ConvertADC();
                    while( BusyADC() );
                    value = ReadADC();
                    m->adc0 = value;
                default:
                    break;
            }

            err = OSQPost(QueueADC0,m);
            if(err == OS_Q_FULL){
                OSMemPut(dMemory,m);
                OSSemPost(STaskTxSerial);
            }
        }else{
            OSSemPost(STaskTxSerial);
        }
		//OSSemPost(STask2);
		OSTimeDly(1);
	}
}

void TaskTxSerial(void *pdata)
{
#if OS_CRITICAL_METHOD == 3
    OS_CPU_SR  cpu_sr;
#endif
	struct AdcMsg *Sensores;
	INT8U err;
    INT16S Sensor1;
    INT16S Sensor2;
    INT16S Sensor3;
    INT16U  Acumulador1;
    INT16U  Acumulador2;
    INT16U  Acumulador3;
    INT8U contador;
    INT16U ValorTeclado;
    INT8S strTx1[5];
    INT8S strTx2[5];
    INT8S strTx3[5];
	
	for(;;)
	{
		OSSemPend(STaskTxSerial,0,&err);
        Acumulador1=0;
        Acumulador2=0;
        Acumulador3=0;
        for(contador=0 ; contador<10 ; contador++) {
            Sensores = (struct AdcMsg *) OSQPend(QueueADC0, 0, &err);
            Acumulador1+=Sensores->adc0;
            Acumulador2+=Sensores->adc1;
            Acumulador3+=Sensores->adc2;
            OSMemPut(dMemory,Sensores);
        }

		OSSemPend(STeclado,0,&err);
        ValorTeclado=NumeroSensores;
        OSSemPost(STeclado);
        Sensor1=0;
        Sensor2=0;
        Sensor3=0;
		switch(ValorTeclado){
			case 3:
				Sensor3 = (INT16S) Acumulador3/10;
			case 2:
				Sensor2 = (INT16S) Acumulador2/10;
			case 1:
				Sensor1 = (INT16S) Acumulador1/10;
			default:
				break;
		}
/*
        itoa(Sensor1,strTx1);
        putsUSART(strTx1);
        putrsUSART(SPACE);
        itoa(Sensor2,strTx2);
        putsUSART(strTx2);
        putrsUSART(SPACE);
        itoa(Sensor3,strTx3);
        putsUSART(strTx3);
        putrsUSART(CRLF);
 */
		if(NumeroSensores > 0){
            itoa(Sensor1,strTx1);
            putsUSART(strTx1);
            putrsUSART(SPACE);
			if(NumeroSensores > 1){
                itoa(Sensor2,strTx2);
                putsUSART(strTx2);
                putrsUSART(SPACE);
			}
			if(NumeroSensores > 2){
                itoa(Sensor3,strTx3);
                putsUSART(strTx3);
			}
			putrsUSART(CRLF);
		}
		//OSSemPost(STask1);
        
		OSTimeDly(10);
	}
}

void TaskTeclado(void *pdata)
{
#if OS_CRITICAL_METHOD == 3
    OS_CPU_SR  cpu_sr;
#endif
	unsigned char input = 0;
	unsigned char err;
	for(;;)
	{
    
		input = Input0;
		Delay10TCYx( 100 );
		if(input != 1 && Input0 != 1){
			while(Input0 == 0){
				OSTimeDly(2);
			}
			OSSemPend(STeclado,0,&err);
			NumeroSensores--;
			if(NumeroSensores < 0){
				NumeroSensores = 3;
			}
			OSSemPost(STeclado);
		}
		OSTimeDly(100);
	}
}
//---------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void Task_START(void *pdata)
{
    INT8U err;
    OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_1);
    
	OpenUSART( USART_TX_INT_OFF &
 				USART_RX_INT_OFF &
 				USART_ASYNCH_MODE &
 				USART_EIGHT_BIT &
 				USART_CONT_RX &
 				//USART_BRGH_LOW,
                USART_BRGH_HIGH,
 			51 );//12 - 9600 LOW
                 //8 - 57.6k HIGH


	OpenADC( ADC_FOSC_32 &
		ADC_RIGHT_JUST &
		ADC_12_TAD,
		ADC_CH0 & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS &
		ADC_INT_OFF, 15 );

    
	TRISA |= 0b01111111;
	TRISD &= 0b01111111;
	TRISE |= 0b00000111;
	ADCON1 &= 0b00000000;
	ADCON1 |= 0b00000000;
	CVRCON &= 0b00111111;
    
    /*
    ANSEL = 0;	//turn off all other analog inputs
	ANSELH = 0;
 	ANSELbits.ANS0 = 1;	// turn on RA0 analog
    ADCON1 = 0;
    ADCON2 = 0b00111000;
    ADCON0 = 0b00000001;
    */


	//STask1  = OSSemCreate(1);
	STaskTxSerial  = OSSemCreate(0);
	STeclado  = OSSemCreate(1);

    dMemory = OSMemCreate((void *)dMemoryData,MEMORY_BLOCK_NUM,MEMORY_SIZE,&err);
    
	QueueADC0 = OSQCreate((void *)QueueADC0Message,QSize);	

	OSTaskCreate(TaskSensores, (void *)0, &TaskSensoresStk[0], 1);
	OSTaskCreate(TaskTxSerial, (void *)0, &TaskTxSerialStk[0], 5);
	OSTaskCreate(TaskTeclado, (void *)0, &TaskTecladoStk[0], 10);

	//i_data = *((int *)pdata);

	// task loop
	for(;;)
	{
		salidaLED_0 = !(salidaLED_0);
		OSTimeDly(50);
		salidaLED_0 = !(salidaLED_0);
		OSTimeDly(50);
	}
}


//-----------------------------------------------------------------------------------------------------------------------
void main (void)
{
	int i_test = 0xABCD;

	/* Set oscilator to 16Mhz */
	OSCCON = 0b01111110;
	TRISD = 0b00001000;
    TRISB = 0b00000001;
	salidaLED_0 = 1;
	salidaLED_1 = 0;
	salidaLED_2 = 0;

	INTCONbits.GIEH = 0;

	OSInit();

	OSTaskCreate(Task_START, (void *)&i_test, &Start_TaskStk[0], 0);

	OSStart();
}
