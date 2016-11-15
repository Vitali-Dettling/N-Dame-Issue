/*!
 *@file print_menu.c
 *@brief Menu function
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

#include "print_menu.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note Print the menu box.
 *@param pnqueen 	is a point at the stuct where all important inforamtion are save for the moment.
 */

/*!The param NDame struct is passed.
 You can see the state what your program is doing by different kind of menu_options. 
 If the menu_option is on than the program is runnung.
 Is the menu_option is off than the program whait for a enter.
 Is the menu_program reset than the program is in its first position.
*/

int print_menu(struct NDame* pnqueen)
{
	int i = 0;

	_gotoxy(0,0);//Start the box at the top left side of the cms.
//------First line--------------------------------------------------------------------------------------------------------------------------------------
	printf("%c",leftangleup);
	for(i=1;i<=36;i++)//Count up half of the line at the top.
	{
		printf("%c",rowline);
	}
			
		printf(" Menu ");//First line with the menu write.

	for(i=1;i<=36;i++)
	{
		printf("%c",rowline);
	}
		printf("%c",rightangleup);
			
							
//-------------------------------Secound line-------------------------------------------------------------------------------------------------------------

	printf("%c Einzelschritt [M]odus",colline);//Print: Einzelschritt 

	for(i=1;i<=37;i++)
	{
	printf(" ");
	}

	printf("[+] Brettgr\x94 \b\xE1 \be [-] %c",colline);//Print: [+] Brettgröße [-]
//--------------------------------Third line------------------------------------------------------------------------------------------------------------

	printf("%c L\x94 \bsung [s]peichern",colline);//Print Lösung [s]peichern

	for(i=1;i<=38;i++)
	{
	printf(" ");
	}

	printf("[e] Programm beenden %c",colline);//Print: [e] Program beenden.
//--------------------------------Fourth line----------------------------------------------------------------------------------------------------------

if(pnqueen->emode == Einzelschrittmodus && pnqueen->menu_option == b_on)//If the step mode is on.
	{
		
			printf("%c",colline);

			for(i=1;i<=29;i++) 
			{
			printf(" ");
			}

			printf("[Enter] nexte L\x94sung");//Print: [Enter] next Lösung.
	
			for(i=1;i<=29;i++)
			{
			printf(" ");
			}

			printf("%c",colline);
		}//End of the automatic mode on.
	
if(pnqueen->emode == Einzelschrittmodus && pnqueen->menu_option == b_off)//If the step mode is off.
	{
		printf("%c",colline);

		for(i=1;i<=26;i++) 
		{
		printf(" ");
		}

		printf("[Enter] erneut berechnen?");//Print: [Enter] erneut berechnen.

		for(i=1;i<=27;i++)
		{
		printf(" ");
		}

		printf("%c",colline);
	
}

if(pnqueen->emode == Automatisch && pnqueen->menu_option == b_on)//If the autmatic mode is on.
{

	printf("%c",colline);
	for(i=1;i<=26;i++) 
	{
	printf(" ");
	}

	printf("[Enter] Berechnung starten");//Print: [Enter] Berechnen starten

	for(i=1;i<=26;i++)
	{
	printf(" ");
	}

	printf("%c",colline);

}

if(pnqueen->emode == Automatisch && pnqueen->menu_option == b_off)//If the automatic mode is off.
	{
		printf("%c",colline);

		for(i=1;i<=26;i++) 
		{
		printf(" ");
		}

		printf("[Enter] erneut berechnen?");//Print: [Enter] erneut berechnen

		for(i=1;i<=27;i++)
		{
		printf(" ");
		}

		printf("%c",colline);
	
}

if(pnqueen->menu_option == b_reset)//If the program is not running.
{

	printf("%c",colline);
	for(i=1;i<=26;i++) 
	{
	printf(" ");
	}

	printf("[Enter] Berechnung starten");//Print: [Enter] Berechnung starten

	for(i=1;i<=26;i++)
	{
	printf(" ");
	}

	printf("%c",colline);

}




//-------------------------------Last line-----------------------------------------------------------------------------------------------------------------

	printf("%c",lefttangledown);//Last line will be printed.
	for(i=1;i<=78;i++)
	{
	printf("%c",rowline);
	}
	printf("%c",righttangledown);


}	