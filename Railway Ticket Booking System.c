#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct node{
	char name[50];
	int num_of_seats;
	int train_num;
	int booking_num;
	struct node *next;
}node; 

node *createNode()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

int login();
void traveller();
void viewdetails();
void viewticket();
void cancel();
node *readLinkedList(char[]);
void writeLinkedList(char[],node*);
void displayLinkedList(node *);
void reservation();
void ticketcollector();
void printticket(int ,char [],int ,int ,int );
void specifictrain(int);


int main()
{  
	int choice,a;
	node *head=NULL;
	//main2();
    printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              COURSE PROJECT                   |\n");
	printf("\t\t|             |    Group-4    |                 |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
	printf(" \n Press any key to continue:");
	getch();
	while(1)
	{
    system("cls");
    printf("\n=================================\n");
	printf("     \tSELECT USER");
	printf("\n=================================");
	printf("\n1>> Traveller");
	printf("\n------------------------");
	printf("\n2>> TicketCollector");
	printf("\n------------------------");
	printf("\n3>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&choice);
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	system("cls");
	switch(choice)
	{
		case 1:
			traveller();		
			break;
		case 2:
			a=login();
			if(a<=1)
			{
				ticketcollector();
			}
			break;
		case 3:
			system("cls");
			printf("  \n\n\n\n       THANK YOU !! FOR USING PUNE RESERVATION SYSTEM\n\n\n\n");
			return 0;
		default:
			printf("\nInvalid choice");
	}
    }
    return 0;
}

void traveller()
{
	while(1)
	{
	int choice;
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View Ticket Details");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			reservation();		
			break;
		case 2:
			viewticket();
			break;
		case 3:
			cancel();
			break;
		case 0:
			return;
			break;
		default:
			printf("\nInvalid choice");
	}
}
}
int login()
{
    int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    do
{
	
    printf("\n  =======================  LOGIN   =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
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
	if(strcmp(uname,"admin")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();
		system("cls");
	}	
}while(a<=1);
     if (a>1)
	{
		printf("\nSorry you have entered the wrong username and password for two times!!!");
		
		getch();
		
	}
	system("cls");	
	return a;
}
void ticketcollector()
{
	int train_num;
	char file_name[30];
	while(1)
	{
	start:
	viewdetails();
	printf("\n\nEnter train number:> ");
	scanf("%d",&train_num);
	switch(train_num)
	{
		case 1001:strncpy(file_name, "Pune to Nashik.txt", 30);
		          break;
		case 1002:strncpy(file_name, "Nashik To Pune.txt", 30);
		          break;
		case 1003:strncpy(file_name, "Pune To Nanded.txt", 30);
		          break;
		case 1004:strncpy(file_name, "Nanded To Pune.txt", 30);
		          break;
		case 1005:strncpy(file_name, "Pune To Aurangabad.txt", 30);
		          break;
		case 1006:strncpy(file_name, "Aurangabad To Pune.txt", 30);
		          break;
		case 1007:strncpy(file_name, "Pune To Ahmednagar.txt", 30);
		          break;
		case 1008:strncpy(file_name, "Ahmednagar To Pune.txt", 30);
		          break;
		case 1009:strncpy(file_name, "Pune To Satara.txt", 30);
		          break;
		case 1010:strncpy(file_name, "Satara To Pune.txt", 30);
		          break;
		case 0:   return;
		          break;
		default:printf("\nInvalid choice");
	            goto start;
	}
	system("cls");
	node *head=NULL;
	head=readLinkedList(file_name);
	displayLinkedList(head);
	printf("\n\n\n\t\tPress any key to view trains...");
	getch();
}
	
}

void viewdetails()
{
	system("cls");
	printf("-----------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tRed Lines Express\tPune to Nashik\t\tRs.5000\t\t9am");
	printf("\n1002\tRed Lines Express\tNashik To Pune\t\tRs.5000\t\t12pm");
	printf("\n1003\tNanded City Express\tPune To Nanded\t\tRs.4500\t\t8am");
	printf("\n1004\tNanded City Express\tNanded To Pune\t\tRs.4500\t\t11am");
	printf("\n1005\tSuperfast Express\tPune To Aurangabad\tRs.4000\t\t7am");
	printf("\n1006\tSuperfast Express\tAurangabad To Pune\tRs.4000\t\t9.30am");
    printf("\n1007\tKeystone Express\tPune To Ahmednagar\tRs.3500\t\t1pm");	
    printf("\n1008\tKeystone Express\tAhmednagar To Pune\tRs.3500\t\t4pm");
    printf("\n1009\tMeteor Express\t\tPune To Satara\t\tRs.6000\t\t3.35pm");
    printf("\n1010\tMeteor Express\t\tSatara To Pune\t\tRs.6000\t\t4.15pm");
}
void reservation()
{
	srand(time(0));
	char file_name[30],confirm;
	int charges,total_charges,train_num;
    node *p,*q;
    p=createNode();
    system("cls");
    printf("\nEnter the name:>");
    scanf("%s",&p->name);
    printf("\nEnter the number of tickets:>");
    scanf("%d",&p->num_of_seats);
    printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	start:
	viewdetails();
	printf("\n\nEnter train number:> ");
	scanf("%d",&train_num);
	switch(train_num)
	{
		case 1001:strncpy(file_name, "Pune to Nashik.txt", 30);
		          charges=5000;
		          break;
		case 1002:strncpy(file_name, "Nashik To Pune.txt", 30);
		          charges=5000;
		          break;
		case 1003:strncpy(file_name, "Pune To Nanded.txt", 30);
		          charges=4500;
		          break;
		case 1004:strncpy(file_name, "Nanded To Pune.txt", 30);
		          charges=4500; 
		          break;
		case 1005:strncpy(file_name, "Pune To Aurangabad.txt", 30);
		          charges=4000;
				  break;
		case 1006:strncpy(file_name, "Aurangabad To Pune.txt", 30);
		          charges=4000;
				  break;
		case 1007:strncpy(file_name, "Pune To Ahmednagar.txt", 30);
		          charges=3500;
				  break;
		case 1008:strncpy(file_name, "Ahmednagar To Pune.txt", 30);
		          charges=3500;
				  break;
		case 1009:strncpy(file_name, "Pune To Satara.txt", 30);
		          charges=6000;
				  break;
		case 1010:strncpy(file_name, "Satara To Pune.txt", 30);
		          charges=6000;
				  break;
		case 0:   return;
		          break;
		default:printf("\nInvalid choice");
	            goto start;
	}
	p->train_num=train_num;
	p->booking_num=rand();
	total_charges=p->num_of_seats*charges;
	printticket(p->booking_num,p->name,p->num_of_seats,p->train_num,total_charges);
    printf("\n\n\nConfirm Ticket (y/n):>");
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
	node *head=NULL;
	head=readLinkedList(file_name);
	if(head==NULL)
	{
    head=p;
    writeLinkedList(file_name,head);
   }
   else
   {
   q=head;
   while(q->next!=NULL)
   {
	q=q->next;
	}        
	q->next=p;
    writeLinkedList(file_name,head);	
    }
        printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
		getch();
	}
	else
	{
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
			getch();
		
    }
//    if(head==NULL)
//    {
//     head=p;
//     return head;
//    }
//    else
//    {
//        q=head;
//        while(q->next!=NULL)
//		{
//			q=q->next;
//		}        
//		q->next=p;
//		
//    }
//    return head;
}
void printticket(int booking_num,char name[],int num_of_seats,int train_num,int charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Booking Number:\t\t%d",booking_num);
	printf("\nName:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);
	printf("\nCharges:\t\t%d",charges);
}
void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tPune to Nashik\t\t");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tNashik To Pune");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tNanded City Express");
		printf("\nDestination:\t\tPune To Nanded");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tNanded City Express");
		printf("\nDestination:\t\tNanded To Pune");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tSuperfast Express");
		printf("\nDestination:\t\tPune To Aurangabad");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tSuperfast Express");
		printf("\nDestination:Aurangabad To Pune\t\t");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\nDestination:\t\tPune To Ahmednagar");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tKeystone Express");
		printf("\n Destination:\t\tAhmednagar To Pune");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tPune To Satara");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tMeteor Express");
		printf("\nDestination:\t\tSatara To Pune");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void viewticket()
{
	char file_name[30];
	int charges,total_charges,count=1,train_num,booking_num;
	start:
	viewdetails();
	printf("\n\nEnter train number:> ");
	scanf("%d",&train_num);
	switch(train_num)
	{
		case 1001:strncpy(file_name, "Pune to Nashik.txt", 30);
		          charges=5000;
		          break;
		case 1002:strncpy(file_name, "Nashik To Pune.txt", 30);
		          charges=5000;
		          break;
		case 1003:strncpy(file_name, "Pune To Nanded.txt", 30);
		          charges=4500;
		          break;
		case 1004:strncpy(file_name, "Nanded To Pune.txt", 30);
		          charges=4500; 
		          break;
		case 1005:strncpy(file_name, "Pune To Aurangabad.txt", 30);
		          charges=4000;
				  break;
		case 1006:strncpy(file_name, "Aurangabad To Pune.txt", 30);
		          charges=4000;
				  break;
		case 1007:strncpy(file_name, "Pune To Ahmednagar.txt", 30);
		          charges=3500;
				  break;
		case 1008:strncpy(file_name, "Ahmednagar To Pune.txt", 30);
		          charges=3500;
				  break;
		case 1009:strncpy(file_name, "Pune To Satara.txt", 30);
		          charges=6000;
				  break;
		case 1010:strncpy(file_name, "Satara To Pune.txt", 30);
		          charges=6000;
				  break;
		case 0:   return;
		          break;
		default:printf("\nInvalid choice");
	            goto start;
	}
	system("cls");
    printf("\nEnter the Booking Number:>");
    scanf("%d",&booking_num);
    node *head=NULL,*q=NULL;
    head=readLinkedList(file_name);
  
    q=head;
    while(q!=NULL)
    {
    	if(q->booking_num==booking_num)
    	{
    		total_charges=charges*q->num_of_seats;
    		
    		printticket(q->booking_num,q->name,q->num_of_seats,q->train_num,total_charges);
    		count=0;
    		printf("\n\n\n\tPress any key to go back to Main menu");
		    getch();
		}
    	q=q->next;
	}
	if(count)
	{
		printf("\n\n\t\tTicket not Found...");
		getch();
	}
	
}
void cancel()
{
  	char file_name[30];
	int count=1,train_num,booking_num;
	start:
	viewdetails();
	printf("\n\nEnter train number:> ");
	scanf("%d",&train_num);
	switch(train_num)
	{
		case 1001:strncpy(file_name, "Pune to Nashik.txt", 30);
		          break;
		case 1002:strncpy(file_name, "Nashik To Pune.txt", 30);
		          break;
		case 1003:strncpy(file_name, "Pune To Nanded.txt", 30);
		          break;
		case 1004:strncpy(file_name, "Nanded To Pune.txt", 30); 
		          break;
		case 1005:strncpy(file_name, "Pune To Aurangabad.txt", 30);
				  break;
		case 1006:strncpy(file_name, "Aurangabad To Pune.txt", 30);
				  break;
		case 1007:strncpy(file_name, "Pune To Ahmednagar.txt", 30);
				  break;
		case 1008:strncpy(file_name, "Ahmednagar To Pune.txt", 30);
				  break;
		case 1009:strncpy(file_name, "Pune To Satara.txt", 30);
				  break;
		case 1010:strncpy(file_name, "Satara To Pune.txt", 30);
				  break;
		case 0:   return;
		          break;
		default:printf("\nInvalid choice");
	            goto start;
	}
	system("cls");
    printf("\nEnter the Booking Number:>");
    scanf("%d",&booking_num);
    node *head=NULL,*q=NULL,*prev;
    head=readLinkedList(file_name);
    node *p,*s;
    p=head;
    q=head;
    if(q->booking_num==booking_num)
    {
      head=p->next;
      free(p);
      count=0;
      writeLinkedList(file_name,head);
    }
    else
    {
        q=q->next;
        q=q->next;
        while(p->next->booking_num!=booking_num)
        {
            p=p->next;
            q=q->next;
            if(p==NULL)
            {
            	 count++;
                 break;
            }
        }
        count--;
        s=p->next;
        p->next=q;
        free(s);
        writeLinkedList(file_name,head);
    }
    
    
	if(count)
	{
		system("cls");
		printf("\n\n\t\tTicket not Found...");
		getch();
	}
	else
	{
		system("cls");
		printf("\n\n\t\tTicket Cancelled !!");
			printf("\n\n\n\tPress any key to go back to Main menu");
		    getch();
	}
		
}
void displayLinkedList(struct node *root)
{
    struct node *temp = root;
    printf("\nBooking.No\tName of Passenger\t\tTrain Number\t\tNumber of seats\n");
    while(temp!=NULL)
    {
        printf("\n%d\t\t%s\t\t\t\t%d\t\t\t%d",temp->booking_num, temp->name,temp->train_num,temp->num_of_seats);
        temp = temp->next;
    }
}
struct node* readLinkedList(char filename[]){

