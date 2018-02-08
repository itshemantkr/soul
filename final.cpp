#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iomanip.h>
#define gt gotoxy
#define tc textcolor
#define tb textbackground
union REGS i,o;
int aaa=15,bbb=00;
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
void editor();
void disaster ();
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
int acal();
//_________________________________________________________________
class nw
{
	char name[40],phn[13],pass[20];
	public :
	void getdata()
	{	gt(32,10); cprintf("Name :"); gets(name);
		gt(32,12); cprintf("Phone : ");gets(phn);
		gt(32,14); cprintf("Password :");gets(pass);//pass();
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
//___________________________________EDITOR_______________________________________
void editor()
{
	clrscr();
	fstream  fout("scrpad",ios::out);
	if(!fout)
	{
		printf("file not open ");}
		char a,b,line,ch,k,word[20],com[20];
		int z,i;
	printf("Want to enter something (y/n) : ");
	scanf("%c",&a);
	if(a=='y'||a=='Y')
	{
		clrscr();
cprintf("___________________________________SCRATCH PAD__________________________________");
cprintf("\nEnter ` to stop writing.");
printf("\n");
for(i=1;i>0;i++)
     {
	scanf("%c",&line);
	fout<<line;
	if(line=='`')
	break;
     }
}
	fout.close();
	clrscr();
	fstream  fin("scrpad",ios::in);
	printf("You want to see in your file (y/n) : ");
	cin>>b;
	fin.seekg(0);
	if(b=='y'||b=='Y')
	{
		clrscr();
		while(!fin.eof())
		{fin.get(ch);
		printf("%c",ch);
		}

	}
	getch();
     
}

//________________________________CALCULATOR___________________________
long int fact(int a)
{
	if(a==1 || a==0)
		return 1;
	else
		return a*fact(a-1);
}
int acal(void)

{       
	clrscr();
	cout<<"\t\t\t\tCALCULATOR";
	double a, b;
	int menu;
	char option;
	abc:
	cout<<"\n\n\t\t\t********** MENU **********";
	cout<<"\n1. Addition";
	cout<<"\n2. Subtraction";
	cout<<"\n3. Multiplication";
	cout<<"\n4. Division";
	cout<<"\n5. Sum upto n number ";
	cout<<"\n6. Sum of squares upto n number ";
	cout<<"\n7. Logarithm ";
	cout<<"\n8. Factorial ";
	do
	{
		cout<<"\nEnter operation number from MENU: ";
		cin>>menu;
		switch(menu)
		{
			case 1:
			cout<<"Enter two numbers: ";
			cin>>a>>b;
			cout<<a<<" + "<<b<<" = "<<a+b<<"\n";
			break;
			case 2:
			cout<<"Enter two numbers: ";
			cin>>a>>b;
			cout<<a<<" - "<<b<<" = "<<a-b<<"\n";
			break;
			case 3:
			cout<<"Enter two numbers: ";
			cin>>a>>b;
			cout<<a<<" x "<<b<<" = "<<a*b<<"\n";
			break;
			case 4:
			cout<<"Enter two numbers: ";
			cin>>a>>b;
			cout<<a<<" / "<<b<<" = "<<a/b<<"\n";
			break;
			case 5: cout<<"\nEnter the number upto which you want the sum: ";
			cin>>a;
			cout<<"\nThe sum upto "<<a<<" natural numbers is: "<<(a*(a+1))/2<<"\n";
			break;
			case 6: cout<<"\nEnter the number upto which you want the sum of squares: ";
			cin>>a;
			cout<<"\nThe sum of squares upto "<<a<<" natural numbers is: "<<(a*(a+1)*(2*a+1))/6<<"\n";
			break;
			case 7:cout<<"\nEnter the number to find logarithm of the number to the base e: ";
			cin>>a;
			cout<<"log "<<a<<" = "<<log(a)<<"\n";
			break;
			case 8: cout<<"\nEnter the number whose factorial you want to calculate: ";
			cin>>a;
			cout<<"\n"<<a<<"! = "<<fact(a)<<"\n";
			break;
			default:cout<<"Wrong option chosen :::\n";
			break;
		}
		cout<<"\nWant to do more calculations: (Press y or Y for yes): ";
		cin>>option;
		clrscr();
		if(option=='y' || option=='Y')
		goto abc;
		else
		goto pqr;
	}while(option=='y' || option=='Y');
	pqr:
	cout<<"\n\n\t\t**** PRESS ANY KEY TO EXIT **** ";
	getch();
	return 0;
}

//________________________________NEW USER ________________________________
void user()
{	char ch[30];  
	clrscr();gt(32,5); cprintf("ENTER DETAILS");
	gt(31,6);cprintf("%c_____________%c",char(4),char(4));
	nw A; A.getdata();clrscr();
	gt(27,12);cprintf("SUCCESS !!");getch();clrscr();inside();
}
//________________________________OLD USER______________________
void olu()
{
	clrscr();gt(32,5); cprintf("ENTER DETAILS");
	gt(31,6);cprintf("%c_____________%c",char(4),char(4));
	nw A;A.getdata();
	
	clrscr();inside();
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
	//initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");
	int status=intmouse();
	if(status==0) cprintf("No Mouse detected !");
	else {	showptr();cleardevice();setcolor(WHITE);setbkcolor(BLACK);closegraph(); getch();}
	bb:
	tb(aaa);tc(bbb);clrscr();	showptr();
	gt(27,6);cprintf("%c Apps",char(5));
	gt(27,8);cprintf("%c Arithematic Calculator",char(5));
	gt(27,10);cprintf("%c Office",char(5));
	gt(27,12);cprintf("%c Exit",char(5));
	ch=getch();
	if(ch=='1') {	calci();goto bb;	}
	else if(ch=='2'){	acal();goto bb;	}
	else if(ch=='3')
	{       abc:
		clrscr();
		gt(30,4);cprintf("APPS");gt(28,5);cprintf("%c______%c",char(4),char(4));
		gt(27,8);cprintf("%c Calender",char(5));
		gt(27,10);cprintf("%c Editor",char(5));
		gt(27,12);cprintf("%c Background colour",char(5));
		gt(27,14);cprintf("%c Text mode and colour",char(5));
		gt(27,16);cprintf("%c EXIT",char(5));
		ch=getch();
		if(ch=='1') {	calen();	goto bb;}
		else if(ch=='2') {	editor(); goto bb;}
		else if(ch=='5') goto bb;
		else if(ch=='4')
		{
			clrscr();
			gt(27,4);cprintf("Choose colour :");
			gt(26,5);cprintf("_________________");
			gt(27,8);cprintf("1. Black");gt(27,9);cprintf("2. Blue");gt(27,10);cprintf("3. Green");gt(27,11);cprintf("3. Light Blue");gt(27,12);cprintf("4. Red ");gt(27,13);cprintf("5.Cyan ");gt(27,14);cprintf("6. Pink");gt(27,15);
			ch=getch();
			if(ch=='1'){ bbb=0;tc(0);clrscr();goto abc;}
			if(ch=='2'){ bbb=1;tc(1);clrscr();goto abc;}
			if(ch=='3'){ bbb=2;tc(2);clrscr();goto abc;}
			if(ch=='4'){ bbb=3;tc(3);clrscr();goto abc;}
			if(ch=='5'){ bbb=4;tc(4);clrscr();goto abc;}
			if(ch=='6'){ bbb=5;tc(5);clrscr();goto abc;}
			if(ch=='7'){ bbb=7;tc(7);clrscr();goto abc;}
			goto bb;
		}
		else if(ch=='3')
		{	clrscr();
			gt(27,4);cprintf("Choose colour :");
			gt(26,5);cprintf("_________________");
			gt(27,8);cprintf("1. Black");gt(27,9);cprintf("2. Blue");gt(27,10);cprintf("3. Green");gt(27,11);cprintf("3. Light Blue");gt(27,12);cprintf("4. Red ");gt(27,13);cprintf("5.Cyan ");gt(27,14);cprintf("6. Pink");gt(27,15);
			ch=getch();
			if(ch=='1'){ aaa=0;tb(0);clrscr();goto abc;}
			if(ch=='2'){ aaa=1;tb(1);clrscr();goto abc;}
			if(ch=='3'){ aaa=2;tb(2);clrscr();goto abc;}
			if(ch=='4'){ aaa=3;tb(3);clrscr();goto abc;}
			if(ch=='5'){ aaa=4;tb(4);clrscr();goto abc;}
			if(ch=='6'){ aaa=5;tb(5);clrscr();goto abc;}
			if(ch=='7'){ aaa=7;tb(7);clrscr();goto abc;}
			goto bb;
		}
		else {	clrscr();gt(27,12);cprintf("WRONG INPUT !!/n Press any key to continue");  goto abc;	}
	}      //	man();
	else if(ch=='4') exit(0);
	else {	clrscr(); gt(27,20);cprintf("Wrong input"); getch();goto bb;	}
}

//____________________________________WELCOME SCREEN_______________
void wel_sc()
{    	tb(15);tc(00);clrscr();
	char ch,arr[20]={'W','E','L','C','O','M','E',' ','T','O',' ','S','O','U','L','\0'};
	for(int i=0;i<=16;++i)
	{	gt(27+i,10);cprintf("%c",arr[i]);delay(50);	}
	getch();  clrscr();
	gt(16,7);cprintf(" лллллллллллл млллллллм пллп   пллп млллллллм пллп   пллп");
	delay(200);
	gt(16,8);cprintf(" п    лл    п лл     лл  лл     лл  лл     лл  лл     лл");
	delay(200);
	gt(16,9);cprintf("      лл      лл     лл  лл     лл  но     но  ллллллллл");
	delay(200);
	gt(16,10);cprintf("      лл      лл     лл  лл     лл  лл     мм  лл     лл")    ;
	delay(200);
	gt(16,11);cprintf("    ммллмм    плллллллп  плллллллп  плллллллп мллм   мллн")    ;
	delay(550);	clrscr();
	gt(27,7);cprintf("	ллллллл  лллллл    лллллл   лл");
	delay(200);
	gt(27,8);cprintf("	лл       лл        лл       лл");
	delay(200);
	gt(27,9);cprintf("	ллллл    лллллл    лллллл   лл");
	delay(200);
	gt(27,10);cprintf("	лл       лл        лл       лл");
	delay(200);
	gt(27,11);cprintf("	лл       лллллл    лллллпн  лллллпн");
	delay(550);	clrscr();
	gt(27,7);cprintf("	лл      лл   лл    лл   лллллл");
	delay(150);
	gt(27,8);cprintf("	лл      лл    лл  лл    лллл");
	delay(150);
	gt(27,9);cprintf("	лл      лл     лллл     лл");
	delay(150);
	gt(27,10);cprintf("	лллллл  лл      лл      лллллл");
	delay(600);   abc:	clrscr();
	gt(32,10); cprintf("%c New ",char(5)); gt(32,13);cprintf("%c Existing user",char(5));
	ch=getch();
	if(ch=='1') user();
	else if(ch=='2') olu();
	else {	clrscr();gt(27,12);cprintf("WRONG INPUT !!/n Press any key to continue");goto abc;}

}
//___________________________MAIN_________________
void main()
{
	clrscr();
	wel_sc();
	getch();
	exit(0);
}
//_______________________________CALCI_______________________//
void box1(int x,int y){
			textcolor(9);
			gt(x+1,y+1);cprintf("  мммм ");
			gt(x+1,2+y);cprintf("       ");
			gt(x+1,3+y);cprintf("  лллл ");
			textcolor(1+y+x+128);gt(4+x,1+y);cprintf("лл");
				     gt(3+x,2+y);cprintf(" лл ");}

void box4(int x,int y){    textcolor(11);
			gt(x+1,3+y);cprintf("  лллл ");
			gt(x+1,4+y);cprintf("       ");
			gt(x+1,5+y);cprintf("  пппп ");
			textcolor(x+y+1+128);gt(4+x,4+y);cprintf("лл");
		      gt(4+x,5+y);cprintf("лл");}
void box2(int x,int y){
			textcolor(2+x+128);
			gt(x+1,y+1);cprintf("   ЩЭЭ ");textcolor(x+7);
			gt(x+1,2+y);cprintf("ЩЭЭллЭЭЛ");textcolor(14);
			gt(x+1,3+y);cprintf("лллллллл");}
void box3(int x,int y){
		       textcolor(1+x+128);
			gt(x+1,y+1);cprintf("  ЭЭЛ  ");textcolor(x);
			gt(x+1,2+y);cprintf("ЩЭЭллЭЭЛ");textcolor(14);
			gt(x+1,3+y);cprintf("лллллллл");}
void box5(int x,int y,int z){
	    textcolor(x+5+128);
	    gt(x+1,z);cprintf("       ");
	    gt(x+1,z+1);cprintf("  ЩпЛ  ");textcolor(y);
	    gt(x+1,z+2);cprintf("мплллпм");
	    gt(x+1,z+3);cprintf("п ллл п");
	    gt(x+1,z+4);cprintf(" л   л ");}
void box6(int x,int y){int i,j;
	    for(j=0;j<5;j++)
	    for(i=x;i<x+7;i++){gt(i+1,j+y);cprintf(" ");delay(20);}
	     }
void game(){start:
	int i=0,j=0,k,l=1,n,n1,th,m,m1,t=0;
	char ch;
	textbackground(0);window(0,0,80,25);clrscr();
	_setcursortype(_NOCURSOR);
	randomize();box2(0,0);
	aa:t++;n1=0;n=random(72);m=random(20);
	if(n>=72)n=0;
	if(m>=20)m=0;
	th=random(2);
	if(th==1)for(k=0;k<m;k++){sound(random(2000));box5(n,14,k);delay(90);nosound();}
	else {for(k=21;k>m-1;k--){sound(random(2000));box5(n,14,k);delay(90);gt(n+1,k+4);cprintf("             ");nosound();}}
	while(1){
	    for(k=0;k<4;k++){gt(n,m+1+k);cprintf("       ");}
			clrscr();
			if(l==1)box2(i,j);
			if(l==2)box4(i,j-1);
			if(l==3)box1(i,j+1);
			if(l==4)box3(i+1,j);
	    if(n>=72)n=0;
	    if(m>=20)m=0;
	    for(k=0;k<10;k++)box5(n,14,m);
	    ab:ch=getch();
	    switch(ch){
			case 77:l=1;i++;if(i==72)i=0;box2(i,j);break;
			case 80:l=2;if(j>=20)j=0;box4(i,j);j++;break;
			case 72:l=3;if(j<=0)j=22;box1(i,j);j--;break;
			case 75:l=4;if(i==-1)i=70;box3(i,j);i--;break;
			case 32:if(l==1){if((j==m+3||j==m+1||j==m+2||j==m)&&n>=i){n1++;for(k=i+7;k<n+3;k++){sound(500+i*i+k*j*k*k);box2(i,j);textcolor(9);gt(k,j+1);putch(' ');delay(10);gt(k,j+1);putch(' ');}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=i+7;k<80;k++){sound(500+i*i+k*k*k);box2(i,j);textcolor(9);gt(k,j+1);putch(' ');delay(10);gt(k,j+1);putch(' ');}nosound();gt(80,j+1);cprintf(" ");}}
				if(l==4){if((j==m+3||j==m+1||j==m+2||j==m)&&n<=i){n1++;for(k=i+3;k>n+3;k--){sound(500+i*i+k*j*k*k);box3(i+1,j);textcolor(9);gt(k,j+1);putch(' ');delay(10);gt(k,j+1);cprintf(" ");}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=i+3;k>0;k--){sound(500+i*i+k*k*k);box3(i+1,j);textcolor(9);gt(k,j+1);putch(' ');delay(10);gt(k,j+1);cprintf(" ");}nosound();gt(0,j+1);cprintf(" ");}}
				if(l==2){if((i==(n-3)||i==(n-2)||i==(n-1)||i==(n)||i==(n+1)||i==(n+2)||i==(n+3))&&m>=j+1){n1++;for(k=j+4;k<m+4;k++){sound(500+i*i+k*j*k*k);box4(i,j-1);textcolor(14);gt(i+4,k);putch(' ');delay(20);gt(i+4,k);cprintf(" ");}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=j+4;k<25;k++){sound(500+i*i+k*j*k*k);box4(i,j-1);textcolor(14);gt(i+4,k);putch(' ');delay(20);gt(i+4,k);cprintf(" ");}gt(i+4,25);cprintf(" ");}}
				if(l==3){if((i==(n-3)||i==(n-2)||i==(n-1)||i==(n)||i==(n+1)||i==(n+2)||i==(n+3))&&m<=j+1){n1++;for(k=j+1;k>m+2;k--){sound(500+i*i+k*j*k*k);box1(i,j+1);textcolor(14);gt(i+4,k);putch(' ');delay(20);gt(i+4,k);cprintf(" ");}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=j+1;k>0;k--){sound(500+i*i+k*j*k*k);box1(i,j+1);textcolor(14);gt(i+4,k);putch(' ');delay(20);gt(i+4,k);cprintf(" ");}gt(i+4,0);cprintf(" ");}}nosound();
				m=random(20);n=random(72);break;
			case 27:goto l;
			default:goto ab;
			}sound(1000);delay(20);nosound();
			if(t<=12){
			m1=random(8-2*(int)t/3);
			if(m1==4-(int)t/3){m=random(20);n=random(72);}}
			else {clrscr();for(k=0;k<30;k++){sound(random(1000));gt(k+1,15);textcolor(k+17);cprintf(" You won now!!");gt(53-k,17);cprintf("Do you want to continue?[y/n] ");delay(70);}
			      nosound();_setcursortype(_NORMALCURSOR);
			      bb:ch=getch();
			      if(ch=='n')goto l;
			      else if(ch=='y')goto start;
			      else goto bb;}
			}l:}

