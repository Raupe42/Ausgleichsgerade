/*
author: Raupe

Info:
Allgemeine Hilfen zur vereinfachung des Ein-Ausgabehandl�ings bei Konsolenanwendungen
*/

#ifndef _ioHelp
#define _ioHelp

#define TEST \x84
#define � \x84
#define � \x94
#define � \x81
#define � \x8E
#define � \x99
#define � \x9A
#define � \xE1
#define xstr(x) #x		//eine KONSTANTE x direkt eintragen
#define str(x) xstr(x)	//use: str(x)  -> result: x

#ifdef UNIX
#define CLS "clear"
#elif unix
#define CLS "clear"
#else
#define CLS "cls"
#endif

#endif // !_ioHelp
