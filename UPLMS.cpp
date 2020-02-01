#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<time.h>
#include<stdio.h>
#include<graphics.h>

#define FOUR 1
#define TWO 2

struct tm* datetime()
{
	time_t ts;
	struct tm *ct;
	ts = time(NULL);
	ct = localtime(&ts);
	return ct;
}

int choice;
int parkinfo[4][10];
int vehiclecount;
int fourcount;
int twocount;

void option();

class checkin
{
	protected:
		int type, number, row, col, tarr[2];
		int hour, minute, second;
		
	public:
		checkin()
		{ row=0; col=0;}
		void frontpage();
		void displaymenu();
		void entry(struct tm *ct);
		int getfreerowcol();
		void add();
		void countw();
		void countr();
		void storeparkw();
		void storeparkr();
		void storearrivaltime(struct tm *ct);
		void displaytotal();
};


class checkout: public checkin
{
	protected:
		int hh, mm, ss;
	public:
		void leave();
		int getvehicle();
		void getarrivaltime(struct tm *ct);
		void calculatetime(int, int);
		void minus();
		void storedeparttime(struct tm *ct);
};


class order
{
	private:
		int r, c ;

	public:
		void displayorder();
};

void checkin :: displaymenu()
{
	clrscr();
	cout<<"\t\t\t\t Parking Management System\n";
	cout<<"\t\t\t\t   Kantipur City College\n";
	cout<<"\t\t\t\t-----------------------------\n";
	cout<<"Main Menu\n";
	cout<<"1. Check In\n";
	cout<<"2. Total Vehicles Parked\n";
	cout<<"3. Display order in which vehicles are parked\n";
	cout<<"4. Check Out\n";
	cout<<"5. Exit\n";
	cout<<"\n---------------------------------------\n";	
	cout<<"Enter the corresponding number :";
	cin>>choice;
}

void checkin :: entry(struct tm *ct)
{
	clrscr();
	type = 0 ;
	cout<<"\t\t\t*** VEHICLE ENTRY ***\n\n";
	cout<<"\n___________________________________________\n\n";	
	cout<<"VECHICLE TYPE		    COST(per hour)\n";
	cout<<"1.FOUR WHEELER            100    \n";
	cout<<"2.TWO WHEELER             50   \n" ;
	cout<<"3. Back\n";
	cout<<"\n___________________________________________\n\n";	
		
/* -----------------------------check for vehicle type ----------------------------*/

	while( type != FOUR && type != TWO )
	{
		cout<<"Enter vehicle type : ";
		cin>>type;
		
		if(type==3)
			option();
		
		if(type==FOUR || type==TWO)
		{
			getfreerowcol();
			
			if(tarr[0] != -1 && tarr[1] != -1)
			{
				row=tarr[0];
				col=tarr[1];
				cout<<"Enter vehicle number :";
				cin>>number;
				parkinfo[row][col]=number;
				storeparkw();
				storearrivaltime(datetime());
				add();
				if(ct->tm_hour <=11 && ct->tm_min <=59 && ct->tm_sec<=59)
				{
					if(ct->tm_min<10)
						cout<<"\nYour vehicle has been parked!!!\t" <<"\t\tTime: "<<ct->tm_hour<<":"<<"0"<<ct->tm_min<<" AM"<<endl;
					else
						cout<<"\nYour vehicle has been parked!!!\t" <<"\t\tTime: "<<ct->tm_hour<<":"<<ct->tm_min<<" AM"<<endl;
				}
				else 
				{
					int ttime=ct->tm_hour;
					ttime=ttime-12;
					if(ct->tm_min<10)
						cout<<"\nYour vehicle has been parked!!!\t" <<"\t\tTime: "<<ttime<<":"<<"0"<<ct->tm_min<<" PM"<<endl;
					else
						cout<<"\nYour vehicle has been parked!!!\t" <<"\t\tTime: "<<ttime<<":"<<ct->tm_min<<" PM"<<endl;
				}
			}
			
			else
			{
				cout<<"\n*** SORRY!!! SLOTS ARE OCCUPIED!!! ***\n";
				getch();
				option();
			}
		}
		
		else
		{
			cout<<"\nWrong command!!!\n";
			getch();
			option();
		}
	}
}	

