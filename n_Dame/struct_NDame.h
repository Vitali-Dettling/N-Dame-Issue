#include <time.h>

#define m_row 12
#define m_col 12


enum mode
{
Einzelschrittmodus,//Single step mode
Automatisch//Automatic
}emode;

enum save
{
on,//Save activated.
off//Save not activated.
}esave;

enum menu
{
b_on,//If the program is running.						
b_off,//If the program is finisch witch running.
b_reset//If the program gous into their start position.
}menu_option;

struct position//Set the queen in a row and col.
{
	int ilastcol;//Col where the queen is set.
	int ilastrow;//Row where the queen is set.

};

struct NDame//All information for my N_Dame
{
	enum mode emode;
	enum save esave;
	enum menu menu_option;
	int board [m_col][m_row];//Two dimension array.
	int boardsize;//Size of the effective boardsize.

	clock_t start;//Is needed to calculate the time.
	int time_Start;//Start of the time.
	int time_End;//End of the time.

	struct position lastqueen;//Where the queen was set.
	int isolution;//Counts the solutions.
	char filename[256];//Saved the path which can be written.
	int olddeleted;
};