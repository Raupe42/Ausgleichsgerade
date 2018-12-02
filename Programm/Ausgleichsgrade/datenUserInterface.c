/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datensätzen
*/

#define _CRT_SECURE_NO_WARNINGS

//includes
	//erternen Abhängigkeiten
#include <stdio.h>
#include <stdlib.h>
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
double doubleEinlesen();
messwert_t messwertEinlesen(long wertNr);

int datenAusgeben(messreihe_t *p_messreihe)
{
	int i;
	system(CLS);
	printf("einfachste ausgabe...\n");
	for (i = 0; i < p_messreihe->anzahlMesswerte; i++)
	{
		if ((*p_messreihe->messreihe+i)->val == 1)
		printf("%i:x = %g, y= %g\n", i, (*p_messreihe->messreihe + i)->x, (*p_messreihe->messreihe + i)->y);
	}
	getchar();
	return 0;
}

int datenEinlesen(messreihe_t *p_messreihe)
{
	system(CLS);
	int wertNr = 1;
	long aktObj = 0;
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
	printf("Messwert 1 bitte einegeben\nWert 1 X:");
	messwert1.x = doubleEinlesen();
	printf("Wert 1 Y:");
	messwert1.y = doubleEinlesen();
	messwert1.val = 1;

	aktMesswert = messwert1;
	aktObj = findePlatz(p_messreihe);
	//mehr Werte einlesen
	do
	{
		system(CLS);
		//aktObj = findePlatz(p_messreihe);
		*(*p_messreihe->messreihe + aktObj) = aktMesswert;
		aktObj = findePlatz(p_messreihe);
		wertNr++;
		printf("Messwert 1 X=%g, Y=%g", messwert1.x, messwert1.y);
		printf("      (Erneut einegeben f"str(ü)"r Eingabeende)\n");
		printf("Wert %i:\nX:", wertNr);
		aktMesswert.x = doubleEinlesen();
		printf("Y:");
		aktMesswert.y = doubleEinlesen();
		aktMesswert.val = 1;
		} while (aktMesswert.x != messwert1.x || aktMesswert.y != messwert1.y);


	getchar();
	return 0;
}

int datenManipulieren(messreihe_t *p_messreihe)
{
	int i;
	long auswahl = 42, eingabeLong;
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
	scanf("%i", &auswahl); while (getchar() != '\n');
		switch (auswahl)
		{
		case 1:
			for (i = 0; i < p_messreihe->kapazitaetMessreihe; i++)
				(*p_messreihe->messreihe + i)->val = -1;
			messreihePruefen(p_messreihe);
			break;
		case 2:
			printf("Beenden mit Wert-Nr. -1\n");
			do {
				scanf("%i", &eingabeLong); while (getchar() != '\n');
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
			} while (eingabeLong != -1);
			break;
		case 3:
			printf("Beenden mit Wert-Nr. -1\n");
			do {
				scanf("%i", &eingabeLong); while (getchar() != '\n');
				if (eingabeLong >= 0) {
					if (eingabeLong < (p_messreihe->kapazitaetMessreihe))
						if ((*p_messreihe->messreihe + eingabeLong)->val == 1)
						{
							printf("Wert %li: X: %g  Y: %g\n", eingabeLong,
								(*p_messreihe->messreihe + eingabeLong)->x, (*p_messreihe->messreihe + eingabeLong)->y);
							*(*p_messreihe->messreihe + eingabeLong) = messwertEinlesen(eingabeLong);
							messreihePruefen(p_messreihe);
						}
						else
							printf("Wert nicht vorhanden\n");
					else
						printf("Wert au"str(ß)"erhalb des Wertebereichs");
				}
			} while (eingabeLong != -1);
			break;
		case 4:
			printf("Beenden mit Wert-Nr. -1\n");
			do {
				scanf("%i", &eingabeLong); while (getchar() != '\n');
				if (eingabeLong >= 0) {
					if (eingabeLong < (p_messreihe->kapazitaetMessreihe))
						if ((*p_messreihe->messreihe + eingabeLong)->val == 1)
						{
							printf("Wert %li: X: %g  Y: %g\n", eingabeLong,
								(*p_messreihe->messreihe + eingabeLong)->x, (*p_messreihe->messreihe + eingabeLong)->y);
							printf("Wert wirklich löschen? (y/n)?\n");
							if (getchar() == 'y')
							{
								(*p_messreihe->messreihe + eingabeLong)->val = -1;
								messreihePruefen(p_messreihe);
							}

							else if (getchar == 'n');
							else;
						}
						else
							printf("Wert nicht vorhanden\n");
					else
						printf("Wert au"str(ß)"erhalb des Wertebereichs");
				}
			} while (eingabeLong != -1);
			break;
		default:;
		}
	}
	return 0;
}


//lokale Funktionen
double doubleEinlesen()
{
	double retVal = 0.;
	scanf("%lf", &retVal);
	//while (getchar() != '\n');
	return retVal;
}

messwert_t messwertEinlesen(long wertNr)
{
	messwert_t messwert;
	printf("Wert %i:\nX:", wertNr);
	messwert.x = doubleEinlesen();
	printf("Y:");
	messwert.y = doubleEinlesen();
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