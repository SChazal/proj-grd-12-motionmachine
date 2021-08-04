void introanim();
void menubg();
class ball
{



		double a;
		double u;
		double posx;
		double posy;
		double t;
		double H;
		double T;
		double R;
		int rad;
		int color;
		long g;
		int mass;


		double scalex;
		double scaley;
		int originx;
		int originy;

		public:

		char savename[100];
		int saveflag;
		ball();
		ball(int opt);
		void defaultball();
		void create();
		void axis();
		void saveball();
		void loadball();




		void axesgraph();
		void axesmark();
		void analysis();
		void ballpath();
		void anim_graph();
		void ballcontrol();
		void quicky();

		void posy_set()
		{
			posy = ( tan(a)	*  posx	- (  posx*posx*tan( a )/R ) );
		}

};
extern ball b_ini;

//fhandling
struct fhand
{
	void saveball(ball &b);
	void loadball();
	void scrollmenua();
	void scrollmenub(int num);
	ball btemp[3];
};


// graph ke functions

void ball::axesgraph()
{


	{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;

	}


	setbkcolor(DARKGRAY);
	setfillstyle(WIDE_DOT_FILL,LIGHTGRAY);
	bar(0,0,getmaxx(),getmaxy());

	setcolor(WHITE);
	setlinestyle(DASHED_LINE,0,THICK_WIDTH);
	line(originx,0,originx,getmaxy()); //vertical axis
	line(0,originy,getmaxx(),originy); //horizontal axis

	axesmark();
}

void ball::axesmark()
{

{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;
		}

	//x axis:

setcolor(WHITE);
settextstyle(SMALL_FONT,HORIZ_DIR,0);
char locx[17]="0";
char locy[17]="0";


for( int xmark=0  ;  xmark<=500 ;  xmark=xmark+50 )
{

itoa( (xmark*scalex) , locx , 10 );

outtextxy( (originx) + xmark , (originy+20) , locx  );
}


for( int ymark=0  ;  ymark <= 400  ;  ymark=ymark+20 )
{

itoa( (ymark*scaley) , locy , 10 );

outtextxy(  (originx - 20) , originy - ymark, locy  );
}


}

void ball::ballpath()
{

	{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;
	}

    setcolor(CYAN);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    moveto(originx,originy);


	long xcord=0;
	long ycord=0;

	   for( xcord=0 ; xcord <= R ; xcord++ )
	{

		ycord= (  tan(a) *  xcord - (  xcord*xcord*tan(a)/ R ) );

		lineto( originx + xcord/scalex , originy -ycord/scaley);

	}

}

void ball::analysis()
{
	{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;
	}

	char tempdispx[33], tempdispy[33], tempux[33], tempuy[33], temptime[33], tempPE[33],tempKE[33];
	long tdispx, tdispy, tux, tuy, ttime,tPE,tKE;

	tdispx  =	posx;
	tux     =	( u * cos(a));
	ttime   =	tdispx/tux;
	tdispy  =	posy;
	tuy     =	( u*sin(a) ) - (g*ttime);

	//add ke, pe radius of curvature, torque about origin, all one can think of for further analysis

	tPE=	 mass*g*tdispy;
	tKE=	(mass*u*u /2)-tPE;

	ltoa(tdispx,tempdispx,10);
	ltoa(tdispy,tempdispy,10);
	ltoa(tux,tempux,10);
	ltoa(tuy,tempuy,10);
	ltoa(ttime,temptime,10);
	ltoa(tPE,tempPE,10);
	ltoa(tKE,tempKE,10);


	
	setfillstyle(SOLID_FILL,WHITE);
	bar(getmaxx()*3/8,10,getmaxx()*7/8+20,110);
	setfillstyle(WIDE_DOT_FILL,MAGENTA);
	bar(getmaxx()*7/8+20,10,getmaxx(),110);
	
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	setcolor(MAGENTA);
	rectangle(getmaxx()*3/8,10,getmaxx()*7/8+20,110);
	rectangle(getmaxx()*7/8+20,10,getmaxx(),110);
	
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT,VERT_DIR,2);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	outtextxy(getmaxx()-35,105,"ANALYSIS");
	
	settextstyle(SMALL_FONT,HORIZ_DIR,0);
	setcolor(DARKGRAY);
	
	outtextxy(getmaxx()*4/8,30,"X-Velocity: ");
	outtextxy(getmaxx()*6/8,30,"Y-Velocity: ");
	outtextxy(getmaxx()*4/8,50,"Displacement X: ");
	outtextxy(getmaxx()*6/8,50,"Displacement Y: ");
	outtextxy(getmaxx()*4/8,70,"Time: ");
	outtextxy(getmaxx()*6/8,70,"Kinetic energy: ");
	outtextxy(getmaxx()*5/8,90,"Potential energy: ");

	outtextxy(getmaxx()*4/8+60,30,tempux);
	outtextxy(getmaxx()*6/8+60,30,tempuy);
	outtextxy(getmaxx()*4/8+60,50,tempdispx);
	outtextxy(getmaxx()*6/8+60,50,tempdispy);
	outtextxy(getmaxx()*4/8+60,70,temptime);
	outtextxy(getmaxx()*6/8+70,70,tempKE);
	outtextxy(getmaxx()*5/8+70,90,tempPE);

	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(WHITE);
	outtextxy(20,40,"E");


}

