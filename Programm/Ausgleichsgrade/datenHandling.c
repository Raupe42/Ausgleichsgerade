/*
author: Raupe

Info:
*/


//includes
	//von externen Abh�ngigkeiten
#include <stdlib.h>
#include <stdio.h>

	//interna
#include "datenHandling.h"

#ifndef _MAIN
int main(void)
{
	messreihe_t dummyDaten;
	dummyDaten.messreihe = NULL;
	dummyDaten.kapazitaetMessreihe = 0;
	dummyDaten.anzahlMesswerte = 0;
	
}
#endif // !_MAIN

/*
LOKALE Funktion
Parameter:
anzahl: Anzahl der messwert_t die aufgenommen werden sollen
	bei Werten <= 0 wird die bestehnde Messreihe gel�scht
struct messwert_t messreihe: Zeiger auf die bestehende Messreihe
	wird NULL �bergeben, wird eine neue Messreihe angelegt



R�ckgabewert: int
Status des Aufrufs
-1: Fehler
0: Messreihe leer, kein Fehler
1: messreihe neu initialisiert
2: speicher realloziiert
*/
int messreiheAllocate(long neueAnzahl, messreihe_t *p_messreihe)

{
	//lokal f�r lesabrkeit
	messwert_t *messreihe = p_messreihe->messreihe;

	int retVal = -1;

	if (messreihe == NULL)	//malloc
	{
		messreihe = malloc(neueAnzahl * sizeof(messwert_t));
		retVal = 1;
	}
	else if (messreihe && neueAnzahl > 0)	//realloc
	{
		messreihe = (messwert_t*)realloc(messreihe, neueAnzahl * sizeof(messwert_t));
		retVal = 2;
	}
	else if (messreihe && neueAnzahl <= 0)	//free
	{
		free(messreihe);
		retVal = 0;
	}
	else
		return -1;
	if (!messreihe)
		retVal = -1;
	

	//lokal zr�ck speichern
	p_messreihe->messreihe = messreihe;
	return retVal;
}

/*Verwaltung des Messreihenspeichers
der ben�tigte Speicherplatz im Hauptspeicher soll
relativ optimal dimensioniert werden

Parameter:
Alle Werte werden als InPlaceSubstitution ggf. ge�ndert
.
.
.


R�ckgabewert Status:
0: kein Fehler
*/

int messreihePruefen(messreihe_t *p_messreihe)
{
	//lokaldaten zur lesbarkeit
	int i = 0;

	long kapazitaetMessreihe = p_messreihe->kapazitaetMessreihe;
	//long anzahlMesswerte = p_messreihe->anzahlMesswerte;
	long anzahlMesswerte = 10;
	for (i = 0; i < kapazitaetMessreihe; i++)
	{
		if ((*p_messreihe->messreihe + i)->val == 1)
			anzahlMesswerte++;
	}
	
	//pr�fe Messreihe
	if (kapazitaetMessreihe < anzahlMesswerte)
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}
	else if (kapazitaetMessreihe > anzahlMesswerte * 1.1)		//TODO: Pr�fe, ob keine g�ltigen Messwerte verworfen werden
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}

	//r�ckschreiben der lokaldaten
	p_messreihe->anzahlMesswerte = anzahlMesswerte;
	p_messreihe->kapazitaetMessreihe = kapazitaetMessreihe;
	return 0;
}