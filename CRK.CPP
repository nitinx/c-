//CRICKET : Developed by Nitin <nitinpai81@yahoo.com>
//
//OBJECT OF THE GAME :
// The player 1st has to choose 2 teams. By default it is a 60-ball game. The
// player has to enter a number between 1-6 and corresponding to the number a
// random number(run) would be generated and added to the total. The team with
// more runs wins!!! The progress of each team is shown graphically.
// Best Of Luck!!
// To execute this game the graphic files *.chr, *.bgi and bgiobj.exe need to
// be in the same directory

#include <graphics.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

char teams[11][13]={"Australia","Bangladesh","England","India","New Zealand","Pakistan","South Africa","Sri Lanka","West Indies","Zimbabwe"};

void drawpoly(int c1,int c2,int c3, int c4,int c)
{
	int poly[8];
	poly[0] = poly[6] = c1;			poly[1] = poly[3] = c2;
	poly[4] = poly[2] = c3;			poly[5] = poly[7] = c4;
	setfillstyle(SOLID_FILL,c);
	fillpoly(4,poly);
}

void drawpoly1(int c1,int c2,int c3, int c4,int c)
{
	int poly[8];
	poly[0] = poly[6] = c1;			poly[1] = poly[3] = c2;
	poly[4] = poly[2] = c3;			poly[5] = poly[7] = c4;
	setfillstyle(EMPTY_FILL,c);
	fillpoly(4,poly);
}

int menu(int team)
{
	int i,j,ch,a=145+(team*200),b=70,c=265+(team*200);
	static int d;
	char ch1,ch2,temp[10];

	if(team == 0)
	{
		cleardevice();
		setbkcolor(BLACK);
		setcolor(WHITE);
		settextstyle(SMALL_FONT,HORIZ_DIR,5);

		outtextxy(155,20,"Team #1");
		outtextxy(355,20,"Team #2");

		for(i=0;i<2;i++)
		{
			for(j=0;j<10;j++)
			{
				strcpy(temp,teams[j]);
				outtextxy(150+(i*200),70+(j*20),temp);
			}
		}
	}
	drawpoly1(a,b,c,b+20,WHITE);

	do
	{
		ch1 = getch();

		if(int(ch1) == 13)
		{
			if(team == 1)
			{
				if(d == ((b - 70) / 20))
					outtextxy(165,340,"Invalid Choice! Select another team...");
				else
				{
					d = (b - 70) / 20;
					outtextxy(350,320,teams[d]);
					outtextxy(180,390,"Press any key to continue...");
					break;
				}
			}
			else
			{
				d = (b - 70) / 20;
				outtextxy(150,320,teams[d]);
				outtextxy(260,320,"Vs.");
				break;
			}
		}
		else if(int(ch1) == 0)
		{
			ch2 = getch();

			switch(int(ch2))
			{
				case 72	:
				case 75	:   setcolor(BLUE);
							drawpoly1(a,b,c,b+20,BLACK);
							if(b == 70)			b = 250;
							else                b = b - 20;
							setcolor(WHITE);
							drawpoly1(a,b,c,b+20,WHITE);
							break;
				case 77	:
				case 80	:   setcolor(BLUE);
							drawpoly1(a,b,c,b+20,WHITE);
							if(b == 250)        b = 70;
							else                b = b + 20;
							setcolor(WHITE);
							drawpoly1(a,b,c,b+20,WHITE);
			}
		}
	}while(int(ch1) != 13 || int(ch1) != 0);
	getch();
	return d;
}

void frame(char team1[20],char team2[20])
{
	char temp[50];
	cleardevice();
	drawpoly(1,1,638,478,BLACK);			//Full Frame
	drawpoly(4,4,635,52,LIGHTCYAN);			//Heading Frame
	drawpoly(4,55,57,475,YELLOW);			//Sp!Ze Frame
	drawpoly(60,55,245,110,RED);			//Score Frame
	drawpoly(248,55,380,110,GREEN);			//Run Frame
	drawpoly(60,113,380,137,BLUE);			//Predict
	drawpoly(383,260,635,340,LIGHTRED);		//Stat Frame
	drawpoly(429,343,496,440,RED);			//Misc#1 Frame
	drawpoly(383,55,635,257,BLACK);			//Graph Worm
	drawpoly(60,363,426,440,BLUE);			//Runs Frame
	drawpoly(499,343,635,440,GREEN);		//Optionz Frame
	drawpoly(60,140,380,360,CYAN);			//Graph Tower
	drawpoly(60,443,635,475,YELLOW);		//Status Frame

	line(60,240,380,240);	//Graphtower
	line(80,140,80,340);
	line(80,340,380,340);
	line(400,240,620,240);	//Graphworm
	line(400,240,400,70);

	setcolor(BLACK);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	strcat(strcat(strcpy(temp,team1)," Vs. "),team2);
	outtextxy(20,2,temp);

	settextstyle(TRIPLEX_FONT,VERT_DIR,4);
	outtextxy(10,170,"Sp!Ze Cup");

	setcolor(WHITE);
	settextstyle(SMALL_FONT,VERT_DIR,5);
	outtextxy(61,150,"Runs ---->");
	outtextxy(61,255,"Runs ---->");
	outtextxy(384,160,"Runs ---->");

	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(80,342,"Balls ---->");
	outtextxy(400,241,"Balls ---->");

	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(538,360,"OPTIONZ");
	outtextxy(525,375,"1-6 : Runs");
	outtextxy(540,390,"S : Diff Stat");
	outtextxy(540,405,"A : About");
	outtextxy(540,420,"Q : Quit");
}

