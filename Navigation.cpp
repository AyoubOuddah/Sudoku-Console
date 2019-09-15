#include <iostream>
#include <conio.h> 
#include <windows.h>
#include "Define.h"
#include "Functions.h"
#include "Frame.h" 
using namespace std; 

char  navSudoku(int &spx , int &spy ){
	  bool esc;
	  char choix=0;  
	 bool num = false; 
 do
  {
  gotoxy(spx*4+41,spy*2+5);
  choix=getch();
   switch(choix){
    case LEFT: {
    	if (spx==0)
    	   spx = 8; 
		else
    	   spx--; 
		break;
    }
    case RIGHT: {
    	if (spx==8)
    	   spx = 0; 
		else 
		   spx++;
		break;
    }
    case UP:{
	    if (spy==0)
		   spy = 8; 
		else   
    	  spy--;
		break;
	}
    case DOWN:   {
    	if (spy==8)
    	  spy=0; 
		else 
		  spy++; 
		break;
	}
	case 27:{
		esc = true;
    break;}
   }
   if (choix-48>=1 && choix-48<= 9)
   	   num = true; 
  }while(esc==false&&num==false); 
return choix; 
}

int navHorizental(char choix,int position,int max){
    switch(choix){
      case LEFT:{
    	if(position==0){
    	  position=max;}
    	else{
    	  position-=1;}
    	break;
	  }
      case RIGHT:{
    	if(position==max){
    	  position=0;}
    	else{
    	  position+=1;}
		break;
	  }
    }
    if(choix==27)
	  return 27;
    else
	  return position;	
}

int navVertical(char choix,int position,int max){
    switch(choix){
      case UP:{
    	if(position==0){
    	  position=max;}
    	else{
    	  position-=1;}
    	break;
	  }
      case DOWN:{
    	if(position==max){
          position=0;}
    	else{
    	  position+=1;}
	    break;
	  }
	}
    if(choix==27)
	   return 27;
    else
	   return position;	
}
