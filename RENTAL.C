





#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<time.h>
#include<ctype.h>


//~~~~~~~~~~~~~~USER DEFINED FUNCTIONS~~~~~~~~~~~~~~~~~
void welcome();
void login();
void menu();
	void select_vehicle();
		void cycle();
		void car();
		void heavy_vehicle();
		void offroad();
		void luxury();
	  //	void date(*char);
/*applies for all functions for menu*/		void costumer_detail(char*,int);
void details();
		void modifier();
		void view_report();
		void search();
		void update_remarks();

//~~~~~~~~~~~~~~~~STRUCTURE USED~~~~~~~~~~~~~~~~~~~~~~~~
struct customer
{
	char firstname[20];
	char lastname[20];
	char phoneno[20];
	char vehicle[30];
	char date[30];
	char remarks[20];
	int quantity,till;

}p;


//~~~~~~~~~~~~MAIN FUNCTION~~~~~~~~~~~~~~
void main()
{
	welcome();
	login();
	getch();
}



//~~~~~~~~~~~USER DEFINED FUNCTIONS~~~~~~~~~

//~~~~~~~~~WELCOME SCREEN~~~~~~
void welcome()
{
	clrscr();
	printf(" \t\t  * * * * * * * * * * * * * * * * *\n");
	printf(" \t\t       VEHICLE RENTAL SYSTEM\n");
	printf(" \t\t  * * * * * * * * * * * * * * * * *\n");
	printf("\n\n\n\n\n\n\n\n");
	printf(" ______________________________\n");
	printf("|  DESIGNED AND COMPILED BY   |\n");
	printf("|-----------------------------|\n");
	printf("| Safal Koirala               |\n");
	printf("| Suyog Adhikari              |\n");
	printf("| Nishant Ghimire             |\n");
	printf("|_____________________________|\n");
	printf("\n\n\n\n\n\t\t\t");
	printf("\t\t\tPRESS ANY KEY TO CONTINUE...");
	getch();
	printf("\n");
}

//~~~~~~login for admin~~~~~~~~~~
//USER ID : user
//PASSWORD: 12345

void login()
{
	int i=0;
	char uname[10],c=' ';
	char pword[8],code[10];
	clrscr();
	printf(" \n\n\n\n\n\n\n\n\n");
	printf("\t\t\t           Login to Continue");
	printf("\n\t\t\t    ---------------------------");
	printf("\n\n\t\t\tEnter UserID :");
	scanf("%s",&uname);
	printf("\n\t\t\tEnter Password :");
	while(i<10)
		{
		    pword[i]=getch();
		    c=pword[i];
		    if(c==13) break;
		    else printf("*");
		    i++;
		}
	pword[i]='\0';
	i=0;
	if(strcmp(uname,"user")==0 && strcmp(pword,"12345")==0)
		{
		    clrscr();
		    printf(" \n\n\n\n\n\n\n\n\n");
		    printf("\t\t     WELCOME !! YOUR LOGIN IS SUCCESSFUL");
		    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		    printf("\t\t\t\t\t\t   Press any key to continue...");
		    getch();//holds the screen
		    menu();
		}
	else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL \n\t PLEASE TRY AGAIN");
			getch();
			login();
		}


    getch();
}


//~~~~~~~MAIN MENU~~~~~~~~~~~~~~~~
void menu()
{
	int choice;
	clrscr();
	printf("\n \t \t");
	printf("\t \n \t \t \n \n \n");
	printf(" \n \t \t \t # # # # # # # # # # # # # #");
	printf(" \n \t \t \t #          MAIN MENU      #");
	printf(" \n \t \t \t #       --------------    #");
	printf(" \n \t \t \t #     1. BOOK A VEHICLE   #");
	printf(" \n \t \t \t #     2. DETAIL           #");
	printf(" \n \t \t \t #     3. EXIT             #");
	printf(" \n \t \t \t # # # # # # # # # # # # # #");
	printf("\n\n\n\nEnter the Corresponding Number:");
	printf("\n----------------------------------------------");
	printf("\nYOUR CHOICE  : ");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			select_vehicle();
			break;

		case 2:
			details();
			break;
		case 3:
			exit(1);
			break;

		default:
			printf("\n INVALID INPUT(PLEASE TRY AGAIN...)");
			getch();
			menu();
	}
}



//~~~~~~~~~VEHICLE SELECTION SECTION~~~~~~~~~~~~~~~~~~~(second menu)

