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

#ifdef NOMAIN
int main(void)
{
	printHelp();
}
#endif // !MAIN


void printHelp()
{
	system(CLS);
	printf("hier wird die Hilfe stehen... \n \n \n \n");

	printf("Beliebige Taste dr"str(ü)"cken");
	getchar();
	return;
}