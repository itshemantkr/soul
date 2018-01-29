#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iomanip.h>
//#define gotoxy gt
#define tc textcolor
#define tb textbackground
union REGS i,o;
//________________________________functions_________________________
int intmouse();
char whatDay (int);
int isLeapYear (int);
int numOfDaysInMonth (int,int);
void printHeader (int);
void printMonth (int, int&);
void skip (int);
void skipToDay (int);
void inside();
void disaster ();
void man();
void showptr();
long int fact(int a);
void line();
void equation( int );
void pascal_tri();
void multiple();
void equa( int );
void PGCD_PPCM( int );
PGCD(int,int);
void Arrangement();
void Combination();
void sort(int);
void star();
void discount();
void deci_num();
void sum_def_ma(int);
void product_ma();
void unit_digo_ma(int);
void upper_lower_ma(int);
void sum(int);
void system(int);
void prime_odd_even(int);
void max_min();
int d[33][33];
void calci();
void calen();
//_________________________________________________________________
class nw
{
	char name[40],phn[13];
	public :
	void getdata()
	{	gotoxy(32,10); cprintf("Name :"); gets(name);
			gotoxy(32,14); cprintf("Phone : ");gets(phn);
	}

};
//_______________________________MOUSE___________________________
int intmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return (o.x.ax);
}
void posi(int &xpos,int &ypos,int &click)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	click=o.x.bx;
	ypos=o.x.dx;
	xpos=o.x.cx;
}
void showptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

//________________________________NEW USER ________________________________
void user()
{	char ch[30];  ofstream fout("papu");
	clrscr();gotoxy(32,5); cprintf("ENTER DETAILS");
	gotoxy(31,6);cprintf("%s_____________%s",char(17),char(18));
	nw A; A.getdata();clrscr(); gotoxy(27,8);cprintf("Enter password :");
	for(int i=0;ch[i]!='\n';i++)
	{	ch[i]=getch();
		if(ch[i]=='\n') break;
		else {  cout<<"*";	fout<<ch[i];	}
	}
	fout.close();
	gotoxy(27,12);cprintf("SUCCESS !!");getch(); inside();
}
//________________________________OLD USER______________________
void olu()
{
	clrscr();gotoxy(32,5); cprintf("ENTER DETAILS");
	gotoxy(31,6);cprintf("%s_____________%s",char(17),char(18));
	nw A;A.getdata();
	char ch[40];
	clrscr();gotoxy(32,10);cprintf("Welcome ");
}
//________________________________INSIDE ROOT________________________
void inside()
{       char ch; int b=6,xpos,ypos,click;
	int gdriver = DETECT,gmode,x,y,i;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	for(i=30;i<200;i++)
	{
		delay(10);
		setcolor(i/10); arc(x,y,0,180,i-10);
	}
	initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");
	int status=intmouse();
	if(status==0) cout<<"No Mouse detected !";
	else {	showptr();cleardevice();setcolor(WHITE);setbkcolor(BLACK);closegraph(); getch();}
	tb(15);tc(00);clrscr();
	showptr();
	gotoxy(27,6);cprintf("%c Apps",char(5));
	gotoxy(27,8);cprintf("%c Fun",char(5));
	gotoxy(27,10);cprintf("%c Office",char(5));
	gotoxy(27,12);cprintf("%c Exit",char(5));
  getch();
}

//____________________________________WELCOME SCREEN_______________
void wel_sc()
{    	tb(15);tc(00);clrscr();
	char arr[20]={'W','E','L','C','O','M','E',' ','T','O',' ','S','O','U','L','\0'};
	for(int i=0;i<=16;++i)
	{	gotoxy(27+i,10);cprintf("%c",arr[i]);delay(50);	}
	getch();  clrscr();
	gotoxy(16,7);cprintf(" ÛÛÛÛÛÛÛÛÛÛÛÛ ÜÛÛÛÛÛÛÛÜ ßÛÛß   ßÛÛß ÜÛÛÛÛÛÛÛÜ ßÛÛß   ßÛÛß");
	delay(200);
	gotoxy(16,8);cprintf(" ß    ÛÛ    ß ÛÛ     ÛÛ  ÛÛ     ÛÛ  ÛÛ     ÛÛ  ÛÛ     ÛÛ");
	delay(200);
	gotoxy(16,9);cprintf("      ÛÛ      ÛÛ     ÛÛ  ÛÛ     ÛÛ  ÝÞ     ÝÞ  ÛÛÛÛÛÛÛÛÛ");
	delay(200);
	gotoxy(16,10);cprintf("      ÛÛ      ÛÛ     ÛÛ  ÛÛ     ÛÛ  ÛÛ     ÜÜ  ÛÛ     ÛÛ")    ;
	delay(200);
	gotoxy(16,11);cprintf("    ÜÜÛÛÜÜ    ßÛÛÛÛÛÛÛß  ßÛÛÛÛÛÛÛß  ßÛÛÛÛÛÛÛß ÜÛÛÜ   ÜÛÛÝ")    ;
	delay(550);	clrscr();
	gotoxy(27,7);cprintf("	ÛÛÛÛÛÛÛ  ÛÛÛÛÛÛ    ÛÛÛÛÛÛ   ÛÛ");
	delay(200);
	gotoxy(27,8);cprintf("	ÛÛ       ÛÛ        ÛÛ       ÛÛ");
	delay(200);
	gotoxy(27,9);cprintf("	ÛÛÛÛÛ    ÛÛÛÛÛÛ    ÛÛÛÛÛÛ   ÛÛ");
	delay(200);
	gotoxy(27,10);cprintf("	ÛÛ       ÛÛ        ÛÛ       ÛÛ");
	delay(200);
	gotoxy(27,11);cprintf("	ÛÛ       ÛÛÛÛÛÛ    ÛÛÛÛÛßÝ  ÛÛÛÛÛßÝ");
	delay(550);	clrscr();
	gotoxy(27,7);cprintf("	ÛÛ      ÛÛ   ÛÛ    ÛÛ   ÛÛÛÛÛÛ");
	delay(150);
	gotoxy(27,8);cprintf("	ÛÛ      ÛÛ    ÛÛ  ÛÛ    ÛÛÛÛ");
	delay(150);
	gotoxy(27,9);cprintf("	ÛÛ      ÛÛ     ÛÛÛÛ     ÛÛ");
	delay(150);
	gotoxy(27,10);cprintf("	ÛÛÛÛÛÛ  ÛÛ      ÛÛ      ÛÛÛÛÛÛ");
	delay(600);	clrscr();
	{       //********************MOUSE //*********
		int xpos,ypos,click;
		gotoxy(32,10); cprintf("%c New ",char(5)); gotoxy(32,13);cprintf("%c Existing user",char(5));getch();

		int gdriver = DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
		showptr();cleardevice();setcolor(WHITE);setbkcolor(BLACK);
		posi(xpos,ypos,click);getch();
	      // 	do
		//{
			//if((xpos>=31 && xpos<=35 && ypos==10) || (xpos>=31 && xpos<=40 && ypos==13)
	     /*	abc:
		while(click==0)	posi(xpos,ypos,click);
	       //while(click==1 || click==2 || click==3)
		if((xpos>=31 && xpos<=35 && ypos==10))	user();
		else if((xpos>=31 && xpos<=40 && ypos==13)) olu();
		else goto abc;
	 }  */
	 }
}
//___________________________MAIN_________________
void main()
{
	clrscr();
	wel_sc();
	inside();
	getch();
	exit(0);
}