void dispruns(int f,int score[2],int balls[2],char tmp[2][13],int totballs,int r[2][6])
{
	int i;
	char temp[20];
	drawpoly(60,363,426,440,BLUE);
	line(60,397,426,397);
	line(165,363,165,440);
	line(320,363,320,440);

	if(f == 1)
		dispruns(0,score,balls,tmp,totballs,r);

	outtextxy(210,363,"Break Up");
	outtextxy(345,363,"Run Rate");
	outtextxy(330,380,"Curr.");
	outtextxy(380,380,"Reqd.");
	outtextxy(170,380,"0s");
	outtextxy(195,380,"1s");
	outtextxy(220,380,"2s");
	outtextxy(245,380,"3s");
	outtextxy(270,380,"4s");
	outtextxy(295,380,"6s");

	outtextxy(65,400+(f*20),tmp[f]);
	for(i=0;i<6;i++)
	{
		itoa(r[f][i],temp,10);
		outtextxy(170+(i*25),400+(f*20),temp);
	}

	gcvt(float(score[0])/float(balls[0]),3,temp);
	outtextxy(335,400,temp);
	strcpy(temp," - ");
	outtextxy(390,400,temp);

	if(f == 1)
	{
		gcvt(float(score[1])/float(balls[1]),3,temp);
		outtextxy(335,420,temp);

		if(balls[1] < totballs)
			gcvt(float(score[0]+1-score[1])/float(totballs-balls[1]),3,temp);
		outtextxy(390,420,temp);
	}
}

void dispscore(int f,int score[2],int balls[2],char team[2][13],int totballs)
{
	char temp[10],temp1[10];
	drawpoly(60,55,245,110,RED);

	outtextxy(80,60,team[0]);
	itoa(score[0],temp,10);
	itoa(balls[0]-(balls[0]/totballs),temp1,10);
	strcat(strcat(temp," ("),strcat(temp1,")"));
	outtextxy(180,60,temp);

	outtextxy(80,85,team[1]);
	if(f == 1)
	{
		itoa(score[1],temp,10);
		itoa(balls[1],temp1,10);
		strcat(strcat(temp," ("),strcat(temp1,")"));
		outtextxy(180,85,temp);
	}
	else
		outtextxy(180,85,"-");
}

void predict(int f,int score[2],int balls[2],char tmp[2][13],int totballs)
{
	char temp[50],temp1[10];
	drawpoly(60,113,380,137,BLUE);
	strcpy(temp,"At This Rate:");
	strcat(temp,tmp[f]);

	if(f == 0)
	{
		strcat(temp," would reach ");
		itoa(((float(score[0])/float(balls[0]))*totballs),temp1,10);
		strcat(temp,temp1);
	}
	else
	{
		if(((float(score[1])/float(balls[1]))*totballs) > score[0])
			strcat(temp," would Win!");
		else
			strcat(temp," would Lose!");
	}
	outtextxy(65,117,temp);
}

void disprun(int run)
{
	drawpoly(248,55,380,110,GREEN);
	setcolor(BLACK);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);

	switch(run)
	{
		case 0 :	outtextxy(280,65,"NO RUN");
					break;
		case 1 :	outtextxy(280,65,"SINGLE");
					break;
		case 2 :	outtextxy(300,65,"TWO");
					break;
		case 3 :	outtextxy(280,65,"THREE");
					break;
		case 4 :	outtextxy(290,65,"FOUR");
					break;
		case 6 :	outtextxy(290,65,"SIX");
	}
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
}