int checkin :: getfreerowcol()
{
	int fromrow=0, torow=2;
	if(type==TWO)
	{
		fromrow += 2;
		torow += 2;
	}
	
	for(int r = fromrow; r < torow ; r++)
	{
		for(int c=0 ; c<10 ; c++)
		{
			if(parkinfo[r][c]==0)
			{
				tarr[0]=r;
				tarr[1]=c;
				return 0;
			}
		}
	}
	
	if( r==2 || r==4)
	{
		tarr[0] = -1;
		tarr[1] = -1;
	}
	return 0;
}

void checkin :: add()
{
	if(type==FOUR)
		fourcount++;
	
	if(type==TWO)
		twocount++;
	
	vehiclecount++;
	countw();
}

void checkin :: countw()
{
	ofstream fout("count.txt");
	fout<<fourcount<<" "<<twocount<<" "<<vehiclecount<<" ";
	fout.close();
}

void checkin :: countr()
{	
	int v,t,f;
	ifstream fin("count.txt");
	fin>>f>>t>>v;
	vehiclecount=v;
	fourcount=f;
	twocount=t;
	fin.close();
}

void checkin :: storeparkw()
{
	ofstream fout("park.txt");
	for(int r=0;r<4;r++)
	{
		for(int c=0;c<10;c++)
		{
			fout<<parkinfo[r][c]<<" ";
		}
	}
	fout.close();
}

void checkin :: storeparkr()
{
	ifstream fin("park.txt");
	for(int r=0;r<4;r++)
	{
		for(int c=0;c<10;c++)
		{
			fin>>parkinfo[r][c];
		}
	}
	fin.close();
}

void checkin :: storearrivaltime(struct tm *ct)
{
	hour   = ct->tm_hour;
	minute = ct->tm_min;
	second = ct->tm_sec;

	ofstream fout("time.txt",ios::app);
	fout<<number<<" ";
	fout<<hour<<" "<<minute<<" "<<second<<" ";
	fout.close();
}

void checkin :: displaytotal()
{
		clrscr();
		countr();
		cout<<"\nTotal no. of vehicles parked	: "<<vehiclecount<<endl;
		cout<<"Total no. of Two Wheelers Parked	: "<<twocount<<endl;
		cout<<"Total no. of Four Wheelers Parked: "<<fourcount<<endl;

		cout<<"\n\n Press any key to exit to Menu ...";
		getch();
		option();
}

void checkout :: leave()
{
	clrscr();
	type=0;
	cout<<"\t\t*** DEPARTURE OF VEHICLE *** \n";
	
	while(type!=FOUR && type!=TWO)
	{
		cout<<"VECHICLE TYPE		    COST(per hour)\n";
		cout<<"1.FOUR WHEELER            100    \n";
		cout<<"2.TWO WHEELER             50   \n" ;
		cout<<"3. Back\n";
		cout<<"\n___________________________________________\n\n";	
		cout<<"\nEnter vehicle type : ";
        cin>>type;
		if(type==3)
			option();
		
		if(type==FOUR||type==TWO)
		{
			cout<<"Enter vehicle number: ";
			cin>>number;
			getvehicle();
			
			if( tarr[0] != -1 && tarr[1] != -1)
			{
				row=tarr[0];
				col=tarr[1];
				parkinfo[row][col]=0;
				storeparkw();
				storedeparttime(datetime());
				calculatetime(number,type);
				cout<<"\n\n\n\n\n\t\t\t*** Please Visit Again!!! ***\n";
				getch();
				option();			
			}
			
			if(tarr[0] == -1 && tarr[1] == -1)
			{
				cout<<"\nInvalid vehicle number!!!\n";
				getch();
				leave();
			}
		}
		else
		{
			cout<<"\nInvalid type!!!";
			getch();
			leave();
		}
	}
}

int checkout :: getvehicle()
{
	int fromrow=0, torow=2;
	if(type==TWO)
	{
		fromrow += 2;
		torow += 2;
	}
	
	for(int r = fromrow; r < torow ; r++)
	{
		for(int c=0 ; c<10 ; c++)
		{
			if(parkinfo[r][c]==number)
			{
				tarr[0]=r;
				tarr[1]=c;
				return 0;
			}
		}
	}
	
	if( r==2 || r==4)
	{
		tarr[0] = -1;
		tarr[1] = -1;
	}
	return 0;
}