void select_vehicle()
{        char ch[10]="cycle";
	int cat_select;
	clrscr();
	printf("\n\n\n");
	printf("\n\t\t# # # # # # # # # # # # # # # # # # # # # #");
	printf("\n\t\t#             AVAILABLE VEHICLES          #");
	printf("\n\t\t#            --------------------         #");
	printf("\n\t\t#                1. Cycle                 #");
	printf("\n\t\t#                2. Car                   #");
	printf("\n\t\t#                3. Heavy Vehicle         #");
	printf("\n\t\t#                4. Off Road              #");
	printf("\n\t\t#                5. Luxury                #");
	printf("\n\t\t#                6. Back                  #");
	printf("\n\t\t#                7. Exit                  #");
	printf("\n\t\t# # # # # # # # # # # # # # # # # # # # # #");
	printf("\n\n\n\n\n Please select the corresponding Number:");
	fflush(stdin);
	scanf("%d",&cat_select);

	switch(cat_select)
	{
		case 1:

			 cycle(ch);
				break;

		case 2:
				car();
				break;

		case 3:
				heavy_vehicle();
				break;
		case 4:
				offroad();
				break;
		case 5:
				luxury();
				break;
		case 6:
				menu();
				break;
		case 7:
				exit(1);
				break;

		default:
				printf("Invalid Input Given...\n");
				printf("Please Try Again.");
				getch();
				select_vehicle();
	}

}

void cycle()
{
	static int total_cycle=15;
	int qty,back;
	char confirm;
       //	printf(" cycle is %s ",as);
	clrscr();
	while(cycle>0)
	{
		lbl:
		printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
		printf("\n\t#                   CYCLE RENTAL                            #");
		printf("\n\t#-----------------------------------------------------------#");
		printf("\n\t# Category  #  Qtantity Available  #  price/qty(per day)    #");
		printf("\n\t#-----------------------------------------------------------#");
		printf("\n\t#  Biycle   #        %d            #   500                  #",total_cycle);
		printf("\n\t#           #                      #                        #");
		printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
		printf("\n\n\nConfirm Rental??(Y/N) :");
		fflush(stdin);
		scanf("%c",&confirm);
		confirm=toupper(confirm);
		switch(confirm)
		{

				case 'Y':
				printf("How many cycle would you rent :");
				scanf("%d",&qty);
				if(qty>total_cycle)
				{
						printf("Sorry, we only have %d Cycle",total_cycle);
					getch();
					goto lbl;
				}
				if(qty<1)
				{
					printf("Sorry, we only have %d Cycle",total_cycle);
					getch();
					goto lbl;
				}
				total_cycle=total_cycle-qty;
				costumer_detail("Bicycle",qty);
				 break;

		case 'N':
				clrscr();

				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     2. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				fflush(stdin);
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN\n");
					getch();
					goto lbl;
				}
				break;

		default:
				clrscr();
				printf("Invalid Input Given!!! TRY AGAIN\n");
				getch();
				goto lbl;
	}
	}
}

void car()
{
	static int mazda=5,scorpio=5,maruti=5;
	int choose,back,qty;
	char confirm;
	clrscr();
	while(mazda>0||scorpio>0||maruti>0)
	{
		printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
		printf("\n\t#                       CAR RENTAL                                #");
		printf("\n\t#-----------------------------------------------------------------#");
		printf("\n\t# SN  #  Category  #  Qtantity Available  #  price/qty(per day)   #");
		printf("\n\t#-----------------------------------------------------------------#");
		printf("\n\t#  1. #   Mazda    #        %d            #   5000                #",mazda);
		printf("\n\t#  2. #   Scorpio  #        %d            #   6000                #",scorpio);
		printf("\n\t#  3. #   Maruti   #        %d            #   4000                #",maruti);
		printf("\n\t#     #            #                      #                       #");
		printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
		printf("\n\n\n\n\n Confirm Rental??(Y/N) ::");
		fflush(stdin);
		scanf("%c",&confirm);

	switch(confirm)
	{
		case 'y':
				printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
				fflush(stdin);
				scanf("%d",&choose);

				switch(choose)
				{
					case 1:
							printf("How many Mazda car would you rent :");
							scanf("%d",&qty);
							if(qty>mazda)
							{
								printf("Sorry, we only have %d car",mazda);
								getch();
								car();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d car",mazda);
								getch();
								car();
							}
							mazda=mazda-qty;
							costumer_detail("Mazda",qty);
							break;


					case 2:
							printf("How many Scorpio car would you rent :");
							scanf("%d",&qty);
							if(qty>scorpio)
							{
								printf("Sorry, we only have %d car",scorpio);
								getch();
								car();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d car",scorpio);
								getch();
								car();
							}
							scorpio=scorpio-qty;
							costumer_detail("Scorpio",qty);
							break;


					case 3:
							printf("How many Maruti car would you rent :");
							scanf("%d",&qty);
							if(qty>maruti)
							{
								printf("Sorry, we only have %d car",maruti);
								getch();
								car();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d car",maruti);
								getch();
								car();
							}
							maruti=maruti-qty;
							costumer_detail("Maruti",qty);
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							car();
				}

		case 'Y':
				printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
				fflush(stdin);
				scanf("%d",&choose);

				switch(choose)
				{
					case 1:
							printf("How many Mazda car would you rent :");
							scanf("%d",&qty);
							if(qty>mazda)
							{
								printf("Sorry, we only have %d car",mazda);
								getch();
								car();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d car",mazda);
								getch();
								car();
							}
							mazda=mazda-qty;
							costumer_detail("Mazda",qty);
							break;

					case 2:
							printf("How many Scorpio car would you rent :");
							scanf("%d",&qty);
							if(qty>scorpio)
							{
								printf("Sorry, we only have %d car",scorpio);
								getch();
								car();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d car",scorpio);
								getch();
								car();
							}
							scorpio=scorpio-qty;
							costumer_detail("Scorpio",qty);
							break;


					case 3:
							printf("How many Maruti car would you rent :");
							scanf("%d",&qty);
							if(qty>maruti)
							{
								printf("Sorry, we only have %d car",maruti);
								getch();
								car();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d car",maruti);
								getch();
								car();
							}
							maruti=maruti-qty;
							costumer_detail("Maruti",qty);
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							car();
				}

		case 'n':
				clrscr();
				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     2. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN");
					getch();
					car();
				}
				break;

		case 'N':
				clrscr();
				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     2. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN");
					getch();
					car();
				}
				break;

		default:
				printf("Invalid Input Given!!! TRY AGAIN");
				getch();
				car();

	}

	}
}


