#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>

#include "Define.h"
#include "Save.h"
#include "Functions.h"
#include "Frame.h"
#include "Sound.h"
#include "Animation.h"
#include "Navigation.h"
#include "sudokuGen.h"
#include "verification.h"

string menusudokuVe       [] = {"CONTINUE","NEW GAME","SAVE GAME","SETTING","HOW TO PLAY","EXIT GAME"};
string difficultysudokuVe [] = {"     EASY     ","    MEDIUM    ","     HARD    "," CHALLENGING"};
string colorList     [] = {"BLACK         ","BLUE          ","GREEN         ","CYAN          ","RED           ","MAGENTA       ","BROWN         ","LIGHTGRAY     ",
                           "DARKGRAY       ","LIGHTBLUE     ","LIGHTGREEN    ","LIGHTCYAN     ","LIGHTRED      ","LIGHTMAGENTA  ","YELLOW        ","default       "};
string yesNosudokuVe      [] = {"NO  ","YES "}; 

string namesudokuVe       [] = {"devlopers : ","Bachagha Yasmine","Djerouni ahd-Djabra","Laib Mohamed-Reeda","Ouddah Ayoub","Saad-khorchef Moad","Souames Imen","","Copyright **DevClub** 2016"};

string songNames  [2] [5] = {{"Bomberguy     ","Retro         ","Sequence      ","Sonic-Power   ","Type-Zero     "},
                            {"Androids      ","Brave-Worm    ","Gamey         ","Pinball       ","Star-Commander"}}; 
int sudoku [9][9] = {{3,2,8,9,4,7,1,5,6},
                     {7,9,6,1,5,8,3,4,2},
                     {4,5,1,2,6,3,9,8,7},
                     {2,7,5,8,9,4,6,1,3},
                     {6,4,9,3,2,1,5,7,8},
                     {8,1,3,6,7,5,2,9,4},
                     {1,8,4,5,3,6,7,2,9},
                     {5,3,2,7,8,9,4,6,1},
                     {9,6,7,4,1,2,8,3,5}};
int  sudokuA [9][9];
int  sudokuM [9][9]; 
bool sudokuV [9][9]; 
bool sudokuVe[9][9];
bool sudokuVB[9][9];

int setDifficulty=true; 
int setBackgroundColor=0; 
int setColorMainFrame=15; 
int setColorSudoku1=15; 
int setColorSudoku2=15;
int setColorText1=15;
int setColorText2=15; 
int setSongMenu=true; 
int setSongSudoku=true;
bool enabled = false; 
bool mute    = false; 

/************************************************************************************
*******************************    PROTOTYPES  ************************************** 
/***********************************************************************************/
 int  navMenu ();
 int  navDialogue(string);
 int  navDifficulty(string []); 
 bool navSetting (bool &,int &,int &,int &,int &,int &,int &,int &);
 bool gameLoop (); 