void calci(){
	int i,j,n,k=0,l=0;
	char ch;
	char *list[]={"Equation first degree : ax+b=0           ","Equation second degree : ax§+bx+c=0      ","Find the root of: ax+b<0                 ",
		      "Find the root of: ax+b>0                 ","Find PGCD of n number                    ","Find PPCM of n number                    ",
		      "Find an Arrangement A(n,p)               ","Pascal triangle                          ","Multiplication (2 to 12)                 ",
		      "Find the Combination C(n,p)              ","Sort of n number (ascending)             ","Sort of n number (descending)            ",
		      "Star triangle                            ","Discount on payment                      ","Decimal number of key on keyboard        ",
		      "Sum of matrices                          ","Defferent of matrices                    ","Product of matrices                      ",
		      "Unit matrices                            ","Digonal matrices                         ","Upper triangular matrices                ",
		      "Lower triangular matrices                ","Convert from Decimal system to Binary    ","Convert from Decimal system to Octal     ",
		      "Convert from Decimal to Hexadecimal      ","Prime number or not                      ","Odd or even number                       ",
		      "Find the maximum and minimum             ",
		      "Sumination of n number                   ","Find :S=1+2+3+..........+n               ",
		      "Find :S=1!+2!+3!+.......+n!              ","Find :S=1*1*1+2*2*2+....+n*n*n           ","Find :S=1*2*3+2*3*4+....+n(n+1)(n+2)     ",
		      "Find :S=1-6+11-......+pow(-1,n+1)*(5n-4) ","Find :S=5-5*5+5*5*5-............         ","Find :S=5+55+555+...............         ",
		      "Find :S=2-7+12-......+pow(-1,n+1)*(5n-3) ","Find :S=5+5*5+5*5*5+.............        ","Find :S=1+1+2+3+5..........  (Fibonacci) ",
		      "Find :S=1-7+13-......+pow(-1,n+1)*(6n-5) ","Find :S=1!.2^2+2!.3^3+....+n!.(n+1)^(n+1)","Find :S=1/1!+2/2!+.......+n/n!           ",
		      "Find :S=1(1!)+2(2!)+3(3!)+.......+n(n!)  ","Find :S=C(n,1)-C(n,2)+..+(-1)^(p+1)C(n,p)","Find :S=1^3+2^3+3^3+........+n^3         ",
		      "Find :P=1*5*9*...........*(4n-3)         ","Find :P=n!=1*2*3*...........*n           ","Find :P=nќ=n*n*n*......*n                ",
		      "Game tank with robot                     ",
			    };
	start:window(0,0,80,25);tb(0);clrscr();
	randomize();
	for(i=0;i<24;i++)
		{tc(9);gt(1,i+1);cprintf("В");gt(80,i+1);cprintf("В");}
	for(i=0;i<=80;i++)
		{tc(10);gt(i,2);putch(4);gt(i,25);putch(4);}
	for(i=0;i<4;i++)
		{tc(14+128);gt(1,(i+1)*5);putch(4);gt(80,(i+1)*5);putch(4);}
	for(i=0;i<8;i++)
		{tc(15+128);gt((i+1)*9,1);putch(4);gt((i+1)*9,24);putch(4);}
	c:line();
	for(i=0;i<16;i++)
		{tc(13);gt(15,i+5);cprintf("Г");gt(64,i+5);cprintf("Г");}
	for(i=0;i<48;i++)
		{tc(15);gt(16+i,4);cprintf("Ф");gt(16+i,21);cprintf("Ф");}
		gt(15,4);cprintf("к");gt(15,21);cprintf("Р");
		gt(64,4);cprintf("П");gt(64,21);cprintf("й");
	tb(1);
	for(j=0;j<16;j++){gt(16,5+j);cprintf("                                                ");}
	b:tb(3);
	for(j=0;j<16;j++){tc(1);gt(65,5+j);cprintf("В");}
		gt(65,21);cprintf(" ");gt(65,4);cprintf(" ");
		gt(65,5+(int)(k+l)/3);cprintf("ў");
	for(i=l;i<l+14;i++){tb(1);tc(15);gt(22,6+(i-l));cprintf("%s",list[i]);}
	tb(4);gt(17,6+k);cprintf("                                               ");
	tc(15+128);gt(18,6+k);cprintf(" ");
	tc(14);gt(22,6+k);
	cprintf("%s",list[k+l]);
	a:ch=getch();
	if(ch==80){if(k<13)k++;else {if(l<35)l++;k=13;}tb(1);gt(17,5+k);cprintf("                                               ");goto b;}
	else if(ch==72){if(k>0)k--;else {if(l>0)l--;k=0;}tb(1);gt(17,7+k);cprintf("                                               ");goto b;}
	else if(ch==13){line();
		if(k+l==0)equation(1);
		if(k+l==1)equation(2);
		if(k+l==2)equa(1);
		if(k+l==3)equa(2);
		if(k+l==4)PGCD_PPCM(1);
		if(k+l==5)PGCD_PPCM(2);
		if(k+l==6)Arrangement();
		if(k+l==7)pascal_tri();
		if(k+l==8)multiple();
		if(k+l==9)Combination();
		if(k+l==10)sort(1);
		if(k+l==11)sort(2);
		if(k+l==12)star();
		if(k+l==13)discount();
		if(k+l==14)deci_num();
		if(k+l==15)sum_def_ma(1);
		if(k+l==16)sum_def_ma(2);
		if(k+l==17)product_ma();
		if(k+l==18)unit_digo_ma(1);
		if(k+l==19)unit_digo_ma(2);
		if(l+k==20)upper_lower_ma(1);
		if(l+k==21)upper_lower_ma(2);
		if(l+k==22)system(1);
		if(l+k==23)system(2);
		if(l+k==24)system(3);
		if(l+k==25)prime_odd_even(1);
		if(l+k==26)prime_odd_even(2);
		if(l+k==27)max_min();
		if(l+k==28)sum(1);
		if(l+k==29)sum(2);
		if(l+k==30)sum(3);
		if(l+k==31)sum(4);
		if(l+k==32)sum(5);
		if(l+k==33)sum(6);
		if(l+k==34)sum(7);
		if(l+k==35)sum(8);
		if(l+k==36)sum(9);
		if(l+k==37)sum(10);
		if(l+k==38)sum(11);
		if(l+k==39)sum(12);
		if(l+k==40)sum(13);
		if(l+k==41)sum(14);
		if(k+l==42)sum(15);
		if(l+k==43)sum(16);
		if(l+k==44)sum(17);
		if(l+k==45)sum(18);
		if(l+k==46)sum(19);
		if(l+k==47)sum(20);
		if(l+k==48){game();goto start;}
		tc(12+128);tb(0);gt(25,23);cprintf("<<Press ANY KEY to the list>>");
		if(k+l!=13)getch();
		goto c;}
	else if(ch==27);//exit(1);
	else goto a;
	}
