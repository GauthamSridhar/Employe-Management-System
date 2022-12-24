#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct Employee
{
char empID[15];
char fname[20];
char lname[20];
int age;
float sal1;
float bonus;
float dm,dl;
} Employee;
FILE *fp;
Employee emp;
char fileName[]="EMP.txt";
char tempFileName[]="temp.txt";
void AddEmployee();
void ListEmployee();
void SearchEmployee();
void ModifyEmployee();
void DeleteEmployee();
void first();
char file();
void main()
{
char ch='a';
int gd=DETECT,gm,x,y;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
clrscr();
first();
fp=fopen(fileName,"rb+");
if(fp==NULL)
{
fp=fopen( fileName,"wb+");
if(fp==NULL)
{
printf("Can't Open File");
exit();
}
}
while(ch!='6')
{
ch=file();
switch(ch)
{
case '1':
AddEmployee();
break;
case '2':
ListEmployee();
break;
case '3':
SearchEmployee();
break;
case '4':
ModifyEmployee();
break;
case '5':
DeleteEmployee();
break;
case '6':
exit(0);
break;
default:
gotoxy(30,10);
printf("WRONG CHOICE!!!");
getch();
break;
}
}
}
void AddEmployee()
{
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_END);
another='Y';
gotoxy(25,3);
printf("ADD EMPLOYEE RECORD");
gotoxy(25,6);
printf("1.ENTER EMPLOYEE ID: ");
gets(emp.empID);
gotoxy(25,7);
printf("2.ENTER FIRST NAME OF EMPLOYEE: ");
gets(emp.fname);
gotoxy(25,8);
printf("3. ENTER LAST NAME OF EMPLOYEE: ");
gets(emp.lname);
gotoxy(25,9);
printf("4.ENTER AGE OF EMPLOYEE:");
scanf("%d",&emp.age);
gotoxy(25,10);
printf("5.ENTER BASE SALARY OF EMPLOYEE:");
scanf("%f",&emp.sal1);
gotoxy(25,12);
textcolor(MAGENTA + BLINK);
printf("SAVE CHANGE (y/n)?");
ch=getch();
if(ch=='y'||ch=='Y')
{
fwrite(&emp,sizeof(emp),1,fp);
fflush(stdin);
}
gotoxy(28,15);
printf("ADD ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'|| another=='y');
}
void ListEmployee()
{
double sal2;
int i;
char ch;
gotoxy(1,1);
printf("Do You Want Final Salary(y/n)\n");
ch=getch();
if(ch=='y'||ch=='Y')
{
gotoxy(0,1);
printf("ENTER NUMBER OF DAYS IN THE MONTH:");
gotoxy(0,2);
scanf("%f",&emp.dm);
gotoxy(0,3);
printf("ENTER NUMBER OF DAYS EMPLOYEE ON LEAVE:");
gotoxy(0,4);
scanf("%f",&emp.dl);
gotoxy(0,5);
printf("ENTER BONUS AMOUNT IF ANY:");
gotoxy(0,6);
scanf("%f",&emp.bonus);
sal2=(emp.sal1-((emp.sal1/emp.dm)*emp.dl)+emp.bonus);
fseek(fp,0,SEEK_SET);
gotoxy(1,6);
printf("LIST OF EMPLOYEE RECORD");
gotoxy(1,7);
printf("EMP ID");
gotoxy(14,7);
printf("FIRST NAME");
gotoxy(27,7);
printf("LAST NAME");
gotoxy(40,7);
printf("AGE");
gotoxy(53,7);
printf("BASE SALARY");
gotoxy(66,7);
printf("FINAL SALARY");
for(i=1;i<=80;i++)
{
gotoxy(i,8);
printf("-");
}
i=9;
while(fread(&emp,sizeof(emp),1,fp)==1)
{
gotoxy(1,i);
printf("%s",emp.empID);
gotoxy(14,i);
printf("%s",emp.fname);
gotoxy(27,i);
printf("%s",emp.lname);
gotoxy(40,i);
printf("%d",emp.age);
gotoxy(52,i);
printf("%f",emp.sal1);
gotoxy(66,i);
printf("%lf",sal2);
i++;
}
getch();
}
else
{
fseek(fp,0,SEEK_SET);
gotoxy(1,1);
printf("LIST OF EMPLOYEE RECORD");
gotoxy(1,2);
printf("EMP ID");
gotoxy(14,2);
printf("FIRST NAME");
gotoxy(27,2);
printf("LAST NAME");
gotoxy(40,2);
printf("AGE");
gotoxy(53,2);
printf("BASE SALARY");
gotoxy(66,2);
printf("FINAL SALARY");
for(i=1;i<=80;i++)
{
gotoxy(i,3);
printf("-");
}
i=4;
while(fread(&emp,sizeof(emp),1,fp)==1)
{
gotoxy(1,i);
printf("%s",emp.empID);
gotoxy(14,i);
printf("%s",emp.fname);
gotoxy(27,i);
printf("%s",emp.lname);
gotoxy(40,i);
printf("%d",emp.age);
gotoxy(53,i);
printf("%f",emp.sal1);
gotoxy(66,i);
printf("%lf",sal2);
i++;
}
getch();
}

}
void SearchEmployee()
{
float sal2;
int i,datafound=0;
char employeeId[15];
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_SET);
gotoxy(1,1);
textcolor(RED);
cprintf("SEARCH EMPLOYEE RECORD");
gotoxy(5,2);
textcolor(GREEN);
cprintf("ENTER EMPLOYEE ID: ");
gets(employeeId);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)==0)
{
datafound=1;
break;
}
}
if(datafound==1)
{
gotoxy(0,4);
printf("ENTER NUMBER OF DAYS IN THE MONTH:");
gotoxy(0,5);
scanf("%f",&emp.dm);
gotoxy(0,6);
printf("ENTER NUMBER OF DAYS EMPLOYEE ON LEAVE:");
gotoxy(0,7);
scanf("%f",&emp.dl);
gotoxy(0,8);
printf("ENTER BONUS AMOUNT IF ANY:");
gotoxy(0,9);
scanf("%f",&emp.bonus);
sal2=(emp.sal1-((emp.sal1/emp.dm)*emp.dl)+emp.bonus);
textcolor(RED);
gotoxy(4,6);
printf("RECORD OF EMPLOYEE");
textcolor(GREEN);
gotoxy(4,7);
printf("________________________");
gotoxy(4,8);
printf("EMPLOYEE ID :");
printf("%s",emp.empID);
gotoxy(4,9);
printf("FIRST NAME :");
printf("%s",emp.fname);
gotoxy(4,10);
printf("LAST NAME :");
gotoxy(4,11);
printf("AGE :");
printf("%d",emp.age);
gotoxy(4,12);
printf("BASIC SALARY :");
printf("%f",emp.sal1);
gotoxy(4,13);
printf("FINAL SALARY:");
printf("%f",sal2);
}
else
{
gotoxy(10,8);
printf("EMPLOYEE NOT FOUND!!!!!");
}
gotoxy(25,15);
textcolor(RED+BLINK);
printf("SEARCH ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'|| another=='y');
}
void ModifyEmployee()
{
float sal2;
int i, datafound=0,recordNo=0;
char employeeId[15];
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_SET);
rewind(fp);
gotoxy(1,1);
textcolor(RED);
printf("MODIFY EMPLOYEE RECORD");
textcolor(GREEN);
gotoxy(2,2);
printf("ENTER EMPLOYEE ID TO BE MODIFIED:");
gets(employeeId);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)==0)
{
datafound=1;
break;
}
recordNo++;
}
if(datafound==1)
{
gotoxy(0,4);
printf("ENTER NUMBER OF DAYS IN THE MONTH:");
gotoxy(0,5);
scanf("%f",&emp.dm);
gotoxy(0,6);
printf("ENTER NUMBER OF DAYS ON EMPLOYEE ON LEAVE:");
gotoxy(0,7);
scanf("%f",&emp.dl);
gotoxy(0,8);
printf("ENTER BONUS AMOUNT IF ANY:");
gotoxy(0,9);
scanf("%f",&emp.bonus);
sal2=(emp.sal1-((emp.sal1/emp.dm)*emp.dl)+emp.bonus);
gotoxy(5,3);
textcolor(RED);
printf("OLD RECORD IS:");
gotoxy(5,7);
textcolor(GREEN);
printf("EMPLOYEE ID :");
printf("%s",emp.empID);
gotoxy(5,8);
printf("FIRST NAME :");
printf("%s",emp.fname);
gotoxy(5,9);
printf("LAST NAME :");
printf("%s",emp.lname);
gotoxy(5,10);
printf("AGE :");
printf("%d",emp.age);
gotoxy(5,11);
printf("BASIC SALARY :");
printf("%f",emp.sal1);
gotoxy(5,13);
printf("FINAL SALARY:");
printf("%lf",sal2);
gotoxy(5,15);
textcolor(GREEN);
printf("NEW RECORD->");
gets(emp.empID);
gotoxy(5,16);
printf("EMPLOYEE ID :");
gets(emp.empID);
gotoxy(5,17);
printf("FIRST NAME :");
gets(emp.fname);
gotoxy(5,18);
printf("LAST NAME :");
gets(emp.lname);
gotoxy(5,19);
printf("AGE :");
scanf("%d",&emp.age);
gotoxy(5,20);
printf("BASIC SALARY :");
scanf("%f",&emp.sal1);
gotoxy(5,21);
fseek(fp,sizeof(emp)*(recordNo),SEEK_SET);
gotoxy(10,21);
if(fwrite(&emp,sizeof(emp),1,fp)==1)
printf("THE RECORD HAS BEEN MODIFIED!!!!!");
else
printf("EROR DURING MODIFICATION!!!!!");
}
else
{
gotoxy(10,21);
printf("EMPLOYEE NOT FOUND!!!!!");
}
gotoxy(10,23);
textcolor(RED+BLINK);
printf("MODIFY ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'||another=='y');
}
void DeleteEmployee()
{
int i,datafound=0;
char employeeId[15];
FILE *fpTemp;
char another,ch;
do
{
clrscr();
fseek(fp,0,SEEK_SET);
rewind(fp);
textcolor(RED);
gotoxy(1,1);
printf("DELETE EMPLOYEE RECORD");
textcolor(GREEN);
gotoxy(2,2);
printf("ENTER EMPLOYEE ID TO BE DELETED:");
gets(employeeId);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)==0)
{
datafound=1;
break;
}
}
if(datafound==1)
{
fpTemp=fopen(tempFileName,"wb");
rewind(fp);
while(fread(&emp,sizeof(emp),1,fp)==1)
{
if(strcmp(emp.empID,employeeId)!=0)
fwrite(&emp,sizeof(emp),1,fpTemp);
}
fclose(fp);
fclose(fpTemp);
remove(fileName);
rename(tempFileName,fileName);
fp=fopen(fileName,"rb+");
gotoxy(6,8);
printf("SUCCESSFULLY DELETED!!!!!");
}
else
{
gotoxy(2,6);
printf("EMPLOYEE NOT FOUND!!!!!");
}
gotoxy(10,20);
textcolor(RED+BLINK);
printf("DELETE ANOTHER EMPLOYEE(Y/N)?");
fflush(stdin);
another=getch();
fflush(stdin);
textcolor(WHITE);
}while(another=='Y'|| another=='y');
}
void first()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(GREEN);
settextstyle(4,0,3);
outtextxy(200,200,"EMPLOYEE RECORD MANAGEMENT SYSTEM");
getch();
restorecrtmode();
}
char file()
{
int gdriver=DETECT, gmod;
char i;
initgraph(&gdriver,&gmod,"c:\\tc\\bgi");
setcolor(RED);
setcolor(GREEN);
settextstyle(7,0,2);
outtextxy(130,45,"EMPLOYEE INFORMATION SYSTEM");
settextstyle(7,0,3);
setcolor(YELLOW);
outtextxy(260,95,"MAIN MENU");
settextstyle(0,0,0);
setcolor(MAGENTA);
outtextxy(200,145,"1>>ADD EMPLOYEE RECORD.");
outtextxy(200,170,"2>>LIST RECORDS OF ALL EMPLOYEE.");
outtextxy(200,195,"3>>SEARCH A PARTICULR EMPLOYEE.");
outtextxy(200,220,"4>>MODIFY INFORMATION OF A EMPLOYEE.");
outtextxy(200,245,"5>>DELETE A EMPLOYEE.");
outtextxy(200,270,"6>>EXIT STSTEM.");
setcolor(GREEN+BLINK);
outtextxy(200,360,"ENTER YOUR CHOICE: ");
i=getch();
restorecrtmode();
return (i);
}