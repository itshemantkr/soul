#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
void main()
{     
	clrscr();
 	ofstream  fout("scrpad",ios::out||ios::app);
 	if(!fout)
 	{
 		cout<<"file not open ";
 	}
	char a,b,line[80],ch,l[80],k,w[15],c;
	int z;
	cout<<"want to enter something (y/n) ; ";
	cin>>a;
	if(a=='y'||a=='Y')

	{
	clrscr();
	cout<<"***********************************SCRATCH PAD**********************************";

	for( int i=1;i>0;i++)
    {
	scanf("%c",&line);
	fout<<line;
	for(int j=0;j<strlen(line);j++)
	{
	if(line[j]=='`')
	goto xyz;
	}
    }
}
	xyz:
	fout.close();
	ifstream  fin("scrpad",ios::in||ios::app);
	cout<<"you want to see in your file (y/n) : ";
	cin>>b;      
	fin.seekg(0);
	if (b=='y'||b=='Y')
	{
		clrscr();
		while(!fin.eof())
		{
			fin.get(ch);
			printf("%c",ch);
		}

	}
	cout<<"you want to search something";
	cin>>c;
	if(c=='y'|| c=='Y')
	cout<<"enter word you want to search : ";
	for(int p=0;p>=0;p++)
	{
		scanf("%c",w[p]);
		if(w[p]==' ')
		break;
	}
			z=strlen(w);
			fin.seekg(0);
			while(!fin.eof())
			{
			fin.getline(line,80);
			k=strlen(line);
			for(int r=0;r<k-1;r++)
			{
			sd:
			}

		}
	getch();
	return 0;
}