/************************************************************************************
******************************* END PROTOTYPES ************************************** 
/***********************************************************************************/
int main(int argc, char** argv) {
	
   // chargement du sudoku 
   settingLoad(mute,setSongMenu,setSongSudoku,setBackgroundColor,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2);
   sudokuLoad(sudokuA,sudokuM,sudokuV,sudokuVe,sudokuVB);
   if (sudokuA[0][0]!=0)
   	   enabled = true; 
   else 
       enabled = false; 
   songPlayer(1,setSongSudoku); 
   mainFrame(setColorMainFrame); 
   startAnimation(BX+25,BY+11,setColorMainFrame);
   // fin chargement 
menuP:system("cls"); 
   mainFrame(setColorMainFrame); 
   switch(navMenu()){
   	case 0 : {
          if(enabled==false){
             Beep(320,500); 
		     goto menuP; 
		  }else{
		     goto play;
		  }  
	      break;
	   }
    case 1 : {
    	 system("cls"); 
         mainFrame(setColorMainFrame); 
    	 if (enabled == true ){
    	 	system("cls"); 
            mainFrame(setColorMainFrame); 
    	 	if (navDialogue(" want to start a new game?")==0)
		        goto menuP;
		 }
		 system("cls"); 
         mainFrame(setColorMainFrame); 
		 setDifficulty = navDifficulty(difficultysudokuVe);
		 if (setDifficulty==0)
		    goto menuP;
		 else{
		 	  enabled = true;  
		      gen(sudoku,sudokuA,sudokuM,sudokuV,sudokuVe,setDifficulty);
         play:system("cls"); 
              mainFrame(setColorMainFrame);
              if (mute==false)
		          songPlayer(2,setSongSudoku);
		      else 
		          songPlayer(3,0); 		 
			  if (gameLoop() == false){
              	  songPlayer(1,setSongMenu); 
              	  goto menuP;
			  }
              else{
              	  afect(sudoku,sudokuA,sudokuM,sudokuV,sudokuVe);
                  for(int i = 0 ; i <9;i++)
                     for (int j = 0 ; j<9 ; j++)
                         sudokuA[i][j]=0;
                  enabled = false; 
				  system("cls"); 
				  endAnimation(setColorMainFrame); 
                  goto menuP;
		      }
		 } 
		 break;
	 }
	case 2 : {
	     system("cls"); 
         mainFrame(setColorMainFrame); 
		 if (navDialogue("  save the current game?")==0)
		     goto menuP; 
		 else{
		 	 sudokuSave(sudokuA,sudokuM,sudokuV,sudokuVe,sudokuVB);
		     goto menuP;
		 }
		 break;
	}
	case 3 : {
         system("cls"); 
         mainFrame(setColorMainFrame);
         if (navSetting  (mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2) == false )
             goto menuP; 
         else {
             system("cls"); 
             mainFrame(setColorMainFrame);
		     if (navDialogue(" save the current settings?")==0)
		         settingLoad(mute,setSongMenu,setSongSudoku,setBackgroundColor,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2);
		     else 
		         settingSvae(mute,setSongMenu,setSongSudoku,setBackgroundColor,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2); 
		     goto menuP;	
		 }
		 break;
	}
	case 4 : {
		 system("cls"); 
         mainFrame(setColorMainFrame);
         howToPlayFrame(setColorMainFrame);
		 goto menuP; 
		 break;
	}
	case 5 : {
		system("cls"); 
        mainFrame(setColorMainFrame); 
	    if (navDialogue("Do you want to exit game ?")==0)
		    goto menuP; 
		else{
		  system("cls"); 
		  mainFrame(setColorMainFrame); 
		  nameAnimation(BX+25,namesudokuVe,setColorMainFrame);
	    }
		break;
	}
   }
   return 0;
}

   /***********************************************************************************
   *******************************    FUNCTIONS   ************************************* 
   ************************************************************************************/

int navMenu(){
 char choix = 0 ;
 int  position =0;
 menu(0,menusudokuVe,enabled);
   do {
     choix = getch();
	 if (choix != 27){
	 position = navVertical(choix,position,5);
	 menu(position,menusudokuVe,enabled);
	 }
   }while(choix != OK);
 return position; 
}

int navDialogue(string message){
 char choix = 0 ;
 int  position =0;
confirmation (message,0,setColorMainFrame);
 do {
     choix = getch();
	 if (choix != 27){
	   position = navHorizental(choix,position,1);
       confirmation (message,position,setColorMainFrame);
	 }else 
	    return 0; 
 }while(choix != OK);
 return position; 
}

