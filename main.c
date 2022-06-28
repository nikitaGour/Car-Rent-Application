#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "car.h"

int main()
{
    int i,type,k,choice,result;
    User *usr;
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(GREEN);
    printf("RENT A CAR AND GO WHEREEVER YOU NEED");
    getch();
    textcolor(YELLOW);
    addAdmin();
    while(1)
    {
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        getch();
        gotoxy(1,8);
        textcolor(YELLOW);
       for(i=0;i<80;i++)
       {
           printf("*");
       }
       gotoxy(1,18);
              for(i=0;i<80;i++)
       {
           printf("*");
       }
       gotoxy(32,10);
       printf("1. Admin");
       gotoxy(32,12);
       printf("2. Employe");
       gotoxy(32,14);
       printf("3. Quit");
       gotoxy(32,16);
       textcolor(WHITE);
       printf("Select your role:");
       do
       {
           scanf("%d",&type);
           if(type==1)
           {
             do
            {
             usr=getInput();
             if(usr==NULL)
                break;
             else
              {
                k=checkUserExist(*usr,"admin");
              }
            }while(k==0);

            if(k==-1)
              break;
             if(k==1)
             {
               gotoxy(1,20);
               textcolor(WHITE);
               printf("Press any key to continue");
               getch();

            while(1)
               {
                clrscr();
                choice=adminMenu();
                if(choice==7)
                    break;
                switch(choice)
                {
                  case 1:
                       clrscr();
                       addEmployee();
                       break;
                  case 2:
                       clrscr();
                       addCarDetails();
                       break;
                  case 3:
                      clrscr();
                      viewEmployee();
                       break;
                  case 4:
                      clrscr();
                      showCarDetails();
                       break;
                  case 5:
                      clrscr();
                      result=deleteEmp();
                      gotoxy(15,14);
                      if(result==0)
                      {
                        textcolor(LIGHTRED);
                        printf("Sorry! No record of the given employee found ");
                      }
                      if(result==1)
                       {
                           textcolor(LIGHTGREEN);
                           printf("Record Deleted Successfully!");
                       }
                       else if(result==2)
                       {
                           textcolor(LIGHTRED);
                           printf("Error in deletion");
                       }
                      textcolor(WHITE);
                      printf("\nPress any key to go back to the main menu");
                      getch();
                      break;
                  case 6:
                      clrscr();
                      result=deleteCarModel();
                      gotoxy(15,14);
                      if(result==0)
                      {
                        textcolor(LIGHTRED);
                        printf("Sorry! No record of the given employee found ");
                      }
                      if(result==1)
                       {
                           textcolor(LIGHTGREEN);
                           printf("Record Deleted Successfully!");
                       }
                       else if(result==2)
                       {
                           textcolor(LIGHTRED);
                           printf("Error in deletion");
                       }
                      textcolor(WHITE);
                      printf("\nPress any key to go back to the main menu");
                      getch();
                      break;
                       break;
                  default:
                      {
                        break;
                      }

                }
               }
            }
        }

           else if(type==2)
           {
              do
            {
             usr=getInput();
             if(usr==NULL)
                break;
             else
              {
                k=checkUserExist(*usr,"emp");
              }
            }while(k==0);

            if(k==-1)
              break;
             if(k==1)
             {
               gotoxy(1,20);
               textcolor(WHITE);
               printf("Press any key to continue");
               getch();
                 while(1)
               {
                clrscr();
                choice=empMenu();
                if(choice==5)
                    break;
                switch(choice)
                {
                  case 1:
                       clrscr();
                       int rentresp=rentCar();
                       if(rentresp==-2)
                       {
                         textcolor(LIGHTRED);
                         gotoxy(35,9);
                         printf("Sorry ! All cars booked !");
                         getch();
                       }
                       else if(rentresp==0)
                       {
                         textcolor(LIGHTRED);
                         gotoxy(27,18);
                         printf("You did not choose any car");
                         getch();
                       }
                       break;
                  case 2:
                       clrscr();
                       bookedCarDetails();
                       break;
                  case 3:
                      clrscr();
                      availCarDetails();
                       break;
                  case 4:
                      clrscr();
                      showCarDetails();
                       break;
                  default:
                       break;
               }
              }
           }
        }
             else if(type==3)
              {
               clrscr();
               textcolor(GREEN);
               gotoxy(30,12);
               printf("THANK YOU!!FOR USING THE APP");
               exit(0);
             }
           else
            {

               textcolor(RED);
               gotoxy(30,20);
               printf("INVALID CHOICE");
               getch();
               gotoxy(30,20);
               printf("\t\t\t");
               gotoxy(49,16);
               printf("\t\t\t");
               textcolor(WHITE);
               gotoxy(49,16);

           }
       }while(1);
       getch();
  }
   return 0;
}