void line(){
	int i;
	for(i=0;i<22;i++){tb(0);gt(2,2+i);cprintf("                                                                              ");}
	  }
	  //*****************
void equation(int l){int a,b,c;float x,x1,x2,D;
       if(l==1){tc(11);gt(25,3);cprintf("Find the root of : ax+b=0");
	      gt(25,4);         cprintf("     =====***=====    ");
	tc(9);gt(21,5);cprintf("Please input the value of a & b");
	tc(15);gt(23,7);cprintf("a=");scanf("%d",&a);
	gt(33,7);cprintf("and        b=");scanf("%d",&b);
	agg:tb(0);
	 gt(23,11);cprintf("=>%dx=%d",a,-b);
	 gt(23,12);cprintf("=> x=%d/%d",-b,a);
	 gt(23,9);
	 if(b>=0)cprintf("Then the equation is %dx+%d=0",a,b);
	 else cprintf("Then the equation is %dx-%d=0",a,-b);
	if(a==0){gt(33,15);cprintf("So");tb(4);
		tc(14);gt(30,17);
		if(b!=0)cprintf(" No root or not have! ");
		else cprintf(" Have many root ");}
	else {x=(float)-b/a;
		gt(27,13);cprintf("=%.2f",x);
		tc(10);gt(27,17);cprintf("So");tb(5);
		tc(14);gt(32,17);cprintf(" x=%.2f ",x);}}
	if(l==2) {
       tc(15);gt(25,3);cprintf("Find the root of : ax§+bx+c=0");
	      gt(25,4);cprintf("      ======***======        ");
       tc(13);gt(22,5);cprintf("Please input the value of a, b & c");
       tc(11);gt(25,7);cprintf("a=");scanf("%d",&a);
	      gt(30,7);cprintf(",     b=");scanf("%d",&b);
	      gt(44,7);cprintf("and     c=");scanf("%d",&c);
	gt(23,8);
	   if(b>=0&&c>=0)cprintf("Then the equation is: %dx§+%dx+%d=0",a,b,c);
	   if(b>=0&&c<0)cprintf("Then the equation is: %dx§+%dx-%d=0",a,b,-c);
	   if(b<0&&c>=0)cprintf("Then the equation is: %dx§-%dx+%d=0",a,-b,c);
	   if(b<0&&c<0)cprintf("Then the equation is: %dx§-%dx-%d=0",a,-b,-c);
      if(a==0){a=b;b=c;l=1;goto agg;}
      else {D=b*b-4*a*c;
		gt(18,10);cprintf("     D=b§-4ac=%d§-4x(%d)x(%d)=%.2f",b,a,c,D);
		tc(7);gt(19,12);
	if(D>0){x1=(-b-sqrt(D))/(2*a);x2=(-b+sqrt(D))/(2*a);
		cprintf("Then x1=(-b-ћD))/2a=%.2f",x1);
		gt(22,13);cprintf("and x2=(-b+ћD)/2a=%.2f",x2);
		tc(2);gt(35,15);cprintf("So");
		tc(3);tb(4);gt(18,17);cprintf(" x1=%.2f ",x1);
		gt(43,17);cprintf(" x2=%.2f ",x2);}
	else if(D==0){
		x1=(float)-b/(2*a);
		cprintf("Then x1=x2=-b/2a=%.2f",x1);
		tc(2);gt(23,17);cprintf("So");
		tc(10);tb(4);gt(28,17);cprintf(" x1=x2=%.2f ",x1);}
	else {D=fabs(D);
		cprintf("Then x1=(-b-ћSi)/2a  ,(S=ГDГ)");
		gt(20,13);cprintf("and x2=(-b+ћSi)/2a)");
		tc(10);gt(36,15);cprintf("So");
		tc(15);tb(4);gt(18,17);cprintf(" x1=(-%d-%.2fi)/%d ",b,sqrt(D),2*a);
		gt(43,17);cprintf(" x2=(-%d+%.2fi)/%d ",b,sqrt(D),2*a);
		tc(9);tb(0);gt(28,19);cprintf("i is complex number.");}}}
		}
