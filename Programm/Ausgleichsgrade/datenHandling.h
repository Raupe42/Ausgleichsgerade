#define SPEICHERRESERVE 5	//freie Messwertfelder vor realloziieren

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



#ifndef _datenverwaltung
	#define _datenverwaltung

int messreiheAllocate (long, messreihe_t *);

int messreihePruefen (messreihe_t *);

#endif 
