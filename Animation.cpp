#include "Functions.h"
#include "define.h"
#include "Frame.h" 
#include <iostream>
#include <windows.h>  
using namespace std; 

void startAnimation(int x , int y,int colorT){	
	gotoxy(x-3,y-1);
    cout<<"S";Sleep(750); 
    system("color 0B");
    gotoxy(x-3,y-1);
    cout<<"SU";Sleep(750); 
    system("color 0C");
    gotoxy(x-3,y-1);
    cout<<"SUD";Sleep(750);
    system("color 0D");
    gotoxy(x-3,y-1);
    cout<<"SUD"<<char(153);Sleep(750);
    system("color 0E");
    gotoxy(x-3,y-1);
    cout<<"SUD"<<char(153)<<"K";Sleep(750);
    system("color 0F");
    gotoxy(x-3,y-1);
    cout<<"SUD"<<char(153)<<"KU";Sleep(750);
	mainFrame(colorT); 
	gotoxy(x-3,y-1);cout<<"SUD"<<char(153)<<"KU"<<endl;
	gotoxy(x-7,y);cout<<"Loading...";
	int i ; 
	for(int i=0;i<=100;i++){
		gotoxy(x+3,y);
		if (i<10) 
		   cout<<" "; 
		cout<<i<<"%";
		Sleep(50);
    } 	
}

void nameAnimation(int x,string nameTab[],int colorT){
	int i,j; 
	for (i=18;i>-5;i--){ 
		for (j=0;j<8;j++){
			if (i+j>=3&&i+j<=18){
			    if (j==0)
			       gotoxy(x-10,i);
			    else 
			       gotoxy(x,i+j); 
	        cout<<nameTab[j]; 			
			}
		}
		Sleep(300); 
		system("cls"); 
		mainFrame(colorT); 	
	}
	gotoxy(x-4,18);cout<<char(184)<<" "<<nameTab[8]; 
	Sleep(2000); 	
}
void endAnimation(int colorT){
	mainFrame(colorT);  
    mainFrame1(30,BX+10,BY+5,false,colorT); 
    mainFrame2(30,11,BX+10,BY+5,colorT); 
    mainFrame3(30,BX+10,BY+17,false,colorT);
	gotoxy(BX+20,BY+11); 
	cout<< "GAME OVER";  
	Sleep(5000); 
}
