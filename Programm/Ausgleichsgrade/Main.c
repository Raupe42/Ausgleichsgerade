/*
author: Raupe

Info:
Dies ist die Hauptdatei ...


*/


//KONSTANTEN und MAKROS
#define TEST \x84
#define � \x84
#define � \x94
#define � \x81
#define � \x8E
#define � \x99
#define � \x9A
#define � \xE1





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
	//von externen Abh�ngigkeiten
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//von eigenen Modulen
#include "help.h"
#include "datenHandling.h"

//globale typedefs


#ifndef _messdaten_t
	#define _messdaten_t
	/*
	x,y Koordinaten des Messwertes
	val f�r G�ltigkeit ('1': g�ltig; '0' oder andere: ung�ltig
	*/
typedef struct struct_messwert {
	double x;
	double y;
	char val;
} messwert_t;

typedef struct struct_messreihe {
	messwert_t(*messreihe)[];
	long anzahlMesswerte;
	long kapazitaetMessreihe;
} messreihe_t;

#endif // !_messdaten_t

//Prototypen
int menue();



//MAIN

int main(void)
{
	int funktionalitaet = -1;
	messreihe_t messwerte;
	messwerte.messreihe = NULL;
	messwerte.anzahlMesswerte = 10;
	messwerte.kapazitaetMessreihe = 0;
	int i;
	while (funktionalitaet != 0)
	{
		system(CLS);
		funktionalitaet = menue();
		printf("%i \n", funktionalitaet);
		
		messreihePruefen(&messwerte);

		switch (funktionalitaet)
		{
		case 0:	//Porgramm-Ende
			break;
		case 1:
			printf("Funktion 1");
			break;
		case 2:
			printf("veraltet");
			getchar();
			break;
		case 3:

			for (i = 0; i < messwerte.anzahlMesswerte; i++)
			{
				(*messwerte.messreihe + i)->x = i;
				(*messwerte.messreihe +i)->y = i * 2;
				(*messwerte.messreihe +i)->val = 1;
			}
			getchar();
			break;
		case 4:

			for (i = 0; i < messwerte.anzahlMesswerte; i++)
			{
				printf("%i:x = %g, y= %g\n",i, (*messwerte.messreihe+i)->x, (*messwerte.messreihe+i)->y);
			}
			getchar();
			break;
		case 5:
			messwerte.anzahlMesswerte += 10;
			break;
		case 6:
			messwerte.anzahlMesswerte += 1000000;
			break;
		case 7:
			messwerte.anzahlMesswerte -= 1000000;
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
/* Verwaltung des Programmmen�s - der Benutzer w�hlt mit eingabe auf der Konsole
die Funktionalit�ten aus
Der R�ckgabewert ist die ausgew�hlte Funktionalit�t
0: Ende
1:
2:
*/
int menue()
{
	int retVal = -1;
	do
	{
		printf("Bitte Funktionalit"str(�)"t ausw"str(�)"hlen: \n");
		printf("0: Ende \n");
		printf("1: Was anderes \n");
		printf("9: Hilfe \n");
		scanf("%i", &retVal); while (getchar() != '\n');


	} while (retVal == -1);

	return retVal;
}
