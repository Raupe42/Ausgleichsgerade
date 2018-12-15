/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datensätzen
*/

#define TEST \x84
#define ä \x84
#define ö \x94
#define ü \x81
#define Ä \x8E
#define Ö \x99
#define Ü \x9A
#define ß \xE1
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
	//erternen Abhängigkeiten
#include <stdio.h>
	//internen Abhängigkeiten
#include "datenUserInterface.h"


int datenAusgeben(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(ü)"rde die Ausgabe kommen\n");
	getchar();
}

int datenEinlesen(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(ü)"rde die Eingabe kommen\n");
	getchar();
}

int datenManipulieren(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(ü)"rde die Datenmanipultation kommen\n");
	getchar();

}

