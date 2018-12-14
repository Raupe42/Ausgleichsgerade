/*
author: Raupe

Info:
Diese Header-Datei definiert die maßgebliche Datenstruktur dieser Anwendung.
Zur besseren Übersicht ist hierzu eine Begleitdokumentation angefertigt worden.
Für ein effizientes Handling innerhalb des Programms mit übersichtlichen 
Aufrugen werden hier die Strukturen über typedef erstellt
Die zentrale Referenz auf die Datenreihe darf nicht verloren gehen und sollte 
z.B. in der MAIN-Funktion verwaltet werden.
Die Struktur ist für "call by name" optimiert- also für Zeiger-Übergaben

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