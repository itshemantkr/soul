#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>

union REGS i,o;
//functions
int intmouse();
void showptr();

//______________________________________________________________
class nw
{
	char name[40],pass[30],phn[13];
	public :
	void getdata()
	{	gotoxy(32,10); cprintf("Name :"); gets(name);//,40,'/n');	}
 
		gotoxy(32,12); cprintf("Password :"); gets(pass);//,30,'/n'); }
 
		gotoxy(32,14); cprintf("Phone : "); gets(phn);//,13,'/n');	}
    }
}
