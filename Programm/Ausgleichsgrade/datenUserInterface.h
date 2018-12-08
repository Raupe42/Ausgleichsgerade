/*
author: Raupe

Info:
*/



#ifndef MAIN
#define _MAIN
#endif // !MAIN



#include "messreihe.h"

#ifndef _datenEinlesen
#define _datenEinlesen
/*
Unterfunktion des Dateneinlesens
Die Einagbe erfolgt jeweils in einzelenen Koordianten
Durch die erneute Eingabe des ersten Koordinatenpaares 
wird die Einagbe beendet
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenEinlesen(messreihe_t *messreihe);
#endif // !_datenEinlesen

#ifndef _datenAusgeben
#define _datenAusgeben
/*
Unterfunktion zum sequentiellen Ausgeben der Daten
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenAusgeben(messreihe_t *messreihe);
#endif // !_datenAusgeben

#ifndef _datenManipulieren
#define _datenManipulieren
/*
Unterfunktion zum Manipulieren einzelner Messwerte
Durch ein neues Untermen� ist die Manipulation von Datens�tzen
m�glich.
Dazu z�hlt:
- das �ndern von Werten
- l�schen von Wertepaaren
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenManipulieren(messreihe_t *messreihe);
#endif // !_datenManipulieren