void heavy_vehicle()
{
	static int bus=5,micro=5,van=5;
	int back,choose,qty;
	char confirm;
	clrscr();
	while(bus>0||micro>0||van>0)
	{
		printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
		printf("\n\t#                     HEAVY VEHICAL RENTAL                          #");
		printf("\n\t#-------------------------------------------------------------------#");
		printf("\n\t# SN  #  Category    #   Qtantity Available  #  price/qty(per day)  #");
		printf("\n\t#-------------------------------------------------------------------#");
		printf("\n\t#  1. #   Bus        #         %d            #   500                #",bus);
		printf("\n\t#  2. #   Micro Bus  #         %d            #   500                #",micro);
		printf("\n\t#  3. #   Van        #         %d            #   500                #",van);
		printf("\n\t#                                                                   #");
		printf("\n\t# # # # # # # # # #  # # # #  # # # # # # # # # # # # # # # # # # # #");
		printf("\n\n\n\n\n Confirm Rental??(Y/N) ::");
		fflush(stdin);
		scanf("%c",&confirm);

		switch(confirm)
	{
		case 'y':
				printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
				fflush(stdin);
				scanf("%d",&choose);

				switch(choose)
				{
					case 1:
							printf("How many Bus would you rent :");
							scanf("%d",&qty);
							if(qty>bus)
							{
								printf("Sorry, we only have %d bus",bus);
								getch();
								heavy_vehicle();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d bus",bus);
								getch();
								heavy_vehicle();
							}
							bus=bus-qty;
							costumer_detail("Bus",qty);
							break;


					case 2:
							printf("How many micro would you rent :");
							scanf("%d",&qty);
							if(qty>micro)
							{
								printf("Sorry, we only have %d MICRO BUS",micro);
								getch();
								heavy_vehicle();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d MICRO BUS",micro);
								getch();
								heavy_vehicle();
							}
							micro=micro-qty;
							costumer_detail("Micro",qty);
							break;


					case 3:
							printf("How many Van would you rent :");
							scanf("%d",&qty);
							if(qty>van)
							{
								printf("Sorry, we only have %d VANS",van);
								getch();
								heavy_vehicle();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d VANS",van);
								getch();
								heavy_vehicle();
							}
							van=van-qty;
							costumer_detail("Van",qty);
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							heavy_vehicle();
				}

		case 'Y':
				printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
				fflush(stdin);
				scanf("%d",&choose);

				switch(choose)
				{
					case 1:
							printf("How many Bus would you rent :");
							scanf("%d",&qty);
							if(qty>bus)
							{
								printf("Sorry, we only have %d bus",bus);
								getch();
								heavy_vehicle();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d bus",bus);
								getch();
								heavy_vehicle();
							}
							bus=bus-qty;
							costumer_detail("Bus",qty);
							break;


					case 2:
							printf("How many micro would you rent :");
							scanf("%d",&qty);
							if(qty>micro)
							{
								printf("Sorry, we only have %d MICRO BUS",micro);
								getch();
								heavy_vehicle();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d MICRO BUS",micro);
								getch();
								heavy_vehicle();
							}
							micro=micro-qty;
							costumer_detail("Micro",qty);
							break;


					case 3:
							printf("How many Van would you rent :");
							scanf("%d",&qty);
							if(qty>van)
							{
								printf("Sorry, we only have %d VANS",van);
								getch();
								heavy_vehicle();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d VANS",van);
								getch();
								heavy_vehicle();
							}
							van=van-qty;
							costumer_detail("Van",qty);
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							heavy_vehicle();
				}

		case 'n':
				clrscr();
				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     3. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN");
					getch();
					heavy_vehicle();
				}
				break;

		case 'N':
				clrscr();
				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     3. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN");
					getch();
					heavy_vehicle();
				}
				break;

		default:
				printf("Invalid Input Given!!! TRY AGAIN");
				getch();
				heavy_vehicle();
	}
	}
}


