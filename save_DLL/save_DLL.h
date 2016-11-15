#include <stdio.h>

__declspec(dllexport)int save_DLL_funktion(int pBoard[12][12], int boardsize, int solution,char filename[256]);

//int file_exists(const char * filename);
//__declspec(dllexport)void file_delete(const char * filename);