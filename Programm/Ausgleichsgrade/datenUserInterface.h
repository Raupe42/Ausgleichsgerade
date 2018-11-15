/*
author: Raupe

Info:
*/



#ifndef MAIN
#define NOMAIN
#endif // !MAIN


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

