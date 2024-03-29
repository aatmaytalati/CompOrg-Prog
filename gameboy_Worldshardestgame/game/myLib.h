// AATMYA TALATI
// FALL 2016


typedef unsigned short u16;
typedef unsigned int u32;
#define REG_DISPCNT *(u16*) 0x4000000
#define BG2_EN (1 << 10)
#define MODE_3 3
#define SCANLINECOUNTER *(volatile unsigned short *)0x4000006


#define RGB(r,g,b) ((r)|((g)<<5)|((b)<<10))
#define RED RGB(31,0,0)
#define GREEN RGB(0,31,0)
#define BLUE RGB(0,0,31)
#define CYAN RGB(0,31,31)
#define MAGENTA RGB(31,0,31)
#define YELLOW RGB(31,31,0)
#define BLACK 0
#define WHITE RGB(31,31,31)


#define OFFSET(r,c,nc) ((r)*(nc)+(c))


extern u16 *videoBuffer;



// Buttons

#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT	(1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)

#define BUTTONS *(unsigned int *)0x4000130

#define ON_PRESS(key)  (~(BUTTONS) & key)


// DMA

#define REG_DMA0SAD         *(const volatile u32*)0x40000B0 // source address
#define REG_DMA0DAD         *(volatile u32*)0x40000B4       // destination address
#define REG_DMA0CNT         *(volatile u32*)0x40000B8       // control register

// define DMA channel 1 register
#define REG_DMA1SAD         *(const volatile u32*)0x40000BC // all same as above
#define REG_DMA1DAD         *(volatile u32*)0x40000C0
#define REG_DMA1CNT         *(volatile u32*)0x40000C4

// define DMA channel 2 register
#define REG_DMA2SAD         *(const volatile u32*)0x40000C8  // all same as above
#define REG_DMA2DAD         *(volatile u32*)0x40000CC
#define REG_DMA2CNT         *(volatile u32*)0x40000D0

// define DMA channel 3 register
#define REG_DMA3SAD         *(const volatile u32*)0x40000D4  // all same as above
#define REG_DMA3DAD         *(volatile u32*)0x40000D8
#define REG_DMA3CNT         *(volatile u32*)0x40000DC

typedef struct
{
	const volatile void *src;
	const volatile void *dst;
	u32                  cnt;
} DMA_CONTROLLER;

#define DMA ((volatile DMA_CONTROLLER *) 0x040000B0)

// Defines
#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

typedef struct player
{
		int row;
		int col;
		int size;
		int death;
}PLYR;

typedef struct enemy
{
		int width;
		int height;
		int row;
		int col;
		int oldrow;
		int oldcol;
}DUSHMAN;

void drawImg(int r, int c, int width, int height, const u16* image);
void drawRect(int row, int col, int height, int width, u16 color);
void setPixel(int r, int c, u16 color_ur);
void waitForVblank();