void ball::anim_graph()
{
	{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;
	}

	cleardevice();



	//

	setbkcolor(DARKGRAY);
	setfillstyle(WIDE_DOT_FILL,WHITE);
	bar(0,0,getmaxx(),getmaxy());

	setcolor(WHITE);
	setlinestyle(DASHED_LINE,0,THICK_WIDTH);

	for(int i=0;i<=getmaxx();i++)
	{
		line(originx,0,originx,i); //vertical axis
		delay(2);
	}

	for(i=0;i<=getmaxx();i++)
	{
		line(0,originy,i,originy); //horizontal axis
		delay(2);
	}

	//
	getch();
	axesmark();
	//
	setcolor(CYAN);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    moveto(originx,originy);

	getch();

	float xcord=0;
	float ycord=0;

	for( xcord=0 ; xcord <= R ; xcord++)
	{
		ycord=(tan(a)*xcord-(tan(a)*xcord*xcord/R));
		lineto( originx + xcord/scalex , originy - ycord/scaley);

		delay(1);
	}
	getch();

	ballcontrol();

}

void ball::quicky()
{
	cleardevice();
	axesgraph();
	axesmark();
	analysis();
	ballpath();
	create();
}


void ball::ballcontrol()
{

	{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;
	}

	char key='0';
	int breakkey=0;

	while(breakkey!=1)
		{
			quicky();
			key=getch();

			switch(key)
			{

				case 'd':

						if(posx > R )
						{
							posx=0;
							posy_set();
							quicky();
							continue;
						}

						//type casted here so that integer values are compared, else decimals might mess up.

						else
						{
						      /*	int count=0;
							while( ((int)posx =< (int) R ) && (count!=10) );
							{
								posx++;
								posy_set();
								count++;
								quicky();
								delay(0.1);
							}
							*/
							posx=posx+10*scalex;
							posy_set();
							quicky();
						}

						break;


				case 'a':

						if( posx <= 0 )
						{
							posx=R;
							posy_set();
							quicky();
						}

						//type casted here so that integer values are compared, else decimals might mess up.

						else
						{
							/*int count=0;
							while(((int)posx >= 0  ) && (count!=10));
							{
								posx--;
								posy_set();
								count++;
								quicky();
								delay(0.1);
							} */
							posx=posx-10*scaley;
							posy_set();
							quicky();
						}

						break;

				case 'e':
							cleardevice();
							setbkcolor(DARKGRAY);
							setfillstyle(WIDE_DOT_FILL,LIGHTGRAY);
							bar(0,0,getmaxx(),getmaxy());
							
							setcolor(CYAN);
							settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
							settextjustify(CENTER_TEXT,BOTTOM_TEXT);
							outtextxy(getmaxx()/2,getmaxy()/2 - 40 ,"Press s to save, and any other character to exit without saving");
							char saveop=getch();

							if (saveop=='s')
							{
							saveflag=1;
							}
							else
							{
							saveflag=0;
							}
							breakkey=1;
						break;

				default:
					continue;




		}
}


}

