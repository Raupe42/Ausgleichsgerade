/*
author: Raupe

Info:
Dieses Modul führt die Berechnung der Kennzahlen durch
Nach außen ist nur die Hauptfunktion sichtbar.
*/
#define _CRT_SECURE_NO_WARNINGS

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
void punkteEinerGeraden(double m, double b);


/*
Dies ist die Hauptfunktion des Berechnungsmoduls.
Von hier werden die weiteren Unterfunktionen aufgerufen.
*/
int berechnungsmenue(messreihe_t *p_messdaten)
{
	double m, b;
	long double nenner;
	char buff;
	system(CLS);
	printf("Men"str(_ue)" zur Berechnung\n");
	getchar();
	printf("starte Berechnung\n");
	nenner = berechneNenner(p_messdaten);
	b = berechneY_Achsenabschnitt(p_messdaten, nenner);
	m = berechneSteigung(p_messdaten, nenner);
	printf("b = %g\n", b);
	printf("m = %g\n", m);
	printf("y = %g x + %g\n", m, b);
	while (getchar() != '\n');
	printf("Soll eine Wertetabelle angezeigt werden? (y/n)\n");
	buff = getchar();
	if (buff == 'y')
		punkteEinerGeraden(m, b);
	return 0;
}

/*
Parameter: p-messreihe: die Messreihe
nenner: der zuvor berechnete Nenner als long double
Die angewendete Formel entsprocht der Vorlage
Rückgabewert: b als double Wert
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
Rückgabewert: m als double Wert
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
Rückgabwert: Nenner des Bruches als long double
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
die gültigen Messwerte gebildet
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

/*
Diese Funktion gibt in Abhängigkeit von Benutzereingaben
Punkte einer Geraden aus
Rückgabewert: void
Parameter: double m, b
	wie in der allg. Geradengleichung m*x+b
*/
void punkteEinerGeraden(double m, double b)
{
	long i, n = 1;
	double schrittw = 1;
	int stellenzahl = 1;
	printf("Eine Wertetabelle der Gerade wird ausgegeben:\n");
	printf("Wie viele Eintr"str(_ae)"ge sollen Angezeigt werden?\n");
	scanf("%li", &n);
	while (getchar() != '\n');
	if (n < 0)
		n *= -1;
	printf("Bei welcher Schrittweite?\n");
	scanf("%lf", &schrittw);
	while (getchar() != '\n');
	printf("Mit wie vielen Nachkommastellen?\n");
	scanf("%i", &stellenzahl);
	if (stellenzahl < 0)
		stellenzahl *= -1;
	while (getchar() != '\n');
	printf("Y = m * x + b\n");
	for (i = 0; i < n; i++)
	{
		printf("Y = %.*lf * %.*lf + %.*lf = %.*lf\n",
			stellenzahl, m, 
			stellenzahl,(i * schrittw), 
			stellenzahl, b,
			stellenzahl, m*(i*schrittw) + b);
	}
	while (getchar()!= '\n');
	return;
}