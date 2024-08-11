#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//FUNC DECLARATION
int booking();
int c; //global var
int routes();
void price();
void aboutus();
void display();

//STRUCTURE USER VARIABLE
struct custinfo {
	char f_name[40];
	char l_name[40];
	char add[40];
	char pass_no[10];
	char phone_no[20];
};

//MAIN FUNCTION
int main(){
	display();//map for whole proram
}

//FUNC for showing map of program
void display(){
    system("COLOR 5E");
    printf("\n\t\tPROGRAMMING FUNDAMENTALS LAB PROJECT\n\t\t    FLIGHT MANAGEMENT SYSTEM");

    printf("\n\n\n\t\t    Welcome to FAST Airlines\n\n\n");
    int choice=0;
    printf("Follow below steps chronoogically to fly with us!\n");
    printf("Press 1 for Boooking Seats\n");
    printf("Press 2 for Routes and Price\n");
    printf("Press 3 for About us\n");
    printf("Press 0 for Exit\n\n\n");
        
    scanf("%d", &choice);
    system("cls");
    switch(choice)
    {
        case 1:     
        booking();
        break;
        		    
        case 2:
	    routes();
    	price();
    	break;
    	
    	case 3:
    	aboutus();				    	
	    break;	
	    
	    case 0:
	    	printf("\t\t*****Thank you for choosing us! Safe travels *****");
	    default:
	    	break;
}
}

//FUNC for booking seat number of flights
int booking(){
	struct custinfo ci;
    int i, j, st, z, p, l, lug;
    int s[10]={};
    int k[10]={};
    char ans, b[10];
    char ch, f;
   
   int num;
   FILE *fptr;

   fptr = fopen("C:\\Users\\OK Computers.OKComputers-PC\\Desktop\\PfProject\\PF file doc.txt","w");

   if(fptr == NULL)// file not located scenario
   {
      printf("File could not be opened!");   
      exit(1);             
   }
   //input in USER DEFINED VARIABLE
    fflush(stdin);
    printf("Enter your first name: ");
    gets(ci.f_name);
    fflush(stdin);
    printf("Enter your last name: ");
    gets(ci.l_name);
    fflush(stdin);
    printf("Enter your address: ");
    gets(ci.add);
    fflush(stdin);
    printf("Enter your passport number: ");
    gets(ci.pass_no);
    fflush(stdin);
    printf("Enter your phone number: ");
    gets(ci.phone_no);
    
    //printing input in file for Records
    fprintf(fptr,"%s%s %s %s %s",ci.f_name,ci.l_name,ci.add,ci.pass_no,ci.phone_no);
    fclose(fptr);
    
    system("cls");
    printf("\n\n   *********\n");
    printf("   Enter the number of seats you want: ");
    scanf("%d", &st);
    printf("\n   ********");    
for (j=0; j<st; j++)//loop for number of seats
{
    printf("   *****\n");
    printf("   Class\n\n   [B] Business Class\n   [E] Economic class\n\n");
    printf("   *****\n");
    printf("   Choose: ");
    fflush(stdin);
    scanf(" \n%c",&f);
switch(f)//switch for quantity and quality of pics
{      
case 'B':
    printf("   *****\n");
    printf("   Business class\n\n");
    printf("   Choose Seat(s): \n     |1|2|3|4|5|\n\n");
    printf("   *****\n");

do
{         
                b[j]='B';
                printf("   Pick a seat: ");
                scanf("%i",&p);
                s[j]=p;
   for (i=0; i<j; i++)//check to see if seat is reservred
   {
                    if (s[j]==s[i])
                    {
                        printf("\n\n   Seat taken.\n\n");
                        break;
                    }
   }
            }
            while (i!=j);
                if(s[j] <= 5)
                {
                    printf("  *****\n");
                    printf("\n");
                    printf("   Class: Business class\n");
                    printf("   Seat no : %i\n",s[j]);
                    k[j]=s[j];
                    printf("\n");
                }
                else
                printf("\nWrong seat number! \n\n");
            break;
case 'E':
    printf("   *****\n");
    printf("   Economical class\n\n");
    printf("   Seats available\n    |6|7|8|9|10|\n\n");
    printf("   *****\n");
do
{
	            b[j]='E';
                printf("   Pick a seat: ");
                scanf("%i",&p);
                s[j]=p;
   for (i=0; i<j; i++)//check to see if seat is taken or not?
   {
                    if (s[j]==s[i])
                    {
                        printf("\n\n   Seat taken.\n\n");
                        break;
                    }
   }
            }
            while (i!=j);
                if(s[j] >= 6)
                {
                    printf("   *****\n");
                    printf("\n");
                    printf("   Class: Economical class\n");
                    printf("   Seat no : %i\n",p);
                    k[j]=s[j];
                    printf("\n");
                }
                else
                {
printf("\n    Wrong seat number!  \n\n");
j=j-1;
}
            break;
        default:
                break;
                
}   
}   
    //luggage weight calculation
    printf("\nWill you be carrying luggage?\n");
    printf("1.Yes\n2.No");
    scanf("%d", &l);
    if(l=1)
    {
    	printf("Enter the weight of Luggage in kg:");
    	scanf("%d", &lug);
    	if(lug<=7)
    	{
    		printf("\nYou may carry the Luggage in plane.");
		}
		else if(lug>7 && lug<=30)
		{
			printf("\nThe Luggage will be placed in Plane Luggage Area.");
		}
		else if(lug>30)
		{
			printf("\nMaximum capacity reached! Try minimizing some of the items.");
		}
	}
    
    //printing
    printf("\nName: %s %s\n", ci.f_name, ci.l_name);          
    printf("Address: %s\n", ci.add);
    printf("Passport number: %s\n", ci.pass_no);
    printf("Phone number: %s\n\n", ci.phone_no);
    printf("Number of seats: %d\n", st);
    printf("Seats taken are:\n");
    for(i=0; i<st; i++)
    {
    	if(b[i]=='B')
    	{
    		printf("Business class seat's number: %d\n",s[i]);
		}
		else if (b[i]=='E')
		{
		  	printf("Economic class seat's number: %d\n",s[i]);
		}	
	}

	printf("Press any number key to return to main menu. \n");
	scanf("%d", &z);
	if(z=1)
	{
		display();
	}
}