//ball again
ball::ball()
{
	rad=20;
	color=5;
	g=10;
	a=0;
	u=0;
	posx=0;
	posy=0;
	t=0;
	H=0;
	T=0;
	R=0;
	strcpy(savename,"-");
	saveflag=0;
	mass=1;
}
ball::ball(int opt)
{


	settextstyle(SCRIPT_FONT,HORIZ_DIR,4);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(WHITE);
	mass=1;
	rad=20;
	color=5;
	g=10;
	strcpy(savename,"-");
	saveflag=0;

	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(WIDE_DOT_FILL,DARKGRAY);
	bar(0,0,getmaxx(),getmaxy());

	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(0,getmaxy()/2-50,getmaxx(),getmaxy()/2+50);

	gotoxy(35,17);
	int ktemp=0;

	switch(opt)
	{
		case 12:
		case 21:

			outtextxy(getmaxx()/2,getmaxy()/2,"Enter u and a (in degrees)");
			cin>>u>>ktemp;
			a=ktemp*3.14/180;
			R=(2*u*u*sin(a)*cos(a))/g;
			H=(u*u*sin(a)*sin(a))/(2*g);
			T=(2*u*sin(a))/g;

		break;

		case 13:
		case 31:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter u and T");
			cin>>u>>T;

			a=asin((T*g)/(2*u));
			R=(2*u*u*sin(a)*cos(a))/g;
			H=(u*u*sin(a)*sin(a))/(2*g);

		break;

		case 14:
		case 41:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter u and R");
			cin>>u>>R;

			a=(asin((g*R)/(u*u)))/2;
			H=(u*u*sin(a)*sin(a))/(2*g);
			T=(2*u*sin(a))/g;

		break;

		case 15:
		case 51:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter u and H");
			cin>>u>>H;

			a=asin(sqrt((2*g*H)/(u*u)));
			R=(2*u*u*sin(a)*cos(a))/g;
			T=(2*u*sin(a))/g;

		break;

		case 23:
		case 32:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter a(in degrees) and T");
			cin>>ktemp>>T;
			a=ktemp*3.14/180;
			u=(T*g)/(2*sin(a));
			R=(2*u*u*sin(a)*cos(a))/g;
			H=(u*u*sin(a)*sin(a))/(2*g);

		break;

		case 24:
		case 42:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter a(in degrees) and R");
			cin>>ktemp>>R;
			a=ktemp*3.14/180;
			u=sqrt((R*g)/sin(2*a));
			H=(u*u*sin(a)*sin(a))/(2*g);
			T=(2*u*sin(a))/g;

		break;

		case 25:
		case 52:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter a (in degrees) and H");
			cin>>ktemp>>H;
			a=ktemp*3.14/180;
			u=sqrt(2*g*H/(sin(a)*sin(a)));
			R=(2*u*u*sin(a)*cos(a))/g;
			T=(2*u*sin(a))/g;

		break;

		case 34:
		case 43:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter T and R");
			cin>>T>>R;

			a=atan((g*T*T)/(2*R));
			u=(T*g)/(2*sin(a));
			H=(u*u*sin(a)*sin(a))/(2*g);

		break;

		/*
		case 35:
		case 53:
			gotoxy(35,13)
			cout<<"Enter T and H";
			cin>>T>>H;



		break;

		*/

		case 45:
		case 54:
			outtextxy(getmaxx()/2,getmaxy()/2,"Enter R and H");
			cin>>R>>H;

			a=atan(4*H/R);
			u=sqrt((R*g)/sin(2*a));
			T=(2*u*sin(a))/g;

		break;

		default:
			outtextxy(getmaxx()/2,getmaxy()/2,"Error");
			introanim();

	}
}

void ball::defaultball()
{
	a=0;
	u=0;
	posx=0;
	posy=0;
	t=0;
	H=0;
	T=0;
	R=0;


}

void ball::create()
{

	{
		scalex = (R>500) ? ((long)R%500 + 1) : (1);
		scaley = (H>400) ? ((long)H%400 + 1) : (1);
		//500 se bada toh graph aadha and so

		originx=getmaxx()/8;
		originy=getmaxy()*7/8;
	}

	 setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	/* setcolor(RED);
	 circle(originx+posx,originy-posy,rad);

	 setcolor(LIGHTRED);
	 floodfill(originx+posx,originy-posy,RED);
	 */

	setcolor(LIGHTGREEN);
for(int angle=2;angle<=rad;angle=angle+5)
{

	ellipse(originx+posx/scalex,originy-posy/scaley,0,360,rad,angle);
	ellipse(originx+posx/scalex,originy-posy/scaley,0,360,angle,rad);
}
	//creates a filled ball
}


