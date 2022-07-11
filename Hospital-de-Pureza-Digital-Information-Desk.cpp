//FOR HOSPITAL PERSONNEL 
// COVID DOCTOR PASSWORD = 1234
//CHECK UP DOCTOR PASSWORD = 9876

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
void fullscreen();
int patient();
int patientMenu();
int covid();
int checkup();
int menu();
int doctor(); 
void patientInfoWrite();
int readaccounts ();

/** STRUCT FOR COVID INFO**/
struct tagname 
{ //SIGN UP PROCEDURE OR LOG IN
  char password[30]; //must be not empty
  char email[30];
  char lastname[20];
  char firstname[20];
  char sex[7];
  char address[30];
  int age;
  char contact[12];
  // SCHEDULE CHECK UP
  // if patient transaction is for covid whereabouts, these must be initialized to 0 or null
  int checkupDay; 
  //COVID WHEREABOUTS
  // if patient transaction is for scheduled check up, these must be initialized to 0 or null
  float temp;  
  int cough;
  int sneeze; 
  int fever;
  int breathing; 
  int soreThroat;
  int loss;
  char covidTime[10];
} add_menu_field[50];

int numPatients=0; //num of patients that will sign up. 
int mon=0, tues=0, wed=0; //3 patients per day is the maximum due to covid protocols, if 3 is reached then patient can no longer plan a sched on that day

//variable that is not included in the file handling
int numPatientTemp=0;

//automatically maximize the screen upon run
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void gotoxy(short x, short y) //function for the gotoxy
{COORD po = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), po);
	COORD coord={0,0}; }
	
void brand () //function for borders and design
{int n, j; //variables for lines
system("COLOR 2E");  	
for(j=2; j<7; j++)
 	{gotoxy(7,j);
  	printf("%c",219); }
for(j=2; j<7; j++)
 	{gotoxy(15,j);
  	printf("%c",219); }
gotoxy(7,4);
	for(n=1;n<=9;n++)
		printf("%c",219);
  	
for(j=1; j<35;j++)
 	{gotoxy(25,j);
  	printf("%c",215); }

gotoxy(0,9);
	for(n=1;n<=119;n++) 
		printf("%c",220);

		
gotoxy(3,8);
printf("Hospital De Pureza\n\n\n\n    We Care For Your\n Privacy As We Care For\n      Your Health");	
}

/*** MAIN FUNCION ***/
int main(){
	fullscreen();
	readaccounts ();
	menu();
}

/*** MENU METHOD ***/
int menu(){
	system("cls");
	int num;
		
gotoxy(5,12);
printf("\n\n\n\n\n\t MENU");
printf("\n\n  1. PATIENT\n  2. HOSPITAL PERSONNEL\n  3. EXIT");
printf("\n\n      Kindly input\n   your answer here:\n       (1,2,3)\n\t ___"); 	
	 brand();
gotoxy(10,26);
{scanf("%d", &num);
}

if (num==1){
	system("cls");
	patient();
}
else if (num==2){
	doctor();
}
else if(num==3){
	system("cls");
	gotoxy(2,20);
	printf("Thank you for using\n\t this app.\n\n  Press Enter to Exit.");
	brand();
	gotoxy(2,30);
	getch();

}
else{
	gotoxy(2,28);
	printf("Wrong input!Try Again!\n\n Kindly Press Enter :)");
	getch();
	menu();
	
}
}