void graphtower(int f,int run,int balls)
{
	int b,h;
	static int c=0;

	if((f == 0) && (run == 0) && (balls == 0))
		c = 0;
	else
	{
		b = (300 / balls);
		h = (run * 15);
		drawpoly(80+(b*(c-(f*balls))), 240+(90*f)+(f*10), 80+b+(b*(c-(f*balls))), (240-h)+(90*f)+(f*10), RED);
		c++;
	}
}

void graphworm(int f,int run,int balls)
{
	int b;
	static int c=0,h=240;

	if((f == 0) && (run == 0) && (balls == 0))
	{
		c = 0;
		h = 240;
	}
	else
	{
		if(f == 0)			setcolor(LIGHTGREEN);
		else                setcolor(LIGHTRED);

		if((f == 1) && (c == balls))
			h = 240;

		b = (210 / balls);
		h = h - (run * 1);
		line(400+(b*(c-(f*balls))),h+(run),400+b+(b*(c-(f*balls))),h);
		c++;
		setcolor(WHITE);
	}
}

void miscstats(int f,char team[2][13])
{
	int i,j,ra,stat[4];
	char temp[50],temp1[13];
	drawpoly(383,260,635,340,LIGHTRED);
	ifstream fin;

	fin.open("stats.dat");
	if(!fin)
	{
		ofstream fout;
		fout.open("stats.dat");
		for(i=0;i<10;i++)
		{
			for(j=0;teams[i][j]!='\0';j++)
				if((teams[i][j] == ' ') && (teams[i][j+1] != ' '))
					teams[i][j] = '_';
			fout << teams[i] << "\t" << 0 << "\t" << 360 << "\t" << 0 << "\t" << 0 << "\n" ;
		}
		fout.close();
	}
	else
		fin.close();

	ra = random(4);
	outtextxy(386,260,"STATS :");
	for(f=0;f<2;f++)
	{
		fin.open("stats.dat");
		for(i=0;i<10;i++)
		{
			fin >> temp1;
			for(j=0;j<4;j++)
				fin >> stat[j];
			for(j=0;temp1[j]!='\0';j++)
				if((temp1[j] == '_') && (teams[i][j+1] != ' '))
					temp1[j] = ' ';

			if(stricmp(team[f],temp1) == 0)
				break;
		}

		itoa(stat[ra],temp1,10);
		switch(ra)
		{
			case 0 :    strcat(strcat(strupr(strcpy(temp,team[f])),"'s Highest Total : "),temp1);
						break;
			case 1 :    strcat(strcat(strupr(strcpy(temp,team[f])),"'s Lowest Total : "),temp1);
						break;
			case 2 :    strcat(strcat(strcat(strcpy(temp,"Max 4s by "),strupr(team[f]))," : "),temp1);
						break;
			case 3 :	strcat(strcat(strcat(strcpy(temp,"Max 6s by "),strupr(team[f]))," : "),temp1);
		}

		if((stat[ra] == 0) || (stat[ra] == 360))
			strcat(strcpy(temp,team[f]),": No Stats available!");
		outtextxy(386,280+(f*20),temp);
		fin.close();
	}
}

void writestats(char team[2][13],int score[2],int r[2][6])
{
	ifstream fin;
	ofstream fout;
	int i,j,c,stat[11][4];
	char temp1[15];

	for(i=0;i<2;i++)
		for(j=0;team[i][j]!='\0';j++)
			if((team[i][j] == ' ') && (team[i][j+1] != ' '))
				team[i][j] = '_';

	fin.open("stats.dat");
	for(i=0;i<10;i++)
	{
		fin >> temp1;
		for(j=0;j<4;j++)
			fin >> stat[i][j];
		for(j=c=0;j<2;j++)
			if(strcmpi(temp1,team[j]) == 0)
			{
				if(stat[i][0] < score[j])		stat[i][0] = score[j];
				if(stat[i][1] > score[j])       stat[i][1] = score[j];
				if(stat[i][2] < r[j][4])        stat[i][2] = r[j][4];
				if(stat[i][3] < r[j][5])        stat[i][3] = r[j][5];
				c++;
				if(c == 2)		break;
			}
	}
	fin.close();

	fout.open("stats.dat");
	for(i=0;i<10;i++)
	{
		for(j=0;teams[i][j]!='\0';j++)
			if((teams[i][j] == ' ') && (teams[i][j+1] != ' '))
				teams[i][j] = '_';
		fout << teams[i];
		for(j=0;j<4;j++)
			fout << "\t" << stat[i][j];
		fout << "\n";
	}
	fout.close();

	for(i=0;i<10;i++)
		for(j=0;teams[i][j]!='\0';j++)
			if(teams[i][j] == '_')
				teams[i][j] = ' ';
}