//***************===============-----------
void pascal_tri(){int i,n,j;
	gt(20,4);cprintf("The program is about pascal triangle");
	gt(25,6);tc(3);cprintf(" Please input n (1-14):");
	aa:gt(48,6);clreol();
	   tc(14);gt(48,6);scanf("%d",&n);
		if(n<=0||n>14){tc(12);gt(30,23);cprintf("You must input again!");
			delay(900);gt(30,23);cprintf("                             ");
			goto aa;}
			 tc(7);
	for(i=1;i<=n;i++){
	  for(j=1;j<=i;j++)
	   {if(j==1||j==i)d[i][j]=1;
	    else d[i][j]=d[i-1][j-1]+d[i-1][j];
	    gt(33.5+5*j-2.5*(i-2),8+i);cprintf("%d",d[i][j]);}
	    delay(20);}
	    }
	    /*End pascal_tri*/
void multiple(){int s,l,i,j,k=0;
	_setcursortype(_NOCURSOR);
	while(!kbhit()){
		if(k>31)k=0;
		if(k>18&&k<=31)tc(k+128);
		if(k>=0&&k<=18){if(k==0||k==16)k++;else k=k;tc(k);}
	for(j=1;j<=12;j++){
	     for(i=1;i<=10;i++){
		s=i*j;l=10*j;
		if(j<=6){gt(13*j-9,2+i);
		   if(i<=9)cprintf("%d*%d =%d",j,i,s);
		   else cprintf("%d*10=%d",j,l);}
		else {gt(13*(j-6)-9,13+i);
		   if(i<=9)cprintf("%d*%d =%d",j,i,s);
		   else cprintf("%d*10=%d",j,l);}
	      }delay(20);}k++;
      }}
      /*End Multiplication*/
void equa(int l){start:int a,b;float S;
      tc(14);gt(25,4);cprintf("Find the root of ax+b %c0",58+2*l);
      gt(22,6);tc(11);cprintf("Please input the value of a & b");
      _setcursortype(_NORMALCURSOR);
      gt(23,8);cprintf("a=");scanf("%d",&a);
      gt(33,8);cprintf("and       b=");scanf("%d",&b);
		S=(float)-b/a;
	 tc(7);gt(24,10);
      if(b>=0)cprintf("Then ax+b%c0 => %dx+%d%c0",58+2*l,a,b,58+2*l);
      else cprintf("Then ax+b%c0 => %dx-%d%c0",58+2*l,a,-b,58+2*l);
	l:tc(11);gt(27,16);cprintf("So");gt(27,12);
	if(a<0)
		{cprintf("=> x%c%d/(%d)",64-2*l,-b,a);
		gt(27,14);cprintf("x%c%.2f",64-2*l,S);
		tc(9);tb(2);gt(32,16);cprintf(" x%c%.2f ",64-2*l,S);}
	else if(a>0)
		{cprintf("=> x%c%d/%d",58+2*l,-b,a);
		gt(27,14);cprintf("x%c%.2f",58+2*l,S);
		tc(9);tb(2);gt(32,16);cprintf(" x%c%.2f ",58+2*l,S);}
	   else
		{gt(32,16);tb(5);tc(10);
	     if((b<0&&l==1)||(b>0&&l==2))
		cprintf(" Have many root ");
	     else cprintf(" No root ");
		}}
	//*********************++++++++++++++
PGCD(int x,int y){while(x!=y){
		if(x>y)x=x-y;
		else y=y-x;}
		return(x);}
	//+++++++++++++++++++++++=======
void PGCD_PPCM(int l){int n,k,A[25],j;long C,S1;
		char *PP[]={"PGCD","PPCM"};
      _setcursortype(_NORMALCURSOR);
     if(l==1){tc(10);gt(28,4);cprintf("Find the PGCD of n number.");}
     if(l==2){tc(10);gt(28,4);cprintf("Find the PPCM of n number.");}
	       tc(9); gt(28,5);cprintf("      =====***=====");
	  aa:tc(15);gt(59,6);clreol();
	  gt(24,6);cprintf("Please input the value of n(1-24):");
	  gt(59,6);scanf("%d",&n);
	  if(n<=0||n>24)goto aa;
	  tc(3);gt(24,7);cprintf("Please input each numbers below");
	for(k=1,j=0;k<=n;k++)
		{if(k==9+8*j)j++;tc(7);gt(16+6*(k-(8*j)),9+j);scanf("%d",&A[k]);}
	  tc(13);gt(35,15);cprintf("Result");tb(4);
	  S1=A[1];
     if(l==1)for(j=2;j<=n;j++){S1=PGCD(A[j],S1);}
     if(l==2)for(j=2;j<=n;j++){C=PGCD(S1,A[j]);S1=(A[j]*S1)/C;}
	tc(11);gt(25,18);cprintf(" The %s of %d number is: %ld ",PP[l-1],n,S1);
	}
	//******************--------------
void Arrangement(){int i,n,p;long L,C,P;
	tc(14);gt(25,3);cprintf(" Find an arrangement of p in n: A(n,p)");
	tc(11);gt(25,4);cprintf("          =======***=======           ");
		_setcursortype(_NORMALCURSOR);
		tc(7);gt(20,6);cprintf("A(n,p)=n!/(n-p)!=(n-p+1)(n-p+2)......n");
		gt(20,8);cprintf("C(n,p)=n!/(p!.(n-p)!)=A(n,p)/p!");
		gt(25,9);cprintf("=>A(n,p)=C(n,p)*p!");
		ll:tc(7);gt(18,11);cprintf("Please input the value of n:       and p :     ");
		gt(47,11);scanf("%d",&n);gt(61,11);scanf("%d",&p);
if(n<=0||p<=0||p>n){sound(1000);
	gt(20,20);cprintf("Please input again ,it invalid!");delay(1000);
	gt(20,20);cprintf("                                                  ");
	nosound();goto ll;}
else {C=1;
	for(i=1;i<=n;i++)C=C*i;
	    P=1;
	    for(i=1;i<=(n-p);i++)P=P*i;
		L=C/P;
	tc(15);gt(22,15);cprintf("The result of A(%d,%d) is : ",n,p);
	tc(10+128);gt(50,15);cprintf("%ld",L);}
	}
	//***********************
void Combination(){int i,p,n;long C;
	_setcursortype(_NORMALCURSOR);
	tc(14);gt(20,4);cprintf("Find the Combination of p in n:c(n,p)");
	tc(15);gt(20,5);cprintf("         =======***=======           ");
	tc(3);gt(22,7);cprintf("c(n,p)=n!/(p!.(n-p)!)");
	gt(22,9);cprintf("c(n,p)=((n-p+1)/p).C(n,p-1)");
	gt(18,11);cprintf("Please input the value of n:       and p :     ");
	gt(47,11);scanf("%d",&n);gt(61,11);scanf("%d",&p);
     if(p>n||n<=0||p<=0){tc(15);gt(28,19);cprintf("The Combination is not have!");}
     else {i=1;C=1;
 while(i<=p){C=C*(n-i+1)/i;i++;}
	tc(10);gt(33,17);cprintf("Result");
 tc(11);gt(20,19);cprintf("The Combination of %d in %d is c(%d,%d):%ld",p,n,n,p,C);}
	}
	//*********************
void sort(int l){int n,i,j,A[17],temp;
	    tc(11);gt(24,3);cprintf("The program of sort number.");
	    tc(14);gt(24,4);cprintf("        ====***====        ");
	    tc(3);gt(20,5);cprintf("How many elements do you want to sort?");
	    a:gt(46,6);clreol();tc(7);gt(25,6);cprintf("Please input n(1-16):");
	    gt(46,6);scanf("%d",&n);
	    if(n<=0||n>16)goto a;
		gt(20,8);cprintf("Please input the value of elements");
	for(i=0,j=0;i<n;i++)
		 {if(i==8)j++;tc(11);gt(17+6*i-48*j,9+j);scanf("%d",&A[i]);}
		gt(20,12);cprintf("The number before sorting is:");
	for(i=0,j=0;i<n;i++)
		  {if(i==8)j++;tc(15);gt(17+6*i-48*j,13+j);cprintf("%d",A[i]);}
		gt(21,16);tc(14);cprintf("The number after sorting is:");
		for(i=0;i<n-1;i++)
			for(j=1+i;j<n;j++)
				if(A[i]>A[j]){temp=A[i];A[i]=A[j];A[j]=temp;}
	  if(l==1){for(i=0,j=0;i<n;i++)
			{if(i==8)j++;gt(17+6*i-48*j,17+j);tc(15);cprintf("%d",A[i]);
			 gt(18,21);cprintf("Sort from lower to upper (ascending)");}}
	  if(l==2){for(i=n-1,j=0;i>=0;i--)
			{if(i==n-7)j++;gt(17+6*i-48*j,17+j);tc(15);cprintf("%d",A[i]);
			 tc(15);gt(18,21);cprintf("Sort from upper to lower (descending)");}}
	  }
	  //***************+++++++++++++
