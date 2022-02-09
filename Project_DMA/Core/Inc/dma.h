
#ifndef INC_DMA_H_
#define INC_DMA_H_

#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int *)(PORT_ID + REG_ID))


//clk for AHB1 Bus
#define RCC_AHB1ENR GPIO_REG(0x40023800, 0x30)
// DMA2 registers
#define DMA_LISR  	GPIO_REG(0x40026400,0x00)
#define DMA_HISR  	GPIO_REG(0x40026400,0x04)
#define DMA_LIFCR   GPIO_REG(0x40026400,0x08)
#define DMA_HIFCR   GPIO_REG(0x40026400,0x0C)
// stream 0 registers
#define DMA_S0CR    GPIO_REG(0x40026400,0x10)
#define DMA_S0NDTR  GPIO_REG(0x40026400,0x14)
#define DMA_S0PAR   GPIO_REG(0x40026400,0x18)
#define DMA_S0M0AR  GPIO_REG(0x40026400,0x1C)
#define DMA_S0M1AR  GPIO_REG(0x40026400,0x20)
#define DMA_S0FCR   GPIO_REG(0x40026400,0x24)

#define NVIC_ISER1   GPIO_REG(0xE000E100,0x04)

//DMA type
#define DMA1 ((unsigned char)1)
#define DMA2 ((unsigned char)2)

// Data transfer direction
#define Peripheral_to_memory ((unsigned char)0x00)
#define Memory_to_peripheral ((unsigned char)0x01)
#define Memory_to_memory 	 ((unsigned char)0x02)
#define reserved 			 ((unsigned char)0x03)

// Channel selection
#define channel_0 ((unsigned char)0x00)
#define channel_1 ((unsigned char)0x01)
#define channel_2 ((unsigned char)0x02)
#define channel_3 ((unsigned char)0x03)
#define channel_4 ((unsigned char)0x04)
#define channel_5 ((unsigned char)0x05)
#define channel_6 ((unsigned char)0x06)
#define channel_7 ((unsigned char)0x07)
#define no ((unsigned char)0)

// Data Priority level
#define Low 	  ((unsigned char)0x00)
#define Medium 	  ((unsigned char)0x01)
#define High      ((unsigned char)0x02)
#define Very_High ((unsigned char)0x03)

// Data size
#define byte       ((unsigned char)0x00)
#define half_word  ((unsigned char)0x01)
#define word       ((unsigned char)0x02)
#define reserved   ((unsigned char)0x03)

// transfer_type ( INCRx:incremental burst of x beats)
#define single_transfer ((unsigned char)0x00)
#define INCR4           ((unsigned char)0x01)
#define INCR8           ((unsigned char)0x02)
#define INCR16          ((unsigned char)0x03)

// FIFO threshold selection
#define quarter_full_FIFO		((unsigned char)0x00)
#define half_full_FIFO          ((unsigned char)0x01)
#define three_quarter_full_FIFO ((unsigned char)0x02)
#define full_FIFO     			((unsigned char)0x03)

// modes
#define FIFO ((unsigned char)0)
#define Direct ((unsigned char)1)

void DMA_init (unsigned char DMA_type,unsigned char priority_level,unsigned char transfer_direction,unsigned char channel_selected);
void DMA_parameters (unsigned int *Source_address,unsigned int *destination_address,
				unsigned int number_of_transfers,unsigned char transfer_item_size,
				unsigned char transfer_mode, unsigned char transfer_type);
void start_transfer ();

void transfer_state ();

#endif /* INC_DMA_H_ */

