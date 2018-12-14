/*
author: Raupe

Info:
Dies ist die Header-Datei f�r die Berechnungsfunktion.
Die gesamte Funktionalit�t ist Hard-Coded und nicht von au�en beeinflussbar.

*/




#ifndef MAIN
#define _MAIN
#endif // !MAIN


#include "messreihe.h"


/*
Aufruf f�r das Berechnungsmen�.
Die Benutzinteraktion wird dirket durch das Men� durchgef�hrt.
Parameter: p_messdaten: Ein Zeiger auf die Messdaten
R�ckgabewert: int Status: es kann ausgewertet werden, ob die Funktion fertig bearbeitet wurde
R�ckgabe: 0 Aufruf beendet
*/
int berechnungsmenue(messreihe_t *p_messdaten);