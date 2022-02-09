
#include "dma.h"


void DMA_init (unsigned char DMA_type,unsigned char priority_level,unsigned char transfer_direction,unsigned char channel_selected) {

	if(DMA_type==1) {
		*RCC_AHB1ENR |= (0x01 <<21 );//to enable DMA1 clk
     }
	else{
		*RCC_AHB1ENR |= (0x01 <<22 ); //to enable DMA2 clk
		}

    *DMA_S0CR &=~(1<<0); // to disable stream 0
    // priority level
	*DMA_S0CR&= ~(0x03 << 16);
	*DMA_S0CR|= (priority_level <<16 );
	// Data transfer direction
	*DMA_S0CR&= ~(0x03 << 6);
	*DMA_S0CR|= (transfer_direction << 6 );
	// select channel
	if (transfer_direction!=0x02)
		{*DMA_S0CR&= ~(0x07 << 25);
		 *DMA_S0CR|= (channel_selected <<25 );
		}

	// increment mode (MINC & PINC)
	*DMA_S0CR|= (1 << 9 );
	*DMA_S0CR|= (1 << 10 );

}


void DMA_parameters (unsigned int *Source_address,unsigned int *destination_address,
				unsigned int number_of_transfers,unsigned char transfer_item_size,
				unsigned char transfer_mode, unsigned char transfer_type)
{

	*DMA_S0NDTR= number_of_transfers;
	*DMA_S0PAR= Source_address;
	*DMA_S0M0AR= destination_address;
	//psize
	*DMA_S0CR&= ~(0x03 << 11);
	*DMA_S0CR|= (transfer_item_size <<11 );
	//msize
	*DMA_S0CR&= ~(0x03 << 13);
	*DMA_S0CR|= (transfer_item_size <<13 );

	if (transfer_mode==0)
	{   // disable direct mode
		*DMA_S0FCR|= (1 <<2 );
		// threshold selection (full FIFO)
		*DMA_S0FCR|=(0x03 << 0);
	}

	// PBURST
	*DMA_S0CR&= ~(0x03 << 21);
	*DMA_S0CR|= (transfer_type <<21);
	// MBURST
	*DMA_S0CR&= ~(0x03 << 23);
	*DMA_S0CR|= (transfer_type <<23);


}

void start_transfer () {

	 // enable Transfer complete interrupt
	*DMA_S0CR|= (1 <<4);
	 // enable Transfer error interrupt
	*DMA_S0CR|= (1 <<2);

	// clear stream 0 interrupt flags
	*DMA_LIFCR  = 0x3D;
	*DMA_S0CR |=(1<<0); // to enable stream 0

}

void transfer_state () {
  // check if transfer complete event occurred on stream 0 & if there is transfer error
	if((((*DMA_LISR) & (1 << 5)) >> 5)==1 && (((*DMA_LISR) & (1 << 3)) >> 3)!=1 )
		{ LedCallouts();}

//clear flag of Stream 0 transfer complete & Transfer error interrupt
	  *DMA_LIFCR  |=(1<<5);
	  *DMA_LIFCR  |=(1<<3);
}

/*void DMA_ISR () {


}*/