int navDifficulty(string difficultysudokuVe []){
 char choix = 0  ;
 int  position = 0;
 difficultyFrame(difficultysudokuVe[0],setColorMainFrame);
 do {
     choix = getch();
	 if (choix != 27){
	   position = navHorizental(choix,position,3);
	   difficultyFrame(difficultysudokuVe[position],setColorMainFrame);
	 }else 
	    return 0; 
 }while(choix != OK);
 return position+1; 
} 

 bool navSetting  (bool &mute,int &setSongMenu,int &setSongSudoku,int &setColorMainFrame,int &setColorSudoku1,int &setColorSudoku2,int &setColorText1,int &setColorText2){
 char choix = 0  , choix1 = 0  ;
 int  position =0;
 bool modif = false;
 system("cls"); 
 mainFrame(setColorMainFrame);
	  do {
	  	options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
        choix = getch();
	    if (choix != 27){
	    	if (choix !=OK){
	    		position = navVertical(choix,position,7);
				modif = true;
			}else{
	            switch(position){
	            	case 0: {
	            		   do {	                     
                             choix1 = getch();
	                          if (choix1 != 27){
	                            mute = navHorizental(choix1,mute,1);
							    if (mute==true){
							        songPlayer(3,0); 	
								}else if (choix1 != OK)
								    songPlayer(1,setSongMenu); 
					                options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
							  }
                           }while(choix1 != OK && choix1!=27);
						break;
					}
					case 1: {
						   do {                       
                             choix1 = getch();
	                          if (choix1 != 27){							  
	                              setSongMenu = navHorizental(choix1,setSongMenu,4);
							      if (mute == false && choix1 != OK){
							       songPlayer(1,setSongMenu);
		          	               options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
								  }
							  }
						   }while(choix1 != OK && choix1!=27);
						break;
					}
					case 2: {
						do {	                          
                             choix1 = getch();
	                          if (choix1 != 27){
	                          	 setSongSudoku = navHorizental(choix1,setSongSudoku,4);
							     if (mute == false && choix1 != OK){
							     	  songPlayer(2,setSongSudoku);
  									  options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
								 }
							  }
                           }while(choix1 != OK && choix1!=27);
						if (mute==false)
		                    songPlayer(1,setSongMenu);
		                else 
		                    songPlayer(3,0);
						break;
					}
					case 3: {
	            		do {	       
                             choix1 = getch();
	                          if (choix1 != 27){
	                          	setColorMainFrame = navHorizental(choix1,setColorMainFrame,15);
							    options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
							  }
                           }while(choix1 != OK && choix1!=27);
						break;
					}
					case 4: {
						do {	                           
                             choix1 = getch();
	                          if (choix1 != 27){
	                          	setColorSudoku1 = navHorizental(choix1,setColorSudoku1,15);
						        options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
							  }
                           }while(choix1 != OK && choix1!=27);
						break;
					}
					case 5: {
						do {	                          	
                             choix1 = getch();
	                          if (choix1 != 27){
	                            setColorSudoku2 = navHorizental(choix1,setColorSudoku2,15);
					            options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
							  }
                           }while(choix1 != OK && choix1!=27);
						break;
					}
					case 6: {
	            		do {	                          
                             choix1 = getch();
	                          if (choix1 != 27){
	                            setColorText1 = navHorizental(choix1,setColorText1,15);
							    options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
							  }
                           }while(choix1 != OK && choix1!=27);
						break;
					}
					case 7: {
						do {                                
                             choix1 = getch();
	                          if (choix1 != 27){
	                          	 setColorText2 = navHorizental(choix1,setColorText2,15);
						         options(position,colorList,yesNosudokuVe,songNames,mute,setSongMenu,setSongSudoku,setColorMainFrame,setColorSudoku1,setColorSudoku2,setColorText1,setColorText2,setColorMainFrame);
							  }
                           }while(choix1 != OK && choix1!=27);
						break;
					}
				}			
			}
	    } 
      }while(choix !=27);
 return modif;  
}

bool gameLoop(){
   int spx=0,spy=0; 
   char choix = 0;
   bool done = false;
   sudokuFrame(setColorMainFrame,setColorSudoku1,setColorSudoku2);
   printSudoku(sudokuM,sudokuV,sudokuVe,setColorText1,setColorText2);
   do{
	  choix = navSudoku(spx,spy); 
      if (choix != 27){
	      inserer(sudokuM,sudokuV,spx,spy,choix);
	      gotoxy(spx*4+41,spy*2+5); 		
		  done=virification (sudokuA,sudokuM,sudokuV,sudokuVe,sudokuVB,spx ,spy);//verification(sudokuA,sudokuM,sudokuVe);
		  printSudoku(sudokuM,sudokuV,sudokuVe,setColorText1,setColorText2);
	      gotoxy(spx*4+41,spy*2+5); 		
	  }else 
	      return false; 
   }while(done==false);
return true; 
}
