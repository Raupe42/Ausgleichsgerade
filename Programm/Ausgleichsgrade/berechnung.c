/*
author: Raupe

Info:
Dieses Modul f�hrt die Berechnung der Kennzahlen durch
*/

#include <stdlib.h>
#include <stdio.h>

#include "ioHilfen.h"
#include "berechnung.h"

#ifndef _MAIN
int main(void)
{
	messreihe_t dummyDaten;
	dummyDaten.messreihe = NULL;
	dummyDaten.kapazitaetMessreihe = 0;
	dummyDaten.anzahlMesswerte = 0;
	berechnungsmenue(&dummyDaten);
}
#endif // !_MAIN


int berechnungsmenue(messreihe_t *p_messdaten)
{
	system(CLS);
	printf("Men"str(�)" zur Berechnung.\n");
	getchar();
	return 0;
}