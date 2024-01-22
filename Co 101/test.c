/***************PREPROCESSORS*******************/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/**************GLOBAL VARIABLES*******************/
typedef struct
{
    char name[50];
    int train_num;
    int num_of_seats;
} pd;
/**************FUNCTION PROTOTYPE*******************/
void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char name[], int, int, float);
void specifictrain(int);
float charge(int, int);
/***************FUNCTION DECLARATION*******************/
/****************MAIN()****************/
int main()
{
    system("cls");
printf("\t\t=================================================\n");
printf("\t\t| |\n");
printf("\t\t| ----------------------------- |\n");
// printf("\t\t| TRAIN TICKET MAKER |\n");
printf("######## ########     ###    #### ##    ##    ######## ####  ######  ##    ## ######## ########    ##     ##    ###    ##    ## ######## ######## \n"); 
printf("   ##    ##     ##   ## ##    ##  ###   ##       ##     ##  ##    ## ##   ##  ##          ##       ###   ###   ## ##   ##   ##  ##       ##     ##\n"); 
printf("   ##    ##     ##  ##   ##   ##  ####  ##       ##     ##  ##       ##  ##   ##          ##       #### ####  ##   ##  ##  ##   ##       ##     ##\n"); 
printf("   ##    ########  ##     ##  ##  ## ## ##       ##     ##  ##       #####    ######      ##       ## ### ## ##     ## #####    ######   ######## \n"); 
printf("   ##    ##   ##   #########  ##  ##  ####       ##     ##  ##       ##  ##   ##          ##       ##     ## ######### ##  ##   ##       ##   ##  \n"); 
printf("   ##    ##    ##  ##     ##  ##  ##   ###       ##     ##  ##    ## ##   ##  ##          ##       ##     ## ##     ## ##   ##  ##       ##    ## \n"); 
printf("   ##    ##     ## ##     ## #### ##    ##       ##    ####  ######  ##    ## ########    ##       ##     ## ##     ## ##    ## ######## ##     ##\n"); 
printf("\t\t| ----------------------------- |\n");
printf("\t\t| |\n");
printf("\t\t| |\n");
printf("\t\t| |\n");
printf("\t\t| |\n");
printf("\t\t| |\n");
printf("\t\t| |\n");
printf("\t\t=================================================\n\n\n");
printf(" \n Press any key to continue:");
getch();
system("cls");
int menu_choice,choice_return;
start:
system("cls");
printf("\n=================================\n");
printf(" TRAIN RESERVATION SYSTEM");
printf("\n=================================");
printf("\n1>> Reserve A Ticket");
printf("\n------------------------");
printf("\n2>> View All Available Trains");
printf("\n------------------------");
printf("\n3>> Cancel Reservation");
printf("\n------------------------");
printf("\n4>> Exit");
printf("\n------------------------");
printf("\n\n-->");
scanf("%d",&menu_choice);
switch(menu_choice)
{
    case 1:
        reservation();
        break;
    case 2:
        viewdetails();
        printf("\n\nPress any key to go to Main Menu..");
        getch();
        break;
    case 3:
        cancel();
        break;
    case 4:
        return (0);
    default:
        printf("\nInvalid choice");
}
goto start;
return(0);
}
/****************VIEWDETAILS()****************/
void viewdetails(void)
{
    system("cls");
    printf("-----------------------------------------------------------------------------");
printf("\nTr.No Name Destinations                             Charges                 \t\tTime\n");
printf("-----------------------------------------------------------------------------");
printf("\n1001 Paschim Express Mumbai to Delhi                Rs.5000                 \t\t 9am");
printf("\n1002 Paschim Express Delhi to Mumbai                Rs.5000                 \t\t12pm");
printf("\n1003 BGP Gimp Spl Ahmedabad to Lucknow              Rs.4500                 \t\t8am");
printf("\n1004 BGP Gimp Spl Lucknow to Ahmedabad              Rs.4500                 \t\t11am");
printf("\n1005 Klka SHTB Delhi to Klka ji                     Rs.4000                 \t\t7am");
printf("\n1006 Klka SHTB Klka ji to Delhi                     Rs.4000                 \t\t9.30am");
printf("\n1007 Festival SPL Bhopal to Coimbatore              Rs.3500                 \t\t1pm");
printf("\n1008 Festival SPL Coimbatore to Bhopal              Rs.3500                 \t\t4pm");
printf("\n1009 Nagpur Mumbai CST premium Ranchi to Kolkata    Rs.6000                 \t\t3.35pm");
printf("\n1010 Nagpur Mumbai CST premium Kolkata to Ranchi    Rs.6000                 \t\t4.15pm");
}
/****************RESERVATION()****************/
void reservation(void)
{
    char confirm;
    int i = 0;
    float charges;
    pd passdetails;
    FILE *fptr;
    fptr = fopen("seats_reserved.txt", "a");
    system("cls");
    printf("\nEnter Your Name:> ");
    fflush(stdin);
    gets(passdetails.name);
    printf("\nEnter Number of seats:> ");
    scanf("%d", &passdetails.num_of_seats);
    printf("\n\n>>Press Enter To View Available Trains<< ");
    getch();
    system("cls");
    viewdetails();
    printf("\n\nEnter train number:> ");
start1:
    scanf("%d", &passdetails.train_num);
    if (passdetails.train_num >= 1001 &&
        passdetails.train_num <= 1010)
    {
        charges = charge(passdetails.train_num, passdetails.num_of_seats);
        printticket(passdetails.name, passdetails.num_of_seats, passdetails.train_num, charges);
    }
    else
    {
        printf("\nInvalid train Number! Enter again--> ");
        goto start1;
    }
    printf("\n\nConfirm Ticket (y/n):>");
start:
    scanf(" %c", &confirm);
    if (confirm == 'y')
    {
        fprintf(fptr, "%s\t\t%d\t\t%d\t\t%.2f\n", &passdetails.name, passdetails.num_of_seats, passdetails.train_num, charges);
        printf("==================");
        printf("\n Reservation Done\n");
        printf("==================");
        printf("\nPress any key to go back to Main menu");
    }
    else
    {
        if (confirm == 'n')
        {
printf("\nReservation Not Done!\nPress any key to go back to Main menu!");
        }
        else
        {
printf("\nInvalid choice entered! Enter again-----> ");
goto start;
        }
    }
    fclose(fptr);
    getch();
}
/****************CHARGE()****************/
float charge(int train_num, int num_of_seats)
{
    if (train_num == 1001)
    {
        return (5000.0 * num_of_seats);
    }
    if (train_num == 1002)
    {
        return (5000.0 * num_of_seats);
    }
    if (train_num == 1003)
    {
        return (4500.0 * num_of_seats);
    }
    if (train_num == 1004)
    {
        return (4500.0 * num_of_seats);
    }
    if (train_num == 1005)
    {
        return (4000.0 * num_of_seats);
    }
    if (train_num == 1006)
    {
        return (4000.0 * num_of_seats);
    }
    if (train_num == 1007)
    {
        return (3500.0 * num_of_seats);
    }
    if (train_num == 1008)
    {
        return (3500.0 * num_of_seats);
    }
    if (train_num == 1009)
    {
        return (6000.0 * num_of_seats);
    }
    if (train_num == 1010)
    {
        return (6000.0 * num_of_seats);
    }
}
/****************PRINTTICKET()****************/
void printticket(char name[], int num_of_seats, int train_num, float charges)
{
    system("cls");
    printf("-------------------\n");
    printf("\tTICKET\n");
    printf("-------------------\n\n");
    printf("Name:\t\t\t%s", name);
    printf("\nNumber Of Seats:\t%d", num_of_seats);
    printf("\nTrain Number:\t\t%d", train_num);
    specifictrain(train_num);
    printf("\nCharges:\t\t%.2f", charges);
}
/****************SPECIFICTRAIN()****************/
void specifictrain(int train_num)
{
    if (train_num == 1001)
    {
        printf("\nTrain:\t\t\tPashchim Express");
        printf("\nDestination:\t\tMumbai to Delhi");
        printf("\nDeparture:\t\t9am ");
    }
    if (train_num == 1002)
    {
        printf("\nTrain:\t\t\tPashchim Express");
        printf("\nDestination:\t\tDelhi to Mumbai");
        printf("\nDeparture:\t\t12pm");
    }
    if (train_num == 1003)
    {
        printf("\nTrain:\t\t\tBGP Gimp Spl");
        printf("\nDestination:\t\tAhmedabad to Lucknow");
        printf("\nDeparture:\t\t8am");
    }
    if (train_num == 1004)
    {
        printf("\nTrain:\t\t\tBGP Gimp Spl");
        printf("\nDestination:\t\tLucknow to Ahmedabad");
        printf("\nDeparture:\t\t11am ");
    }
    if (train_num == 1005)
    {
        printf("\nTrain:\t\t\tKlka SHTB");
        printf("\nDestination:\t\tDelhi to Klka ji");
        printf("\nDeparture:\t\t7am");
    }
    if (train_num == 1006)
    {
        printf("\ntrain:\t\t\tKlka SHTB");
        printf("\nDestination:\t\tKlka ji to Delhi");
        printf("\nDeparture:\t\t9.30am ");
    }
    if (train_num == 1007)
    {
        printf("\ntrain:\t\t\tFestival SPL");
        printf("\nDestination:\t\tBhopal to Coimbatore");
        printf("\nDeparture:\t\t1pm ");
    }
    if (train_num == 1008)
    {
        printf("\ntrain:\t\t\tFestival SPL");
        printf("\n Destination:\t\tCoimbatore to Bhopal");
        printf("\nDeparture:\t\t4pm ");
    }
    if (train_num == 1009)
    {
        printf("\ntrain:\t\t\tNagpur Mumbai CST premium");
        printf("\nDestination:\t\tRanchi to Kolkata");
        printf("\nDeparture:\t\t3.35pm ");
    }
    if (train_num == 1010)
    {
        printf("\ntrain:\t\t\tNagpur Mumbai CST premium");
        printf("\nDestination:\t\tKolkata to Ranchi");
        printf("\nDeparture:\t\t1.15 ");
    }
}
void cancel(void)
{
    system("cls");
    int trainnum;
    printf("-----------------------\n");
    printf("Enter the train number: \n");
    printf("-----------------------\n");
    fflush(stdin);
    scanf("%i", &trainnum);
    if(trainnum >= 1001 && trainnum<= 1010){
        printf("\n\nCancelled");
    }
    else{
        printf("Invalid Train Number");
    }
    
    getch();
}