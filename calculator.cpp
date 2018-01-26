#include <iostream.h>
#include <conio.h>
#include <math.h>

long int fact(int a)
{
	if(a==1 || a==0)
		return 1;
	else 
		return a*fact(a-1);
}

int main ()
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
