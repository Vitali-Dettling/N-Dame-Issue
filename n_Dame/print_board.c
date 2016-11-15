/*!
 *@file print_board.c
 *@brief Board function
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

# include "print_board.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note Print the board
 *@param pnqueen 	is a point at the stuct where all important inforamtion are save for the moment.
 */

/*!Here is all deposited if the boadsize is changing or in the step mode that the queens are been showed.
The collor for the board is done with ACII code. As well as the print of the queens.
The print of the board is done with a 2 dimension array. At first the board is filled with 255 for black and 219 for with.
Later the array is checked if a 1 is set. If yes than the 1 will be overwritten with 82 for Q (queen) and print it out.
At the end the array will be ckecked again for 82 and rewritte with 1. That the logarithm of calc_queen can still work.
*/

int print_board(struct NDame* pnqueen)
{
	int s = 0;
	int z = 0;

for (z=0; z < pnqueen->boardsize ; z++)
{
	if(z%2 == 0)//The board is filled for even number.
	{
		for(s=0; s<pnqueen->boardsize ; s++)//The horizontal (x) arbor of the two dimension array.
		{
			if(pnqueen->board[z][s] == 1)
			{

				pnqueen->board[z][s] = Queen;//Set the queen.

			}
			else
			{
				if(s%2 != 0)//The ACII Code is changed between black and white for even and uneven numbers.
				{
				pnqueen->board[z][s]= black;
				}
				else
				{
				pnqueen->board[z][s] = white;
				}
			}
		}
	
	}//Ent of if
	else//The horizontal (x) arbor of the two dimension array which fill the board for uneven number.
	{
		for(s=0; s<pnqueen->boardsize ; s++)
		{
				if(pnqueen->board[z][s] == 1)
			{

				pnqueen->board[z][s] = Queen;//Set the queen.

			}
			else
			{
				if(s%2 != 0)//The ACII Code is changed between black and white for even and uneven numbers.
				{
				pnqueen->board[z][s]= white;
				}
				else
				{
				pnqueen->board[z][s] = black;
				}
			}
		}
	}//End of the else operator
}// End of the hole loop

//Print the two dimension array and put the board into the middle of the cms window.
for (z=0 ; z < pnqueen->boardsize ; z++)
{
	_gotoxy(38+(2-(pnqueen->boardsize/2)),(10.5+z)+(2-(pnqueen->boardsize/2)));//The middle of the cms window.
	for(s=0; s < pnqueen->boardsize ; s++)
	{
		printf("%c",pnqueen->board[z][s]);
	}
	printf("\n");
}

//Is checking for Queens.
for(z = 0 ; z < pnqueen->boardsize ; z++)
{
	for(s = 0 ; s < pnqueen->boardsize ; s++)
	{
		if(pnqueen->board[z][s] == Queen)
		{
			pnqueen->board[z][s] = 1;//Delet the queen again.
		}
		else
		{
			pnqueen->board[z][s] = 0;//Delet the queen again.
		}
	}
}


}