void star(){int i,n,j;
	    ab:_setcursortype(_NORMALCURSOR);
	      tc(15);gt(30,3);cprintf("Star triangle");
	      tc(1); gt(30,4);cprintf("    ==*==     ");
	    gt(22,5);tc(11);cprintf("Please input the value of n(n<=15):   ");
	    gt(58,5);scanf("%d",&n);
	   if(n>15||n<=0)goto ab;
	    _setcursortype(_NOCURSOR);
	for(i=1;i<=n;i++){gt(40-i,6+i);tc(15);
		for(j=1;j<=2*i-1;j++){sound(random(2000));
			putch('*');delay(50);nosound();}
			}
	for(i=1;i<=n;i++){gt(5,6+i);
		for(j=1;j<=i;j++){tc(14);sound(random(2000));
			putch('*');delay(50);nosound();}
			}
	for(i=1;i<=n;i++){gt(75-i,6+i);
		for(j=1;j<=i;j++){tc(13);sound(random(3000));
			putch('*');delay(50);nosound();}
			}}
//****************************
void discount(){ char tha,*str;int i;float spent,pay,disc;
	start:tb(0);gt(17,23);cprintf("                                                 ");
	tc(11);gt(31,7);cprintf("DISCOUNT ON PAYMENT");
	_setcursortype(_NORMALCURSOR);
	tc(9);gt(14,9);cprintf("spent:");
	tc(7);gt(14,11);cprintf("discount:");
	tc(10);gt(14,13);cprintf("payment:");
	tc(6);gt(14,15);cprintf("choose:");
	gt(24,15);cprintf("<<A>> Again");
	gt(24,16);cprintf("<<W>> written by");
	gt(24,17);cprintf("<<T>> taught by");
	tb(14);tc(11);gt(24,9);cprintf("$                   ");
	gt(24,11);cprintf("                    ");
	gt(24,13);cprintf("                    ");
	gt(26,9);scanf("%f",&spent);
if(spent<50)disc=5*spent/100;
else if(spent<200)disc=10*spent/100;
  else if(spent<500)disc=25*spent/100;
    else disc=40*spent/100;
	pay=spent-disc;
	gt(26,11);cprintf("$%2f",disc);
	gt(26,13);cprintf("$%2f",pay);
	tb(0);tc(10);gt(14,15);cprintf("choose:");
	gt(24,15);cprintf("<< >> Again");
	gt(24,16);cprintf("<< >> written by");
	gt(24,17);cprintf("<< >> taught by");
	tc(11+128);gt(26,15);cprintf("A");
	tc(10+128);gt(26,16);cprintf("W");
	tc(9+128);gt(26,17);cprintf("T");
	tt:tc(12+128);tb(0);gt(17,23);cprintf("<<Press ANY KEY beside <a>,<w>,<t> to the list>>");
	tha=getch();
       switch(tha){
		case 'A':case 'a':tb(2);tc(10);gt(24,15);cprintf("<< >> Again");
			tc(11+128);gt(26,15);cprintf("A");
			delay(1000);goto start;
		case 'W':case 'w':tb(2);tc(10);gt(24,16);cprintf("<< >> written by");
			tc(10+128);gt(26,16);cprintf("W");delay(900);
			tb(0);tc(10);gt(24,16);cprintf("<< >> written by");
			tc(10+128);gt(26,16);cprintf("W");
			tc(14);strcpy(str," Write by Mr Iech Setha.");
			for(i=1;i<=24;i++)
				{sound(random(2000));gt(27+i,20);
				cprintf("%c",str[i]);delay(50);nosound();}
			goto tt;
	       case 'T':case 't':tb(2);tc(10);gt(24,17);cprintf("<< >> taught by");
			tc(9+128);gt(26,17);cprintf("T");delay(900);
			tb(0);tc(10);gt(24,17);cprintf("<< >> taught by");
			tc(9+128);gt(26,17);cprintf("T");
			tc(14);strcpy(str," Taught by Mr Kean Tak. ");
		     for(i=1;i<=24;i++)
			  {sound(random(700+i*i*i+9*i));gt(27+i,20);
			  cprintf("%c",str[i]);delay(50);nosound();}
			goto tt;
		      default:goto l;}
				l:}
		     //******************************
void deci_num(){int i;char ch;
	_setcursortype(_NORMALCURSOR);
	for(i=1;i<=9;i++)
		{gt(18,i+6);cprintf("                                       ");}
		tc(3);gt(20,4);cprintf("The program is about the decimal number of key");
		gt(19,5);cprintf(" If you want to know you should press any key to see.");
		tc(15);gt(30,7);cprintf("The code of key");
		tc(11);gt(28,14);cprintf("Press \"Esc\" to skip");
		bb:tc(14);gt(38,10);
		ch=getch();
		gt(38,10);printf("%d   ",ch);
	if(ch==27){sound(1000);delay(999);nosound();goto l;}
	else goto bb;
	 l:}
     //===================================
void sum_def_ma(int l){int n,m,i,j,e[33][33],g[33][33];
	_setcursortype(_NORMALCURSOR);
	if(l==1){tc(14);gt(23,3);cprintf("Find the sumination of two matrices");}
	if(l==2){tc(14);gt(23,3);cprintf("Find the different of two matrices");}
		 tc(15);gt(23,4);cprintf("         ======*****=======     ");
	start:tc(11);gt(25,5);cprintf("Please input the row and column");
	tc(7);gt(26,7);cprintf("Row:     ");gt(30,7);scanf("%d",&m);
	gt(46,7);cprintf("Column:      ");gt(53,7);scanf("%d",&n);
	tc(3);gt(5,9);cprintf("The first matrix is A:");
	gt(55,9);cprintf("The second matrix is B:");
if(n<0||m<0){sound(1000);
	tc(15);gt(29,23);cprintf("Please input again.It's invalid!");delay(1000);nosound();
	gt(29,23);cprintf("                                          ");
	goto start;}
else if(m<2){
	tc(7);gt(5,11);cprintf("к");gt(5,12);cprintf("Г");
	gt(7+3*n,13);cprintf("й");gt(7+3*n,11);cprintf("П");
	gt(7+3*n,12);cprintf("Г");gt(5,13);cprintf("Р");
for(i=1;i<=n;i++)
	{tc(11);gt(4+3*i,12);cscanf("%d",&d[1][i]);}
	tc(7);gt(48,11);cprintf("к");gt(48,12);cprintf("Г");
	gt(50+3*n,13);cprintf("й");gt(50+3*n,11);cprintf("П");
	gt(50+3*n,12);cprintf("Г");gt(48,13);cprintf("Р");
for(i=1;i<=n;i++)
	{tc(11);gt(47+3*i,12);cscanf("%d",&e[1][i]);}
	tc(15);gt(20,14);
     if(l==1)cprintf("The sumination of A and B is A+B:");
     if(l==2)cprintf("The different of A and B is A-B:");
	tc(7);gt(28,16);cprintf("к");gt(28,17);cprintf("Г");
	gt(30+3*n,18);cprintf("й");gt(30+3*n,16);cprintf("П");
	gt(30+3*n,17);cprintf("Г");gt(28,18);cprintf("Р");
for(i=1;i<=n;i++){
	if(l==1)g[1][i]=d[1][i]+e[1][i];
	if(l==2)g[1][i]=d[1][i]-e[1][i];
	tc(11);gt(27+3*i,17);cprintf("%d",g[1][i]);delay(200);
	}}
    else {tc(7);gt(5,11);cprintf("к");gt(7+3*n,10+m);cprintf("й");
		gt(7+3*n,11);cprintf("П");gt(5,10+m);cprintf("Р");
for(i=1;i<=m-2;i++)
	{gt(5,11+i);cprintf("Г");gt(7+3*n,11+i);cprintf("Г");}
for(j=1;j<=m;j++)
	for(i=1;i<=n;i++)
		{tc(11);gt(4+3*i,10+j);cscanf("%d",&d[j][i]);}
	tc(7);gt(48,11);cprintf("к");gt(50+3*n,10+m);cprintf("й");
	gt(50+3*n,11);cprintf("П");gt(48,10+m);cprintf("Р");
for(i=1;i<=m-2;i++)
	{gt(48,11+i);cprintf("Г");gt(50+3*n,11+i);cprintf("Г");}
for(j=1;j<=m;j++)
	for(i=1;i<=n;i++)
		{tc(11);gt(47+3*i,10+j);cscanf("%d",&e[j][i]);}
	tc(15);gt(20,11+m);
     if(l==1)cprintf("The sumination of A and B is A+B:");
     if(l==2)cprintf("The different of A and B is A-B:");
	tc(7);gt(28,13+m);cprintf("к");gt(30+3*n,12+2*m);cprintf("й");
	gt(30+3*n,13+m);cprintf("П");gt(28,12+2*m);cprintf("Р");
for(i=1;i<=m-2;i++)
	{gt(28,13+m+i);cprintf("Г");gt(30+3*n,13+m+i);cprintf("Г");}
for(j=1;j<=m;j++)
	for(i=1;i<=n;i++){
		if(l==1)g[j][i]=d[j][i]+e[j][i];
		if(l==2)g[j][i]=d[j][i]-e[j][i];
	tc(11);gt(27+3*i,12+m+j);cprintf("%d",g[j][i]);delay(200);}
	}getch();}
	//**************************
