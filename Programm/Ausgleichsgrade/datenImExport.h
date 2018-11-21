/*
author: Raupe

Info:
*/


#ifndef MAIN
#define _MAIN
#endif // !MAIN


#include "messreihe.h"

#ifndef _datenSpeichern
#define _datenSpeichern
/*
Unterfunktion zum speichern der Daten in eine Datei
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenSpeichern(messreihe_t *messreihe);
#endif // !_datenSpeichern

#ifndef _datenLaden
#define _datenLaden
/*
Unterfunktion zum lesen der Daten aus einer Datei
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenLadenErsetzend(messreihe_t *messreihe);
#endif // !_datenLaden