/*
author: Raupe

task: Anzeige des Hilfetextets
*/


//includes
	//extern
#include <stdio.h>
#include <stdlib.h>
	//intern
#include "help.h"
#include "ioHilfen.h"

#ifndef _MAIN
int main(void)
{
	printHelp();
}
#endif // !MAIN


void printHelp()
{
	system(CLS);
	printf("hier wird die Hilfe stehen... \n \n \n \n");

	printf("Beliebige Taste dr"str(_ue)"cken");
	//wprintf(L"Beliebige Taste dr�cken");
	//printf("Beliebige Taste dr�cken");
	getchar();
	return;
}