    struct node* temp = (struct node *)malloc(sizeof(struct node));;
    struct node* head; // points to the first node of the linked list in the file
    struct node* last; // points to the last node of the linked list in the file
    last = head = NULL;

    FILE* file;
    file = fopen (filename, "r");
    if (file == NULL)
    {
        return NULL;
        
    }

    // reading nodes from the file
    // nodes are read in the same order as they were stored
    // we are using the data stored in the file to create a new linked list
    while(fread(temp, sizeof(struct node), 1, file))
    {

        if(head==NULL)
        {
            head = last = (struct node *)malloc(sizeof(struct node));
        }
        else
        {
            last->next = (struct node *)malloc(sizeof(struct node));
            last = last->next;
        }
        last->num_of_seats = temp->num_of_seats;
        last->train_num= temp->train_num;
        last->booking_num= temp->booking_num;
        strcpy(last->name, temp->name);
        last->next = NULL;

    }

    fclose(file);

    return head;

}

void writeLinkedList(char filename[], node* head){
    
    struct node* temp = head;
    
    FILE* file;
    FILE* file_display;
    char display[100]="print_";
    file = fopen (filename, "w");
    file_display=fopen(strcat(display,filename),"w");
    
    if (file == NULL||file_display==NULL)
    {
        printf("\nCouldn't Open File'\n");
        
    }
    
    // writing all the nodes of the linked list to the file
    else
    {


    while(temp!=NULL)
    {
    	    

        fwrite(temp, sizeof(struct node), 1, file);
       
        fprintf(file_display,"\n%d\t\t%s\t\t\t\t%d\t\t\t%d\n",temp->booking_num, temp->name,temp->train_num,temp->num_of_seats);
        
        temp = temp->next;
    }
	}
    
    fclose(file_display);
    
    fclose(file);
    
}
