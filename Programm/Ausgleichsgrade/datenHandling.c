
//includes
	//von externen Abhängigkeiten
#include <stdlib.h>
#include <stdio.h>

	//interna
#include "datenHandling.h"



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
	//lokal für lesabrkeit
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
	printf("%p", messreihe);

	//*p_messreihe = messreihe;

	//lokal zrück
	p_messreihe->messreihe = messreihe;
	return retVal;
}

/*Verwaltung des Messreihenspeichers
der benötigte Speicherplatz im Hauptspeicher soll
relativ optimal dimensioniert werden

Parameter:
Alle Werte werden als InPlaceSubstitution ggf. geändert
.
.
.


Rückgabewert Status:
0: kein Fehler
*/

int messreihePruefen(messreihe_t *p_messreihe)
{
	//lokaldaten zur lesbarkeit
	long anzahlMesswerte = p_messreihe->anzahlMesswerte;
	long kapazitaetMessreihe = p_messreihe->kapazitaetMessreihe;
	//prüfe Messreihe
	if (kapazitaetMessreihe < anzahlMesswerte)
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}
	else if (kapazitaetMessreihe > anzahlMesswerte * 1.1)		//TODO: Prüfe, ob keine gültigen Messwerte verworfen werden
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}

	//rückschreiben der lokaldaten
	p_messreihe->anzahlMesswerte = anzahlMesswerte;
	p_messreihe->kapazitaetMessreihe = kapazitaetMessreihe;
	return 0;
}