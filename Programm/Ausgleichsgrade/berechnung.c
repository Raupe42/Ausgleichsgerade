/*
author: Raupe

Info:
Dieses Modul f�hrt die Berechnung der Kennzahlen durch
Nach au�en ist nur die Hauptfunktion sichtbar.
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

//local Proto
double berechneY_Achsenabschnitt(messreihe_t* p_messreihe, long double nenner);
double berechneSteigung(messreihe_t* p_messreihe, long double nenner);
long double berechneNenner(messreihe_t* p_messreihe);
long double berechneSumme(messreihe_t* p_messreihe, long double(*sumFunk)(messwert_t* p_messwert));
long double sumX(messwert_t* p_messwert);
long double sumY(messwert_t* p_messwert);
long double sumXpow2(messwert_t* p_messwert);
long double sumXY(messwert_t* p_messwert);

int berechnungsmenue(messreihe_t *p_messdaten)
{
	double m, b;
	long double nenner;
	system(CLS);
	printf("Men"str(_ue)" zur Berechnung.\n");
	getchar();
	printf("starte Berechnung\n");
	nenner = berechneNenner(p_messdaten);
	b = berechneY_Achsenabschnitt(p_messdaten, nenner);
	m = berechneSteigung(p_messdaten, nenner);
	//printf("m * x + b = %g * x + %g", m, b);
	printf("b = %g\n", b);
	printf("m = %g\n", m);
	printf("y = %g x + %g", m, b);
	while (getchar() != '\n');
	return 0;
}

/*
Parameter: p-messreihe: die Messreihe
nenner: der zuvor berechnete Nenner als long double
Die angewendete Formel entsprocht der Vorlage
R�ckgabewert: b als double Wert
*/
double berechneY_Achsenabschnitt(messreihe_t* p_messreihe, long double nenner)
{
	double b= 0;
	b = berechneSumme (p_messreihe, sumY) * berechneSumme(p_messreihe, sumXpow2) 
		- berechneSumme(p_messreihe, sumX) * berechneSumme(p_messreihe, sumXY);
	return b/nenner;
}
/*
Parameter: p-messreihe: die Messreihe
nenner: der zuvor berechnete Nenner als long double
Die angewendete Formel entsprocht der Vorlage
R�ckgabewert: m als double Wert
*/
double berechneSteigung(messreihe_t* p_messreihe, long double nenner)
{
	double m = 0;
	m = p_messreihe->anzahlMesswerte * berechneSumme(p_messreihe, sumXY) 
		- berechneSumme(p_messreihe, sumX) * berechneSumme(p_messreihe, sumY);
	return m/nenner;
}
/*
Parameter:p-messreihe: die Messreihe
Berechnung des Nenners nach gegebener Formel
R�ckgabwert: Nenner des Bruches als long double
*/
long double berechneNenner(messreihe_t* p_messreihe)
{
	long double retVal;
	long n = p_messreihe->anzahlMesswerte;
	long double sumXValue = berechneSumme(p_messreihe, sumX);
	retVal = n * berechneSumme(p_messreihe, sumXpow2) - sumXValue * sumXValue;
	return retVal;
}
/*
Parameter: p-messreihe: die Messreihe
sumFunk: Zeiger euf eine der Berechnungsfunktionen
So wird die Summe einer Variablen Berechnungsvorschrift �ber
die g�ltigen Messwerte gebildet
*/
long double berechneSumme(messreihe_t* p_messreihe, long double (*sumFunk)(messwert_t* p_messwert))
{
	int i;
	long double summe = 0;
	for (i = 0; i < p_messreihe->kapazitaetMessreihe; i++)
	{
		if ((*p_messreihe->messreihe + i)->val == 1)
			summe += sumFunk((*p_messreihe->messreihe + i));
	}
	return summe;
}
/*
Rechenvorschrift x
*/
long double sumX(messwert_t* p_messwert)
{
	return p_messwert->x;
}
/*
Rechenvorschrift y
*/
long double sumY(messwert_t* p_messwert)
{
	return p_messwert->y;
}
/*
Rechenvorschrift x*x
*/
long double sumXpow2(messwert_t* p_messwert)
{
	return (p_messwert->x * p_messwert->x);
}
/*
Rechenvorschrift x*y
*/
long double sumXY(messwert_t* p_messwert)
{
	return (p_messwert->x * p_messwert->y);
}