void offroad()
{
	int two_wheeler,four_wheeler,type,back,qty;
	int choose1,choose2,choose3,choose4;
	char confirm1,confirm2;
	static int vr=5,crossfire=5,xr=5;
	static int jeep=5,mahindra=5,scorpio=5;
	clrscr();
	while(vr>0||crossfire>0||xr>0||jeep>0||mahindra>0)
	{
		printf("\n\t# # # # # # # # # # # # # # # # # # # # ## # # #");
		printf("\n\t#             OFFROAD VEHICAL RENTAL           #");
		printf("\n\t#----------------------------------------------#");
		printf("\n\t# SN   #  Category    #     price/qty(per day) #");
		printf("\n\t#----------------------------------------------#");
		printf("\n\t#  1.  #  2 Wheelers  #      500               #");
		printf("\n\t#  2.  #  4 wheelers  #      500               #");
		printf("\n\t#  3.  #  BACK                                 #");
		printf("\n\t#  4.  #  EXIT                                 #");
		printf("\n\t# # # # # # # # # #  # # # #  # # # # # ## # # #");
		printf("\n\n\n\n\n Choose a Vehicle Type(Enter the corresponding number) ::");
		fflush(stdin);
		scanf("%d",&type);

		switch(type)
		{
			case 1:
					clrscr();
					printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
					printf("\n\t#                    OFFROAD VEHICAL RENTAL                       #");
					printf("\n\t#                          TWO WHEELERS                           #");
					printf("\n\t#-----------------------------------------------------------------#");
					printf("\n\t# SN   #  Category   #  Qtantity Available  #  price/qty(per day) #");
					printf("\n\t#-----------------------------------------------------------------#");
					printf("\n\t#  1.  #  VR         #        %d            #   500               #",vr);
					printf("\n\t#  2.  #  CROSSFIRE  #        %d            #   500               #",crossfire);
					printf("\n\t#  3.  #  XR         #        %d            #   500               #",xr);
					printf("\n\t#                                                                 #");
					printf("\n\t# # # # # # # # # # # # # #  # # # # # # # # # # # # # # # # # # ##");
					printf("\n\n\n\n\n Confirm Rental??(Y/N) ::");
					fflush(stdin);
					scanf("%c",&confirm1);

					switch(confirm1)
					{
						case 'y':
								printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
								fflush(stdin);
								scanf("%d",&choose1);
								switch(choose1)
								{
									case 1:
											printf("How many VR would you rent :");
											scanf("%d",&qty);
											if(qty>vr)
											{
												printf("Sorry, we only have %d VR",vr);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d VRs",vr);
												getch();
												offroad();
											}
											vr=vr-qty;
											costumer_detail("VR",qty);
											break;


									case 2:
											printf("How many CROSSFIRE would you rent :");
											scanf("%d",&qty);
											if(qty>crossfire)
											{
												printf("Sorry, we only have %d CROSSFIRES",crossfire);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d CROSSFIRES",crossfire);
												getch();
												offroad();
											}
											crossfire=crossfire-qty;
											costumer_detail("Crossfire",qty);
											break;


									case 3:
											printf("How many XR would you rent :");
											scanf("%d",&qty);
											if(qty>xr)
											{
												printf("Sorry, we only have %d XRs",xr);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d XRs",xr);
												getch();
												offroad();
											}
											xr=xr-qty;
											costumer_detail("XR",qty);
											break;

									default:
											printf("Invalid Input Given!!! TRY AGAIN");
											getch();
											offroad();
								}

						case 'Y':
								printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
								fflush(stdin);
								scanf("%d",&choose2);
								switch(choose2)
								{
									case 1:
											printf("How many VR would you rent :");
											scanf("%d",&qty);
											if(qty>vr)
											{
												printf("Sorry, we only have %d VR",vr);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d VRs",vr);
												getch();
												offroad();
											}
											vr=vr-qty;
											costumer_detail("VR",qty);
											break;


									case 2:
											printf("How many CROSSFIRE would you rent :");
											scanf("%d",&qty);
											if(qty>crossfire)
											{
												printf("Sorry, we only have %d CROSSFIRES",crossfire);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d CROSSFIRES",crossfire);
												getch();
												offroad();
											}
											crossfire=crossfire-qty;
											costumer_detail("Crossfire",qty);
											break;


									case 3:
											printf("How many XR would you rent :");
											scanf("%d",&qty);
											if(qty>xr)
											{
												printf("Sorry, we only have %d XRs",xr);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d XRs",xr);
												getch();
												offroad();
											}
											xr=xr-qty;
											costumer_detail("XR",qty);
											break;

									default:
											printf("Invalid Input Given!!! TRY AGAIN");
											getch();
											offroad();
								}

						case 'n':
								clrscr();
								printf("\n \t \t");
								printf("\t \n \t \t \n \n \n");
								printf(" \n \t \t \t # # # # # # # # # # # # # #");
								printf(" \n \t \t \t #     1. BACK             #");
								printf(" \n \t \t \t #     3. EXIT             #");
								printf(" \n \t \t \t # # # # # # # # # # # # # #");
								printf("\n\n\n\n");
								printf("Press the corresponding Number:\n");
								scanf("%d",&back);
								if(back==1)
									select_vehicle();
								else if(back==2)
									exit(1);
								else
								{
									printf("Invalid Input given!!! TRY AGAIN");
									getch();
									offroad();
								}
								break;

					case 'N':
							clrscr();
							printf("\n \t \t");
							printf("\t \n \t \t \n \n \n");
							printf(" \n \t \t \t # # # # # # # # # # # # # #");
							printf(" \n \t \t \t #     1. BACK             #");
							printf(" \n \t \t \t #     3. EXIT             #");
							printf(" \n \t \t \t # # # # # # # # # # # # # #");
							printf("\n\n\n\n");
							printf("Press the corresponding Number:\n");
							scanf("%d",&back);
							if(back==1)
								select_vehicle();
							else if(back==2)
								exit(1);
							else
							{
								printf("Invalid Input given!!! TRY AGAIN");
								getch();
								offroad();
							}
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							offroad();
					}
			case 2:
					clrscr();
					printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
					printf("\n\t#                    OFFROAD VEHICAL RENTAL                         #");
					printf("\n\t#                          FOUR WHEELERS                             #");
					printf("\n\t#-------------------------------------------------------------------#");
					printf("\n\t# SN   #  Category    #   Quantity Available  #  price/qty(per day) #");
					printf("\n\t#-------------------------------------------------------------------#");
					printf("\n\t#  1.  #  JEEP        #         %d            #   500               #",jeep);
					printf("\n\t#  2.  #  MAHINDRA    #         %d            #   500               #",mahindra);
					printf("\n\t#  3.  #  SCORPIO     #         %d            #   500               #",scorpio);
					printf("\n\t#                                                                   #");
					printf("\n\t# # # # # # # # # #  # # # #  # # # # # # # # # # # # # # # # # # # #");
					printf("\n\n\n\n\n Confirm Rental??(Y/N) ::");
					fflush(stdin);
					scanf("%c",&confirm2);
					switch(confirm2)
					{
						case 'y':
								printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
								fflush(stdin);
								scanf("%d",&choose3);

								switch(choose3)
								{
									case 1:
											printf("How many mahindra would you rent :");
											scanf("%d",&qty);
											if(qty>mahindra)
											{
												printf("Sorry, we only have %d MAHINDRA",mahindra);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d MAHINDRA",mahindra);
												getch();
												offroad();
											}
											mahindra=mahindra-qty;
											costumer_detail("Mahindra",qty);
											break;


									case 2:
											printf("How many scorpio would you rent :");
											scanf("%d",&qty);
											if(qty>scorpio)
											{
												printf("Sorry, we only have %d SCORPIOS",scorpio);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d SCORPIOS",scorpio);
												getch();
												offroad();
											}
											scorpio=scorpio-qty;
											costumer_detail("Scorpio",qty);
											break;

									default:
											printf("Invalid Input Given!!! TRY AGAIN");
											getch();
											offroad();
								}

						case 'Y':
								printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
								fflush(stdin);
								scanf("%d",&choose4);

								switch(choose4)
								{
									case 1:
											printf("How many mahindra would you rent :");
											scanf("%d",&qty);
											if(qty>mahindra)
											{
												printf("Sorry, we only have %d MAHINDRA",mahindra);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d MAHINDRA",mahindra);
												getch();
												offroad();
											}
											mahindra=mahindra-qty;
											costumer_detail("Mahindra",qty);
											break;


									case 2:
											printf("How many scorpio would you rent :");
											scanf("%d",&qty);
											if(qty>scorpio)
											{
												printf("Sorry, we only have %d SCORPIOS",scorpio);
												getch();
												offroad();
											}
											if(qty<1)
											{
												printf("Sorry, we only have %d SCORPIOS",scorpio);
												getch();
												offroad();
											}
											scorpio=scorpio-qty;
											costumer_detail("Scorpio",qty);
											break;

									default:
											printf("Invalid Input Given!!! TRY AGAIN");
											getch();
											offroad();
								}


						case 'n':
								clrscr();
								printf("\n \t \t");
								printf("\t \n \t \t \n \n \n");
								printf(" \n \t \t \t # # # # # # # # # # # # # #");
								printf(" \n \t \t \t #     1. BACK             #");
								printf(" \n \t \t \t #     3. EXIT             #");
								printf(" \n \t \t \t # # # # # # # # # # # # # #");
								printf("\n\n\n\n");
								printf("Press the corresponding Number:\n");
								scanf("%d",&back);
								if(back==1)
									select_vehicle();
								else if(back==2)
									exit(1);
								else
								{
									printf("Invalid Input given!!! TRY AGAIN");
									getch();
									offroad();
								}
								break;

						case 'N':
								clrscr();
								printf("\n \t \t");
								printf("\t \n \t \t \n \n \n");
								printf(" \n \t \t \t # # # # # # # # # # # # # #");
								printf(" \n \t \t \t #     1. BACK             #");
								printf(" \n \t \t \t #     3. EXIT             #");
								printf(" \n \t \t \t # # # # # # # # # # # # # #");
								printf("\n\n\n\n");
								printf("Press the corresponding Number:\n");
								scanf("%d",&back);
								if(back==1)
									select_vehicle();
								else if(back==2)
									exit(1);
								else
								{
									printf("Invalid Input given!!! TRY AGAIN");
									getch();
									offroad();
								}
								break;

						default:
								printf("Invalid Input Given!!! TRY AGAIN");
								getch();
								offroad();


					}
			case 3: select_vehicle();
					break;

			case 4: exit(1);
					break;

			default:
					printf("Invalid Input Given!!! TRY AGAIN");
					getch();
					offroad();
		}

	}

}

