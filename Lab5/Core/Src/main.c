
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
	  GPIO_WritePin('A', i, (sevenSegHex[counter] & (1 << i)) >> i); }
}

int main(void) {

  GPIO_EnableClock('A');
  for (int i = 0; i < 7; i++) {
    GPIO_Init('A', i, OUTPUT, PUSH_PULL);
  } 
  Keypad_init();
  while (1) {
	  Keypad_manage();

        }

  return 0;
}

/* You are required to build a software that display a number on a seven-segment display after pressing a button on a keypad. The implemented GPIO driver shall be used to interface the Keypad and the seven-segment display.*/

