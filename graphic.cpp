void box1(int x,int y){
			textcolor(9);
			gotoxy(x+1,y+1);cprintf("  ÜÜÜÜ ");
			gotoxy(x+1,2+y);cprintf(" ‘    ‘");
			gotoxy(x+1,3+y);cprintf(" ‘ÛÛÛÛ‘");
			textcolor(1+y+x+128);gotoxy(4+x,1+y);cprintf("ÛÛ");
				     gotoxy(3+x,2+y);cprintf(" ÛÛ ");}

void box4(int x,int y){    textcolor(11);
			gotoxy(x+1,3+y);cprintf(" ‘ÛÛÛÛ‘");
			gotoxy(x+1,4+y);cprintf(" ‘    ‘");
			gotoxy(x+1,5+y);cprintf("  ßßßß ");
			textcolor(x+y+1+128);gotoxy(4+x,4+y);cprintf("ÛÛ");
		      gotoxy(4+x,5+y);cprintf("ÛÛ");}
void box2(int x,int y){
			textcolor(2+x+128);
			gotoxy(x+1,y+1);cprintf("   ÉÍÍ ");textcolor(x+7);
			gotoxy(x+1,2+y);cprintf("ÉÍÍÛÛÍÍ»");textcolor(14);
			gotoxy(x+1,3+y);cprintf("ÛÛÛÛÛÛÛÛ");}
void box3(int x,int y){
		       textcolor(1+x+128);
			gotoxy(x+1,y+1);cprintf("  ÍÍ»  ");textcolor(x);
			gotoxy(x+1,2+y);cprintf("ÉÍÍÛÛÍÍ»");textcolor(14);
			gotoxy(x+1,3+y);cprintf("ÛÛÛÛÛÛÛÛ");}
void box5(int x,int y,int z){
	    textcolor(x+5+128);
	    gotoxy(x+1,z);cprintf("       ");
	    gotoxy(x+1,z+1);cprintf("  Éß»  ");textcolor(y);
	    gotoxy(x+1,z+2);cprintf("ÜßÛÛÛßÜ");
	    gotoxy(x+1,z+3);cprintf("ß ÛÛÛ ß");
	    gotoxy(x+1,z+4);cprintf(" Û   Û ");}
void box6(int x,int y){int i,j;
	    for(j=0;j<5;j++)
	    for(i=x;i<x+7;i++){gotoxy(i+1,j+y);cprintf(" ");delay(20);}
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
	else {for(k=21;k>m-1;k--){sound(random(2000));box5(n,14,k);delay(90);gotoxy(n+1,k+4);cprintf("             ");nosound();}}
	while(1){
	    for(k=0;k<4;k++){gotoxy(n,m+1+k);cprintf("       ");}
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
			case 32:if(l==1){if((j==m+3||j==m+1||j==m+2||j==m)&&n>=i){n1++;for(k=i+7;k<n+3;k++){sound(500+i*i+k*j*k*k);box2(i,j);textcolor(9);gotoxy(k,j+1);putch('');delay(10);gotoxy(k,j+1);putch(' ');}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=i+7;k<80;k++){sound(500+i*i+k*k*k);box2(i,j);textcolor(9);gotoxy(k,j+1);putch('');delay(10);gotoxy(k,j+1);putch(' ');}nosound();gotoxy(80,j+1);cprintf(" ");}}
				if(l==4){if((j==m+3||j==m+1||j==m+2||j==m)&&n<=i){n1++;for(k=i+3;k>n+3;k--){sound(500+i*i+k*j*k*k);box3(i+1,j);textcolor(9);gotoxy(k,j+1);putch('');delay(10);gotoxy(k,j+1);cprintf(" ");}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=i+3;k>0;k--){sound(500+i*i+k*k*k);box3(i+1,j);textcolor(9);gotoxy(k,j+1);putch('');delay(10);gotoxy(k,j+1);cprintf(" ");}nosound();gotoxy(0,j+1);cprintf(" ");}}
				if(l==2){if((i==(n-3)||i==(n-2)||i==(n-1)||i==(n)||i==(n+1)||i==(n+2)||i==(n+3))&&m>=j+1){n1++;for(k=j+4;k<m+4;k++){sound(500+i*i+k*j*k*k);box4(i,j-1);textcolor(14);gotoxy(i+4,k);putch('');delay(20);gotoxy(i+4,k);cprintf(" ");}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=j+4;k<25;k++){sound(500+i*i+k*j*k*k);box4(i,j-1);textcolor(14);gotoxy(i+4,k);putch('');delay(20);gotoxy(i+4,k);cprintf(" ");}gotoxy(i+4,25);cprintf(" ");}}
				if(l==3){if((i==(n-3)||i==(n-2)||i==(n-1)||i==(n)||i==(n+1)||i==(n+2)||i==(n+3))&&m<=j+1){n1++;for(k=j+1;k>m+2;k--){sound(500+i*i+k*j*k*k);box1(i,j+1);textcolor(14);gotoxy(i+4,k);putch('');delay(20);gotoxy(i+4,k);cprintf(" ");}nosound();for(k=0;k<7;k++){box5(n,k+8,m);delay(50);if(n1>=3){box6(n,m);goto aa;}}}else {for(k=j+1;k>0;k--){sound(500+i*i+k*j*k*k);box1(i,j+1);textcolor(14);gotoxy(i+4,k);putch('');delay(20);gotoxy(i+4,k);cprintf(" ");}gotoxy(i+4,0);cprintf(" ");}}nosound();
				m=random(20);n=random(72);break;
			case 27:goto l;
			default:goto ab;
			}sound(1000);delay(20);nosound();
			if(t<=12){
			m1=random(8-2*(int)t/3);
			if(m1==4-(int)t/3){m=random(20);n=random(72);}}
			else {clrscr();for(k=0;k<30;k++){sound(random(1000));gotoxy(k+1,15);textcolor(k+17);cprintf(" You won now!!");gotoxy(53-k,17);cprintf("Do you want to continue?[y/n] ");delay(70);}
			      nosound();_setcursortype(_NORMALCURSOR);
			      bb:ch=getch();
			      if(ch=='n')goto l;
			      else if(ch=='y')goto start;
			      else goto bb;}
			}l:}
