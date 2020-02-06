#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int b=300,c=400,d=300,e=100,f=300,g=250,i=0,dis1=100,dis2=100;
int xvel=0,yvel=0,p1=0,p2=0;
FILE *p;
void pause();
void ball();
char p1s[100],p2s[100];
char choice;
void disp();
void end_game();
void quit();
void player2();
void frst_pg()
{
    char back;
    choice='\0';
    game_pg: moveto(150,200);
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    if(back!='b')
    {
        outtext("GLOW HOCKEY");
        getch();
    }
    back='\0';
    cleardevice();
    moveto(150,50);
    outtext("GLOW HOCKEY");
    setcolor(BLUE);
    moveto(175,175);
    outtext("1.New Game");
    moveto(175,225);
    outtext("\n2.Resume Game");
    moveto(175,275);
    outtext("\n3.Instructions");
    do
    {
        choice=getch();

    }while(choice!='1'&&choice!='2'&&choice!='3');
    if(choice=='3')
    {
        cleardevice();
        setcolor(BLUE);
        moveto(140,100);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
        outtext("INSTRUCTIONS");
        setcolor(YELLOW);
        moveto(80,150);
        settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
        outtext("For player 1 'w','a','s','d' movement");
        moveto(20,175);
        outtext("Keys are used.For player 2 'i','j','k,'l' keys are");
        moveto(18,200);
        outtext(" used same as player 1.Hit 5 goals to win");
        moveto(20,225);
        outtext("'q' for quit. Press 'b' for back");
        do
        {
            back=getch();
        }
        while(back!='b');
        cleardevice();
        goto game_pg;
    }
    if(choice=='2')
    {
         p=fopen("resume.txt","r");
        fscanf(p,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&b,&c,&d,&e,&f,&g,&xvel,&yvel,&p1,&p2,&i,&dis1,&dis2);
        fclose(p);
        disp();
        outtextxy(176,225,"Game Starts in :3s");
        delay(1000);
        cleardevice();
        disp();
        outtextxy(176,225,"Game starts in :2s");
        delay(1000);
        cleardevice();
        disp();
        outtextxy(176,225,"Game starts in :1s");
        delay(1000);
        cleardevice();
        disp();
        player2();
    }

}
void disp()
{
    cleardevice();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(BLUE);
    moveto(225,10);
    outtext("P1 : ");
    sprintf(p1s,"%d",p1);
    outtext(p1s);
    outtext(" P2 : ");
    sprintf(p2s,"%d",p2);
    outtext(p2s);
	setbkcolor(GREEN);
	setcolor(WHITE);
	line(175,50,175,450);
	line(175,50,240,50);
	line(425,50,425,450);
	line(175,450,240,450);
	line(360,450,425,450);
	setcolor(RED);
	line(175,250,425,250);
	setcolor(BLUE);
	arc(300,50,180,360,60);
	arc(300,450,0,180,60);
	setcolor(WHITE);
	line(360,50,425,50);
	setcolor(BLUE);
	circle(300,250,60);
	setcolor(BROWN);
	setfillstyle(SOLID_FILL,BROWN);
	circle(b,c,25);
	floodfill(b+1,c+1,BROWN);
	setcolor(CYAN);
	setfillstyle(SOLID_FILL,CYAN);
	circle(d,e,25);
	floodfill(d,e,CYAN);
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(f,g,15);
	floodfill(f+1,g+1,YELLOW);
}
void player2();
void player1()
{
    disp();
    if(p2==5)
    {
        cleardevice();
        end_game();
    }
	char a;
	delay(50);
	dis1=sqrt(pow(f-b,2)+pow(g-c,2));
	while(kbhit())
	{
		cleardevice();
		disp();
		a=getch();
		if(a=='w'&&c>275)
		{
            if(dis1>=40||!(c>g))
                c-=20;
		}
		else if(a=='a'&&b>200)
		{
            if(dis1>=40||!(b>f))
                b-=20;
		}
		else if(a=='s'&&c<415)
		{
		        if(dis1>=40||!(g>c))
                c+=20;
		}
		else if(a=='d'&&b<400)
		{
            if(dis1>=40||!(f>b))
              b+=20;
		}
		else if(a=='q')
		{
		    quit();
		}
		else if(a=='p')
		{
		    pause();
		}
		goto autoply1;

	}
	a='h';
	autoply1:
	ball();
}
void pause()
{
    char pause;
    do
    {
        pause=getch();
        pause=tolower(pause);
    }while(pause!='p');
}
void ball()
{

        if(g<=65&&f>=240&&f<=360)
        {
            cleardevice();
            outtext("Player one scores goal");
            delay(200);
            cleardevice();
            p1++;
            f=300;
            g=200;
            i=0;
            xvel=0;
            yvel=0;
            b=300;
            c=400;
            d=300;
            e=100;
            disp();
            delay(200);
            player2();
        }
        else if(g>=435&&f>=240&&f<=360)
        {
            cleardevice();
            outtext("Player two scores goal");
            delay(200);
            p2++;
            cleardevice();
            f=300;
            g=300;
            xvel=0;
            yvel=0;
            d=300;
            e=100;
            b=300;
            c=400;
            disp();
            delay(200);
            i=1;
            player1();
        }
        if(dis1<=40)
        {

            xvel=(f-((5*b+3*f)/8))/2;
            yvel=(g-((5*c+3*g)/8))/2;
        }
        if(dis2<=40)
        {
            xvel=(f-(5*d+3*f)/8)/2;
            yvel=(g-(5*e+3*g)/8)/2;
        }
        if((f+xvel<=190))
        {
            f=190;
            disp();
            delay(30);
            xvel=-(xvel);
        }
        if((f+xvel)>=410)
        {
            f=410;
            disp();
            delay(30);
            xvel=-(xvel);
        }

        if((g+yvel<=65)&&(f<240||f>360))
        {
            g=65;
            disp();
            delay(30);
            yvel=-(yvel);
        }
        if((g+yvel)>=435&&(f<240||f>360))
        {
            g=435;
            disp();
            delay(30);
            yvel=-(yvel);
        }
        f+=xvel;
        g+=yvel;
            if(i%2==0)
            {
                i++;
                player1();
            }
            else
            {
                i++;
                player2();
            }
}
void player2()
{
    disp();
    if(p1==5)
    {
        cleardevice();
        end_game();
    }
    char a;
    delay(50);
	dis2=sqrt(pow(f-d,2)+pow(e-g,2));
	while(kbhit())
	{
		cleardevice();
		disp();
		a=getch();
		if(a=='i'&&e>85)
		{
            if(dis2>=40||!(e>g))
                e-=20;
		}
		else if(a=='j'&&d>200)
		{
            if(dis2>=40||!(d>f))
                d-=20;
		}
		else if(a=='k'&&e<225)
		{
            if(dis2>=40||!(g>e))
                e+=20;
		}
		else if(a=='l'&&d<400)
		{
		    if(dis2>=40||!(f>d))
			d+=20;
		}
		else if(a=='q')
		{
		    quit();
		}
		else if(a=='p')
		{
		    pause();
		}
    goto riyaz;
	}
	a='c';
	riyaz:
    ball();
}
void end_game()
{
    delay(200);
    moveto(100,200);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    if(p1==5)
        outtext("PLAYER ONE WON");
    else
        outtext("PLAYER TWO WON");
        delay(300);
    getch();
    exit(0);
}
void quit()
{
    p=fopen("resume.txt","w");
    fprintf(p,"%d %d %d %d %d %d %d %d %d %d %d %d %d",b,c,d,e,f,g,xvel,yvel,p1,p2,i,dis1,dis2);
    fclose(p);
    exit(0);
}
main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   int choose;
   setbkcolor(GREEN);
   cleardevice();
    frst_pg();
    srand(time(0));
	choose=rand()%2;
        if(choose==0)
        {
            g=200;
            disp();
            player2();
        }
        else
        {
            g=300;
            disp();
            player1();
        }
        getch();
        closegraph();
}
