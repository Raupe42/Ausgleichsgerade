/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datens�tzen
*/

#define TEST \x84
#define � \x84
#define � \x94
#define � \x81
#define � \x8E
#define � \x99
#define � \x9A
#define � \xE1
#define xstr(x) #x		//eine KONSTANTE x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x
#ifdef UNIX
#define CLS "clear"
#elif unix
#define CLS "clear"
#else
#define CLS "cls"
#endif

//includes
	//erternen Abh�ngigkeiten
#include <stdio.h>
	//internen Abh�ngigkeiten
#include "datenverwaltung.h"


int datenAusgeben(messreihe_t *messreihe)
{
	printf("jetzt w"str(�)"rde die Ausgabe kommen\n");
}

int datenEinlesen(messreihe_t *messreihe)
{
	printf("jetzt w"str(�)"rde die Eingabe kommen\n");
}

int datenLaden(messreihe_t *messreihe)
{
	printf("jetzt w"str(�)"rde die Ladefunktion kommen\n");
}

int datenManipulieren(messreihe_t *messreihe)
{
	printf("jetzt w"str(�)"rde die Datenmanipultation kommen\n");

}

int datenSpeichern(messreihe_t *messreihe)
{
	printf("jetzt w"str(�)"rde die Datensicherung kommen\n");
}