void product_ma(){
	int j,e[22][22],l[8][6],m,n,i,m1,s1,n1,h[6][4],k[5][9],t,S1;
	char sss[]="Can not product,because column of A are not equal the row of B";
	stt:_setcursortype(_NORMALCURSOR);
	tc(9);gt(23,2);cprintf("Find the multiplication of matrices");
	tc(11);gt(23,3);cprintf("        ======****=======");
	tc(3);gt(10,4);cprintf("The first matrices A have:");
	tc(7);gt(8,5);cprintf("Row:");scanf("%d",&m);
	gt(29,5);cprintf("Column:");scanf("%d",&n);
	if(n<0||m<0)
		{sound(1000);tc(15);gt(29,23);cprintf("Please input again,it invalid!");
		delay(500);nosound();
		gt(29,23);cprintf("                                          ");
		goto stt;}
	else if(m<2){
		gt(5,7);cprintf("к");gt(5,8);cprintf("Г");
		gt(7+3*n,9);cprintf("й");gt(7+3*n,7);cprintf("П");
		gt(7+3*n,8);cprintf("Г");gt(5,9);cprintf("Р");
	for(i=1;i<=n;i++)
		{gt(4+3*i,8);scanf("%d",&d[1][i]);}
	tc(3);gt(50,4);cprintf("The second matrices B have:");
	again:tc(7);gt(48,5);cprintf("Row:  ");gt(52,5);scanf("%d",&m1);
	gt(71,5);cprintf("Column:  ");gt(78,5);scanf("%d",&n1);
	if(n1<0||m1<0)
		{sound(1000);gt(29,23);cprintf("Please input again,it impossible!");
		delay(2000);
		gt(29,23);cprintf("                                           ");
		nosound();goto again;}
	if(m1!=n){
		for(j=1;j<=7;j++){
			tc(j+8);
		   for(i=0;i<=strlen(sss);i++)
			{sound(134+20*i*j);gt(15+i,23);cprintf("%c",sss[i]);
			 delay(10);}
			}nosound();delay(1000);
	    gt(15,23);cprintf("                                                              ");
	    goto again;
		}
	else {
	  if(m1<2){
		tc(7);gt(48,7);cprintf("к");gt(48,8);cprintf("Г");
		gt(50+3*n1,9);cprintf("й");gt(50+3*n1,7);cprintf("П");
		gt(50+3*n1,8);cprintf("Г");gt(48,9);cprintf("Р");
		for(i=1;i<=n1;i++)
			{gt(47+3*i,8);scanf("%d",&e[1][i]);}
			tc(15);gt(20,14);cprintf("The multiplication of A and B is A*B:");
		gt(30,16);cprintf("к");gt(30,17);cprintf("Г");
		gt(32+3*n1,18);cprintf("й");gt(32+3*n1,16);cprintf("П");
		gt(32+3*n1,17);cprintf("Г");gt(30,18);cprintf("Р");
	for(i=1;i<=n1;i++)
		{S1=d[1][1]*e[1][i];gt(29+3*i,17);cprintf("%d",S1);delay(200);}
			}
	else if(n1<2){
		tc(7);gt(48,7);cprintf("к");gt(50+3*n1,6+m1);cprintf("й");
		gt(50+3*n1,7);cprintf("П");gt(48,6+m1);cprintf("Р");
	for(i=1;i<=m1-2;i++)
		{gt(48,7+i);cprintf("Г");gt(50+3*n1,7+i);cprintf("Г");}
	for(j=1;j<=m1;j++)
		for(i=1;i<=n1;i++)
			{gt(47+3*i,6+j);scanf("%d",&e[j][i]);}
		tc(11);gt(20,14);cprintf("The multiplication of A and B is A*B:");
		gt(30,16);cprintf("к");gt(35,18);cprintf("й");
		gt(35,16);cprintf("П");gt(30,18);cprintf("Р");
		gt(30,17);cprintf("Г");gt(35,17);cprintf("Г");
		S1=0;
	for(i=1;i<=n;i++)
		{S1=S1+d[1][i]*e[i][1];}
	gt(32,17);cprintf("%d",S1);
		}
	else{
		gt(48,7);cprintf("к");gt(50+3*n1,6+m1);cprintf("й");
		gt(50+3*n1,7);cprintf("П");gt(48,6+m1);cprintf("Р");
	for(i=1;i<=m1-2;i++)
		{gt(48,7+i);cprintf("Г");gt(50+3*n1,7+i);cprintf("Г");}
	for(j=1;j<=m1;j++)
		for(i=1;i<=n1;i++)
			{gt(47+3*i,6+j);scanf("%d",&e[j][i]);}
	tc(15);gt(20,14);cprintf("The multiplication of A and B is A*B:");
	gt(30,16);cprintf("к");gt(32+3*n1,18);cprintf("й");
	gt(32+3*n1,16);cprintf("П");gt(30,18);cprintf("Р");
	gt(30,17);cprintf("Г");gt(32+3*n1,17);cprintf("Г");
	for(j=1;j<=n1;j++){
		S1=0;
		for(i=1;i<=n;i++)
			{S1=S1+d[1][i]*e[i][j];}
			gt(29+3*j,17);cprintf("%d",S1);}
			}}}
	else{
		gt(5,7);cprintf("к");gt(7+3*n,6+m);cprintf("й");
		gt(7+3*n,7);cprintf("П");gt(5,6+m);cprintf("Р");
	for(i=1;i<=m-2;i++)
		{gt(7+3*n,7+i);cprintf("Г");gt(5,7+i);cprintf("Г");}
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
		     {gt(4+3*i,6+j);scanf("%d",&d[j][i]);}
	tc(3);gt(50,4);cprintf("The second matrices B have:");
	again1:tc(7);gt(48,5);cprintf("Row:  ");gt(52,5);scanf("%d",&m1);
	gt(71,5);cprintf("Column:  ");gt(78,5);scanf("%d",&n1);
	if(n1<0||m1<0)
		{sound(1000);gt(29,23);cprintf("Please input again, it impossible!");
		delay(2000);gt(29,23);cprintf("                                           ");
		nosound();goto again1;}
	if(m1!=n){
	  for(j=1;j<=7;j++){
		tc(j+8);
	      for(i=0;i<=strlen(sss);i++)
		  {sound(134+20*i*j);gt(15+i,23);cprintf("%c",sss[i]);delay(10);}
				}
			nosound();delay(1000);
		  gt(15,23); cprintf("                                                              ");
		  goto again1;
		  }
	else {
	  if(m1<2){
		gt(48,7);cprintf("к");gt(48,8);cprintf("Г");
		gt(50+3*n1,9);cprintf("й");gt(50+3*n1,7);cprintf("П");
		gt(50+3*n1,8);cprintf("Г");gt(48,9);cprintf("Р");
	for(i=1;i<=n1;i++)
		{gt(47+3*i,8);scanf("%d",&e[1][i]);}
			}
	else {
		gt(48,7);cprintf("к");gt(50+3*n1,6+m1);cprintf("й");
		gt(50+3*n1,7);cprintf("П");gt(48,6+m1);cprintf("Р");
	for(i=1;i<=m1-2;i++)
		{gt(48,7+i);cprintf("Г");gt(50+3*n1,7+i);cprintf("Г");}
	for(j=1;j<=m1;j++)
		for(i=1;i<=n1;i++)
			{gt(47+3*i,6+j);scanf("%d",&e[j][i]);}
			}
	tc(11);gt(20,14);cprintf("The multiplication of A and B is A*B:");
	gt(30,16);cprintf("к");gt(32+3*n1,15+m);cprintf("й");
	gt(32+3*n1,16);cprintf("П");gt(30,15+m);cprintf("Р");
	for(i=1;i<=m-2;i++)
		{gt(30,16+i);cprintf("Г");gt(32+3*n1,16+i);cprintf("Г");}
	for(i=1;i<=m;i++)
		for(t=1;t<=n1;t++)
			{l[i][t]=0;
			for(j=1;j<=n;j++)l[i][t]=d[i][j]*e[j][t]+l[i][t];}
	for(i=1;i<=m;i++)
		for(t=1;t<=n1;t++)
			{gt(30+3*t,15+i);cprintf("%d",l[i][t]);delay(100);}
			}}lp1:}
	 //******************************
void unit_digo_ma(int l){int n,i,j;
	start:tc(14);gt(18,6);cprintf("          ========*****========           ");
   if(l==1){tc(11);gt(20,4);cprintf("The program write about unit matrice.");}
   if(l==2){tc(11);gt(20,4);cprintf("The program write about digonal matrice.");}
	gt(18,5);cprintf("Please input the number of row and column:    ");
	gt(60,5);scanf("%d",&n);
 if(n<=1){sound(1000);tc(9);gt(25,12);cprintf("Invalid function");
	delay(1000);nosound();
	gt(25,12);cprintf("                        ");
	goto start;}
 else {tc(13);gt(25,8);cprintf("к");gt(27+3*n,7+n);cprintf("й");
	gt(27+3*n,8);cprintf("П");gt(25,7+n);cprintf("Р");
 for(i=1;i<=n-2;i++)
	{gt(25,8+i);cprintf("Г");gt(27+3*n,8+i);cprintf("Г");}
 for(j=1;j<=n;j++)
	for(i=1;i<=n;i++)
		{if(l==1){if(i==j)d[j][i]=1;
			  else d[j][i]=0;}
		 if(l==2){if(i==j){gt(24+3*i,7+j);cscanf("%d",&d[j][i]);}
			  else d[j][i]=0;}
		}
for(j=1;j<=n;j++)
	for(i=1;i<=n;i++)
		{if(i==j)tc(10);
		 else tc(15);gt(24+3*i,7+j);cprintf("%d",d[j][i]);
	   delay(50);}}
	if(l==2)getch();
		}
