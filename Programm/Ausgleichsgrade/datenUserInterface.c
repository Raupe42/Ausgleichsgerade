/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datensätzen
*/

#define _CRT_SECURE_NO_WARNINGS

#define _OPEN_SYS_ITOA_EXT

//includes
	//erternen Abhängigkeiten
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	//internen Abhängigkeiten
#include "datenUserInterface.h"
#include "ioHilfen.h"
#include "datenHandling.h"

#ifndef _MAIN
int main(void)
{

}
#endif // !_MAIN

//interne Prototypen
long findePlatz(messreihe_t *p_messreihe);
//double doubleEinlesen();
messwert_t messwertEinlesen(long wertNr, char introText[]);
//double einlesen(long wertNr, char introText[], char zweiterText [] );
double einlesen(long wertNr, char introText[], char wertKoord, char text2[]);

int datenAusgeben(messreihe_t *p_messreihe)
{
	long i, anfangAusgabeBlock, nAusgegeben; 
	int anzahlProBlock = -1;
	char buff;
	system(CLS);
	printf("Anahl der Messwerte bis Eingabetaste gefordert wird:\n");
	printf("(0 f"str(ü)"r geamte Ausgabe)\n");
	scanf("%i", &anzahlProBlock);
	while (buff = getchar() != '\n')
	{
		if (buff != '\n' && anzahlProBlock == -1)
			anzahlProBlock = 0;
	}
	//wenn eine unzulaessige Eingabe entdeckt wurde, wird der Modus 
	// gesamte Ausgbe angewendet
	i = 0;
	if (anzahlProBlock <= 0)
		anzahlProBlock = p_messreihe->anzahlMesswerte;
	while (i < p_messreihe->kapazitaetMessreihe)
	{
		anfangAusgabeBlock = i;
		nAusgegeben = 0;
		while (nAusgegeben < anzahlProBlock && i < p_messreihe->kapazitaetMessreihe)
		{
			if (i < p_messreihe->kapazitaetMessreihe)
			{
				if ((*p_messreihe->messreihe + i)->val == 1)
				{
					printf("%i:x = %g, y= %g\n", i, (*p_messreihe->messreihe + i)->x, (*p_messreihe->messreihe + i)->y);
					nAusgegeben++;
				}
			}
			i++;
		}
		if (nAusgegeben > 0)
			while (buff = getchar() != '\n');
	
	}
	printf("Alle Messwerte ausgegeben...\n");
	getchar();
	

	//getchar();
	return 0;
}

int datenEinlesen(messreihe_t *p_messreihe)
{
	system(CLS);
	long wertNr = 1;
	long aktObj = 0;
	char text[1000], tmpStr[500];
	messwert_t messwert1, aktMesswert;

	//Kurzanleitung
	printf("Dies ist die Dateneingabe.\n");
	printf("Fortlaufende Eingabe der Punkte\n");
	printf("Zum beenden den ersten Wert erneut eingeben.\n");
	printf("Die einzelnen Werte eines Datenpaares werden getrennt abgefragt\n");

	printf("Bitte Eingabetaste dr"str(ü)"cken\n");
	while (getchar() != '\n');

	//Einlesen
	system(CLS);
	messwert1 = messwertEinlesen(0, "");
	aktMesswert = messwert1;
	aktObj = findePlatz(p_messreihe);
	//mehr Werte einlesen
	do
	{
		system(CLS);
		*(*p_messreihe->messreihe + aktObj) = aktMesswert;
		aktObj = findePlatz(p_messreihe);
		wertNr++;
		sprintf(text, "Messwert 1 X=%g, Y=%g", messwert1.x, messwert1.y);
		sprintf(tmpStr, "      (Erneut einegeben f"str(ü)"r Eingabeende)\n");
		strcat(text, tmpStr);
		aktMesswert = messwertEinlesen(wertNr, text);
		aktMesswert.val = 1;
	} while (aktMesswert.x != messwert1.x || aktMesswert.y != messwert1.y);
	getchar();
	return 0;
}