//FUNCTION to Tell user about Routes and Prices
int routes()
{
	int r;
	printf("Enter the country you want to travel from the given options\n");
	printf("1.USA\n2.Canada\n3.Japan\n4.Switzerland\n5.Australia\n");
	scanf("%d",&c);
	printf("Do you want Direct flight or Connecting flight\n");
	printf("1.Direct Flight\n2.Connecting Flight\n");
	scanf("%d",&r);
	switch(c)
	{
		case 1:
			switch(r)
			{
				case 1:
					printf("Booked\n");
					break;
				case 2:
					printf("The connecting flight will land first in Morrocow\n");
					break;
			}
			break;
		case 2:
			switch(r)
			{
				case 1:
					printf("Booked\n");
					break;
				case 2:
					printf("The connecting flight will land first in Saudi Arabia\n");
						break;
			}
				break;
		case 3:
			switch(r)
			{
				case 1:
					printf("Booked\n");
						break;
				case 2:
					printf("The connecting flight will land first in Spain\n");
						break;
			}
				break;
		case 4:
			switch(r)
			{
				case 1:
					printf("Booked\n");
						break;
				case 2:
					printf("The connecting flight will land first in Germany\n");
						break;
			}
				break;
		case 5:
			switch(r)
			{
				case 1:
					printf("Booked\n");
						break;
				case 2:
					printf("The connecting flight will land first in Qatar\n");
						break;
			}
			break;
				
	}
	//Duration of flight
	int t;	
	printf("Would you like to know the duration of your flight\n");
	printf("1.Yes\n2.No\n");
	scanf("%d",&t);
	if(t==1)
	{
	switch(c)
	{
		case 1:
			switch(r)
			{
				case 1:
					printf("Your flight will take 15 hours to reach your destination\n");
						break;
				case 2:
					printf("Your flight will take 22 hours to reach your destination\n");
						break;
			}
			break;
		case 2:
			switch(r)
			{
				case 1:
					printf("Your flight will take 16 hours to reach your destination\n");
						break;
				case 2:
					printf("Your flight will take 20 hours to reach your destination\n");
						break;
			}
				break;
		case 3:
			switch(r)
			{
				case 1:
					printf("Your flight will take 15 hours to reach your destination\n");
						break;
				case 2:
					printf("Your flight will take 22 hours to reach your destination\n");
						break;
			}
				break;
		case 4:
			switch(r)
			{
				case 1:
					printf("Your flight will take 5 hours to reach your destination\n");
						break;
				case 2:
					printf("Your flight will take 10 hours to reach your destination\n");
						break;
			}
		case 5:
			switch(r)
			{
				case 1:
					printf("Your flight will take 17 hours to reach your destination\n");
						break;
				case 2:
					printf("Your flight will take 20 hours to reach your destination\n");
						break;
			}		
		}
	}
	else
	{
		printf("Thank You");
	}
	return c;
}
//FUNCTION to show price amount
void price()
{
	int p, z;
	printf("\n\nWould you like to go for one way ticket or return ticket\n");
	printf("1.One way Ticket\n2.Return Ticket\n");
	scanf("%d", &p);
	switch(p)
	{
		case 1:
			switch(c)
			{
				case 1:
					printf("The price of the ticket is $2500\n");
					break;
				case 2:
					printf("The price of the ticket is $5500\n");
					break;
				case 3:
					printf("The price of the ticket is $1500\n");
					break;
				case 4:
					printf("The price of the ticket is $4700\n");
					break;
				case 5:
					printf("The price of the ticket is $2800\n");
					break;
			}
			break;
		case 2:
			switch(c)
			{
				case 1:
					printf("The price of the ticket is $6000");
					break;
				case 2:
					printf("The price of the ticket is $1110");
				case 3:
					printf("The price of the ticket is $4500");
					break;
				case 4:
					printf("The price of the ticket is $1110");
				case 5:
					printf("The price of the ticket is $8000");
			        break;
		        default:
					break;
	}
	printf("Press any number key to return to main menu. \n");
	scanf("%d", &z);
	if(z=1)
	{
		display();
	}
}
}
//FUNCTION answering common queastings regarding Enlish
void aboutus()
{
	int n, z;
	printf("1.Company information\n2.Luggage Information\n3.Staff Information\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("\t\tWelcome to FAST Airlines \n");
			printf("\nThere are total 7 flights operational with 5 currently on their journey");
			printf("This project is develpoed by Saad Ahmed, Ali Raza and Ali Haris with team efforts. \n");
			break;
		case 2:
		printf("For hand luggage, the limitation is of 7Kg\n Luggage more than this will go under the plane luggage area\n Total limitation is of 30Kg\n");
		break;	
		case 3:
			printf("The Airline is operating under 800 Staff members\nWith 60 pilots\n50 air hostess\100 other staff for branch\n");
			break;
		default:
			break;
	}
	printf("Press any number key to return to main menu. \n");
	scanf("%d", &z);
	if(z=1)
	{
		display();
	}
}