void upper_lower_ma(int l){int n,i,j;
    start:tc(13);gt(20,5);cprintf("           =======****=======             ");
 if(l==1){tc(11);gt(18,3);cprintf("The program write about upper triangular matrice.");}
 if(l==2){tc(11);gt(18,3);cprintf("The program write about lower triangular matrice.");}
    gt(20,4);cprintf("Please input the number of row and column:     ");
    gt(63,4);scanf("%d",&n);
    if(n<=1){sound(1000);tc(15);gt(25,12);cprintf("Invalid function");
	delay(999);nosound();
	gt(25,12);cprintf("                       ");
	goto start;}
    else {tc(14);gt(25,8);cprintf("к");gt(27+3*n,7+n);cprintf("й");
	gt(27+3*n,8);cprintf("П");gt(25,7+n);cprintf("Р");
  for(i=1;i<=n-2;i++)
	{gt(25,8+i);cprintf("Г");gt(27+3*n,8+i);cprintf("Г");}
if(l==1){
 for(j=1;j<=n;j++)
  for(i=1;i<=n;i++){
   if(i>=j)
	{gt(24+3*i,7+j);scanf("%d",&d[j][i]);}
   else d[j][i]=0;
	}
for(j=1;j<=n;j++)
   for(i=1;i<=n;i++){if(i>=j)tc(10);
		     else tc(15);
	       gt(24+3*i,7+j);cprintf("%d",d[j][i]);delay(50);}}}
if(l==2){
  for(j=1;j<=n;j++)
      for(i=1;i<=n;i++){
	if(i<=j){gt(24+3*i,7+j);scanf("%d",&d[j][i]);}
	else d[j][i]=0;}
for(j=1;j<=n;j++)
  for(i=1;i<=n;i++){if(i<=j)tc(10);
		    else tc(15);
       gt(24+3*i,7+j);cprintf("%d",d[j][i]);delay(50);}}
	       }

void sum(int l){int i,n,j=0;double a[33],s=0;long S=0,p=1,q=0,f[11],c=1;
	tc(15);gt(20,5);cprintf("         ======****======          ");
	tc(11);gt(20,4);
   if(l==1)cprintf("Caculate the sumination of n number");
   if(l==2)cprintf("   Caculate S=1+2+3+..........+n   ");
   if(l==3)cprintf("  Caculate S=1!+2!+3!+..........+n!");
   if(l==4)cprintf("Caculate S=1.1.1+2.2.2+......+n.n.n");
   if(l==5)cprintf("Caculate S=1.2.3+2.3.4+....+n(n+1)(n+2)");
   if(l==6)cprintf("Find :S=1-6+11-....+pow(-1,n+1).(5n-4)");
   if(l==7)cprintf("Find :S=5-5.5+5.5.5-..................");
   if(l==8)cprintf("Find :S=5+55+555+..................");
   if(l==9)cprintf("Find :S=2-7+12-......+pow(-1,n+1)*(5n-3)");
   if(l==10)cprintf("Find :S=5+5.5+5.5.5+.................");
   if(l==11)cprintf("Find :S=1+1+2+3+5........... (Fibonacci)");
   if(l==12)cprintf("Find :S=1-7+13-......+pow(-1,n+1)*(6n-5) ");
   if(l==13)cprintf("Find :S=1!.2^2+2!.3^3+...+n!.(n+1)^(n+1)");
   if(l==14)cprintf("Find :S=1/1!+2/2!+3/3!+........+n/n!");
   if(l==15)cprintf("Find :S=1.1!+2.2!+3.3!+........+n.n!");
   if(l==16)cprintf("Find :S=C(n,1)-C(n,2)+..+(-1)^(p+1)C(n,p)");
   if(l==17)cprintf("Find :S=1^3+2^3+3^3+.............+n^3 ");
   if(l==18)cprintf("Find :P=1*5*9*...........*(4n-3)      ");
   if(l==19)cprintf("Find :P=n!=1*2*3*...........*n");
   if(l==20)cprintf("Find :P=nќ=n*n*n*...........*n       ");
	     a:tc(3);gt(24,6);cprintf("Please input the value of n:      ");
		      gt(53,6);scanf("%d",&n);
		if(l==16){gt(58,6);cprintf("and p:     ");gt(64,6);scanf("%d",&p);}
		if(n<=0||p<=0||p>n)
			{sound(1000);tc(15);gt(35,12);cprintf("Invalid function");
			 delay(1000);nosound();gt(35,12);
			 cprintf("                   ");goto a;}
      if(l==1){tc(14);gt(28,7);cprintf("Input each number");
	for(i=1;i<=n;i++)
		{if(i==10)j++;tc(7);gt(20+17*j,8+i-9*j);cprintf("num[%d]=",i);scanf("%lf",&a[i]);}}
      if(l==2){tc(14);gt(22,8);cprintf("   S=1+2+3+........+n=n(n+1)/2 ");
		tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1+2+....+%d = %d(%d+1)/2",n,n,n);
		else if(n==1)cprintf("=> S = 1");
		else cprintf("=> S = 1+2 = 3");}
      if(l==3){	tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1!+2!+....+%d!",n);
		else if(n==1)cprintf("=> S = 1! = 1");
		else cprintf("=> S = 1!+2! = 3");}
      if(l==4){ tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1.1.1+2.2.2+....+%d.%d.%d",n,n,n);
		else if(n==1)cprintf("=> S = 1.1.1 = 1");
		else cprintf("=> S = 1.1.1+2.2.2 = 9");}
      if(l==5){ tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1.2.3+2.3.4+....+%d.%d.%d",n,n+1,n+2);
		else if(n==1)cprintf("=> S = 1.2.3 = 6");
		else cprintf("=> S = 1.2.3+2.3.4 = 30");}
      if(l==6){ tc(7);gt(25,10);
		if(n>2){if((pow(-1,n+1)*(5*n-4))>0)cprintf("=> S=1-6+....+%d",(5*n-4));else cprintf("=> S=1-6+....-%d",(5*n-4));}
		else if(n==1)cprintf("=> S = 1 = 1");
		else cprintf("=> S = 1-6 = -5");}
      if(l==7){ tc(7);gt(25,10);
		if(n>3)cprintf("=> S=5-5.5+5.5.5-...........");
		else if(n==1)cprintf("=> S = 5  ");
		else if(n==2)cprintf("=> S = 5-5.5 = -20");
		else cprintf("=> S = 5-5.5+5.5.5 = 105");}
      if(l==8){ tc(7);gt(25,10);
		if(n>2){for(i=1;i<=n;i++)q=pow(10,i-1)*5+q;cprintf("=> S=5+55+.........+%ld",q);}
		else if(n==1)cprintf("=> S = 5  ");
		else cprintf("=> S = 5+55 = 60");}q=0;
      if(l==9){ tc(7);gt(25,10);
		if(n>2){if(pow(-1,n+1)*(5*n-3)>0)cprintf("=> S=2-7+........+%d",(5*n-3));else cprintf("=> S=2-7+........-%d",(5*n-3));}
		else if(n==1)cprintf("=> S = 2  ");
		else cprintf("=> S = 2-7 = -5");}
      if(l==10){ tc(7);gt(25,10);
		if(n>3)cprintf("=> S=5+5.5+5.5.5+...........");
		else if(n==1)cprintf("=> S = 5  ");
		else if(n==2)cprintf("=> S = 5+5.5 = 30");
		else cprintf("=> S = 5+5.5+5.5.5 = 155");}
      if(l==11){ tc(7);gt(25,10);
		if(n>3){f[1]=1;f[2]=1;for(i=3;i<=n;i++)f[i]=f[i-1]+f[i-2];cprintf("=> S=1+1+2+..........+%ld",f[n]);}
		else if(n==1)cprintf("=> S = 1  ");
		else if(n==2)cprintf("=> S = 1+1 = 2");
		else cprintf("=> S = 1+1+2 = 4");}
      if(l==12){ tc(7);gt(25,10);
		if(n>2){if(pow(-1,n+1)*(6*n-5)>0)cprintf("=> S=1-7+.........+%d",(6*n-5));else cprintf("=> S=2-7+........-%d",(6*n-5));}
		else if(n==1)cprintf("=> S = 1  ");
		else cprintf("=> S = 1-7 = -6");}
      if(l==13){ tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1!.2^2+2!.3^3+.........+%d!.%d^%d",n,n+1,n+1);
		else if(n==1)cprintf("=> S = 1!.2^2 = 4  ");
		else cprintf("=> S = 1!.2^2+2!.3^3 = 58 ");}
      if(l==14){ tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1/1!+2/2!+.........+%d/%d!",n,n);
		else if(n==1)cprintf("=> S = 1/1! = 1  ");
		else cprintf("=> S = 1/1!+2/2! = 2 ");}
      if(l==15){ tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1.1!+2.2!+.........+%d.%d!",n,n);
		else if(n==1)cprintf("=> S = 1.1! = 1  ");
		else cprintf("=> S = 1.1!+2.2! = 5 ");}
      if(l==16){ tc(7);gt(25,10);
		if(p>2){if(pow(-1,p+1)>0)cprintf("=> S=C(%d,1)-C(%d,2)+..+C(%d,%d)",n,n,n,p);else cprintf("=> S=C(%d,1)-C(%d,2)+..-C(%d,%d)",n,n,n,p);}
		else if(p==1)cprintf("=> S = C(%d,1)  ",n);
		else cprintf("=> S = C(%d,1)+C(%d,2)  ",n,n);}
      if(l==17){ tc(7);gt(25,10);
		if(n>2)cprintf("=> S=1^3+2^3+.............+%d^3",n);
		else if(n==1)cprintf("=> S = 1^3 = 1  ");
		else cprintf("=> S = 1^3+2^3 = 9 ");}
      if(l==18){ tc(7);gt(25,10);
		if(n>2)cprintf("=> P=1*5*...........*%d",(4*n-3));
		else if(n==1)cprintf("=> P = 1   ");
		else cprintf("=> P = 1*5 = 5 ");}
      if(l==19){ tc(7);gt(25,10);
		if(n>2)cprintf("=> P=1*2*...........*%d",n);
		else if(n==1)cprintf("=> P = 1   ");
		else cprintf("=> P = 1*2 = 2 ");}
      if(l==20){ tc(7);gt(25,10);
		if(n>2)cprintf("P=%d*%d*.....*%d",n,n,n);
		else if(n==1)cprintf(" P = 1",n);
		else cprintf("P = 2*2 = 4");}
      q=0;f[1]=1;f[2]=1;
	for(i=1;i<=n;i++)
		{if(l==1)s=s+a[i];
		 if(l==2)S=S+i;
		 if(l==3){p=p*i;S=S+p;}
		 if(l==4)S=S+i*i*i;
		 if(l==5)S=S+i*(i+1)*(i+2);
		 if(l==6)S=S+pow(-1,i+1)*(5*i-4);
		 if(l==7){p=p*5;S=S+pow(-1,i+1)*p;}
		 if(l==8){q=q+pow(10,i-1)*5;S=S+q;}
		 if(l==9)S=S+pow(-1,i+1)*(5*i-3);
		 if(l==10){p=p*5;S=S+p;}
		 if(l==11){if(i>2)f[i]=f[i-1]+f[i-2];S=S+f[i];}
		 if(l==12)S=S+pow(-1,i+1)*(6*i-5);
		 if(l==13){p=p*i;S=S+p*pow(i+1,i+1);}
		 if(l==14){p=p*i;s=s+(float)i/p;}
		 if(l==15){p=p*i;S=S+i*p;}
		 if(l==16){c=c*(n-i+1)/i;S=S+pow(-1,i+1)*c;if(i==p)i=n+1;}
		 if(l==17)S=S+pow(i,3);
		 if(l==18)p=p*(4*i-3);
		 if(l==19)p=p*i;
		 if(l==20)p=pow(n,n);}
	    tc(9);gt(35,18);cprintf("Result");
	    tc(15);gt(25,20);cprintf("So");
	    tb(5);gt(31,20);
	       if(l==1)cprintf("  S=%.3lf  ",s);
	       if(l==14){cprintf("  S=%.3lf  ",s);tb(0);gt(25,12);cprintf("<=> S = %.3lf ",s);}
	       if(l>=18){cprintf("  P = %ld  ",p);tb(0);gt(25,12);cprintf("<=> P = %ld ",p);}
	       if((l>=2&&l<18)&&l!=14){cprintf("  S  =  %ld  ",S);tb(0);gt(25,12);cprintf("<=> S = %ld ",S);}
		}
