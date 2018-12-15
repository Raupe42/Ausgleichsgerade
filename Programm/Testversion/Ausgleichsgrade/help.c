/*
author: Raupe

task: Anzeige des Hilfetextets
*/

//KONSTANTEN und MAKROS
#define TEST \x84
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


void printHelp()
{
	system(CLS);
	printf("hier wird die Hilfe stehen... \n \n \n \n");

	printf("Beliebige Taste dr"str(ü)"cken");
	getchar();
	return;
}