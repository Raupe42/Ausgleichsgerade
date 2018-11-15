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
#include "main.h"
#include "help.h"
#include "datenHandling.h"
#include "datenImExport.h"
#include "datenUserInterface.h"

//globale typedefs


#ifndef _messdaten_t
#define _messdaten_t
/*
x,y Koordinaten des Messwertes
val für Gültigkeit ('1': gültig; '0' oder andere: ungültig
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
	messreihe_t *p_messwerte = &messwerte;
	int i;	//Hilfsvariable für Zählschleifen usw.
	while (funktionalitaet != 0)		//Bedienschleife der Konsole
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
			datenEinlesen(p_messwerte);
			break;
		case 2:
			datenAusgeben(p_messwerte);
			break;
		case 3:
			datenManipulieren(p_messwerte);
			break;
		case 4:
			datenSpeichern(p_messwerte);
			break;
		case 5:
			datenLaden(p_messwerte);
			break;
		case 6:
			//Aufruf zum ermitteln der Daten
			break;
		case 7:
			printHelp();
		
			break;
		case 9: //Hilfe Anzeigen
		// D E B U G

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
						(*messwerte.messreihe + i)->y = i * 2;
						(*messwerte.messreihe + i)->val = 1;
					}
					getchar();
					break;
				case 4:

					for (i = 0; i < messwerte.anzahlMesswerte; i++)
					{
						printf("%i:x = %g, y= %g\n", i, (*messwerte.messreihe + i)->x, (*messwerte.messreihe + i)->y);
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
(1) Daten aufnehmen
(2) Daten ausgeben
(3) Daten korrigieren
(4) Daten speichern
(5) Daten laden
(6) Ausgleichsgerade ermitteln
(7) Hilfe anzeigen
(0) Ende
(9) Debug-Modus
*/
int menue()
{
	int retVal = -1;
	do
	{
		printf("(1) Daten aufnehmen\n");
		printf("(2) Daten ausgeben\n");
		printf("(3) Daten korrigieren\n");
		printf("(4) Daten speichern\n");
		printf("(5) Daten laden\n");
		printf("(6) Ausgleichsgerade ermitteln\n");
		printf("(7) Hilfe anzeigen\n");
		printf("(0) Ende\n\n");
		printf("(9) Debug-Modus\n");
		
		scanf("%i", &retVal); while (getchar() != '\n');
	} while (retVal == -1);

	return retVal;
}
