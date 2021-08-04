void selectanim();
void selectbg(int press,int select);
void circles_initialize();
extern int maxx,maxy;

struct radius
{
	int mid;
	int out;
	int circ;
	radius()
	{
	mid=70;
	out=180;
	circ=50;
	}
}r;

struct circles
{

	int x;
	int y;
	int x1,y1;
	int color;

	void fill();
	void line();
}c[5];

void circles::fill()
	{
		setlinestyle(SOLID_LINE,1,THICK_WIDTH);
		setcolor(color);
		circle(x,y,r.circ);

		setfillstyle(SOLID_FILL,color+8);
		floodfill(x+5,y+5,color);

		setcolor(color);
		settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);

		switch(color)
		{
			case 1: outtextxy(x,y,"u");
			break;
			case 2: outtextxy(x,y,"a");
			break;
			case 3: outtextxy(x,y,"t");
			break;
			case 4: outtextxy(x,y,"r");
			break;
			case 5: outtextxy(x,y,"h");
			break;

			default:
			outtextxy(100,100,"error");
			exit(1);
		}

	}

void circles::line()
	{
		setlinestyle(SOLID_LINE,0,THICK_WIDTH);
		setcolor(color);
		circle(x,y,r.circ);

		setcolor(color);
		settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);
		switch(color)
		{
			case 1: outtextxy(x,y,"u");
			break;
			case 2: outtextxy(x,y,"a");
			break;
			case 3: outtextxy(x,y,"t");
			break;
			case 4: outtextxy(x,y,"r");
			break;
			case 5: outtextxy(x,y,"h");
			break;
			default:
			outtextxy(100,100,"error");
			exit(1);
		}

	}


void circles_initialize()
{
	for(double i=1;i<=5;i++)
		{
			c[i].x= getmaxx()/2 + r.out*cos(3.14*(90+(i-1)*72)/180);
			c[i].y= getmaxy()/2 - r.out*sin(3.14*(90+(i-1)*72)/180);
			c[i].color=i;


		}
}




void selectbg(int press,int select)
{
	//used to creat bg
	cleardevice();


	setbkcolor(WHITE);
	setfillstyle(WIDE_DOT_FILL,LIGHTGRAY);
	bar(0,0,getmaxx(),getmaxy());


	setcolor(YELLOW);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(getmaxx()/2,getmaxy()/2,r.mid);
	setfillstyle(WIDE_DOT_FILL,YELLOW);
	floodfill(getmaxx()/2,getmaxy()/2,YELLOW);

	settextstyle(SCRIPT_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(DARKGRAY);

	{

		if(press==0)
		{

			outtextxy(getmaxx()/2,getmaxy()/2-10,"Select");
			outtextxy(getmaxx()/2,getmaxy()/2+20,"Two");
		}

		else
		{
			outtextxy(getmaxx()/2,getmaxy()/2-10,"One");
			outtextxy(getmaxx()/2,getmaxy()/2+20,"More");
		}
}

	c[1].line();
	c[2].line();
	c[3].line();
	c[4].line();
	c[5].line();

	if(select)
	{
		c[select].fill();
	}
	
	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(DARKGRAY);
	outtextxy(20,40,"E");
}


void selectanim()
{

	setbkcolor(WHITE);
	setfillstyle(WIDE_DOT_FILL,LIGHTGRAY);
	bar(0,0,getmaxx(),getmaxy());

	setcolor(YELLOW);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	circle(getmaxx()/2,getmaxy()/2,r.mid);
	setfillstyle(WIDE_DOT_FILL,YELLOW);
	floodfill(getmaxx()/2,getmaxy()/2,YELLOW);


	settextstyle(SCRIPT_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);

	setcolor(DARKGRAY);
	outtextxy(getmaxx()/2,getmaxy()/2-10,"Select");
	outtextxy(getmaxx()/2,getmaxy()/2+20,"Two");
	delay(150);

	for(int j=1;j<=5;j++)
	{
		c[j].line();
		delay(150);
	}


	int cycle=1;
	int press=0;
	int select=0;

	getch();


	//I added an int cycle and made it rotate between 1 and 5. The color of menu icons depend on cycle. I also added char c to take alphabetic input and change cycle. Enter key has ASCII of carrige type, ie 13. I use it and cycle to call respective sunctions in a nested switch case.

	while((cycle>0)&&(cycle<6))
	{
		if(kbhit())
		{
			char input;
			input=getch();

			switch(input)
			{
				case 's':

					if(cycle==5)
					{
						cycle=1;
						selectbg(press,select);
						c[cycle].fill();
						//this was done so that rather incrementing and messing up the while loop, we end up cycling at the first option. noice, right guiz?
					}
					else
					{
						cycle++;
						selectbg(press,select);
						c[cycle].fill();
					}
					break;

				case 'w':
					if(cycle==1)
					{
						cycle=5;
						selectbg(press,select);
						c[cycle].fill();
					}

					else
					{
						cycle--;
						selectbg(press,select);
						c[cycle].fill();
					}
					break;

				case 13:

						int opt=cycle*10+select;

						if(press==0)
						{

							press++;
							select=cycle;
							selectbg(press,select);
							c[cycle].fill();

						}

						else if ((cycle==select)||(opt==35)||(opt==53))
						{
							continue;
						}


						else
						{
							ball b_sim=ball(opt);
							b_sim.anim_graph();

							if(b_sim.saveflag==1)
							{
							outtextxy(getmaxx()/2,getmaxy()/2,"Enter Savename");
							gets(b_sim.savename);
							fhand dynamo;
							dynamo.saveball(b_sim);
							}

							introanim();

						}

					break;

				case 8:

					if(press==1)
					{
						press=0;
						select=0;
						selectbg(press,select);
						c[cycle].fill();
					}
					break;

				case 'e':
					introanim();
					break;


				default:
				continue;
			}


		}

	}


}





