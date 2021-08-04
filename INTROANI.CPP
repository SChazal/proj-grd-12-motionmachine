void circles_initialize();
void credit_anim();
void selectanim();
void introanim();
void titleanim();
void menubg();
void menutitle(int num);




void introanim()
{
	cleardevice();
	b_ini.defaultball();
	
	int i;
	//loading in the grey background

	setbkcolor(WHITE);
	setfillstyle(WIDE_DOT_FILL,DARKGRAY);
	bar(0,0,getmaxx(),getmaxy());




	//loading stripes

	//first from right

	for(i=0;i<=getmaxy();i++)
	{
	setfillstyle(INTERLEAVE_FILL,RED);
	bar(getmaxx()/4-30,0,getmaxx()/4,i);
	delay(1);
	}

	//second from right

	for(i=getmaxy();i>=0;i--)
	{
	setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
	bar(getmaxx()/4-60,getmaxy(),getmaxx()/4-30,i);
	delay(1);
	}
	//third from right

	for(i=0;i<=getmaxy();i++)
	{
	setfillstyle(INTERLEAVE_FILL,LIGHTBLUE);
	bar(getmaxx()/4-90,0,getmaxx()/4-60,i);
	delay(1);
	}
 
 
	titleanim();
}

void menubg()
{
	cleardevice();
	//used to creat bg
	
	setbkcolor(WHITE);
	setfillstyle(WIDE_DOT_FILL,DARKGRAY);
	bar(0,0,getmaxx(),getmaxy());

	setfillstyle(INTERLEAVE_FILL,RED);
	bar(getmaxx()/4-30,0,getmaxx()/4,getmaxy());

	setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
	bar(getmaxx()/4-60,getmaxy(),getmaxx()/4-30,0);

	setfillstyle(INTERLEAVE_FILL,LIGHTBLUE);
	bar(getmaxx()/4-90,0,getmaxx()/4-60,getmaxy());

}

void titleanim()
{

	settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(LIGHTBLUE);

	outtextxy(5*getmaxx()/8,getmaxy()/4,"The Motion Machine");
	delay(50);

	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);

	setcolor(RED);
	outtextxy(5*getmaxx()/8,getmaxy()/4+80,"Start Simulation");
	delay(20);

	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+140,"Load");
	delay(20);

	outtextxy(5*getmaxx()/8,getmaxy()/4+200,"Credits");
	delay(20);

	outtextxy(5*getmaxx()/8,getmaxy()/4+260,"Exit");

	int cycle=1;
	
	//I added an int cycle and made it rotate between 1 and 4. The color of menu icons depend on cycle. I also added char c to take alphabetic input and change cycle. Enter key has ASCII of carrige type, ie 13. I use it and cycle to call respective sunctions in a nested switch case.
	
	while((cycle>0)&&(cycle<5))
	{
		if(kbhit())
		{
			char c;
			c=getch();

			switch(c)
			{
				case 's':

					if(cycle==4)
					{
						cycle=1;
						menutitle(cycle);
						//this was done so that rather incrementing and messing up the while loop, we end up cycling at the first option. noice, right guiz?
					}
					else
					{
						cycle++;
						menutitle(cycle);
					}
					break;

				case 'w':
					if(cycle==1)
					{
						cycle=4;
						menutitle(cycle);
					}       					else
					{
						cycle--;
						menutitle(cycle);
					}
					break;

				case 13:
					{
						switch(cycle)
						{
							case 1:	
								
							circles_initialize();
							selectanim();
							
							break;



							case 2:
							
							fhand stroke;
							stroke.loadball();
							stroke.scrollmenua();
							
							break;



							case 3:
							
							credit_anim();
							
							break;



							case 4:
							closegraph();	
							exit(0);
							break;



							default:
							cout<<"error";
						}
					}
					break;

				default:
				continue;
			}


		}

	}


}


void menutitle(int num)
{

	menubg();

	settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);

	setcolor(BLUE);
	outtextxy(5*getmaxx()/8,getmaxy()/4,"The Motion Machine");

	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);

	if(num==1)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+80,"Start Simulation");



	if(num==2)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+140,"Load");



	if(num==3)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+200,"Credits");



	if(num==4)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+260,"Exit");

}


