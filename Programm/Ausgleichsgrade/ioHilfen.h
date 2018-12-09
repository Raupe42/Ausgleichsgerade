/*
author: Raupe

Info:
Allgemeine Hilfen zur vereinfachung des Ein-Ausgabehandlöings bei Konsolenanwendungen
*/


#define _CRT_SECURE_NO_WARNINGS


#ifndef _ioHelp
#define _ioHelp

#define _ae \x84
#define _oe \x94
#define _ue \x81
#define _AE \x8E
#define _OE \x99
#define _UE \x9A
#define _sz \xE1
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