int datenManipulieren(messreihe_t *p_messreihe)
{
	int i;
	long auswahl = 42, eingabeLong;
	char tempStr[500], buff;
	while (auswahl > 0) {
		system(CLS);
		printf("Datenmanipulation\n");
		printf("(1) Daten l"str(ö)"schen\n");
		printf("(2) Datensatz anzeigen\n");
		printf("(3) Datensatz ver"str(ä)"ndern\n");
		printf("(4) Datensatz l"str(ö)"schen\n");
		printf("\n");
		printf("(0) Hauptmen"str(ü)"\n");
		// mehrere Datensätzen löschen ??
		scanf("%i", &auswahl); while (buff = getchar() != '\n');
		switch (auswahl)
		{
		case 1:
			printf("ALLE Werte wirklich l"str(ö)"schen? (y/n)?\n");
			
			if (getchar() == 'y')
			{
				for (i = 0; i < p_messreihe->kapazitaetMessreihe; i++)
					(*p_messreihe->messreihe + i)->val = -1;
				messreihePruefen(p_messreihe);
			}
			while (getchar() != '\n');
			break;
		case 2:
			printf("Bitte WertNr. eingeben\nBeenden mit Wert-Nr. -1\n");
			do {
				scanf("%i", &eingabeLong); 
				//while (buff = getchar() != '\n');
				/*if (buff != '\n')
					eingabeLong = -1.;*/
				while (buff = getchar() != '\n')
				{
					if (buff != '\n')
						eingabeLong = -1;		//Aktuell führt eine Fehleingabe zur beenmdung des Untermenues
				}
				if (eingabeLong >= 0) {
					if (eingabeLong < (p_messreihe->kapazitaetMessreihe))
						if ((*p_messreihe->messreihe + eingabeLong)->val == 1)
							printf("Wert %li: X: %g  Y: %g\n", eingabeLong,
							(*p_messreihe->messreihe + eingabeLong)->x, (*p_messreihe->messreihe + eingabeLong)->y);
						else
							printf("Wert nicht vorhanden\n");
					else
						printf("Wert au"str(ß)"erhalb des Wertebereichs");
				}
			} while (eingabeLong != -1.);
			break;
		case 3:
			printf("Bitte WertNr. eingeben\nBeenden mit Wert-Nr. -1\n");
			do {
				scanf("%i", &eingabeLong); while (buff = getchar() != '\n')
				{
					if (buff != '\n')
						eingabeLong = -1;		//Aktuell führt eine Fehleingabe zur beenmdung des Untermenues
				}
				if (eingabeLong >= 0) {
					if (eingabeLong < (p_messreihe->kapazitaetMessreihe))
						if ((*p_messreihe->messreihe + eingabeLong)->val == 1)
						{
							sprintf(tempStr, "Wert %li: X: %g  Y: %g\n", eingabeLong,
								(*p_messreihe->messreihe + eingabeLong)->x, (*p_messreihe->messreihe + eingabeLong)->y);
							printf("%s", tempStr);
							*(*p_messreihe->messreihe + eingabeLong) = messwertEinlesen(eingabeLong, tempStr);
							messreihePruefen(p_messreihe);
							printf("Neue Wertnummer angeben oder mit -1 beenden\n");
						}
						else
							printf("Wert nicht vorhanden\n");
					else
						printf("Wert au"str(ß)"erhalb des Wertebereichs");
				}
			} while (eingabeLong != -1.);
			break;
		case 4:
			printf("Bitte WertNr. eingeben\nBeenden mit Wert-Nr. -1\n");
			do {
				scanf("%i", &eingabeLong); while (buff = getchar() != '\n')
				{
					if (buff != '\n')
						eingabeLong = -1;		//Aktuell führt eine Fehleingabe zur beenmdung des Untermenues
				}
				if (eingabeLong >= 0) {
					if (eingabeLong < (p_messreihe->kapazitaetMessreihe))
						if ((*p_messreihe->messreihe + eingabeLong)->val == 1)
						{
							printf("Wert %li: X: %g  Y: %g\n", eingabeLong,
								(*p_messreihe->messreihe + eingabeLong)->x, (*p_messreihe->messreihe + eingabeLong)->y);
							printf("Wert wirklich l"str(ö)"schen? (y/n)?\n");
							if (getchar() == 'y')
							{
								(*p_messreihe->messreihe + eingabeLong)->val = -1;
								messreihePruefen(p_messreihe);
							}
							else if (getchar() == 'n');
							else;
						}
						else
							printf("Wert nicht vorhanden\n");
					else
						printf("Wert au"str(ß)"erhalb des Wertebereichs");
				}
			} while (eingabeLong != -1.);
			break;
		default:;
		}
	}
	return 0;
}


//lokale Funktionen
/*
double doubleEinlesen()
{
	double retVal = 0.;
	char buff = '\n';
	scanf("%lf", &retVal);
	return retVal;
}
*/
double einlesen(long wertNr, char introText [], char wertKoord, char text2[])
{
	char input[50];
	double input_d = 0.;
	int i = 0, valid = 0;
	do {
		system(CLS);
		printf("%s", introText);
		printf("Wert %i\n", wertNr);
		printf("%s", text2);
		printf("%c:", wertKoord);

		//printf("Wert %i:\n%c:", wertNr, wertKoord);
		scanf("%s", input);
		input_d = atof(input);
		//wenn atof fehlerhaft input_d = 0.0
		//Fehler abfangen - aber Eingabe 0.0 zulassen
		valid = 1;
		if (!input_d)
		{

			i = 0;
			while (input[i] != '\0')
			{
				if (i == 0 && input[i] != '0')
					valid = 0;
				if (i == 1 && input[i] != '.')
					valid = 0;
				if (input[i] != '0')
					valid = 0;
				i++;
			}
		}
		if (!valid)
		{
			printf("Fehlerhafte Eingabe: %s\nBeliebige Taste dr"str(ü)"cken\n", input);
			while (getchar() != '\n');
			getchar();

		}
	} while (valid == 0);
	return input_d;
}

messwert_t messwertEinlesen(long wertNr, char introText[])
{
	messwert_t messwert;
	char input[50], tmpStr [100];
	double input_d = 0.;
	int i = 0, valid = 0;
	
	strcpy(tmpStr, "");
	messwert.x = einlesen(wertNr, introText, 'X', tmpStr);
	//sprintf(tmpStr, "X:%g\n", input_d);
	sprintf(tmpStr, "X:%g\n", messwert.x);
	//messwert.y = doubleEinlesen();
	messwert.y = einlesen(wertNr, introText, 'Y', tmpStr);
	messwert.val = 1;
	return messwert;
}

long findePlatz(messreihe_t *p_messreihe)
{
	long aktObj = 0;
	//gültigen speicherplatz suchen und ersten Wert reinschreiben
	messreihePruefen(p_messreihe);
	while ((*p_messreihe->messreihe + aktObj)->val == 1)
		aktObj++;

	return aktObj;
}

