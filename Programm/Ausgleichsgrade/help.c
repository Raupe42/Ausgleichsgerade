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
	printf("    *   *  * * Ausgleichsgeraderechner * *  *   *\n\n\n");
	printf("Dies ist der Ausgleichsgeradenrechner.\n");
	printf("Es können 2-Dimensionale Datensätze eingegeben, angeschaut\n");
	printf("und ausgweretet werden.\n\n");
	printf("Die Bedienung erfolgt ausschlie"str(_sz)"lich "str(_ue)"ber ZUiffern.\n");
	printf("Bedienungshinweise werden im oberen Bereich der Konsole gegben.\n");
	printf("Bei der Eingabe ist ein ',' das Zeichen f"str(_ue)"r Dezimalzahlen.\n");
	printf("Die Datenmanipulation besitzt einige Unterfunktionen, die jeweils durch\n");
	printf("die Eingabe von \"-1\" zu beenden sind.\n");
	printf("Der Im- und Export von eigenen sowie fremden Dateien (C74A Standard vorrausgesetzt)\n");
	printf("ist m"str(_oe)"glich.\n\n");
	printf("Das Entwicklerteam des Ausgleichsgeradenrechners w"str(_ue)"nscht frohes schaffen.\n");


	printf("Beliebige Taste dr"str(_ue)"cken");
	getchar();
	return;
}