/*
author: Raupe
In diesem Modul wird die Messreihe im Heap verwaltet
Hier wird initialisiert über malloc,
realloziiert mit realloc und ggf. der Speicher mit free freigegeben

Desweiteren gibt es eine Funktion zur automatisierten Prüfung der Speicherkapazität

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
Parameter:
anzahl: Anzahl der messwert_t die aufgenommen werden sollen
	bei Werten <= 0 wird die bestehnde Messreihe gelöscht
struct messwert_t messreihe: Zeiger auf die bestehende Messreihe
	wird NULL übergeben, wird eine neue Messreihe angelegt



Rückgabewert: int
Status des Aufrufs
-1: Fehler
0: Messreihe leer, kein Fehler
1: messreihe neu initialisiert
2: speicher realloziiert
*/
int messreiheAllocate(long neueAnzahl, messreihe_t *p_messreihe)

{
	//lokal für lesbarbkeit
	messwert_t *messreihe = (messwert_t*) p_messreihe->messreihe;

	int retVal = -1;

	if (messreihe == NULL)	//malloc
	{
		messreihe = malloc(neueAnzahl * sizeof(messwert_t));
		p_messreihe->anzahlMesswerte = 0;
		p_messreihe->kapazitaetMessreihe = neueAnzahl;
		retVal = 1;
	}
	else if (messreihe && neueAnzahl > 0)	//realloc
	{
		messreihe = (messwert_t*)realloc(messreihe, neueAnzahl * sizeof(messwert_t));
		p_messreihe->anzahlMesswerte = neueAnzahl;
		p_messreihe->kapazitaetMessreihe = neueAnzahl;
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


	//lokal zrück speichern
	p_messreihe->messreihe = (messreihe_t*) messreihe;
	return retVal;
}

/*Verwaltung des Messreihenspeichers
der benötigte Speicherplatz im Hauptspeicher soll
relativ optimal dimensioniert werden

Parameter: p_messreihe
Alle Werte werden als InPlaceSubstitution ggf. ge�ndert
Rückgabewert Status:
0: kein Fehler
*/

int messreihePruefen(messreihe_t *p_messreihe)
{
	//lokaldaten zur lesbarkeit
	int i = 0, state;

	long kapazitaetMessreihe = p_messreihe->kapazitaetMessreihe;
	long letzterMesswert = 0;
	//long anzahlMesswerte = p_messreihe->anzahlMesswerte;
	long anzahlMesswerte = 0;
	for (i = 0; i < kapazitaetMessreihe; i++)
	{
		if ((*p_messreihe->messreihe + i)->val == 1)
		{
			anzahlMesswerte++;
			letzterMesswert = i;
		}
	}

	//prüfe Messreihe
	if (kapazitaetMessreihe <= anzahlMesswerte)	//= besonders wichtig für kapa, anzahl == 0
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}
	else if (kapazitaetMessreihe > anzahlMesswerte * 1.1)	
	{
		if (letzterMesswert > anzahlMesswerte)
			state = messreiheAllocate(letzterMesswert + SPEICHERRESERVE, p_messreihe);
		else
			state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}

	//rückschreiben der lokaldaten
	p_messreihe->anzahlMesswerte = anzahlMesswerte;
	p_messreihe->kapazitaetMessreihe = kapazitaetMessreihe;
	return 0;
}