void checkout :: storedeparttime(struct tm *ct)
{
	hh   = ct->tm_hour;
	mm = ct->tm_min;
	ss = ct->tm_sec;
	
	ofstream fout("time2.txt",ios::app);
	fout<<number<<" ";
	fout<<hh<<" "<<mm<<" "<<ss<<" ";
	fout.close();
}

void checkout :: calculatetime(int tnum, int ttype)
{
	int ahh,amm,ass,anum;
	ifstream finA("time.txt");
	
	while(!finA.eof())
	{
		finA>>anum;
		if(anum==tnum)
		{
			finA>>ahh>>amm>>ass;
		}
	}
	finA.close();
	
	
	int dhh,dmm,dss,dnum;
	ifstream finD("time2.txt");

	while(finD)
	{
		finD>>dnum;
		if(dnum==tnum)
		{
			finD>>dhh>>dmm>>dss;
		}
	}
		finD.close();
		
	int ahour, aminute, asecond;
	int dhour, dminute, dsecond;
	asecond=ass;
	asecond=asecond+amm*60;
	asecond=asecond+ahh*3600;
	
	dsecond=dss;
	dsecond=dsecond+dmm*60;
	dsecond=dsecond+dhh*3600;
	
	int finalsec,fsec;
	finalsec= dsecond-asecond;
	fsec=finalsec;
	
	int fhh, fmm;
	fmm=fsec/60;
	fsec=fsec%60;
	fhh=fmm/60;
	fmm=fmm%60;
	
	float total;
	minus();
	cout<<"Vehicle Parked for : "<<fhh<<":"<<fmm<<":"<<fsec<<endl;
	if(ttype == FOUR )
	{
		total=finalsec*0.0277;
		cout<<"\n Total Price :Rs. "<<total<<endl;
	}
	if(ttype ==TWO )
	{
		total=finalsec*0.013889;
		cout<<"\n Total Price :Rs. "<<total<<endl;
	}
	
}

void checkout :: minus()
{
	if(type==FOUR)
		fourcount--;
	
	if(type==TWO)
		twocount--;
	
	vehiclecount--;
	countw();
}

void order :: displayorder()
{	
	clrscr();
	
	cout<<"\n-------------Four Wheelers Available Slot---------------------\n";
	for ( r = 0 ; r < 4 ; r++ )
	{
		if ( r == 2 )
		cout<<"\n\n-------------Two Wheelers Available Slot ---------------------\n";
		for ( c = 0 ; c < 10 ; c++ )
			cout<<"\t"<<parkinfo[r][c]<<"\t";    
		cout<<"\n";
	}
	cout<<"Press any key to continue:"<<endl;
	getch();
	option();
}

void checkin :: frontpage()
{
	int gd,gm,x,y;

	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	x=getmaxx();
	y=getmaxy();
	settextstyle(7,HORIZ_DIR,9);
	outtextxy(80,0,"WELCOME");
	settextstyle(3,HORIZ_DIR,4);
	outtextxy(100,160,"PARKING MANAGEMENT SYSTEM");
	settextstyle(6,HORIZ_DIR,2);
	outtextxy(110,320,"Designed By:- Safal Koirala, Suyog Adhikari, Gaurav Subedi  ");

	getch();
	closegraph();
	getch();
}

int main()
{
	clrscr();
	vehiclecount=0;
	fourcount=0;
	twocount=0;
	checkout C;
	for(int i=0;i<4;i++)
	{	for(int j=0;j<10;j++)
		{		
			parkinfo[i][j]=0;
		}
	}
	C.storeparkr();
	C.frontpage();
	option();
	getch();
	return 0;
}
	

void option()
{
	checkout CO;
	CO.displaymenu();
	order O;
	while((choice<6&&choice>0))
	{
    
		
		if(choice==1)
		{
			CO.entry(datetime());
			getch();
			option();
		}
	
			
		else if(choice==2)
		{
			CO.displaytotal();
			getch();
			option();
		}	
		
		else if(choice==3)	
		{	
			O.displayorder();
			getch();
			option();
		}
	
		else if(choice==4)
		{
			CO.leave();
			getch();
			option();
		}
	
		else if(choice==5)
		{
			CO.storeparkw();
			exit(0);
		}
		
		else
		{
			cout<<"Invalid Input Given.. ";
			getch();
			option();
		}
	}
}