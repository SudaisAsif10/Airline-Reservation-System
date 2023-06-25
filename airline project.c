#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct Passenger{
	char name[30];
	char address[50];
	char passport[50];
	char eticketno[50];
	char contact[15];
	int luggage;
	char depart[20];
	char arrival[20];
	int seats;
} ;

void welcomescreen(struct Passenger pass[]);
void loginscreen(int,struct Passenger pass[]);
void title();
void mainmenu(struct Passenger pass[],int,int);
void reserve(struct Passenger pass[],int,int);
void display(struct Passenger pass[],int,int);
void retain(struct Passenger pass[],int);

main(){
	struct Passenger pass[100];
	system("color F1");
	welcomescreen(pass);
	
}

void title(){
	printf("\t\t\t\t\t---------------------------\n");
	printf("\t\t\t\t\t  FAST AIRLINE MANAGEMENT\n");
	printf("\t\t\t\t\t---------------------------\n");
}

void welcomescreen(struct Passenger pass[])
{
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t  **************************************");
	printf("\n\t\t\t\t\t  #\t\t WELCOME TO\t       #");
	printf("\n\t\t\t\t\t  #\t       FAST AIRLINES\t       #");
	printf("\n\t\t\t\t\t  **************************************");
	printf("\n\n\n\nPress any key to continue");
	getch();
	system("cls");
	loginscreen(0,pass);
}

void loginscreen( int i,struct Passenger pass[]){
	title();
	char username[20]="NUCES";
	char password[20]="12345";
	char un[20];
	char pw[20];
	printf("\n\t\t\t\t\t   Enter Username: ");
	gets(un);
	fflush(stdin);
	printf("\n\t\t\t\t\t   Enter password: ");
	gets(pw);
	
	if(strcmp(un,username)==0 && strcmp(pw,password)==0)
	{
		system("cls");
		mainmenu(pass,0,0);
	}
	else
	{
		if(i<=1)
		{
			printf("\n\n\t\t\t\t       incorrect username or password.\nPress any key to continue");
			getch();
			system("cls");
			loginscreen(i+1,pass);
		}
		else{
			printf("\n\n\t\t\t\t       Access denied.");
		}
	}
}

void mainmenu(struct Passenger pass[],int i,int ctr)
{
	int choice;
	title();
	printf("\n\n\t\t\t\t\t 1.Reserve Seat");
	printf("\n\n\t\t\t\t\t 2.Display Reserved Seats");
	printf("\n\n\t\t\t\t\t 3.Retain a Seat");
	printf("\n\n\t\t\t\t\t 4.Exit");
	printf("\n\n\t\t\t\t\tEnter your choice: ");
	scanf("%d", &choice);
	system("cls");
	
	switch(choice)
	{
		case 1:{
			reserve(pass,i,ctr);
			break;
		}
		case 2:{
	        system("cls");
			display(pass,i,ctr);
			break;
		}
		case 3:{
		    system("cls");
			retain(pass,ctr);
			break;
		}
		case 4:{
			printf("\n\t\t\t\t\tHave a good day...Comeback later");
			exit (0);
			break;
		}
		default:{
			printf("\n\n\t\t\t\tSorry Invalid choice, please select from 1-4");
			printf("\n\n\t\t\t\t      press any key to continue");
			getch();
			system("cls");
			mainmenu(pass,i,ctr);
			break;
		}
		
		
	}
}

void reserve(struct Passenger pass[],int i,int ctr)
{
	FILE *fp;
	fp = fopen("passengers.txt", "a");
	char ans;
	title();
	printf("\n\t\t\t\t  Reserve A Seat");
	printf("\n\n\t\t\t\t\t  Enter Name: ");
	fflush(stdin);
	gets(pass[i].name);
	fflush(stdin);
	printf("\n\t\t\t\t\t  Enter address: ");
	fflush(stdin);
	gets(pass[i].address);
	printf("\n\t\t\t\t\t  Enter Contact number: ");
	gets(pass[i].contact);
	fflush(stdin);
	printf("\n\t\t\t\t\t  Enter passport: ");
	fflush(stdin);
	gets(pass[i].passport);
	fflush(stdin);
	printf("\n\t\t\t\t\t  Enter E-ticket number: ");
	gets(pass[i].eticketno);
	fflush(stdin);
	printf("\n\t\t\t\t\t  Enter number of luggage: ");
	scanf("%d", &pass[i].luggage);
	printf("\n\t\t\t\t\t  Enter your departure airport: ");
	fflush(stdin);
	gets(pass[i].depart);
	printf("\n\t\t\t\t\t  Enter your arrival airport: ");
	fflush(stdin);
	gets(pass[i].arrival);
	printf("\n\t\t\t\t\t  Enter number of seats you want to reserve: ");
	scanf("%d",&pass[i].seats);
	
	fprintf(fp,"%s %s %s %s %s %d %s %s %d\n", pass[i].name, pass[i].address, pass[i].contact,pass[i].passport, pass[i].eticketno, pass[i].luggage, pass[i].depart,pass[i].arrival,pass[i].seats);
	printf("\n\n\t\t\t\t\t    Seat reserved successfully!!!");
	fclose(fp);
	
	printf("\n\n\t\t\t\tDo you want to reserve more seats? Type Y or N: ");
	fflush(stdin);
	scanf("%c", &ans);
	if(ans=='Y' || ans=='y'){
		system("cls");
		reserve(pass,i+1,ctr+1);
	}
	else if( ans=='N' || ans=='n'){
		system("cls");
		mainmenu(pass,i,ctr+1);
	}
	else{
		printf("\n\n\t\t\t\t\t     Invalid choice");
		getch();
		mainmenu(pass,i,ctr);
	}
}

