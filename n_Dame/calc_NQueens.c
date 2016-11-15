/*!
 *@file calc_NQueens.c
 *@brief Algorithm
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

# include "calc_NQueens.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note Calculation of Queens and solutions
 *@param pnqueen 	is a point at the stuct where all important inforamtion are save for the moment.
 *@param row 		give the funktion the row in which the queen will be set.
 *@return character
 */

/*!
The algorithm set the queens in nearly all row´s and col´s and check if the queens can be attacked.
If not than the queen will be set on this position. 
If yes then the queen will be deleted and the next queen will be set on the next row and col. 

The first if question checked just that the board is not bigger as it was choosen.
After the queen will be set. The next step is the check in the underfunktion isattacking. 
If the queen is attacked a return 1 value comes back and the funktion calc_queen starts again and count one row up with recrusion.
If the queen is not attacked a 0 is returning and the while loop start again and count one coll up. 

There are tree other functions which are running if the funktion was activated in menu. 
This tree funktion are save, step mode and automatic mode. 
Because of the while loop it is possible to exit the program all the time.
*/

char calc_NQueens(struct NDame* pnqueen, int row)
{
	char character = 'f';
	int attack;
	int col;

	if(row < 0 || row >= pnqueen->boardsize)//Shows if the start criterium is fulfilled.
	{
		_gotoxy(0,25);
		printf("ERROR");
	}
	else
	{
		col = 0;//At the first run the col starts from 0.
		
	
		while (col < pnqueen->boardsize && character != 'e')//Abort criterium if the boardsize is maintain or the key bottom e triggert.		
		{
			pnqueen->board[col][row] = 1;//Fill the board with queens.
			pnqueen->lastqueen.ilastrow = row;//Saved the queen in the row.
			pnqueen->lastqueen.ilastcol = col;//Saved the queen in the col.

			attack = isAttacking(pnqueen);//Is checking if the queens are attacking each other.

				if(attack == 1)//If the queen is attacking
				{

				}
				else//If the queen is not attackked
				{
					if(row == pnqueen->boardsize - 1)//If the queen is inside the board.
					{

						pnqueen->isolution++;// Counts the solution onces up.
						print_status(pnqueen);

						if(pnqueen->esave == on)//If you want save the solution.
							{
								save_DLL_funktion(pnqueen->board,pnqueen->boardsize,pnqueen->isolution,pnqueen->filename);//Underfunktion of saving solutions.
							}
						

						if(pnqueen->emode == Automatisch)//If the atuomatic mode is chossen.
							{
								
								if(kbhit())// If the user wants stop the program.
								{
									character = _getch();//In case if 'e' is triggert the program store the e into chareter with the ASCII code. At the end of the while loop the program will break up.
								}
						
							}
						if(pnqueen->emode == Einzelschrittmodus)//If the step mode is choosen.
						{
							print_board(pnqueen);
							print_menu(pnqueen);

								do//Do while loop that the progam goes just with retunr and e forward.
								{
									character = _getch();//In case if 'e' is triggert the program store the 'e' into chareter with the ASCII code. At the end of the while loop the program will break up.

								}while(character != 'e' && character != 13);
							
						}
						
					}
					else
					{
						character = calc_NQueens(pnqueen, row+1);// Recrusion of calc_queen.
					}
				
				}
			pnqueen->board [col][row] = 0;//Reseted the queen. 
			col++;//Counts the col unce up.
			
		}//End of the while loop.

		
		pnqueen->time_End = difftime(clock(),pnqueen->time_Start);//Calculate the end count minus start count.
		
	
	
		
	}
	
		return character;
		
}