/*** LOG IN OR SIGN UP***/
int patient(){
	
	system("cls"); 
	
	int num;
	char tempEmail[30];
	char tempPassword[30];
	int passed=0;
	
gotoxy(5,12);
printf("\n\n\n\n      PATIENT MENU");
printf("\n\n     1. LOG-IN\n  (Already have account)\n     2. SIGN UP\n  (Have no account)\n ");
printf("\n\n      Kindly input\n   your answer here:\n       (1,2)\n\t ___"); 	
	 brand();
gotoxy(10,27);
{scanf("%d", &num);
}

if(num==1){ 
	do{system("cls");
	patientInfoWrite();
	gotoxy(35,12);
	printf("Please make sure you already have an account...\n\n\t\t\t\tEMAIL ADDRESS:\n\t\t\t\tPASSWORD");
	brand();
	gotoxy(46,14);
	{printf("(Ex: mira@yahoo.com)> ");
	scanf(" %s", &tempEmail);
	}
	gotoxy(42,15);
	{printf("(Ex: abcde)> ");
	scanf(" %s", &tempPassword);
	}
	for(int i=0; i<=numPatients; ++i){ 
		if(strcmpi(tempEmail,add_menu_field[i].email)==0 && strcmpi(tempPassword,add_menu_field[i].password)==0){		
			numPatientTemp=i;
			patientMenu();
			passed=1;
		}

	}
	if (passed==0){
		gotoxy(42,17);
			printf("WRONG DATA!  PRESS ENTER TO TRY AGAIN!");
		}
		getch();
	}while(passed==0);
}
if(num==2){ // IF SIGN UP
	gotoxy(35,12);
	printf("SIGN UP: (Please Fill Up The Following):\n\n\t\t\t\tLAST NAME:\n\t\t\t\tFIRST NAME:\n\t\t\t\tAGE:\n\t\t\t\tSEX:\n\t\t\t\tRESIDENTIAL ADDRESS:\n\t\t\t\tCONTACT NUMBER:\n\n\t\t\t\tEMAIL ADDRESS:\n\t\t\t\tPASSWORD:");
	gotoxy(42,14);
	{printf("(Ex: DAVID)> ");
	scanf(" %s", &add_menu_field[numPatients].lastname);
	}
	gotoxy(43,15);
	{printf("(Ex: MIRA)> ");
	scanf(" %s", &add_menu_field[numPatients].firstname);
	}
	gotoxy(36,16);
	{printf("(Ex:24)> ");
	scanf(" %d", &add_menu_field[numPatients].age);
	}
	gotoxy(36,17);
	{printf("(Ex:F)> ");
	scanf(" %s", &add_menu_field[numPatients].sex);
	}
	gotoxy(52,18);
	{printf("(Ex: 116_MAKATI_CITY)> ");
	scanf(" %s", &add_menu_field[numPatients].address);
	}
	gotoxy(48,19);
	{printf("(Ex: 09123456789)> ");
	scanf(" %s", &add_menu_field[numPatients].contact);
	}
	gotoxy(46,21);
	{printf("(Ex: mira@yahoo.com)> ");
	scanf(" %s", &add_menu_field[numPatients].email);
	}
		gotoxy(42,22);
	{printf("(Ex: abcde)> ");
	scanf(" %s", &add_menu_field[numPatients].password);
	}
	numPatientTemp=numPatients;
	++numPatients;
		gotoxy(42,23);
		printf("Thank you for being honest! Press Enter to Continue...");
	add_menu_field[numPatientTemp].checkupDay=0;	
	add_menu_field[numPatientTemp].temp=0;
	add_menu_field[numPatientTemp].cough=0;
	add_menu_field[numPatientTemp].sneeze=0;
	add_menu_field[numPatientTemp].fever=0;
	add_menu_field[numPatientTemp].breathing=0;
	add_menu_field[numPatientTemp].soreThroat=0;
	add_menu_field[numPatientTemp].loss=0;
	strcpy(add_menu_field[numPatientTemp].covidTime,"0");
	
		getch();
		patientMenu();
}
else{
	gotoxy(2,28);
	printf("Wrong input!Try Again!\n\n Kindly Press Enter :)");
	getch();
	patient();
}
}

int patientMenu(){ //PATIENT MENU
	int num;
	
	system("cls");
gotoxy(5,12);
printf("\n\n\n\n\t MENU");
printf("\n\n   1. COVID ADMISSION\n\n   2. SCHEDULED CHECK UPS\n   ");
printf("\n\n      Kindly input\n   your answer here:\n       (1,2)\n\t ___"); 	
	 brand();
gotoxy(10,26);
{scanf("%d", &num);
}
if (num==1){
	covid();
}
else if (num==2){
	checkup();
}
else{
	gotoxy(2,28);
	printf("Wrong input!Try Again!\n\n Kindly Press Enter :)");
	getch();
	patientMenu();
}	
}