void system(int l){long L,A[11],j,i;
	tc(11);gt(25,4);
   if(l==1)cprintf("Convert from decimal to binary");
   if(l==2)cprintf("Convert from decimal to octal");
   if(l==3)cprintf("Convert from hexadecimal to octal");
	tc(11);gt(25,6);cprintf("      =======****=======      ");
	tc(7);gt(23,9);cprintf("Please input the decimal number:");
	_setcursortype(_NORMALCURSOR);
	gt(56,9);scanf("%ld",&L);
	gt(25,13);cprintf("The decimal number is:%ld",L);
	j=1;
	while(L!=0)
		{if(l==1){A[j]=L%2;L=L/2;}
		 if(l==2){A[j]=L%8;L=L/8;}
		 if(l==3){A[j]=L%16;L=L/16;}j++;}
	tc(15);gt(25,15);
	if(l==1)cprintf("The binary number is:");
	if(l==2)cprintf("The octal number is:");
	if(l==3)cprintf("The hexadecimal number is:");
	tc(10);if(l!=3)gt(47,15);
	       else gt(52,15);
	for(i=1;i<j;i++){
		if(l!=3)cprintf("%d",A[j-i]);
		else {
			if(A[j-i]>=10&&A[j-i]<=15){
			   if(A[j-i]==10)A[j-i]=65;
			    else if(A[j-i]==11)A[j-i]=66;
			       else if(A[j-i]==12)A[j-i]=67;
				 else if(A[j-i]==13)A[j-i]=68;
				    else if(A[j-i]==14)A[j-i]=69;
				       else if(A[j-i]==15)A[j-i]=70;
			       cprintf("%c",A[j-i]);}
			 else cprintf("%d",A[j-i]);}
			}}
void prime_odd_even(int l){int i,k;long n;
	tc(11);gt(20,4);
      if(l==1)cprintf("Show the prime number or not prime number");
      if(l==2)cprintf("Show the odd number or even number");
	 tc(14);gt(20,5);cprintf("           =======****=======            ");
	 tc(3);gt(21,7);cprintf("Please input the number you want to know");
	 gt(35,9);cprintf("n=");scanf("%ld",&n);
	 gt(26,17);tb(4);tc(15);
 if(l==1){if(n==2||n==3||n%6==1||n%6==5)
		cprintf("  %ld is Pime number  ",n);
	  else cprintf("  %ld is not the Pime number  ",n);}
 if(l==2){if(n==0)cprintf("  %ld is the not odd or even number  ",n);
	  else if(n%2==0)cprintf("  %ld is the even number  ",n);
	  else cprintf("  %ld is the odd number  ",n);}
	  }
void max_min(){long j=0,i,n,M1,M2, a[33];
	  tc(14);gt(20,4);cprintf("Find the maximum and minimum of n number");
	  tc(11);gt(20,5);cprintf("          =======*****======           ");
	  a:tc(3);gt(20,6);cprintf("     Please input the value of n:      ");
	  gt(53,6);scanf("%ld",&n);
	  if(n<=0)goto a;
	  tc(15);gt(28,7);cprintf("Input each number");
	for(i=1;i<=n;i++)
		{if(i==10)j++;tc(7);gt(20+17*j,8+i-9*j);cprintf("num[%d]=",i);scanf("%ld",&a[i]);}
	M1=a[1];M2=a[1];
	   for(i=2;i<=n;i++)
		    {if(M1<a[i])M1=a[i];
		     if(M2>a[i])M2=a[i];}
	   tb(5);tc(15);gt(25,19);cprintf("  The maximum is : %ld  ",M1);
	   tb(6);tc(15);gt(25,21);cprintf("  The minimum is : %ld  ",M2);
		}

//_______________________CALENDER_____________________
void calen()
{
tc(WHITE);tb(00);
clrscr();
  int year, firstDayInCurrentMonth;
  int leap;
  int currentMonth = 1; // start at Jan
  int numDays;

  cprintf("What year do you want a calendar for? ");
  cin >> year;
  cprintf("What day of the week does January 1 fall on?\n");
  cprintf("(Enter 0 for Sunday, 1 for Monday, etc.) ");
  cin >> firstDayInCurrentMonth;

  leap = isLeapYear(year);
  skip(9); cout << year << endl;

  while (currentMonth <= 12) {
    numDays = numOfDaysInMonth(currentMonth,leap);
    printHeader(currentMonth);
    printMonth(numDays, firstDayInCurrentMonth);
    cout << endl << endl << endl;
    currentMonth = currentMonth + 1;
  }
  cout << endl;
}

void disaster () {
  cprintf("Disaster! Exiting ...\n");
  exit (-1);
}

void skip (int i) {
  while (i > 0) {
    cprintf(" ");
    i = i - 1;
  }
}

char whatDay (int d) {
  if (d == 0) return('S');
  else if (d == 1) return('M');
  else if (d == 2) return('T');
  else if (d == 3) return('W');
  else if (d == 4) return('T');
  else if (d == 5) return('F');
  else if (d == 6) return('S');
  else disaster();
 return 0;
}

int isLeapYear (int y) {
  return ((y % 4) == 0); // simplified
}

void printHeader (int m) {

  if (m == 1) { skip(7); cprintf("January\n"); }
  else if (m == 2) { skip(7); cprintf("February\n"); }
  else if (m == 3) { skip(7); cprintf("March\n"); }
  else if (m == 4) { skip(7); cprintf("April\n"); }
  else if (m == 5) { skip(7); cprintf("May\n"); }
  else if (m == 6) { skip(7); cprintf("June\n"); }
  else if (m == 7) { skip(7); cprintf("July\n"); }
  else if (m == 8) { skip(7); cprintf("August\n"); }
  else if (m == 9) { skip(7); cprintf("September\n"); }
  else if (m == 10) { skip(7); cprintf("October\n"); }
  else if (m == 11) { skip(7); cprintf("November\n"); }
  else if (m == 12) { skip(7); cprintf("December\n"); }
  else disaster();

  cprintf(" S  M  T  W  T  F  S\n");
  cprintf("____________________\n");
}

int numOfDaysInMonth (int m, int leap) {
  if (m == 1) return(31);
  else if (m == 2) if (leap) return(29); else return(28);
  else if (m == 3) return(31);
  else if (m == 4) return(30);
  else if (m == 5) return(31);
  else if (m == 6) return(30);
  else if (m == 7) return(31);
  else if (m == 8) return(31);
  else if (m == 9) return(30);
  else if (m == 10) return(31);
  else if (m == 11) return(30);
  else if (m == 12) return(31);
  else disaster();
}

void skipToDay (int d) {
  skip(3*d);
}

void printMonth (int numDays, int& weekDay) {
  int day = 1;

  skipToDay(weekDay);
  while (day <= numDays) {
    cout << setw(2) << day << " ";
    if (weekDay == 6) {
      cout << endl;
      weekDay = 0;
    }
    else weekDay = weekDay + 1;
    day = day + 1;
  }
 getch();
}
