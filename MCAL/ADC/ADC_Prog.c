#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"ADC_Reg.h"
#include"ADC_Config.h"
#include"../Global Interrupt/GIE_Config.h"


/****** Global Pointer To Function *********/
static void (*GPFunc)(void)=NULL;


void ADC_SetCallBack(void(*LocPFunc)(void))
{
GPFunc=LocPFunc;	
}
/***********ISR FUNCTION ***********/
ISR(__vector_16)
{
	if(GPFunc!=NULL)
	{
		GPFunc();
	}
}

void ADC_VidINIT(void)
{
	/***********ADC VOLTAGE REFFRANCE ***********/
	#if 	ADC_Vref==Vref_turned_off
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	#elif	ADC_Vref==Vref_AVCC
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
	#elif 	ADC_Vref==Vref_Internal
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	#endif
	/**************ADC Prescaler ***************/
	#if	ADC_Prescaler==ADC_Prescaler_2
			 CLR_BIT(ADCSRA,ADPS0);\
			 CLR_BIT(ADCSRA,ADPS1);\
			 CLR_BIT(ADCSRA,ADPS2);
	#elif	ADC_Prescaler==ADC_Prescaler_4
			 CLR_BIT(ADCSRA,ADPS0);\
			 SET_BIT(ADCSRA,ADPS1);\
			 CLR_BIT(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_8
			 SET_BIT(ADCSRA,ADPS0);\
			 SET_BIT(ADCSRA,ADPS1);\
			 CLR_BIT(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_16
			 CLR_BIT(ADCSRA,ADPS0);\
			 CLR_BIT(ADCSRA,ADPS1);\
			 SET_BIT(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_32
			 SET_BIT(ADCSRA,ADPS0);\
			 CLR_BIT(ADCSRA,ADPS1);\
			 SET_BIT(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_64
			 CLR_BIT(ADCSRA,ADPS0);\
			 SET_BIT(ADCSRA,ADPS1);\
			 SET_BIT(ADCSRA,ADPS2);
	#elif     ADC_Prescaler==ADC_Prescaler_128
			 SET_BIT(ADCSRA,ADPS0);\
			 SET_BIT(ADCSRA,ADPS1);\
			 SET_BIT(ADCSRA,ADPS2);
	#endif
	/************ADC ENABLE ******************/
	SET_BIT(ADCSRA,ADEN);
	/************ ADC SAVE FROM **************/
	#if  	ADC_SAVE_FROM==Right_Adjust
		CLR_BIT(ADMUX,ADLAR);
	#elif	ADC_SAVE_FROM==Left_Adjust
		SET_BIT(ADMUX,ADLAR);

	#endif
	/***************ADC MODE******************/
	#if	ADC_Mode==ADC_Single_Conversion
		CLR_BIT(ADCSRA,ADATE);
	#elif	ADC_Mode==ADC_Free_Running
		SET_BIT(ADCSRA,ADATE);
		CLR_BIT(SFIOR,ADTS0);
		CLR_BIT(SFIOR,ADTS1);
		CLR_BIT(SFIOR,ADTS2);
	
	#endif
	
}
void ADC_Start_Conversion(void)
{
	SET_BIT(ADCSRA,ADSC);
}
void ADC_Select_Channal(u8 Channal)
{
	ADMUX&=0B11100000;
	ADMUX|=Channal;
}
void ADC_Interrupt_Enable(void)
{
	SET_BIT(ADCSRA,ADIE);
}
void ADC_Wait_Flag(void)
{
	while(GET_BIT(ADCSRA,ADIF)!=1); //WAIT UNTILL FLAG=1
	SET_BIT(ADCSRA,ADIF);	  //CLEAR FLAG
}
void ADC_Get_Result(u16 *ptr)
{
	*ptr=ADC;
}




