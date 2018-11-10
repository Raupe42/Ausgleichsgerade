/*
author: Raupe

Info:
Dies ist die Hauptdatei ...


*/


//KONSTANTEN und MAKROS
#define TEST \x84
#define � \x84
#define � \x94
#define � \x81
#define � \x8E
#define � \x99
#define � \x9A
#define � \xE1

#define SPEICHERRESERVE 5	//freie Messwertfelder vor realloziieren



#ifdef UNIX
#define CLS "clear"
#elif unix
#define CLS "clear"
#else
#define CLS "cls"
#endif
/*
von https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
show GCC defines on Windows:
gcc -dM -E - <NUL:

on Linux:
gcc -dM -E - </dev/null
*/
#define xstr(x) #x		//eine KONSTANTE x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x

//VS-CE ONLY:
#define _CRT_SECURE_NO_WARNINGS


//includes
	//von externen Abh�ngigkeiten
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	//von eigenen Modulen
#include "help.h"

//globale typedefs

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
	messwert_t (*messreihe)[];
	long anzahlMesswerte;
	long kapazitaetMessreihe;
} messreihe_t;

//Prototypen
int menue();
int messreiheAllocate(long neueAnzahl, messreihe_t *p_messreihe);
int messreihePruefen(messreihe_t *p_messreihe);


//MAIN

int main(void)
{
	int funktionalitaet = -1;
	messreihe_t messwerte;
	messwerte.messreihe = NULL;
	messwerte.anzahlMesswerte = 10;
	messwerte.kapazitaetMessreihe = 0;
	int i;
	while (funktionalitaet != 0)
	{
		system(CLS);
		funktionalitaet = menue();
		printf("%i \n", funktionalitaet);
		
		messreihePruefen(&messwerte);

		switch (funktionalitaet)
		{
		case 0:	//Porgramm-Ende
			break;
		case 1:
			printf("Funktion 1");
			break;
		case 2:
			printf("veraltet");
			getchar();
			break;
		case 3:

			for (i = 0; i < messwerte.anzahlMesswerte; i++)
			{
				(*messwerte.messreihe + i)->x = i;
				(*messwerte.messreihe +i)->y = i * 2;
				(*messwerte.messreihe +i)->val = 1;
			}
			getchar();
			break;
		case 4:

			for (i = 0; i < messwerte.anzahlMesswerte; i++)
			{
				printf("%i:x = %g, y= %g\n",i, (*messwerte.messreihe+i)->x, (*messwerte.messreihe+i)->y);
			}
			getchar();
			break;
		case 5:
			messwerte.anzahlMesswerte += 10;
			break;
		case 6:
			messwerte.anzahlMesswerte += 1000000;
			break;
		case 7:
			messwerte.anzahlMesswerte -= 1000000;
			break;
		case 9: //Hilfe Anzeigen
			printHelp();
			break;
		default:
			printf("Flasche Eingabe \n");
			break;
			

		}	
	}
	return 0;
}

//int menue ()
/* Verwaltung des Programmmen�s - der Benutzer w�hlt mit eingabe auf der Konsole
die Funktionalit�ten aus
Der R�ckgabewert ist die ausgew�hlte Funktionalit�t
0: Ende
1:
2:
*/
int menue()
{
	int retVal = -1;
	do
	{
		printf("Bitte Funktionalit"str(�)"t ausw"str(�)"hlen: \n");
		printf("0: Ende \n");
		printf("1: Was anderes \n");
		printf("9: Hilfe \n");
		scanf("%i", &retVal); while (getchar() != '\n');


	} while (retVal == -1);

	return retVal;
}

/* 

Parameter:
anzahl: Anzahl der messwert_t die aufgenommen werden sollen
	bei Werten <= 0 wird die bestehnde Messreihe gel�scht
struct messwert_t messreihe: Zeiger auf die bestehende Messreihe
	wird NULL �bergeben, wird eine neue Messreihe angelegt



R�ckgabewert: int
Status des Aufrufs
-1: Fehler
0: Messreihe leer, kein Fehler
1: messreihe neu initialisiert
2: speicher realloziiert
*/
int messreiheAllocate(long neueAnzahl, messreihe_t *p_messreihe)

{
	//lokal f�r lesabrkeit
	messwert_t *messreihe = p_messreihe->messreihe;
	
	int retVal = - 1;

	if (messreihe == NULL)	//malloc
	{
		messreihe = malloc(neueAnzahl * sizeof( messwert_t));
		retVal= 1;
	}
	else if (messreihe && neueAnzahl > 0)	//realloc
	{
		messreihe = (messwert_t*) realloc(messreihe, neueAnzahl * sizeof(messwert_t));
		retVal = 2;
	}
	else if (messreihe && neueAnzahl <= 0)	//free
	{
		free(messreihe);
		retVal = 0;
	}
	else
		return -1;
	if (!messreihe)
		retVal = -1;
	printf("%p", messreihe);

	//*p_messreihe = messreihe;

	//lokal zr�ck
	p_messreihe->messreihe = messreihe;
	return retVal;
}

/*Verwaltung des Messreihenspeichers
der ben�tigte Speicherplatz im Hauptspeicher soll
relativ optimal dimensioniert werden

Parameter:
Alle Werte werden als InPlaceSubstitution ggf. ge�ndert
.
.
.


R�ckgabewert Status:
0: kein Fehler
*/

int messreihePruefen(messreihe_t *p_messreihe)
{
	//lokaldaten zur lesbarkeit
	long anzahlMesswerte = p_messreihe->anzahlMesswerte;
	long kapazitaetMessreihe = p_messreihe->kapazitaetMessreihe;
	//pr�fe Messreihe
	if (kapazitaetMessreihe < anzahlMesswerte)
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}
	else if (kapazitaetMessreihe > anzahlMesswerte * 1.1)		//TODO: Pr�fe, ob keine g�ltigen Messwerte verworfen werden
	{
		int state = messreiheAllocate(anzahlMesswerte + SPEICHERRESERVE, p_messreihe);
		kapazitaetMessreihe = anzahlMesswerte + SPEICHERRESERVE;
	}

	//r�ckschreiben der lokaldaten
	p_messreihe->anzahlMesswerte = anzahlMesswerte;
	p_messreihe->kapazitaetMessreihe = kapazitaetMessreihe;
	return 0;
}