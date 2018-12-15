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
	printf("Es k"str(_oe)"nnen 2-Dimensionale Datens"str(_ae)"tze eingegeben, angeschaut\n");
	printf("und ausgweretet werden.\n\n");
	printf("Wenn ein Messwert erneut betrachtet werden soll, kann entweder mit \"2\" alles\n");
	printf("angezeigt werden oder unter Daten manipulieren kann ein Einzelwert ausgegeben werden\n");
	printf("Unter Daten manipulieren ist weiterhin ein nachtr"str(_ae)"gliches "str(_AE)"ndern m"str(_oe)"glich.\n");
	printf("Die Bedienung erfolgt ausschlie"str(_sz)"lich "str(_ue)"ber Ziffern.\n");
	printf("Bedienungshinweise werden im oberen Bereich der Konsole gegben.\n");
	printf("Bei der Eingabe ist ein ',' das Zeichen f"str(_ue)"r Dezimalzahlen.\n");
	printf("Die Datenmanipulation besitzt einige Unterfunktionen, die jeweils durch\n");
	printf("die Eingabe von \"-1\" zu beenden sind.\n");
	printf("Der Im- und Export von eigenen sowie fremden Dateien (C74A Standard vorrausgesetzt)\n");
	printf("ist m"str(_oe)"glich.\n");
	printf("Zwischen den Betriebssystem kann es Komplikation der Codierung geben.\n");
	printf("Kontrollieren, ob '.' oder ',' als Dezimalstelle erforderlich ist!\n\n\n");
	printf("Das Entwicklerteam des Ausgleichsgeradenrechners w"str(_ue)"nscht frohes schaffen.\n");

	printf("Beliebige Taste dr"str(_ue)"cken");
	getchar();
	return;
}