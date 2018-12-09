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

int datenLadenErsetzend(messreihe_t *p_messreihe)
{
	FILE* file;
	messwert_t messwert;
	char  * p_zahlStr;
	char buffer[100];
	double zahlX, zahlY;
	char inChar;
	int i, ret, anzahl = 0;
	file = fopen("messreihe.ttj", "r");
	system(CLS);
	printf("Daten werden geladen\n");
	//vorerst einfach überschreiben
	if (!file)
		perror("Fehlgeschlagen: ");
	else {
		ret = fscanf(file, "%s", buffer);
		printf("Messreihe ge"str(_oe)"ffnet mit: %s ", buffer);
		ret = fscanf(file, "%i", &anzahl);
		printf("%i Messwerten\n", anzahl);
		//Datenbereich vorbereiten
		messreiheAllocate(anzahl, p_messreihe);
		i = 0;
		while (ret != -1)
		{
			ret = fscanf(file, "%lf", &zahlX);
			fgetc(file);
			ret = fscanf(file, "%lf", &zahlY);
			if (ret != -1)
			{
				messwert.x = zahlX;
				messwert.y = zahlY;
				messwert.val = 1;
				*(*p_messreihe->messreihe + i) = messwert;
				i++;
			}
		}
		/*
		inChar = '0';
		while (inChar != '\n')
		{
			inChar = fgetc(file);
			strcat(laenge, inChar);
		}
		strcat(laenge, '\0');
		i = 0;
		while (!feof(file))
		{
			fscanf(file, "%lf", &zahlX);
			fgetc(file);	//weitere auswertung auf ','
			fgetc(file);
			fscanf(file, "%lf", &zahlY);
			messwert.x = zahlX;
			messwert.y = zahlY;
			messwert.val = 1;

			*(*p_messreihe->messreihe +i) = messwert;

					
		}
		*/
		/*fgets(file,240, &zahlStr);
		i = 0;
		while (!feof(file))
		{
			fscanf(file, "%lf", &zahlX);
			fgetc(file);	//weitere auswertung auf ','
			fgetc(file);
			fscanf(file, "%lf", &zahlY);
			messwert.x = zahlX;
			messwert.y = zahlY;
			messwert.val = 1;

			*(*p_messreihe->messreihe + i) = messwert;


		}*/
	}
	getchar();
	return 0;
}