/*Function main*/
void calci(){
	int i,j,n,k=0,l=0;
	char ch;
	char *list[]={"Equation first degree : ax+b=0           ","Equation second degree : axý+bx+c=0      ","Find the root of: ax+b<0                 ",
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
		      "Find :P=1*5*9*...........*(4n-3)         ","Find :P=n!=1*2*3*...........*n           ","Find :P=nü=n*n*n*......*n                ",
		      "Game tank with robot                     ",
			    };
	start:window(0,0,80,25);tb(0);clrscr();
	randomize();
	for(i=0;i<24;i++)
		{tc(9);gotoxy(1,i+1);cprintf("²");gotoxy(80,i+1);cprintf("²");}
	for(i=0;i<=80;i++)
		{tc(10);gotoxy(i,2);putch(4);gotoxy(i,25);putch(4);}
	for(i=0;i<4;i++)
		{tc(14+128);gotoxy(1,(i+1)*5);putch(4);gotoxy(80,(i+1)*5);putch(4);}
	for(i=0;i<8;i++)
		{tc(15+128);gotoxy((i+1)*9,1);putch(4);gotoxy((i+1)*9,24);putch(4);}
	c:line();
	for(i=0;i<16;i++)
		{tc(13);gotoxy(15,i+5);cprintf("³");gotoxy(64,i+5);cprintf("³");}
	for(i=0;i<48;i++)
		{tc(15);gotoxy(16+i,4);cprintf("Ä");gotoxy(16+i,21);cprintf("Ä");}
		gotoxy(15,4);cprintf("Ú");gotoxy(15,21);cprintf("À");
		gotoxy(64,4);cprintf("¿");gotoxy(64,21);cprintf("Ù");
	tb(1);
	for(j=0;j<16;j++){gotoxy(16,5+j);cprintf("                                                ");}
	b:tb(3);
	for(j=0;j<16;j++){tc(1);gotoxy(65,5+j);cprintf("²");}
		gotoxy(65,21);cprintf("");gotoxy(65,4);cprintf("");
		gotoxy(65,5+(int)(k+l)/3);cprintf("þ");
	for(i=l;i<l+14;i++){tb(1);tc(15);gotoxy(22,6+(i-l));cprintf("%s",list[i]);}
	tb(4);gotoxy(17,6+k);cprintf("                                               ");
	tc(15+128);gotoxy(18,6+k);cprintf("");
	tc(14);gotoxy(22,6+k);
	cprintf("%s",list[k+l]);
	a:ch=getch();
	if(ch==80){if(k<13)k++;else {if(l<35)l++;k=13;}tb(1);gotoxy(17,5+k);cprintf("                                               ");goto b;}
	else if(ch==72){if(k>0)k--;else {if(l>0)l--;k=0;}tb(1);gotoxy(17,7+k);cprintf("                                               ");goto b;}
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
		tc(12+128);tb(0);gotoxy(25,23);cprintf("<<Press ANY KEY to the list>>");
		if(k+l!=13)getch();
		goto c;}
	else if(ch==27)exit(1);
	else goto a;
	}
