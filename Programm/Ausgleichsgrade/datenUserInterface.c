/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datensätzen
*/



//includes
	//erternen Abhängigkeiten
#include <stdio.h>
	//internen Abhängigkeiten
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

