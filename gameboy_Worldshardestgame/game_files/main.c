
#include "myLib.c"
#include "start.h"
#include "gameover.h"
#include "endgame.h"
#include <stdio.h>
#include <stdlib.h>
#include "text.h"

// Defining Funcaitons.

void IfyouWin(); // if your chances != 0 and then you are going to Game oVer screen
void haar(); // if your chances == , then you are showing the triangle screen
int karmank;  // Keeping track of the life
PLYR myPlayer = {120,5,8,1}; // Defination of the player. that we have

int main(void)
{
      // Start Screen - Basically the screen with a boy image on it.
        REG_DISPCNT = BG2_EN | MODE_3; // enables mode 3

			  drawImg(0,0,START_WIDTH,START_HEIGHT,start);
			  drawString(12, 29, "Press (ENTER) Gentelly to start", BLUE);

      // defiing position of the player.
        myPlayer.col= 0;


        while(!ON_PRESS(BUTTON_START));

      // Get Explained what it does.
		    u16 color;
		    char buffer[41];
		    int chances = 5;

      // Backgorund Color
      	color = BLUE;
      	DMA[3].src = &color; // source
      	DMA[3].dst = videoBuffer; //destination
      	DMA[3].cnt = (240*160) | DMA_SOURCE_FIXED | DMA_ON;

      // defining 6 enemies.

      	DUSHMAN enemy1 = {20,14,63,41,0,1};
        DUSHMAN enemy2 = {18,14,63,41,32,1};
      	DUSHMAN enemy3 = {29,14,63,41,64,1};
      	DUSHMAN enemy4 = {30,14,63,41,72,1};
      	DUSHMAN enemy5 = {15,14,63,41,88,1};
      	DUSHMAN enemy6 = {35,14,63,41,95,1};

      // ASK TA - How to randomize the heights of the enemies
      // We want to randomize the enemies. So basically what I would do is
      // define each enemey at different height.


      // Defining the heights of the enemies.

      	unsigned short h=0;
      	unsigned short h1=32;
      	unsigned short h2=55;
      	unsigned short h3=65;
      	unsigned short h4=78;
      	unsigned short h5=86;

while(1)
{
      // Drawing enemies on screen

   		 drawRect(h, 30, enemy1.width, enemy1.height, RED);
    	 drawRect(h1, 60, enemy2.width, enemy2.height, WHITE);
 		   drawRect(h2, 90, enemy3.width, enemy3.height, WHITE);
 		   drawRect(h3, 120, enemy4.width, enemy4.height, RED);
       drawRect(h4, 150, enemy5.width, enemy5.height, WHITE);
		   drawRect(h5, 180, enemy6.width, enemy6.height, WHITE);

       // randomizing the height of the enemies
       if (h==140)
       {
              h=0;
		    }

       else{
              h++;
           }

	drawRect(h, 30, enemy1.width, enemy1.height, BLACK);
///////////////////////////////////////////
	  if (h1==132)
           {
              h1=5;
		}

       else{
              h1++;
           }
	drawRect(h1, 60, enemy2.width, enemy2.height, MAGENTA);
//////////////////////////////////////////////////////////////////

	  if (h2==120)
           {
              h2=10;
		}

       else{
              h2++;
           }
	drawRect(h2, 90, enemy3.width, enemy3.height, BLACK);
////////////////////////////////////////////////////////////////////

	  if (h3==175)
           {
              h3=5;
		}

       else{
              h3++;
           }
	drawRect(h3, 120, enemy4.width, enemy4.height, CYAN);
////////////////////////////////////////////////////////////////

	  if (h4==85)
           {
              h4=5;
		}

       else{
              h4++;
           }
	drawRect(h4, 150, enemy5.width, enemy5.height, GREEN);
//////////////////////////////////////////////////////////////////

	  if (h5==100)
           {
              h5=5;
		}

       else{
              h5++;
           }
	drawRect(h5, 180, enemy6.width, enemy6.height, BLACK);
/////////////////////////////////



// if chances are 0, which means you are dying, then... continue
if(chances == 0)
{
		      haar(); // go to the funciton defined as "Lost Game" -- Shows triangle
		      break;
}

// else go to the win then go to the Game Over Screen -- Game Over Sign Picture

else if (myPlayer.col == 232)
{
          IfyouWin(); // go to the funcation of wining the game
	        break;
}

 	if(ON_PRESS(BUTTON_SELECT))
		{
		karmank--; // once you hit someone then decrease the life.
		 main();
		 break;
		}

            if(ON_PRESS(BUTTON_UP))
            {
              myPlayer.row = myPlayer.row-1;
            }

            if(ON_PRESS(BUTTON_DOWN))
            {
              myPlayer.row = myPlayer.row+1;
            }

	           if(ON_PRESS(BUTTON_LEFT))
            {
               myPlayer.col = myPlayer.col -1;
               }

            if(ON_PRESS(BUTTON_RIGHT))
            {
               myPlayer.col = myPlayer.col +1;
            }

            if(myPlayer.row<0)
            {
                myPlayer.row = 0;

            }
            if(myPlayer.row>159-myPlayer.size+1)
            {
                myPlayer.row = 159-myPlayer.size+1;
            }

            if(myPlayer.col < 0)
            {
                myPlayer.col = 0;
            }

            if(myPlayer.col > 239-myPlayer.size+1)
            {
                myPlayer.col = 239-myPlayer.size+1;

            }



          // prints the chances on screen
      		drawRect(myPlayer.row,myPlayer.col,myPlayer.size, myPlayer.size, BLACK);
      		sprintf(buffer, "CHANCES: %d", chances);
      		drawString(150,70, " ", RED);
          drawString(150, 10, buffer, RED);
          //drawString(150,70, " ", RED);

          waitForVblank();

      		color = YELLOW;
      		DMA[3].src = &color; // background color
      		DMA[3].dst = videoBuffer;
      		DMA[3].cnt = (240*160) | DMA_SOURCE_FIXED | DMA_ON;

          //Removing Space from the top of the screen
      		drawRect(myPlayer.row,myPlayer.col,myPlayer.size, myPlayer.size, BLUE);
      		drawRect(0,235, 160,5, BLACK); // Drawing the Finish Line at the End
      //		drawRect(myPlayer.row,myPlayer.col,myPlayer.size, myPlayer.size, RED);

// collision detection
   if (((myPlayer.col>=(30-myPlayer.size)) && (myPlayer.col<=(30+enemy1.width)) && (myPlayer.row<=(h+enemy1.height)) && (myPlayer.row>=(h-myPlayer.size)))||
	((myPlayer.col>=(60-myPlayer.size)) && (myPlayer.col<=(60+enemy2.width)) && (myPlayer.row<=(h1+enemy2.height)) && (myPlayer.row>=(h1-myPlayer.size)))||
	((myPlayer.col>=(90-myPlayer.size)) && (myPlayer.col<=(90+enemy3.width)) && (myPlayer.row<=(h2+enemy3.height)) && (myPlayer.row>=(h2-myPlayer.size)))||
	((myPlayer.col>=(120-myPlayer.size)) && (myPlayer.col<=(120+enemy4.width)) && (myPlayer.row<=(h3+enemy4.height)) && (myPlayer.row>=(h3-myPlayer.size)))||
	((myPlayer.col>=(150-myPlayer.size)) && (myPlayer.col<=(150+enemy5.width)) && (myPlayer.row<=(h4+enemy5.height)) && (myPlayer.row>=(h4-myPlayer.size))) ||
	((myPlayer.col>=(180-myPlayer.size)) && (myPlayer.col<=(180+enemy6.width)) && (myPlayer.row<=(h5+enemy6.height)) && (myPlayer.row>=(h5-myPlayer.size))))
	{
          myPlayer.row = 120;
	        myPlayer.col = 5;
	        chances--;
  }
}

 }

void IfyouWin() // if you win
{
  	       drawImg(0, 0, GAMEOVER_WIDTH, GAMEOVER_HEIGHT, gameover);
  	       drawString(142, 20, "PRESS (Enter) to RESTART LEVEL ", RED);
     	     while(!ON_PRESS(BUTTON_START));
  	       while( ON_PRESS(BUTTON_START));
  	       main();

}

void haar() // if you loose
{
        	drawImg(0, 0, ENDGAME_WIDTH, ENDGAME_HEIGHT, endgame);
        	drawString(142, 20, "No Anger, Start Again", RED);
        	while(!ON_PRESS(BUTTON_START));
        	while(ON_PRESS(BUTTON_START));
        	main();

}
