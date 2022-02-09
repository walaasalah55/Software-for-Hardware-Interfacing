#include "GPIO.h"
//#include "stm32f401cc_interface.h"
#include "Keypad.h"

//button released
int button_state=0;
char key =0 ;
char Keypad_arr[4][3]= {{1,2,3},
						{4,5,6},
						{7,8,9},
						{'*',0,'#'}};


void  Keypad_init  () {
	GPIO_EnableClock(1);
	for (int col = 0; col < 3; col++) {
	    GPIO_Init(1, col, OUTPUT, PUSH_PULL);
	  }
	for (int row = 3; row < 7; row++) {
	 	GPIO_Init(1, row, INPUT, PULL_UP);
	 	  }
}

void Keypad_manage() {
	if (button_state==0)
	 {for (int col = 0; col < 3; col++){
		   GPIO_WritePin(1, col, 0);
		   for (int row = 0; row < 4; row++) {
		         if (GPIO_ReadPin(1, row+3) == 0) {
		            delay30ms();                      // -> Read button
		            if (GPIO_ReadPin(1, row+3) == 0) {
		                key= Keypad_arr[row][col];
		            	button_state = 1;
		            	KeypadCallouts_KeyPressNotificaton(); // by user
		            	}
		         	 }
		   	   	  }
		 GPIO_WritePin(1, col, 1);
	   }
	 }

}

char Keypad_GetKey (void){
 if (button_state==1) //button pressed
    {button_state=0;
     return key; }
 else
	 return -1 ;
}
