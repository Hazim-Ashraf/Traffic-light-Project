/*
 * app.c
 *
 * Created: 1/2/2023 8:32:20 PM
 *  Author: DELL
 */ 
#include "app.h"



 



void APP_INIT() // initialize ECUAL & MCAL
{
	// initialize led for cars port a
	LED_INIT(LEDG_C,PORT_A);
	LED_INIT(LEDY_C,PORT_A);
	LED_INIT(LEDR_C,PORT_A);
	// initialize led for pedestrians
	LED_INIT(LEDG_P,PORT_B);
	LED_INIT(LEDY_P,PORT_B);
	LED_INIT(LEDR_P,PORT_B);
	// button initialize for press
	BUTTON_init(BUTTON,PORT_D,INPUT);
	ENABLE_INTR(INT0);
	INTRE_SENSE(INT0,RISING_EDGE);

}
void NORMAL_STATE()//normal case
{
	LED_OFF(LEDY_P,PORT_B);// back from states all off
	LED_OFF(LEDG_P,PORT_B);
	LED_OFF(LEDR_P,PORT_B);
	
	//green car and  all off
	LED_ON(LEDG_C,PORT_A);
	LED_ON(LEDR_P,PORT_B);
	DELAY(5000);//in miliseconds
	// yellow on all off
	LED_OFF(LEDG_C,PORT_A);
	LED_OFF(LEDR_P,PORT_B);
	LED_BLINK2(LEDY_C,PORT_A,LEDY_P,PORT_B,5);											
	// red car and green pedesterian and  all off
	LED_OFF(LEDY_C,PORT_A);
	LED_OFF(LEDY_P,PORT_B);
	LED_ON(LEDG_P,PORT_B);
	LED_ON(LEDR_C,PORT_A);
	DELAY(5000);//in miliseconds
	// yellow on all off
	LED_OFF(LEDR_C,PORT_A);
	LED_OFF(LEDG_P,PORT_B);
	LED_BLINK(LEDY_C,PORT_A,5);
	LED_OFF(LEDY_C,PORT_A);														
}
void CASE_RED()// case red
{
	//led green pedstrains on and red car for 5 seconds
	LED_ON(LEDG_P,PORT_B);
	LED_ON(LEDR_C,PORT_A);
	DELAY(5000);
}
void CASE_2() // case 2 function
{
	// red pedestrians on
	LED_ON(LEDR_P,PORT_B);
	LED_BLINK2(LEDY_C,PORT_A,LEDY_P,PORT_B,5);// both starts to blink yellow led
	LED_OFF(LEDY_C,PORT_A);// yellow led off
	LED_OFF(LEDY_P,PORT_B);
	LED_OFF(LEDR_P,PORT_B);
	LED_ON(LEDR_C,PORT_A);//red car led on
	LED_ON(LEDG_P,PORT_B);//green pedestrians on
	DELAY(5000);// all of that for 5 seconds
}
void END_STATE()// end of state function
{ 
	// red card and green pedestrains are off 
	LED_OFF(LEDR_C,PORT_A);
	LED_OFF(LEDG_P,PORT_B);
	LED_BLINK2(LEDY_C,PORT_A,LEDY_P,PORT_B,5);// both starts to blink
	// yellow leds off
	LED_OFF(LEDY_C,PORT_A);
	LED_OFF(LEDY_P,PORT_B);
	//after the end of the state
	// green car and red pedestrains are on 
	LED_ON(LEDG_C,PORT_A);
	LED_ON(LEDR_P,PORT_B);
	//DELAY(2000);// to see it on simulation 
}




void APP_START() // flowchart
{
	while(1)
	{
			// which state to apply
			switch(state)
			{
				case 1:// case red pedesterian 
				{
					
					//red cars led is on and green pedesterian doing case 1
					presscount=0;
					press=NOT_PRESSED;
					NORMAL_STATE();
					//CASE_RED();
					// At the end of the state
					//END_STATE();
					// back to normal
					 
					//state=normal;
					// state is done so clear flag
					break;
				}
				case 2:// case 2 gerren or yellow pedesterian 
				{

					//pederstrian red on case 2
					press=NOT_PRESSED;//  (to change the button from press to non-press)
					CASE_2();
					// back to normal
					END_STATE();
					
					presscount=0;// state is done so clear flag
					state=normal;
					
					break;
				}
				case 0:
				{
					//no_overflow=0;// reset nomber of overflows
					//normal mode
					NORMAL_STATE();
					
					//presscount=0;// state is done so clear flag
					break;
				}
			}
		
	}
	
}

ISR(EXT_INT_0)
{
	
	press=PRESS;
	//PEDESTRIAN MODE button is pressed
	if(press==PRESS &&presscount==1)
	{
		presscount++;// reset press flag
	}
	 if(presscount<1)
	{
		
		// read each led pin 
		READ_PIN(LEDR_C,PORTA,&stateRC);
		READ_PIN(LEDG_C,PORTA,&stateGC);
		READ_PIN(LEDY_C,PORTA,&stateYC);
		if(stateGC==HIGH || stateYC==HIGH)
		{
			state=Case2;// case 2 if green and yellow car led are on 
			presscount++;// count touch flag high 
			 
		}
		if(flag_blink==1)
		{
			state=Case2;
			presscount++;
		}
		else if(stateRC==HIGH)
		{
			
			state=CaseRED;// case 1 if red led is on 
					presscount+=2;// count touch flag high 
		}
	}
	else
	{
		presscount=0;// reset press flag
	}

} 

