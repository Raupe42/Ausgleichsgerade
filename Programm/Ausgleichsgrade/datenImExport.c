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
#include "datenImExport.h"

int datenSpeichern(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(�)"rde die Datensicherung kommen\n");
	getchar();
}

int datenLaden(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(�)"rde die Ladefunktion kommen\n");
	getchar();
}