/*
author: Raupe

Info:
Dies ist die Header-Datei für die Berechnungsfunktion.
Die gesamte Funktionalität ist Hard-Coded und nicht von au�en beeinflussbar.

*/




#ifndef MAIN
#define _MAIN
#endif // !MAIN


#include "messreihe.h"


/*
Aufruf für das Berechnungsmenü.
Die Benutzinteraktion wird dirket durch das Menü durchgeführt.
Parameter: p_messdaten: Ein Zeiger auf die Messdaten
Rückgabewert: int Status: es kann ausgewertet werden, ob die Funktion fertig bearbeitet wurde
Rückgabe: 0 Aufruf beendet
*/
int berechnungsmenue(messreihe_t *p_messdaten);