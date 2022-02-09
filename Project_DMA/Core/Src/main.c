
#include "dma.h"
#include "GPIO.h"

void LedCallouts();
int source_arr[100];
int destination_arr[100];

void LedCallouts(){
	// turn on led if source_arr is transfered to destination_arr successfully
if ((source_arr[0]==destination_arr[0]) && (source_arr[99]==destination_arr[99]))
	  GPIO_WritePin(0, 1, 1); }

int main(void) {
	// initalize source (100,200, …) & destination arrays(0,0,…)
	source_arr[0]=100;
	for(unsigned char i=0; i<100; i++) {
		source_arr[i+1] =source_arr[i]+100;
		destination_arr[i] = 0;}

GPIO_EnableClock(0);
GPIO_Init(0, 1, OUTPUT, PUSH_PULL);
DMA_init (DMA2,Very_High ,Memory_to_memory,no);
DMA_parameters (source_arr,destination_arr,100,word,FIFO, INCR4);
// enable interrupt (position 56 in NVIC)
*NVIC_ISER1 |= (0x01<<24);
start_transfer ();

while(1)
{

}
	return 0;
}
