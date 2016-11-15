/*!
 *@file isattacking.c
 *@brief Checking function
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

# include "isattacking.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note Checked if the queen is beeing attacked.
 *@param pnqueen 	is a point at the struct where all important inforamtion are save.
 *@return 0 is not attacking
 *@return 1 is attacking
 */

/*!
Checeked if a queen is attacked or not.

The funktion is limited with the actual max row´s - 1. 
That the checking count is not going farther as the board. 
*/

int isAttacking(struct NDame* pnqueen)
{
	int i, z;
	int dif = 0;
	int back = 0;
	
	for(i = pnqueen->lastqueen.ilastrow - 1; i >= 0 ; i--)//Counts the row down. 
	{
		dif++;
		if(pnqueen->board[pnqueen->lastqueen.ilastcol][i] == 1)//Checked the top of the queen.
		{
			back = 1;//If the queen is beeing attacked.
		}

		if( ((dif + pnqueen->lastqueen.ilastcol) < pnqueen->boardsize) && (pnqueen->board[pnqueen->lastqueen.ilastcol +dif][i] == 1))//Checked the left diagonal side of the queen.
		{
			back = 1;//If the queen is beeing attacked.
		}
		if((dif <= pnqueen->lastqueen.ilastcol) && (pnqueen->board[pnqueen->lastqueen.ilastcol -dif][i] == 1))//Checked the right diagonal side of the queen.
		{
			back = 1;//If the queen is beeing attacked.
		}

	}

	return back;//If the queen is not beeing attacked.
}