void luxury()
{
	static int landrover=5,renault=5,volkswagan=5,nissan=5,mercedes=5;
	int choose,back,qty;
	char confirm;
	clrscr();
	while(landrover>0||renault>0||volkswagan>0||nissan>0||mercedes>0)
	{
		printf("\n\t# # # # # # # # # # # # # # ## # # # # # # # # # # # # # # # # # # #");
		printf("\n\t#                     LUXURY VEHICLE RENTAL                        #");
		printf("\n\t#------------------------------------------------------------------#");
		printf("\n\t# SN#  Category       #  Quantity Available  #  price/qty(per day) #");
		printf("\n\t#------------------------------------------------------------------#");
		printf("\n\t# 1.#  LANDROVER      #      %d            #   12000               #",landrover);
		printf("\n\t# 2.#  RENAULT        #      %d            #   6000                #",renault);
		printf("\n\t# 3.#  VOLKSWAGAN     #      %d            #   8000                #",volkswagan);
		printf("\n\t# 4.#  NISSAN CROWN   #      %d            #   9000                #",nissan);
		printf("\n\t# 5.#  MERCEDES BENZ  #      %d            #   10000               #",mercedes);
		printf("\n\t#                                                                  #");
		printf("\n\t# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #");
		printf("\n\n\n\n\n Confirm Rental??(Y/N) ::");
		fflush(stdin);
		scanf("%c",&confirm);
		switch(confirm)
		{
		case 'y':
				printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
				scanf("%d",&choose);

				switch(choose)
				{
					case 1:
							printf("How many LANDROVER car would you rent :");
							scanf("%d",&qty);
							if(qty>landrover)
							{
								printf("Sorry, we only have %d LANDROVERS",landrover);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d LANDROVERS",landrover);
								getch();
								luxury();
							}
							landrover=landrover-qty;
							costumer_detail("Landrover",qty);
							break;


					case 2:
							printf("How many renault car would you rent :");
							scanf("%d",&qty);
							if(qty>renault)
							{
								printf("Sorry, we only have %d RENAULT",renault);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d RENAULT",renault);
								getch();
								luxury();
							}
							renault=renault-qty;
							costumer_detail("Renault",qty);
							break;


					case 3:
							printf("How many volkswagan car would you rent :");
							scanf("%d",&qty);
							if(qty>volkswagan)
							{
								printf("Sorry, we only have %d VOLKSWAGAN",volkswagan);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d VOLKSWAGAN",volkswagan);
								getch();
								luxury();
							}
							volkswagan=volkswagan-qty;
							costumer_detail("Volkswagan",qty);
							break;

					case 4:
						printf("How many volkswagan car would you rent :");
							scanf("%d",&qty);
							if(qty>volkswagan)
							{
								printf("Sorry, we only have %d NISSAN",nissan);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d  NISSAN",nissan);
								getch();
								luxury();
							}
							nissan=nissan-qty;
							costumer_detail("Nissan",qty);
							break;

					case 5:
						printf("How many MERCEDES car would you rent :");
							scanf("%d",&qty);
							if(qty>mercedes)
							{
								printf("Sorry, we only have %d MERCEDES",mercedes);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d MERCEDES",mercedes);
								getch();
								luxury();
							}
							mercedes=mercedes-qty;
							costumer_detail("Mercedes",qty);
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							luxury();
				}

		case 'Y':
				printf("Choose Your Vehicle(Enter the Corresponding vehicle number) :");
				fflush(stdin);
				scanf("%d",&choose);

				switch(choose)
				{
					case 1:
							printf("How many LANDROVER car would you rent :");
							scanf("%d",&qty);
							if(qty>landrover)
							{
								printf("Sorry, we only have %d LANDROVERS",landrover);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d LANDROVERS",landrover);
								getch();
								luxury();
							}
							landrover=landrover-qty;
							costumer_detail("Landrover",qty);
							break;


					case 2:
							printf("How many renault car would you rent :");
							scanf("%d",&qty);
							if(qty>renault)
							{
								printf("Sorry, we only have %d RENAULT",renault);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d RENAULT",renault);
								getch();
								luxury();
							}
							renault=renault-qty;
							costumer_detail("Renault",qty);
							break;


					case 3:
							printf("How many volkswagan car would you rent :");
							scanf("%d",&qty);
							if(qty>volkswagan)
							{
								printf("Sorry, we only have %d VOLKSWAGAN",volkswagan);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d VOLKSWAGAN",volkswagan);
								getch();
								luxury();
							}
							volkswagan=volkswagan-qty;
							costumer_detail("Volkswagan",qty);
							break;

					case 4:
						printf("How many volkswagan car would you rent :");
							scanf("%d",&qty);
							if(qty>volkswagan)
							{
								printf("Sorry, we only have %d NISSAN",nissan);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d  NISSAN",nissan);
								getch();
								luxury();
							}
							nissan=nissan-qty;
							costumer_detail("Nissan",qty);
							break;

					case 5:
						printf("How many MERCEDES car would you rent :");
							scanf("%d",&qty);
							if(qty>mercedes)
							{
								printf("Sorry, we only have %d MERCEDES",mercedes);
								getch();
								luxury();
							}
							if(qty<1)
							{
								printf("Sorry, we only have %d MERCEDES",mercedes);
								getch();
								luxury();
							}
							mercedes=mercedes-qty;
							costumer_detail("Mercdes",qty);
							break;

					default:
							printf("Invalid Input Given!!! TRY AGAIN");
							getch();
							luxury();
				}

				case 'n':
				clrscr();
				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     3. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN");
					getch();
					luxury();
				}
				break;

		case 'N':
				clrscr();
				printf("\n \t \t");
				printf("\t \n \t \t \n \n \n");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf(" \n \t \t \t #     1. BACK             #");
				printf(" \n \t \t \t #     3. EXIT             #");
				printf(" \n \t \t \t # # # # # # # # # # # # # #");
				printf("\n\n\n\n");
				printf("Press the corresponding Number:\n");
				scanf("%d",&back);
				if(back==1)
					select_vehicle();
				else if(back==2)
					exit(1);
				else
				{
					printf("Invalid Input given!!! TRY AGAIN");
					getch();
					luxury();
				}
				break;

		default:
				printf("Invalid Input Given!!! TRY AGAIN");
				getch();
				luxury();
	}
	}
}