int covid(){ // COVID ADMISSION FUNCTION
		system("cls");
	gotoxy(35,12);
	printf("COVID PERSONAL INFORMATION\n\n\t\t\t\tThe following information would be confidential.");
	gotoxy(32,18);
	printf("Current Temp>\n\n\t\t\t\tAre you having...\n\t\t\t\tCough>\n\t\t\t\tSneeze>\n\t\t\t\tFever>\n\t\t\t\tDifficulty in breathing>\n\t\t\t\tSore Throat>\n\t\t\t\tLoss of Smell and Taste>");
	brand();
	
	gotoxy(45,18);
	{printf("(Ex: 38.5)>");
	 scanf("%f", &add_menu_field[numPatientTemp].temp);
	}
	gotoxy(40,21);
	{printf("YES=1,NO=2 (Ex: 1)>");
	 scanf("%d", &add_menu_field[numPatientTemp].cough);
	}
	gotoxy(40,22);
	{printf("YES=1,NO=2 (Ex: 1)>");
	 scanf("%d", &add_menu_field[numPatientTemp].sneeze);
	}
	gotoxy(40,23);
	{printf("YES=1,NO=2 (Ex: 1)>");
	 scanf("%d", &add_menu_field[numPatientTemp].fever);
	}
	gotoxy(56,24);
	{printf("YES=1,NO=2 (Ex: 1)>");
	 scanf("%d", &add_menu_field[numPatientTemp].breathing);
	}
	gotoxy(46,25);
	{printf("YES=1,NO=2 (Ex: 1)>");
	 scanf("%d", &add_menu_field[numPatientTemp].soreThroat);
	}
	gotoxy(58,26);
	{printf("YES=1,NO=2 (Ex: 1)>");
	 scanf("%d", &add_menu_field[numPatientTemp].loss);
	}
	getch();
	
	system("cls");
	gotoxy(35,12);
	printf("Please Proceed To Our Covid Ward\n\n\t\t\t\t1st Floor-ROOM 128.\n\n\t\t\t\tYou Can Contact: 09876543211");
	gotoxy(35,18);
	printf("Please specify the time of your arrival.\n\t\t\t\tSo that we can assist you better(9AM)>\n\n\n\t\t\t\tThank you!");
	brand();
	gotoxy(71,19);
	{printf(" ");
	scanf(" %s", &add_menu_field[numPatientTemp].covidTime);
	}
	
	patientInfoWrite();	
	getch();
	system("cls");
	menu();
}

int checkup(){ //CHECK UP FUNCTION
	int error;
	do{ 
	system("cls");
	gotoxy(35,12);
	printf("GENERAL PHYSICIANS\n\n\t\t\t\t-DR. MARIA RAMOS\n\n\t\t\t\t-MONDAY TO WEDNESDAY\n\n\t\t\t\t-9AM to 11AM");
	gotoxy(32,20);
	printf("Maximum of 3 patients per day are allowed due to new normal protocols");
	gotoxy(32,22);
	printf("Set your schedule day:\n\t\t\t\t1.Monday\n\t\t\t\t2.Tuesday\n\t\t\t\t3.Wednesday> ");
	brand();
	gotoxy(32,26);
	{
	printf("Schedule (1,2,3)>");
	scanf("%d", &add_menu_field[numPatientTemp].checkupDay);
	if(add_menu_field[numPatientTemp].checkupDay==1)
		{	if(mon==3){
				gotoxy(32,28);
				printf("Sorry, we have enough patients for this day! Try for another day. Thank you for your patience.");
				error=1;	
			}
			else{
			++mon; error=0;
			gotoxy(32,28);
			printf("You are scheduled for Dr. Ramos on Monday. Thank you");
			}			
		}
		
	if(add_menu_field[numPatientTemp].checkupDay==2)
			{	if(tues==3){
				gotoxy(32,28);
				printf("Sorry, we have enough patients for this day! Try for another day. Thank you for your patience.");
				error=1;	
			}
		else{
			++tues; error=0;
			gotoxy(32,28);
			printf("You are scheduled for Dr. Ramos on Tuesday. Thank you");
			}			
		}
		
	if(add_menu_field[numPatientTemp].checkupDay==3)
			{	if(wed==3){
				gotoxy(32,28);
				printf("Sorry, we have enough patients for this day! Try for another day. Thank you for your patience.");
				error=1;	
			}
	else {
			++wed; error=0;
			gotoxy(32,28);
			printf("You are scheduled for Dr. Ramos on Wednesday. Thank you");
			}			
		}
		
	else if(add_menu_field[numPatientTemp].checkupDay>3)
		{error=1;
		gotoxy(35,28);
		printf("Wrong input, try again!");
		}		
		getch();
	}	
	}while(error==1);
	
	patientInfoWrite();
	getch();
	system("cls");
	menu();
	
}
	
