/*
author: Raupe

Info:
Modul zum einlesen, anzeigen, manipulieren und speichern von Datensätzen
*/



//includes
//erternen Abhängigkeiten
#include <stdio.h>
#include <stdlib.h>
//internen Abhängigkeiten
#include "datenImExport.h"
#include "ioHilfen.h"

#ifndef _MAIN
int main(void)
{

}
#endif // !_MAIN

int datenSpeichern(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(ü)"rde die Datensicherung kommen\n");
	getchar();
	return 0;
}

int datenLaden(messreihe_t *messreihe)
{
	system(CLS);
	printf("jetzt w"str(ü)"rde die Ladefunktion kommen\n");
	getchar();
	return 0;
}