void credit_anim()
{
	int i;
	//loading in the grey background

	setbkcolor(WHITE);
	setfillstyle(WIDE_DOT_FILL,GREEN);
	bar(0,0,getmaxx(),getmaxy());




	//loading stripes


	settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(WHITE);

	setfillstyle(INTERLEAVE_FILL,DARKGRAY);

	for(i=0;i<=(getmaxx()/2);i=i+2)
	{

	bar(getmaxx()/2-i,getmaxy()/4-60,getmaxx()/2+i,getmaxy()/4+20);
	outtextxy(getmaxx()/2,getmaxy()/4,"CREDITS");
	delay(0.01);

	}

	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(40,getmaxy()/2-40,getmaxx()-40,getmaxy()/2+160);

	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(WHITE);
	{
	outtextxy(getmaxx()/2,getmaxy()/2,"This project is made solely by Sparsh, Ansh");
	outtextxy(getmaxx()/2,getmaxy()/2+20,"And Samrath Jain.");
	outtextxy(getmaxx()/2,getmaxy()/2+40,"This program aims to simulate.");
	outtextxy(getmaxx()/2,getmaxy()/2+60,"the mechanics of a projectile.");
	outtextxy(getmaxx()/2,getmaxy()/2+100,"La Canada High School, stackoverflow.com,");
	outtextxy(getmaxx()/2,getmaxy()/2+120,"youtube.com, wikipedia.org, TurboC++ and Dev-C++.");
	}

	settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
	settextjustify(CENTER_TEXT,BOTTOM_TEXT);
	setcolor(RED);
	outtextxy(getmaxx()/2,getmaxy()/2+140,"Press escape to return to menu.");

	while(1)
	{
		char c;
		if(kbhit())
		{
			c=getch();

			if(c==27)
			{
				titleanim();
			}
			else
			{
				continue;
			}
		}
	}
}

