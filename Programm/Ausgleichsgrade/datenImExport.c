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
		printf("Abgeschloseen...\n");
	}
	getchar();
	return 0;
}

int datenLaden(messreihe_t *p_messreihe)
{
	FILE* file;
	messwert_t messwert;
	char input[250], laenge [100], zahlStr [250];
	char * p_zahlStr;
	double zahlX, zahlY;
	char inChar;
	int i;
	file = fopen("messreihe.ttj", "r");
	system(CLS);
	printf("Daten werden geladen");
	//vorerst einfach überschreiben
	if (!file)
		perror("Fehlgeschlagen: ");
	else {
		/*
		inChar = '0';
		while (inChar != '\n')
		{
			inChar = fgetc(file);
			strcat(laenge, inChar);
		}
		strcat(laenge, '\0');

		while (!feof(file))
		{
			inChar = '0';
			while (inChar != '\n')
			{
				inChar = fgetc(file);
				strcat(input, inChar);
			}
			strcat(input, '\0');
			strcpy(zahlStr, input);
			strtok(zahlStr, ',');
			zahlX = atof(zahlStr);


			strcpy(zahlStr, input);
			p_zahlStr = &zahlStr;
			while (*p_zahlStr != ',')
			{
				p_zahlStr++;
			}

			

		}*/
		inChar = '0';
		while (inChar != '\n')
		{
			inChar = fgetc(file);
			strcat(laenge, inChar);
		}
		strcat(laenge, '\0');

		while (!feof(file))
		{
			fscanf(file, "%lf", &zahlX);
			fgetc(file);	//weitere auswertung auf ','
			fgetc(file);
			fscanf(file, "%lf", &zahlY);
			messwert.x = zahlX;
			messwert.y = zahlY;
			messwert.val = 1;

			// TODO
			//inkrementell in messreihe speichern
		}
	}
	getchar();
	return 0;
}