/*
author: Raupe

Info:
Dies ist die Hauptdatei ...


*/


//KONSTANTEN und MAKROS
#define TEST \x84
#define ä \x84
#define ö \x94
#define ü \x81
#define Ä \x8E
#define Ö \x99
#define Ü \x9A
#define ß \xE1


#ifdef UNIX
#define CLS "clear"
#elif unix
#define CLS "clear"
#else
#define CLS "cls"
#endif
/*
von https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
show GCC defines on Windows:
gcc -dM -E - <NUL:

on Linux:
gcc -dM -E - </dev/null
*/
#define xstr(x) #x		//eine KONSTANTE x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x

//VS-CE ONLY:
#define _CRT_SECURE_NO_WARNINGS


//includes
	//von externen Abhängigkeiten
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//von eigenen Modulen
#include "help.h"

//Prototypen
int menue();
double * messreiheMalloc(long anzahl);
//MAIN

int main(void)
{
	int funktionalitaet = -1;
	long anzahlMesswerte = 10;
	double * messreihe;
	while (funktionalitaet != 0)
	{
		system(CLS);
		funktionalitaet = menue();
		printf("%i \n", funktionalitaet);
		switch (funktionalitaet)
		{
		case 0:	//Porgramm-Ende
			break;
		case 1:
			printf("Funktion 1");
			break;
		case 2:
			messreihe = messreiheMalloc(anzahlMesswerte);
			printf("%i", sizeof(messreihe));
			getchar();
			break;
		case 9: //Hilfe Anzeigen
			printHelp();
			break;
		default:
			printf("Flasche Eingabe \n");
			break;
		}

	}
	return 0;
}

//int menue ()
/* Verwaltung des Programmmenüs - der Benutzer wählt mit eingabe auf der Konsole
die Funktionalitäten aus
Der Rückgabewert ist die ausgewählte Funktionalität
0: Ende
1:
2:
*/
int menue()
{
	int retVal = -1;
	do
	{
		printf("Bitte Funktionalit"str(ä)"t ausw"str(ä)"hlen: \n");
		printf("0: Ende \n");
		printf("1: Was anderes \n");
		printf("9: Hilfe \n");
		scanf("%i", &retVal); while (getchar() != '\n');


	} while (retVal == -1);

	return retVal;
}

/* Verwaltung des Messreihenspeichers
der benötigte Speicherplatz im Hauptspeicher soll
relativ optimal dimensioniert werden

*/
double * messreiheMalloc(long anzahl)
{
	double * pMessreihe = NULL;

	pMessreihe = malloc(anzahl * 2 * sizeof(double));

	return pMessreihe;
}