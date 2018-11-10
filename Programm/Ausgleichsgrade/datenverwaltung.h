/*
author: Raupe

Info:
*/

#ifndef _messdaten_t
#define _messdaten_t
/*
x,y Koordinaten des Messwertes
val für Gültigkeit ('1': gültig; '0' oder andere: ungültig
*/
typedef struct struct_messwert {
	double x;
	double y;
	char val;
} messwert_t;

typedef struct struct_messreihe {
	messwert_t(*messreihe)[];
	long anzahlMesswerte;
	long kapazitaetMessreihe;
} messreihe_t;

#endif // !_messdaten_t

#ifndef _datenEinlesen
#define _datenEinlesen
/*
Unterfunktion des Dateneinlesens
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
Para: messreihe

RetVal: status
0: kein Fehler
*/
int datenManipulieren(messreihe_t *messreihe);
#endif // !_datenManipulieren

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
int datenLaden(messreihe_t *messreihe);
#endif // !_datenLaden