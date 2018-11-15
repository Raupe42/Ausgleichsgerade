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