/*~~~~~~~~~~~~~~~~~DETAILS SECTION~~~~~~~~~~~~~~~~~~~~~~*/

void details()
{
	int choice;
	clrscr();
	printf(" \n \t \t \t # # # # # # # # # # # # # #");
	printf(" \n \t \t \t #          DETAILS        #");
	printf(" \n \t \t \t #       --------------    #");
	printf(" \n \t \t \t #     1. UPDATE RECORD    #");
	printf(" \n \t \t \t #     2. VIEW ALL RECORD  #");
	printf(" \n \t \t \t #     3. SEARCH RECORD    #");
	printf(" \n \t \t \t #     4. BACK             #");
	printf(" \n \t \t \t #     5. EXIT             #");
	printf(" \n \t \t \t # # # # # # # # # # # # # #");
	printf("\n----------------------------------------------");
	printf("\nYOUR CHOICE  : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				update_remarks();
				break;

		case 2:
				view_report();
				break;

		case 3:
				search();
				break;
		case 4:
				menu();
				break;
		case 5:
				exit(1);
				break;
		default:
			printf("\n INVALID INPUT(PLEASE TRY AGAIN...)");
			getch();
			details();
	}
}

void costumer_detail(char *vn,int amount)
{
		FILE *fptr;
		time_t t;
		time(&t);

		fptr=fopen("records.txt","a+b");

		if(fptr==NULL)
		{
			printf("file cannot be created");
			getch();
		}
	printf("\nENTER THE FIRST NAME:");
	scanf("%s",p.firstname);
	printf("\nENTER THE LAST NAME:");
	scanf("%s",p.lastname);
	printf("\nENTER PHONE NO:");
	scanf("%s",p.phoneno);
	strcpy(p.vehicle,vn);
	p.quantity=amount;
	printf("\nRented from :%s",ctime(&t));
	strcpy(p.date,ctime(&t));
	getch();
	l1:
	printf("Rent for (days):");
	scanf("%d",&p.till);
	if(p.till<=0||p.till>=30)
	{
		printf("Invalid Input given try again");
		getch();
		printf("\n\n");
		goto l1;
	}
	printf("\nENTER REMARKS:");
	scanf("%s",p.remarks);
	printf("\n");
	fwrite(&p,sizeof(p),1,fptr);
	fflush(stdin);

	fclose(fptr);
	strcpy(p.date,ctime(&t));
	printf("\n\nRecord Successfully Stored");
	getch();
	menu();

getch();
}

