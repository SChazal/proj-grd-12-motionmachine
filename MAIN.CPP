#include<fstream.h>
//for file handling

#include<conio.h>
//for getch, clrscr, kbhit

#include<stdio.h>
//gets,puts

#include<stdlib.h>
//itoa ltoa

#include<math.h>


#include<dos.h>
//delay, nosound

#include<string.h>
//string functions

#include<graphics.h>





#include"C:\\TURBOC3\\Projects\\MMNew\\LOGIC.cpp"
#include"C:\\TURBOC3\\Projects\\MMNew\\INTROANIM.cpp"
#include"C:\\TURBOC3\\Projects\\MMNew\\LOADANIM.cpp"
#include"C:\\TURBOC3\\Projects\\MMNew\\CREDITS.cpp"
#include"C:\\TURBOC3\\Projects\\MMNew\\SELECT.cpp"



int maxx,maxy;
int gd = DETECT, gm, error;


void initialize();

//introanim
void introanim();
void titleanim();
void menubg();
void menutitle(int num);

//loadanim
void load_animation(int s,int maxx,int maxy, float ac);
void square(int centx, int centy,int a, int inc);

//credits
void credit_anim();

//select
void selectanim();
void selectbg(int press,int select);
void circles_initialize();

//logic


ball b_ini;

void main()
{


	initialize();
	cleardevice();

	setbkcolor(BLACK);


	{
		setfillstyle(SOLID_FILL,LIGHTRED);
		for(int k=1;k<=3;k++)
			{
			load_animation(20,maxx/2,maxy/2,1);
			}
	}

	introanim();
	closegraph();


}

void initialize()
{
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");


  if (error != grOk)
  {
    perror("Error ");
    printf("Press any key to exit...\n");
    getch();
    exit(EXIT_FAILURE);
  }
  maxx=getmaxx();
  maxy=getmaxy();
}



