#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Define.h"
#include "Functions.h" 
using namespace std; 

void mainFrame1(int x ,int xD , int yD ,bool m ,int colorT){ 
  int i;
  char p;
  color(colorT,0); 
  for(i=0;i<=x;i++){
	gotoxy(xD+i,yD);
	if (m==true){
	  if (i==0)
	    p=C12;
	  else if (i==x)
	    p=C2; 
	  else 
	    p=C13; 
	  cout<<p;
	}else{
	  if (i==0)
	    p=C9;
	  else if (i==x)
	    p=C4; 
	  else 
	    p=C13; 
	  cout<<p; 	
	}
  }
  color(15,0);
}
void mainFrame2(int x , int y , int xD , int yD ,int colorT ){
   char p = C3;
   color(colorT,0); 
   int i;  
   for (i=true;i<=y;i++){
 	gotoxy(xD,yD+i);cout<<p;gotoxy(xD+x,yD+i);cout<<p;
  }
  color(15,0); 		
}
void mainFrame3(int x , int xD , int yD,bool m ,int colorT){ 
  int i;
  char p;
  color(colorT,0); 
  for(i=0;i<=x;i++){
	if (m == true){
	  gotoxy(xD,yD+i);
	  if (i==0)
	    p=C11;
	  else if (i==x)
	    p=C10; 
	  else if (i== 6||i == 12)
	    p=C14; 
	  else  
	   p=C3; 
	 cout<<p; 	
	}else {
	 gotoxy(xD+i,yD);
	  if (i==0)
	    p=C8;
	  else if (i==x)
	    p=C5; 
	  else 
	   p=C13; 
	 cout<<p; 	
	}
	 
  }
  color(15,0); 
}
void mainFrame4(int x , int xD , int yD,bool m , int colorT){
	int i ; 
	char p;
	color(colorT,0);  
	for(i=true;i<x;i++){
	  if (m == true){
	    gotoxy(xD,yD+i); 
	    if (i==2||i==4||i==8||i==10||i==14||i==16)
	      p=C7; 
	    else  
	      p=C1; 
	  cout<<p; 			
	  }else{
	    gotoxy(xD+i,yD); 
	      p=C6; 
	    cout<<p; 	
	  }		
	}
	color(15,0); 
}
void labelFrame(int x ,int y , int xD, int yD,int colorT,string label){
  mainFrame1(x,xD,yD,false,colorT); 
  mainFrame2(x,y-1,xD,yD,colorT); 
  mainFrame3(x,xD,yD+y,false,colorT);
  gotoxy(xD+3,yD);cout<<label;  
}
void mainFrame (int colorT){  // (48,21,BX,BY)  
  mainFrame1(50,BX,BY,false,colorT); 
  mainFrame2(50,21,BX,BY,colorT); 
  mainFrame3(50,BX,BY+22,false,colorT); 
} 

void sudokuFrame(int colorT1,int colorT2,int colorT3){
  mainFrame1(36,SX,SY,false,colorT1); 
  mainFrame2(36,17,SX,SY,colorT1); 
  mainFrame3(36,SX,SY+18,false,colorT1);
   int i; 
   for (i=0;i<18;i+=6){
      mainFrame4(36,SX,SY+2+i,false,colorT3); 
      mainFrame4(36,SX,SY+4+i,false,colorT3);
   } 
   for (i=0;i<18;i+=6){
   	  mainFrame4(18,SX+4+(i*2),SY,true,colorT3); 
      mainFrame4(18,SX+8+(i*2),SY,true,colorT3);
   }
  mainFrame1(36,SX,SY+6,true,colorT2); 
  mainFrame1(36,SX,SY+12,true,colorT2);   
  mainFrame3(18,SX+12,SY,true,colorT2); 
  mainFrame3(18,SX+24,SY,true,colorT2);
}

void menu (int y , string menusudokuVe [] , bool enabled ) { // y == 0 ... y == 4 
  int i;
  for (i=0;i<=10;i+=2){
  	if (i==y*2)
  	    color(15,7);
	gotoxy(MX,MY+i);cout<<menusudokuVe[((int)i/2)];
    color(15,0);
  }
   if (enabled == false){
   	 if (y==0) 
   	    color (0,7);
   	 else 
   	    color (8,0); 
    gotoxy(MX,MY);cout<<menusudokuVe[0]; 
  }
  color(15,0); 
 gotoxy(MX,MY+(y*2));  
}
void options(int y,string colorList [] ,string yesNosudokuVe [],string songNames [2] [5],bool mute,int setSongMenu,int setSongSudoku,
             int setColorMainFrame,int setColorSudoku1,int setColorSudoku2,int setColorText1,int setColorText2, int colorT){
	labelFrame(46,20,BX+2,BY+1,colorT,"options"); 
	labelFrame(42,6,BX+4,BY+3,colorT,"sound-options");
	gotoxy(BX+5,BY+5);cout<<"mute            :";   
	gotoxy(BX+5,BY+6);cout<<"setSongMenu     :";
	gotoxy(BX+5,BY+7);cout<<"setSongSudoku   :";
	labelFrame(42,8,BX+4,BY+11,colorT,"color-options");
    gotoxy(BX+5,BY+13);cout<<"ColorMainFrame  :";
	gotoxy(BX+5,BY+14);cout<<"setColorSudoku1 :";
	gotoxy(BX+5,BY+15);cout<<"setColorSudoku2 :";
	gotoxy(BX+5,BY+16);cout<<"setColorText1   :"; 
	gotoxy(BX+5,BY+17);cout<<"setColorText2   :";
	for (int i=0;i<=7;i++){
  	if (i==y)
  	    color(0,7);
	else
	    color(15,0);
    if (i<=2)
       gotoxy(BX+28,BY+5+i);
    else
	   gotoxy(BX+28,BY+10+i);
	switch(i){
		case 0: {
			cout<<yesNosudokuVe  [mute]; 
			break;
		}
		case 1: {
				cout<<songNames [0] [setSongMenu];
			break;
		}
		case 2: {
			cout<<songNames [1] [setSongSudoku];
			break;
		}
		case 3: {
				cout<<colorList [setColorMainFrame];
			break;
		}
		case 4: {
			cout<<colorList [setColorSudoku1];
			break;
		}
		case 5: {
				cout<<colorList [setColorSudoku2];
			break;
		}
		case 6: {
				cout<<colorList [setColorText1];
			break;
		}
		case 7: {
			    cout<<colorList [setColorText2];
			break;
		}
	}
  }
  color(15,0); 
}