void view_report()
{
	struct customer p;
	FILE *fptr;
	
	fptr=fopen("records.txt","r+b");
	if(fptr==NULL)
	{
		printf("FILE DOES NOT EXIST!!!!!!");
		exit(1);
	}
	clrscr();

	while(fread(&p,sizeof(p),1,fptr))
	{
	
	printf("\n FIRST NAME : %s \t LAST NAME:%s \n  Phone no. :%s \n Vehicle Name: %s \t QUANTITY: %d \n Date: %s \n FOR(DAYS):%d \n Remarks :%s ",p.firstname,p.lastname,p.phoneno,p.vehicle,p.quantity,p.date,p.till,p.remarks);
	printf("\n ************************************************************************");
	}
	fclose(fptr);
	printf("\n\n\n\nPress Enter to Back");
	getch();
	details();
}

void update_remarks()
{

	FILE *fptr;

	char fname[20],lname[20];
	int datafound=0;
	clrscr();
	fptr=fopen("records.txt","a+b");
	printf("ENTER THE  FIRST NAME:");
	scanf("%s",fname);
	printf("\n ENTER THE LAST NAME:");
	scanf("%s",lname);
	printf("\n");
	while(fread(&p,sizeof(p),1,fptr)==1)
	{
		if(strcmp(p.firstname,fname)==0&&strcmp(p.lastname,lname)==0)
		{
			datafound=1;
			fflush(stdin);
			printf("\nold record:");
			printf("\n________________________________________________________________");
		  	printf("\n FIRST NAME : %s \t LAST NAME:%s \n  Phone no. :%s \n Vehicle Name: %s \t QUANTITY: %d \n Date: %s \n FOR(DAYS):%d \n Remarks :%s ",p.firstname,p.lastname,p.phoneno,p.vehicle,p.quantity,p.date,p.till,p.remarks);
			printf("\n_________________________________________________________________");
				printf("\nUPDATE REMARKS:\n");
				scanf(" %s",p.remarks);
				fseek(fptr,sizeof(p)*datafound,SEEK_SET);
				if(fwrite(&p,sizeof(p),1,fptr)==1)
					printf("\n Record Updated");

		  }
	 }
	 if(datafound==0)
		printf("\nMATCHING DATA NOT FOUND");

	 getch();
	 fclose(fptr);
	 printf("\nPress Enter to go to main menu");
	getch();
	menu();
}

