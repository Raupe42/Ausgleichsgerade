/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datens�tzen
*/



//includes
	//erternen Abh�ngigkeiten
#include <stdio.h>
	//internen Abh�ngigkeiten
#include "datenUserInterface.h"
#include "ioHilfen.h"

#ifdef NOMAIN
int main(void)
{

}
#endif // !_MAIN

int datenAusgeben(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(�)"rde die Ausgabe kommen\n");
	getchar();
}

int datenEinlesen(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(�)"rde die Eingabe kommen\n");
	getchar();
}

int datenManipulieren(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(�)"rde die Datenmanipultation kommen\n");
	getchar();

}

