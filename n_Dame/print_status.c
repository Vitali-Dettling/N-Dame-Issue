/*!
 *@file print_status.c
 *@brief Satus function
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

#include "print_status.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note Print the status box.
 *@param pnqueen 	is a point at the stuct where all important inforamtion are save for the moment.
 */

/*!The status box shows you all results from the program.
It shows the solution how often the queens can put on board without beeing attackt.
Here is been shown which configuration you have pressed.
Futuremore you can see the runtime in milisecounds and the boardsize.
*/


int print_status(struct NDame* pnqueen)
{
	int i;

	int milSec = (int) pnqueen->time_End % 100;//Calculation of milisecounds, secunds and minuts.
	int Sec = (int) (pnqueen->time_End / 1000) % 60;
	int Sec_for_count = (int) (pnqueen->time_End / 1000);
	int Min =  Sec_for_count / 60;

	
	char Automatisch[14] = {'A','u','t','o','m','a','t','i','s','c','h',32,32};//Array for the step mode and automatic mode.
	char Einzelschritt[14] = {'E','i','n','z','e','l','s','c','h','r','i','t','t'};
	
	_gotoxy(0,20);//To get the Status Box into the rigth place.
//--------------------------------First Line----------------------------------------------------------------------------------------------------------
	printf("%c",leftangleup);
	for(i=1;i<=35;i++)
	{
		printf("%c",rowline);

			if(i==35)
			{
			printf(" Status ");//Print: Status

				for(i=1;i<=35;i++)
				{
					printf("%c",rowline);
				}
			printf("%c",rightangleup);
			}
	}			
//---------------------------------Secound line---------------------------------------------------------------------------------------------------
	if(pnqueen->emode == Einzelschrittmodus)//Shows the mode which is choosen.
	{
	printf("%c[M]odus: %s",colline,Einzelschritt);
	}
	else
	{
	printf("%c[M]odus: %s",colline,Automatisch);
	}

	if(pnqueen->boardsize < 10)//That the rame of status don´t change their size.
	{
		for(i=1;i<=40;i++)
		{
		printf(" ");
		}
	}
	else//When the boardsize goes more then 10.
		{
		for(i=1;i<=38;i++)
		{
		printf(" ");
		}
	}

	printf("Brettgr\x94 \b\xE1 \be: %dX%d %c",pnqueen->boardsize,pnqueen->boardsize,colline);
//-----------------------------Third line-------------------------------------------------------------------------------------------------------

	printf("%c Vertrichene Zeit: %.2d:%.2d:%.2d",colline, Min, Sec, milSec);//Shows the time.

		for(i=1;i<=23;i++)
		{
		printf(" ");
		}

	printf("L\x94sungsm\x94glichkeiten: %.5d %c",pnqueen->isolution,colline);//Print the solutions.
//------------------------------Fourth line-------------------------------------------------------------------------------------------------------

	if(pnqueen->esave == on)//Show which option is choosen.
	{
		printf("%c Speichern: Ja  ",colline);//Save jes.
	}
	else
	{
		printf("%c Speichern: Nein",colline);//Save no.
	}
	
	for(i=1;i<=62;i++) 
	{
	printf(" ");
	}

	printf("%c",colline);
//-------------------------------Last line----------------------------------------------------------------------------------------------------------

	printf("%c",lefttangledown);//Print the last line.
	for(i=1;i<=78;i++)
	{
	printf("%c",rowline);
	}
	printf("%c",righttangledown);

	
}
