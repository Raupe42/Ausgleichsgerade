/*
author: Raupe

Info:
Header-Datei für das DatenHandling
Dieses Modul organisiert die Datenreihe mit dem Array von Elementen im Heap
Die Funktionen sind von außen zugänglich.
Bei den Aufrufen ist vorsicht geboten. Es handelt sich um Funktionalität die
die Programmstabilität beeinträchtigen können.
*/

#define SPEICHERRESERVE 5	//freie Messwertfelder vor realloziieren



#ifndef MAIN
#define _MAIN
#endif // !MAIN


#include "messreihe.h"

#ifndef _datenverwaltung
	#define _datenverwaltung

/*
Die Übergebene Messreihe wird geprüft
Es wird die Kapazität mit der tatsächlichen Auslastung verglichen
Ist die Kapazität zu mehr als 90% ausgeschöpft so wird die Messreihe vergrößert
Wird festgestellt, dass der Datenspeicher deutlich überdimensioniert ist,
so wird er wenn keine Werte am Ende stehen, gekürzt
Parameter: Zeiger auf die Messreihe
Rückgabewert: 0 wenn fertig bearbeitet
*/
int messreihePruefen (messreihe_t *);
/*
Diese Funktion führt die malloc usw. Aufrufe aus.
Klassischerweise aufgerufen durch messreihePruefen () wird der Speicherbereich angepasst
Es kann aber auch ein externer Aufruf erfolgen. Wie oben beschrieben ist besondere Vorsicht geboten!
Durch falsche Parameter kann die Datenintegrität beschädigt werden!
Parameter: neueAnzahl: die Zahl der Messwerte die gehalten werden sollen
	p_messreihe: der Messreihenzeiger
Rückgabewert: int
Status des Aufrufs
-1: Fehler
0: Messreihe leer, kein Fehler
1: messreihe neu initialisiert
2: speicher realloziiert
*/

int messreiheAllocate(long neueAnzahl, messreihe_t *p_messreihe);

#endif 
