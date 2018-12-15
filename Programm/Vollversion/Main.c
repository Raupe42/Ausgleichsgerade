/*
author: Raupe

Info:
Dies ist die Hauptdatei dieser Anwendung.
Die Funktionalität besteht in der Berechnung einer Ausgleichsgeraden
Die Dafür benötigten Werte können eingelesen, gesicher, manipuliert und importiert werden.
Anforderungsprofil und weitere Informationen sind in der Begelitdokumentation enthalten.

Bei Darstellungsschwierigkeiten für z.B. Umlaute ist die ioHilfen.h zu betrachten.

*/



//VS-CE ONLY:
#define _CRT_SECURE_NO_WARNINGS


//includes
	//von externen Abh�ngigkeiten
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

	//von eigenen Modulen
#define MAIN
#include "messreihe.h"
#include "help.h"
#include "datenHandling.h"
#include "datenImExport.h"
#include "datenUserInterface.h"
#include "berechnung.h"
#include "ioHilfen.h"

//globale typedefs
//siehe mesreihe.h

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


	//setlocale(LC_ALL, "de_DE");	//Erfordert alternative Umlautbehandlung
	setlocale(LC_NUMERIC, "de_DE");


	while (funktionalitaet != 0)		//Bedienschleife der Konsole
	{
		//setlocale(LC_NUMERIC, "de_DE");
		system(CLS);
		funktionalitaet = menue();
		printf("%i \n", funktionalitaet);
		messreihePruefen(p_messwerte);

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
			datenLadenErsetzend(p_messwerte);
			break;
		case 6:
			//Aufruf zum ermitteln der Daten
			berechnungsmenue(p_messwerte);
			break;
		case 7:
			printHelp();
		
			break;
		case 9: //Hilfe Anzeigen
		// D E B U G
#define NO_DEBUG_IN_MAIN
#ifndef NO_DEBUG_IN_MAIN



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
					printf("Falsche Eingabe \n");
					break;


				}
			}
			break;
#endif // !NO_DEBUG_IN_MAIN
#ifdef NO_DEBUG_IN_MAIN
			printf("Funktion Deaktiviert!\n");
			getchar();
#endif // NO_DEBUG_IN_MAIN

		default:
			printf("Falsche Eingabe \n");
			break;


		}
	}
	return 0;
}

//int menue ()
/* Verwaltung des Programmmenüs - der Benutzer wählt mit eingabe auf der Konsole
die Funktionalitäten aus
Der Rückgabewert ist die ausgew�hlte Funktionalität
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
	char buff = '\n';
	do
	{
		system(CLS);
		printf("(1) Daten aufnehmen\n");
		printf("(2) Daten ausgeben\n");
		printf("(3) Daten korrigieren\n");
		printf("(4) Daten speichern\n");
		printf("(5) Daten laden\n");
		printf("(6) Ausgleichsgerade ermitteln\n");
		printf("(7) Hilfe anzeigen\n");
		printf("(0) Ende\n\n");
		printf("(9) Debug-Modus\n");
		
		if (buff != '\n')
		{
			printf("\nFehlerhafte Eingabe: %c\n", buff);
			

		}

		scanf("%i", &retVal); while (buff = getchar() != '\n');
	
	} while (retVal == -1);

	return retVal;
}
