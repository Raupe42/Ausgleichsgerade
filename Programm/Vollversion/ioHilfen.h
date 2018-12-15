/*
author: Raupe

Info:
Allgemeine Hilfen zur vereinfachung des Ein-Ausgabehandlings bei Konsolenanwendungen

WICHTIG: Bei Unix Systemen ist bei Laufzeitests ein konflikt mit UTF8 Codierten Sonderzeichen aufgetreten.
Hiefür wurde der #define alternUml geschaffen (gesprochen: Alternative Umlaute)
Bei Darstellungsproblemen sollte dieser #define für das betreffende OS auskommentiert werden. 
An dieser Stelle sei erwähnt, dass eine direkte erhebliche Abhängigkeit zum gesetzten locale ("de_DE") besteht.
*/


#define _CRT_SECURE_NO_WARNINGS


#ifndef _ioHelp
#define _ioHelp

#ifdef UNIX
#define alternUml
#define CLS "clear"
#elif unix
#define alternUml
#define CLS "clear"
#else
#define CLS "cls"
//#define alternUml
#endif
/*
von https://stackoverflow.com/questions/142508/how-do-i-check-os-with-a-preprocessor-directive
show GCC defines on Windows:
gcc -dM -E - <NUL:

on Linux:
gcc -dM -E - </dev/null
*/



#ifndef alternUml
#define _ae \x84
#define _oe \x94
#define _ue \x81
#define _AE \x8E
#define _OE \x99
#define _UE \x9A
#define _sz \xE1
#endif

#ifdef alternUml
#define _ae ä
#define _oe ö
#define _ue ü
#define _AE Ä
#define _OE Ö
#define _UE Ü
#define _sz ß
#endif

#define xstr(x) #x		//eine KONSTANTE x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x

#endif // !_ioHelp