int doctor(){ //Function for hospital personnel
	int answer;
	int correct;
	system("cls");
	gotoxy(35,18);
	printf("GOOD DAY HEALTH PROFFESIONALS!\n\n\t\t\t\tENTER YOUR PASSWORD>");
	brand();
	gotoxy(55,20);
	printf(" ");
	scanf("%d", &answer);
	
	if(answer==1234){ // info about covid
	system("cls");
	gotoxy(40,12);
	printf("EACH DAY IS A SURVIVAL DAY! LET'S DO OUR BEST!\n\n\t\t\t\tNote: These data are highly confidential.(SYMPTOMS> 1=YES, 2=NO)");
	gotoxy(32,16);
	printf("Last Name\tFirst Name\tAge\tSex\tAddress\t\t     Contact Number\tArrival");
	gotoxy(35,17);
	{for(int i=0; i<numPatients; ++i){
		if(add_menu_field[i].temp!=0){
			printf("\n\t\t\t\t%-15s %-15s %d\t%-7s %-20s %-18s %s", add_menu_field[i].lastname, add_menu_field[i].firstname, add_menu_field[i].age, add_menu_field[i].sex, add_menu_field[i].address, add_menu_field[i].contact, add_menu_field[i].covidTime);
		}	}
	}

	gotoxy(32,35);													
	printf("CurrentTemp\tCough\tSneeze\tFever\tDifficultyInBreathing\tSoreThroat\tLossOfSmellandTaste");
	gotoxy(32,36);
	{for(int i=0; i<numPatients; ++i){
		if(add_menu_field[i].temp!=0){
			printf("\n\t\t\t\t   %-14.2f %-8d %-6d %-15d %-18d %-16d %d", add_menu_field[i].temp, add_menu_field[i].cough, add_menu_field[i].sneeze, add_menu_field[i].fever, add_menu_field[i].breathing, add_menu_field[i].soreThroat, add_menu_field[i].loss);
		}	}
	}
	
	brand();
	
	gotoxy(50,50);
	getch();
	menu();
	}
	else if(answer==9876){//info about check ups
	system("cls");
	gotoxy(40,12);
	printf("TREAT EACH DAY AS A BLESSING!\n\n\t\t\t\tNote: These data are highly confidential.(SCHEDULE> 1=Monday 2=Tuesday 3=Wednesday)");
	gotoxy(32,16);
	printf("Last Name\tFirst Name\tAge\tSex\tAddress\t\t     Contact Number\tSchedule");
	gotoxy(35,17);
	{for(int i=0; i<numPatients; ++i){
		if(add_menu_field[i].checkupDay!=0){
			printf("\n\t\t\t\t%-15s %-15s %d\t%-7s %-20s %-21s %d", add_menu_field[i].lastname, add_menu_field[i].firstname, add_menu_field[i].age, add_menu_field[i].sex, add_menu_field[i].address, add_menu_field[i].contact, add_menu_field[i].checkupDay);
		}	}
	}
	
	brand();
	
	gotoxy(50,50);
	getch();
	menu();		
	}
	else{
		
	gotoxy(40,14);
	printf("WRONG PASSWORD!");
	getch();
	menu();
		
	}
}

void patientInfoWrite()
{int count;
FILE *ptr2;
ptr2=fopen("PatientInfo.txt", "w");
  	 fprintf(ptr2, "%8d", numPatients);
  	 fprintf(ptr2, "%8d", mon);
  	 fprintf(ptr2, "%8d", tues);
  	 fprintf(ptr2, "%8d", wed);
  	 fputs("\n\n ", ptr2);
	  
  for(count=0; count<numPatients; count++)
  {fputs("     ", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].password);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].email); 
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].lastname);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].firstname);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].sex);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].address);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].age );
  	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].contact);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].checkupDay);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%f ", add_menu_field[count].temp );
  	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].cough);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].sneeze);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].fever );
  	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].breathing);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].soreThroat);
	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%d ", add_menu_field[count].loss );
  	fputs("\t\t", ptr2);
  		fprintf(ptr2, "%s ", add_menu_field[count].covidTime);
	fputs("\n", ptr2);
	}
	fclose(ptr2);
}

int readaccounts ()
{ FILE *ptr5;
ptr5=fopen("PatientInfo.txt", "r");

int i;

fscanf(ptr5, "%d", &numPatients);
fscanf(ptr5, "%d", &mon);
fscanf(ptr5, "%d", &tues);
fscanf(ptr5, "%d", &wed);

for(i=0; i<numPatients; i++)
fscanf(ptr5, "%s %s %s %s %s %s %d %s %d %f %d %d %d %d %d %d %s", &add_menu_field[i].password, &add_menu_field[i].email, add_menu_field[i].lastname, add_menu_field[i].firstname, &add_menu_field[i].sex, &add_menu_field[i].address, &add_menu_field[i].age, &add_menu_field[i].contact, &add_menu_field[i].checkupDay, &add_menu_field[i].temp, &add_menu_field[i].cough, &add_menu_field[i].sneeze, &add_menu_field[i].fever, &add_menu_field[i].breathing, &add_menu_field[i].soreThroat,&add_menu_field[i].loss, &add_menu_field[i].covidTime );
fclose(ptr5);
return 0;
}
  
