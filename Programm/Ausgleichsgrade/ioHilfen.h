/*
author: Raupe

Info:
Allgemeine Hilfen zur vereinfachung des Ein-Ausgabehandlöings bei Konsolenanwendungen
*/


#define _CRT_SECURE_NO_WARNINGS


#ifndef _ioHelp
#define _ioHelp

#define ä \x84
#define ö \x94
#define ü \x81
#define Ä \x8E
#define Ö \x99
#define Ü \x9A
#define ß \xE1
#define xstr(x) #x		//eine KONSTANTE x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x

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
#endif // !_ioHelp
