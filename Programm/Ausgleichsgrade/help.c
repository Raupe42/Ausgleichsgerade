/*
author: Raupe

task: Anzeige des Hilfetextets
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

	printf("Beliebige Taste dr"str(�)"cken");
	getchar();
	return;
}