/*
author: Raupe

Info:
Dieses Modul führt die Berechnung der Kennzahlen durch
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
	printf("Men"str(ü)" zur Berechnung.\n");
	getchar();
	return 0;
}

double berechneY_Achsenabschnitt(messreihe_t* p_messreihe)
{
	double retVal = 0;

}

double berechneSteigung(messreihe_t* p_messreihe)
{

}

long double berechneNenner(messreihe_t* p_messreihe)
{

}

long double berechneSumme(messreihe_t* p_messreihe, double (*sumFunk)(messwert_t* p_messwert))
{
	int i;
	long double summe = 0;
	for (i = 0; i < p_messreihe->anzahlMesswerte; i++)
	{

	}
}



double sumX(messwert_t* p_messwert)
{
	return p_messwert->x;
}

double sumY(messwert_t* p_messwert)
{
	return p_messwert->y;
}

double sumXpow2(messwert_t* p_messwert)
{
	return (p_messwert->x * p_messwert->x);
}

double sumXY(messwert_t* p_messwert)
{
	return (p_messwert->x * p_messwert->y);
}