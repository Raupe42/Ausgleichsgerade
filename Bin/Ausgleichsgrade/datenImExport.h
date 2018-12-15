/*
author: Raupe

Info:
Headerdatei des Im- und Exportmoduls
*/


#ifndef MAIN
#define _MAIN
#endif // !MAIN


#include "messreihe.h"

#ifndef _datenSpeichern
#define _datenSpeichern
/*
Unterfunktion zum Speichern der Daten in eine Datei
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenSpeichern(messreihe_t *messreihe);
#endif // !_datenSpeichern

#ifndef _datenLaden
#define _datenLaden
/*
Unterfunktion zum Lesen der Daten aus einer Datei
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenLadenErsetzend(messreihe_t *messreihe);
#endif // !_datenLaden