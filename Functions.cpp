#include <windows.h> 
void gotoxy(int column , int line) {
 	COORD coord ; 
 	coord.X = column ; 
 	coord.Y = line ; 
 	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
 } 
 
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
