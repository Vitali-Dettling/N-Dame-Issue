/*!
 *@file main.c
 *@brief Main function
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

# include "main.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note The main includes all function of controlling the program.
 */

/*!The function of control include boardsize and start of the calculation. 
As well as the option of saving and the option of automatic mode or step mode.
The time will be started after pushing the enter key.
You can break up the program with e.*/


int main()

{

	//Declaration for the first run.
	struct NDame nqueen;//Declaration of the NDame struct.
	
	int enter = 0;
	int on_off = 0;
	int auto_step = 0;
	
	//Start of the first run. At first the save is off the mode is on automatic and the boardsize is 8.
	nqueen.menu_option = b_reset;
	nqueen.time_End = 0;
	nqueen.isolution = 0;
	nqueen.boardsize = 8;//Initialized the boardsize with 8x8.

	nqueen.esave = off;
	nqueen.emode = Automatisch;


	//The fist time where all grafics will be run.
	print_menu(&nqueen);
	print_status(&nqueen);
	print_board(&nqueen);

	//Start of the switch case loop where you can choose your neyt step.
	do
	{

		enter = _getch();


		switch(enter)
		{
		case Plus;
			if(nqueen.boardsize != max_board_size)//If quation that the boardsize can´t be higher as 12.
				{
					
					nqueen.time_End = 0;//Reset the time.
					nqueen.isolution = 0;//Reset the solutions.
					nqueen.boardsize++; //Counts the boardsize up.
					system("cls");//Clean up the cms.
					print_menu(&nqueen);
					print_status(&nqueen);
					print_board(&nqueen);
					
				}
			break;

		case Minus;
			if(nqueen.boardsize != min_board_size)//if quation that the boardsize can´t be smaller than 4.
			{

				nqueen.time_End;//Reset the time.
				nqueen.isolution = 0;//Reset the solution
				nqueen.boardsize--; //Counts the boardsize down.
				system("cls");//Clean uo the cms.
				print_menu(&nqueen);
				print_status(&nqueen);
				print_board(&nqueen);
				
			}
			break;

		case Enter;//Starts the calculation of the queens.
			nqueen.isolution = 0;//Reset the solution every time after starting.
			nqueen.menu_option = b_on;//Shows the menu box when the program is running
			print_menu(&nqueen);


			if(nqueen.esave == on)//Just if save is active.
			{
				
				_gotoxy(0,25);//Write the URL under the status box.
				printf("Please, enter a legal path.\n");
				scanf("%s",&nqueen.filename);//Enter the name of the path.
				_gotoxy(0,25);//Write the URL under the status box.
				printf("                                                                                              ");//!Delet the row where the URL is written.
				if(nqueen.olddeleted == 0)//If the save file is not set.
				{
					nqueen.olddeleted = 1;//The file is set.
					remove(nqueen.filename);
				}
			}


			nqueen.time_Start = clock();//Start of the time count.

			calc_NQueens(&nqueen,0);//Start the logarithm.

			nqueen.olddeleted = 0;//The save file will be deleted again.
			nqueen.menu_option = b_off;//Shows the menu box when the program stoped running.
			print_menu(&nqueen);
			print_status(&nqueen);
			break;

		case k_save;//If you want to save your solution.

			if(on_off%2 == 0)//You can set the save funktion and cancel it again.
			{

			nqueen.esave = on;//All solutions will be saved.
			print_status(&nqueen);
			on_off++;
			}
			else
			{

			nqueen.esave = off;//No solution will be saved.
			print_status(&nqueen);
			on_off++;
			}
			break;

		case k_Einzelschrittmodus;//Option of the automatic mode or step mode.
			
			nqueen.time_End = 0;//Reset the time.
			nqueen.isolution = 0;//Rest the solutions.

			print_status(&nqueen);
			print_board(&nqueen);

			nqueen.menu_option = b_reset;//Reseted the menu box how it was at the first time of running the program.
			print_menu(&nqueen);
			if(auto_step%2 == 0)//You can choose between step and automatic mode.
			{
			nqueen.emode = Einzelschrittmodus;//Einzelschrittmodus;//The step mode is beeing choosen.
			print_status(&nqueen);
			auto_step++;
			}
			else
			{
			nqueen.emode = Automatisch;//The automatic mode is beeing choosen.
			print_status(&nqueen);
			auto_step++;
			}
			break;

		default:
			break;
		}//End of switch case.
																	
	}while(enter != 101);//101 = e key to break up the funktion.
	
	

}