void search()
{
	FILE *fptr;

	char fname[20],lname[20];
	int datafound=0;
	clrscr();
	fptr=fopen("records.txt","a+b");
	printf("ENTER THE  FIRST NAME:");
	scanf("%s",fname);
	printf("\n ENTER THE LAST NAME:");
	scanf("%s",lname);
	printf("\n");
	while(fread(&p,sizeof(p),1,fptr)==1)
	{
		if(strcmp(p.firstname,fname)==0&&strcmp(p.lastname,lname)==0)
		{
			datafound=1;
			fflush(stdin);	
			printf("\nCostumer Record:");
			printf("\n________________________________________________________________");
		 printf("\n FIRST NAME : %s \t LAST NAME:%s \n  Phone no. :%s \n Vehicle Name: %s \t QUANTITY: %d \n Date: %s \n FOR(DAYS):%d \n Remarks :%s ",p.firstname,p.lastname,p.phoneno,p.vehicle,p.quantity,p.date,p.till,p.remarks);
			printf("\n_________________________________________________________________");
		fseek(fptr,sizeof(p)*datafound,SEEK_SET);
		}		
	 }
	 if(datafound==0)
		printf("\nMATCHING DATA NOT FOUND");

	 getch();
	 fclose(fptr);
	 printf("\nPress Enter to go to main menu");
	getch();
	menu();
}