void display(struct Passenger pass[],int i,int ctr){
	FILE *fptr;
	fptr=fopen("passengers.txt","r");
	if(fptr==NULL){
		printf("File not found!!To proceed enter any key ");
		getch();
		system("cls");	
       mainmenu(pass,ctr,i);
	}
	title();
	printf("\n\n\t\t\t   List of Passenger Record \n");
	int j;
	char ans;
char str[100];
fgets(str,100,fptr);
int x=0;
while(!feof(fptr))
{
	struct Passenger *p=pass+x;
	sscanf(str,"%s %s %s %s %s %d %s %s %d",&p->name,&p->address,&p->contact,&p->passport
	,&p->eticketno,&p->luggage,&p->depart,&p->arrival,&p->seats);
	fgets(str,100,fptr);
	x++;
}
int n=x;
for(j=0;j<n;j++){
	printf("\n");
printf("%s",pass[j].name);

printf("\t%s",pass[j].address);

printf("\t%s",pass[j].contact);

printf("\t%s",pass[j].passport);

printf("\t%s",pass[j].eticketno);

printf("\t%d",pass[j].luggage);

printf("\t%s",pass[j].depart);

printf("\t%s",pass[j].arrival);

printf("\t%d",pass[j].seats);

}

fclose(fptr);
printf("\nDo you want to proceed (Y/N)");

scanf(" %c",&ans);
if(ans=='Y' || ans=='y')
{
system("cls");	
mainmenu(pass,ctr,i);
}
else if(ans=='N' || ans=='n'){ 
system("cls");
exit(0);
}
else
printf("INVALID ENTRY!!");
}



void retain(struct Passenger pass[],int ctr){
	FILE *fptr,*fptr1;
    fptr=fopen("passengers.txt","r");
    fptr1=fopen("temp1.txt","a");
	title();
	char ans;
	int i,l=0;
	char name[20];
	printf("\n\n\t\t\t Delete Passenger's Record \n");
	fflush(stdin);
	printf("\n\n\t\t\tEnter the name of Passenger whose record you want to delete ");
	gets(name);
	fflush(stdin);
    struct Passenger p;
   	while (fscanf(fptr,"%s %s %s %s %s %d %s %s %d",p.name,p.address,p.contact,p.passport,p.eticketno,&p.luggage,p.depart,p.arrival,&p.seats)!=EOF)
	{
		if (strcmp(p.name,name)==0){
			
			l=1;
		}
		else 
		{
			fprintf(fptr1,"%s %s %s %s %s %d %s %s %d\n", p.name, p.address, p.contact, p.passport, p.eticketno, p.luggage, p.depart, p.arrival, p.seats);
		}
	}
	
	if(l==0)
	{
		printf("\n\n\t\tRecord not found!!");
		printf("\n\n\t\tDo you want to proceed (Y/N)");	
		scanf("%c",&ans);
    if(ans=='Y' || ans=='y')
    {
        system("cls");	
        mainmenu(pass,ctr,i);
    }
    else if(ans=='N' || ans=='n'){ 
        system("cls");
        exit(0);
    }
    else
        printf("IVALID ENTRY!!");
}
    else
    {		
        fclose(fptr);
        fclose(fptr1);
        remove("passengers.txt");
        rename("temp1.txt","passengers.txt");
        printf("\n\n\t\tYour data has been deleted.Do you want to delete more record (Y/N)");
        scanf(" %c",&ans);
        if(ans=='Y' || ans=='y')
        {
           system("cls");	
           return 	retain(pass,ctr);
        }
        else if(ans=='N' || ans=='n'){ 
           system("cls");
           mainmenu(pass,ctr,i);
        }
        else
        printf("IVALID ENTRY!!");
	
	
}
}