void about()
{
	setcolor(WHITE);
	drawpoly(60,140,380,360,CYAN);
	drawpoly(60,443,635,475,YELLOW);
	setcolor(BLACK);
	line(61,160,379,160);
	line(61,215,379,215);
	line(61,270,379,270);
	outtextxy(65,440,"Press any key to continue...");

	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(200,140,"ABOUT");
	outtextxy(65,165,"This s/w was developed by Nitin,");
	outtextxy(65,190,"& is FREEWARE [:)]");
	outtextxy(65,220,"Comments & Suggestions Welcome...");
	outtextxy(65,240,"Want 2 develop Software/Gamez ??");
	outtextxy(65,275,"Contact me by :");
	outtextxy(95,295,"E-Mail : <nitinpai81@yahoo.com>");
	outtextxy(95,315,"Net    : www.thintin.net");
	outtextxy(95,335,"ICQ#   : 33636427");

	getch();
}

void main(void)
{
	int score[2]={0},balls[2]={0},runs[6]={0},r[2][6]={0},totballs=60;
	int i,j,team,chn,gdriver = DETECT,gmode;
	char ch,ch1,ch2,temp[40],temp1[40],teamsp[2][13];

	initgraph(&gdriver,&gmode,"");

	for(team=0;team<=1;team++)
	{
		chn = menu(team);
		strcpy(teamsp[team],teams[chn]);
	}

	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);

	frame(teamsp[0],teamsp[1]);

	for(team=0;team<2;team++)
	{
		for(balls[team]=1;balls[team]<=totballs;balls[team]++)
		{
			for(i=0;i<6;i++)
			{
				runs[i] = random(7);
				if(runs[i] == 5)
					do
					{
						runs[i] = random(7);
					}while(runs[i] == 5);
			}

			do
			{
				ch = toupper(getch());
			}while(ch!='1' && ch!='2' && ch!='3' && ch!='4' && ch!='5' && ch!='6' && ch!='A' && ch!='S' && ch!='Q');

			switch(ch)
			{
				case '1' :  chn = 0;
							break;
				case '2' :	chn = 1;
							break;
				case '3' :  chn = 2;
							break;
				case '4' :  chn = 3;
							break;
				case '5' :  chn = 4;
							break;
				case '6' :  chn = 5;
							break;
				case 'S' :  if(totballs == 60)
								miscstats(team,teamsp);
							balls[team]--;
							continue;
				case 'Q' :  setcolor(BLACK);
							settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
							outtextxy(70,440,"Quit (Y/N) : ");

							do
							{
								ch = tolower(getch());
							}while(ch!='y' && ch!='n');

							if(ch == 'y')
							{
								about();
								closegraph();
								exit(1);
							}
							else
								drawpoly(60,443,635,475,YELLOW);
				default  : ;

			}
			score[team] = score[team] + runs[chn];
			r[team][runs[chn]-(runs[chn]/5)]++;

			disprun(runs[chn]);
			graphtower(team,runs[chn],totballs);
			graphworm(team,runs[chn],totballs);
			predict(team,score,balls,teamsp,totballs);
			dispscore(team,score,balls,teamsp,totballs);
			dispruns(team,score,balls,teamsp,totballs,r);

			if(totballs == 60)
				miscstats(team,teamsp);

			if(team == 1)
				if(score[team] > score[team-1])
					break;
		}
	}

	if(score[0] > score[1])
	{
		itoa((score[0]-score[1]),temp1,10);
		strcat(strcat(strcat(strcpy(temp,teamsp[0])," wins by "),temp1)," run(s)!");
	}
	else if(score[0] < score[1])
	{
		itoa((totballs-balls[1]),temp1,10);
		strcat(strcat(strcat(strcpy(temp,teamsp[1])," wins with "),temp1)," ball(s) to spare!");
	}
	else
		strcpy(temp,"Itz a TIE!!!");

	if(totballs == 60)
		writestats(teamsp,score,r);

	setcolor(BLACK);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	outtextxy(70,440,temp);
	getch();

	drawpoly(60,443,635,475,YELLOW);
	outtextxy(70,440,"Play Again (Y/N) :");

	do
	{
		ch = tolower(getch());
	}while(ch!='y' && ch!='n');

	if(ch == 'y')
	{
		graphtower(0,0,0);
		graphworm(0,0,0);
		closegraph();
		main();
	}
	else
		about();

	closegraph();
}