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
#include <string.h>
//internen Abhängigkeiten
#include "datenImExport.h"
#include "ioHilfen.h"
#include "datenHandling.h"

#ifndef _MAIN
int main(void)
{

}
#endif // !_MAIN

/*
Diese Funktion speicher die aktuelle Messreihe mit einer Zusatzinformation ab.
Es wird die Anzahl der Messwerte mit abgelegt.
*/
int datenSpeichern(messreihe_t *p_messreihe)
{
	FILE* file;
	long i;
	system(CLS);
	printf("Daten werden gesichert...\n");
	file = fopen("messreihe.ttj", "w");
	if (!file)
		perror("Fehlgeschlagen: ");
	else {
		fprintf(file, "Anzahl: %li\n", (p_messreihe->anzahlMesswerte));
		for (i = 0; i < (p_messreihe->kapazitaetMessreihe); i++)
		{
			if ((*p_messreihe->messreihe + i)->val == 1)
			fprintf(file, "%lf, %lf\n", (*p_messreihe->messreihe + i)->x, (*p_messreihe->messreihe + i)->y);
		}
		fclose(file);
		printf("Abgeschlossen...\n");
	}
	getchar();
	return 0;
}

/*
Diese Funktion lädt den Inhalt einer Backup Datei.
Die geladenen Werte überschreiben bereits existierende Werte.
Es wird von der Initalen Informationszeile übner die Anzahl der Werte ausgegangen
*/
int datenLadenErsetzend(messreihe_t *p_messreihe)
{
	FILE* file;
	messwert_t messwert;
	char buffer[100];
	double zahlX, zahlY;
	int i, ret, anzahl = 0;

	file = fopen("messreihe.ttj", "r");
	system(CLS);
	printf("Daten werden geladen\n");
	if (!file)
		perror("Fehlgeschlagen: ");
	else {
		ret = fscanf(file, "%s", buffer);
		if (atof(buffer) == 0.0)
		{
			printf("Messreihe ge"str(_oe)"ffnet mit: %s ", buffer);
			ret = fscanf(file, "%i", &anzahl);
			printf("%i Messwerten\n", anzahl);

			//Datenbereich vorbereiten
			messreiheAllocate(anzahl, p_messreihe);
		}
		else
			printf("Einlagerung von Fermddatei...\n");
		i = 0;
		while (ret != -1)
		{
			ret = fscanf(file, "%lf", &zahlX);
			fgetc(file);
			ret = fscanf(file, "%lf", &zahlY);
			if (i + 1 > p_messreihe->anzahlMesswerte)	//Falls die Anzahl der vohandenen Werte manipuliert wurde
				messreihePruefen(p_messreihe);
			if (ret != -1)
			{
				messwert.x = zahlX;
				messwert.y = zahlY;
				messwert.val = 1;
				*(*p_messreihe->messreihe + i) = messwert;
				i++;
			}
		}

	}
	printf("Einlagerung abgeschlossen\n Bitte Taste dr"str(_ue)"cken\n");
	getchar();
	return 0;
}