void confirmation (string message,int  x,int colorT){                   	                      
 	mainFrame1(30,DX,DY,false,colorT); 
	mainFrame2(30,6,DX,DY,colorT); 
	mainFrame1(8,DX+2,DY+4,false,colorT); 
	mainFrame2(8,1,DX+2,DY+4,colorT); 
	mainFrame3(8,DX+2,DY+6,false,colorT); 
	mainFrame1(8,DX+20,DY+4,false,colorT); 
	mainFrame2(8,1,DX+20,DY+4,colorT); 
	mainFrame3(8,DX+20,DY+6,false,colorT); 
 	mainFrame3(30,DX,DY+7,false,colorT);
	   
	gotoxy(DX+2,DY+2);cout<<message;
    gotoxy(DX+5,DY+5);cout<<"YES";   	
    gotoxy(DX+23,DY+5);cout<<" NO ";  

  if (x==true){
  	color(15,7); 
    gotoxy(DX+5,DY+5);cout<<"YES";   	
  }
  else{
    color(15,7); 
	gotoxy(DX+23,DY+5);cout<<" NO ";  
  }
  color (15,0); 
} 
void difficultyFrame(string difficulty,int colorT){
	mainFrame1(31,DX-1,DY,false,colorT); 
	mainFrame2(31,6,DX-1,DY,colorT); 
	mainFrame3(31,DX-1,DY+7,false,colorT);
    gotoxy(DX+7,DY+2);cout << "choos defculter "; 
	gotoxy(DX+6,DY+5);cout<<"<";
	color (0,7); 
    gotoxy(DX+8,DY+5); cout<<difficulty;
	color (15,0);  
    gotoxy(DX+23,DY+5);cout<<">";
}
void howToPlayFrame(int colorT){
	labelFrame(46,20,BX+2,BY+1,colorT,"How-to-play"); 
	gotoxy(BX+4,BY+3);cout<<"How to play :\n"; 
	gotoxy(BX+4,BY+4);cout<<"       The objective is to fill a 9x9 grid \n"; 
	gotoxy(BX+4,BY+5);cout<<"       so that each column,each row,\n";
	gotoxy(BX+4,BY+6);cout<<"       and each of the nine 3x3 boxes \n "; 
	gotoxy(BX+4,BY+7);cout<<"       (also called blocks or regions)\n";
    gotoxy(BX+4,BY+8);cout<<"       contains the digits from 1 to 9.\n";
	gotoxy(BX+4,BY+10);cout<<"Keys : \n"; 
	gotoxy(BX+4,BY+11);cout<<"       -UP, DOWN, LEFT and RIGHT : navigate \n"; 
	gotoxy(BX+4,BY+12);cout<<"       the grid or the menu area.\n";	
	gotoxy(BX+4,BY+14);cout<<"In-game highlighting :\n"; 
	gotoxy(BX+4,BY+15);cout<<"       -Red Highlight indicates duplicates\n";
	gotoxy(BX+4,BY+16);cout<<"        in the grid.\n"; 
	gotoxy(BX+4,BY+17);cout<<"       -Green highlight indicates fixed \n";
	gotoxy(BX+4,BY+18);cout << "        cells in the grid."; 
	char choix  = 0 ;  
	do{
		choix = getch(); 
	}while(choix!=27);
}

void inserer( int sudokuM[][9],bool sudokuV[][9],int x,int y ,char choix){
   	 if (choix !=ECHAP){
   	 	 if (sudokuV[y][x]==false)
   	 	     sudokuM[y][x]=(choix-48);
	 }
     gotoxy(x,y);	
}

void printSudoku(int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],int setColorText1,int setColorText2){
     int i , j ; 
      for (i=0;i<9;i++){
      	  for(j=0;j<9;j++){ 
      	  	  if (sudokuV[i][j]==true)
      	  	     color(2,0); 
      	  	  else if (sudokuVe[i][j]==true)
      	  	     color(4,0); 
      	  	  else if (i<3||i>=6){
      	  	        if (j<3||j>=6)
					   color(setColorText1,0); 
					else 
			           color(setColorText2,0); 
			      }else{
			  	    if (j<3||j>=6)
			           color(setColorText2,0); 
			        else 
			           color(setColorText1,0); 
			      }
			  if (sudokuM[i][j]!=0){
			  	  gotoxy(SPX+j*4,SPY+i*2); 
      	  	      cout<<sudokuM[i][j];
			  }       
			}
	  }
	  color(15,0);
}