//now ill have to write a code in which the graph scales according to the range height etc so that the entrie motion fits in the picture and ill have to lable the axes according to it itll be a long code but thats the next logic a=that ill be word=king towards





void fhand::saveball(ball &b)
{

	ifstream fin("C:\\TURBOC3\\Projects\\MMNew\\SAVEFILE.dat",ios::binary);
	ofstream fout("C:\\TURBOC3\\Projects\\MMNew\\TEMP.dat",ios::binary);

	fout.write((char*)&b,sizeof(ball));

	ball beebee;

	for(int k=1;k<3;k++)
	{
		fin.read((char*)&beebee,sizeof(ball));
		fout.write((char*)&beebee,sizeof(ball));

	}
	fout.close();
	fin.close();

	remove("C:\\TURBOC3\\Projects\\MMNew\\SAVEFILE.dat");
	rename("C:\\TURBOC3\\Projects\\MMNew\\TEMP.dat","C:\\TURBOC3\\Projects\\MMNew\\SAVEFILE.dat");

	/*
	ofstream fout("C:\\TURBOC3\\Projects\\MMNew\\savefile.dat",ios::binary);
	fout.write((char*)&b,sizeof(ball));
	fout.close();
	*/
}


void fhand::loadball()
{

	ifstream fin("C:\\TURBOC3\\Projects\\MMNew\\SAVEFILE.dat",ios::binary);

	for( int j=0;j<3;j++)

	{
		fin.read((char*)&btemp[j],sizeof(ball));

	}
	/*
	fin.read((char*)&btemp[1],sizeof(ball));
	*/
	fin.close();

}

void fhand::scrollmenua()

{       cleardevice();
	menubg();
	settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(LIGHTBLUE);

	outtextxy(5*getmaxx()/8,getmaxy()/4,"Load");
	delay(50);

	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);

	setcolor(RED);
	outtextxy(5*getmaxx()/8,getmaxy()/4+80,btemp[0].savename);
	delay(10);

	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+140,btemp[1].savename);
	delay(10);

	outtextxy(5*getmaxx()/8,getmaxy()/4+200,btemp[2].savename);
	delay(10);

	outtextxy(5*getmaxx()/8,getmaxy()/4+260,"Go Back");

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
						scrollmenub(cycle);
						//this was done so that rather incrementing and messing up the while loop, we end up cycling at the first option. noice, right guiz?
					}
					else
					{
						cycle++;
						scrollmenub(cycle);
					}
					break;

				case 'w':
					if(cycle==1)
					{
						cycle=4;
						scrollmenub(cycle);
					}

					else
					{
						cycle--;
						scrollmenub(cycle);
					}
					break;

				case 13:
					{
						switch(cycle)
						{
							case 1:

							if(!strcmp(btemp[0].savename,"-"))
							continue;

							else
							{
							b_ini=btemp[0];
							b_ini.anim_graph();
							introanim();
							}

							break;

							case 2:

							if(!strcmp(btemp[1].savename,"-"))
							continue;
							else {
							b_ini=btemp[1];
							b_ini.anim_graph();
							introanim();
							}

							break;

							case 3:

							if(!strcmp(btemp[2].savename,"-"))
							continue;

							else{
							b_ini=btemp[2];
							b_ini.anim_graph();
							introanim();
							}

							break;

							case 4:
							introanim();
							break;

							default:
							continue;
						}
					}
					break;

				default:
				continue;
			}


		}

	}


}

void fhand::scrollmenub(int num)
{
	cleardevice();

	menubg();

	settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);

	setcolor(BLUE);
	outtextxy(5*getmaxx()/8,getmaxy()/4,"Load");

	settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,4);

	if(num==1)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+80,btemp[0].savename);



	if(num==2)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+140,btemp[1].savename);



	if(num==3)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+200,btemp[2].savename);


	if(num==4)
	setcolor(RED);
	else
	setcolor(LIGHTGRAY);
	outtextxy(5*getmaxx()/8,getmaxy()/4+260,"Go Back");

}




