/*
author: Raupe

Info:
Headerdatei der Benutzerschnittstelle. Die Konsolenanwendung interagiert
�ber die Eingabe von Ziffern mit dem Benutzer.
Klassischerweise wird auch hier immer direkt die Referenz auf die gesamte 
Messreihe �bergeben
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
keine Anderen R�ckgabewerte bis jetzt vorgesehen- Das Fehlerhandling findet intern statt
*/
int datenManipulieren(messreihe_t *messreihe);
#endif // !_datenManipulieren

