#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "save_DLL.h"

#include "Utilities.h"

# include "struct_NDame.h"

# define Plus 43:
# define Minus 45:
# define Enter 13:
# define k_save 115:
# define k_Einzelschrittmodus 109:
# define max_board_size 12
# define min_board_size 4
		


char calc_NQueens(struct NDame* pnqueen, int row);
int print_status(struct NDame* pnqueen);
int print_board(struct NDame* pnqueen);
int print_menu(struct NDame* pnqueen);





