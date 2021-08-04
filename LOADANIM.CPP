void load_animation(int s,int maxx,int maxy, float ac);
void square(int centx, int centy,int a, int inc);


void square(int centx, int centy,int a, int inc)
	{
	bar(centx-a/2+inc,centy-a/2+inc,centx+a/2-inc,centy+a/2-inc);
	}

void load_animation(int s, int centx, int centy, float ac=1)
{

	//maxx and maxy are the coordinates of the centre of central square

	int i;
	for(i=0;ac*i<=40*s/20;i++)
		{

			/*if (i<=10)
				square(cx,cy,20,i);
			else
				square(cx,cy,20,20-i);
			*/


			//code likhne mein aalas so to generalize the loading sequence for sqaure of side 20 im rather multiplying all constants by *s/20

			//left,down

			if ((ac*i>=0*s/20)&&(ac*i<=10*s/20))
				square(centx-s,centy+s,s,ac*i);
			else if ((ac*i>10*s/20)&&(ac*i<=20*s/20))
				square(centx-s,centy+s,s,20*s/20-ac*i);
			else
				square(centx-s,centy+s,s,0);


			//left,mid and mid,down

			if ((ac*i>=5*s/20)&&(ac*i<=15*s/20))
				{
			//left mid
				square(centx-s,centy,s,ac*i-5*s/20);
			//mid,down
				square(centx,centy+s,s,ac*i-5*s/20);
				}

			else if ((ac*i>15*s/20)&&(ac*i<=25*s/20))

				{
				square(centx-s,centy,s,25*s/20-ac*i);
				square(centx,centy+s,s,25*s/20-ac*i);
				}
			else
				{
				square(centx-s,centy,s,0);
				square(centx,centy+s,s,0);
				}






			//left,top and centre and right,down


			if ((ac*i>=10*s/20)&&(ac*i<=20*s/20))
				{
			//left,top
				square(centx-s,centy-s,s,ac*i-10*s/20);
			//centre
				square(centx,centy,s,ac*i-10*s/20);
			//right,down
				square(centx+s,centy+s,s,ac*i-10*s/20);

				}

			else if ((ac*i>20*s/20)&&(ac*i<=30*s/20))

				{
				square(centx-s,centy-s,s,30*s/20-ac*i);
				square(centx,centy,s,30*s/20-ac*i);
				square(centx+s,centy+s,s,30*s/20-ac*i);

				}
			else
				{
				square(centx-s,centy-s,s,0);
				square(centx,centy,s,0);
				square(centx+s,centy+s,s,0);

				}



			//mid,top and right,mid

			if ((ac*i>=15*s/20)&&(ac*i<=25*s/20))
				{
			//right,mid
				square(centx+s,centy,s,ac*i-15*s/20);
			//mid,top
				square(centx,centy-s,s,ac*i-15*s/20);
				}

			else if ((ac*i>25*s/20)&&(ac*i<=35*s/20))

				{
				square(centx+s,centy,s,35*s/20-ac*i);
				square(centx,centy-s,s,35*s/20-ac*i);
				}
			else
				{
				square(centx+s,centy,s,0);
				square(centx,centy-s,s,0);
				}



			//right,top

			if ((ac*i>=20*s/20)&&(ac*i<=30*s/20))
				square(centx+s,centy-s,s,ac*i-20*s/20);
			else if ((ac*i>30*s/20)&&(ac*i<=40*s/20))
				square(centx+s,centy-s,s,40*s/20-ac*i);
			else
				square(centx+s,centy-s,s,0);




			delay(40);
			cleardevice();
		}






}


/*
void main()
	{
	clrscr();
	initialize();
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL,DARKGRAY);

	int p=getmaxx()/2;
	int q=getmaxy()/2;

	for(int k=1;k<=3;k++)
		{
		load_animation(20,p,q,1);
		}

	closegraph();

	}
*/