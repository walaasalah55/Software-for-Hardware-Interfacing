
#include "GPIO.h"
#include "Keypad.h"

void KeypadCallouts_KeyPressNotificaton();
unsigned char counter ;
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void delay30ms() {

  for (int i = 0; i < 30000; i++) {
  }
}

void KeypadCallouts_KeyPressNotificaton(){
	counter=Keypad_GetKey ();
	for (int i = 0; i < 7; i++) {
	  GPIO_WritePin(0, i, (sevenSegHex[counter] & (1 << i)) >> i); }
}

int main(void) {

  GPIO_EnableClock(0);
  for (int i = 0; i < 7; i++) {
    GPIO_Init(0, i, OUTPUT, PUSH_PULL);
  } 
  Keypad_init();
  while (1) {
	  Keypad_manage();

        }

  return 0;
}

/* You are required to define a group of symbolic macros to define all the registers offsets in one GPIO channel. You are required to define a generic macro for the GPIO registers definition instead of using the library provided by STM. The Generic macro shall be on the form GPIO_REG(PORT_ID, REG_ID) You are required to rewrite the GPIO driver using the newly defined macro. You will use the register offset macros to be passed to REG_ID argument. No use of switch case for port selection. apply on lab5 */




