/*!
 *@file save_DLL.c
 *@brief Saved function
 *@author Dettling Vitali
 *@data 11.01.2010
 *
 *
 */

# include "save_DLL.h"

/*!
 *@version 1.2
 *@data 11.01.2010
 *@note Saved the solution extern into a text data.
 *@param pBoard 	pass the actual board.
 *@param boardsize  pass the actual size of board.
 *@param solution	pass the actual solution.
 *@param filename	pass the name where the path is saved.
 */

/*!
Saved the solution extern into a text Data.

The param are just the 2 dimension array, the boardsize and the solution.
If their is a solution the funktion print the solution in which row´s and col´s the queens are.
*/


__declspec(dllexport)int save_DLL_funktion(int pBoard[12][12], int boardsize,int solution,char filename[256])
{

	int s_row = 0;
	int s_col = 0;

	FILE * pFile = NULL;



	 if((pFile = fopen(filename,"a+")) == NULL)//If their is no URL the if question print´s a Error that it can´t save.
	{
		printf("Can´t save.");
	}

	fprintf(pFile,"Solution:%d\n",solution);//Print the effective solutoin.

	for(s_col = 0 ; s_col < boardsize ; s_col++)
	{
		for(s_row = 0 ; s_row < boardsize ; s_row++)
		{
			if(pBoard[s_col][s_row] == 1)//Checked the two dimension array after queens.
			{
				
				fprintf(pFile,"col:%d row:%d\n", s_col,s_row);//Print the col and row where the queen is set.
				
			}
		
		}
	
	}

	fclose(pFile);//Close the path again.
}



