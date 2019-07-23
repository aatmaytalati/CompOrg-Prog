// AATMYA S. TALATI
// FALL 2016

#include "myLib.h"
#define UNUSED(x) (void)(x)

u16 *videoBuffer = (u16*) 0x6000000;

void setPixel(int r, int c, u16 color_ur)
{

				videoBuffer[OFFSET(r, c, 240)] = color_ur;

}


void drawRect(int row, int col, int height, int width, u16 color)
{
    int r;
    for(r=0; r<height; r++)
    {
        DMA[3].src = &color;
        DMA[3].dst = &videoBuffer[OFFSET(row+r, col, 240)];
        DMA[3].cnt = width | DMA_DESTINATION_INCREMENT | DMA_SOURCE_FIXED | DMA_ON;

    }
}

void drawImg(int r, int c, int width, int height, const u16* image)
{
				UNUSED(r);
				UNUSED(c);
				UNUSED(width);
				UNUSED(height);
				DMA[3].src = image;
				DMA[3].dst = videoBuffer;
				DMA[3].cnt = (160*240) | DMA_ON;
}



void waitForVblank()
{
		    while(SCANLINECOUNTER > 160);
		    while(SCANLINECOUNTER < 160);
}
