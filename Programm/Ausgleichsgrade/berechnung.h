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
val f�r G�ltigkeit ('1': g�ltig; '0' oder andere: ung�ltig
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