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