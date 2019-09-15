#include <iostream>
#include <windows.h>
#include <time.h>
#include<stack>
#include<stdlib.h>
using namespace std;
void afect(int sudoku[9][9],int sudokuA[9][9],int sudokuM[9][9],bool sudokuV[9][9],bool sudokuVe[9][9]){
	    for(int i=0;i<9;i++){
		    for(int j=0;j<9;j++){
			    sudokuA[i][j]=sudoku[i][j];
			    sudokuV[i][j]=sudokuVe[i][j]=false;
			    sudokuM[i][j]=0;
		    }
        }
    }
void chll(int sudokuA[9][9]){
	int r,s=0;
	stack<int> p;
	srand(time(NULL));
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			int a=rand()%3+s;
			int b=rand()%3+s;
			for(int k=0;k<9;k++){
				p.push(sudokuA[a][k]);
				}
			for(int k=0;k<9;k++){
				sudokuA[a][k]=sudokuA[b][k];
			}
			for(int k=8;k>=0;k--){
				sudokuA[b][k]=p.top();
				p.pop();
			}
		}
		s+=3;		
	}	
}
void chcc(int sudokuA[9][9]){
	int r,s=0;
	stack<int> p;
	srand(time(NULL));
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			int a=rand()%3+s;
			int b=rand()%3+s;	
			for(int k=0;k<9;k++){
				p.push(sudokuA[k][a]);
				}
			for(int k=0;k<9;k++){
				sudokuA[k][a]=sudokuA[k][b];
			}
			for(int k=8;k>=0;k--){
				sudokuA[k][b]=p.top();
				p.pop();
			}
		}
		s+=3;		
	}			
}
void chbc(int sudokuA[9][9]){
	stack<int> p;
	srand(time(NULL));
	for(int i=0;i<6;i++){
			int a=rand()%3;
			int b=rand()%3;	
		switch(b){
			case 0 : b=0;break;
			case 1 : b=3;break;
			case 2 : b=6;break;
		}
		switch(a){
			case 0 : a=0;break;
			case 1 : a=3;break;
			case 2 : a=6;break;	
		}
		for(int r=0;r<3;r++){			
			for(int k=0;k<9;k++){				
					p.push(sudokuA[k][a+r]);
				}
			for(int k=0;k<9;k++){
				sudokuA[k][a+r]=sudokuA[k][b+r];
			}
			for(int k=8;k>=0;k--){
				sudokuA[k][b+r]=p.top();
				p.pop();
			}	
		}		
	}			
}
void chbl(int sudokuA[9][9]){
	stack<int> p;
	srand(time(NULL));
	for(int i=0;i<6;i++){
			int a=rand()%3;
			int b=rand()%3;	
		switch(b){
			case 0 : b=0;break;
			case 1 : b=3;break;
			case 2 : b=6;break;
		}
		switch(a){
			case 0 : a=0;break;
			case 1 : a=3;break;
			case 2 : a=6;break;	
		}
		for(int r=0;r<3;r++){			
			for(int k=0;k<9;k++){				
					p.push(sudokuA[a+r][k]);
				}
			for(int k=0;k<9;k++){
				sudokuA[a+r][k]=sudokuA[b+r][k];
			}
			for(int k=8;k>=0;k--){
				sudokuA[b+r][k]=p.top();
				p.pop();
			}	
		}		
	}			
}

void chtr (int  sudokuA [][9]){
int  n ;	
srand(time(0));
n = rand() %  4 ;
int sudoku1[9][9] = {0};  
 for(int i=0 ; i<=n ; i++) { 
   for (int l=0;l<9;l++){
	  for (int c=0;c<9;c++){
	   sudoku1 [l][c] = sudokuA [l][c] ; 
	  }   
  } 
  for(int a=0, c=8 ; a<9 ; a++, c--) {
      for(int b=0 ,l=0; b<9  ; b++,l++) {
	    sudokuA [a][b] = sudoku1 [l][c];
      }
  }    
 }	
}	
		
void chmr (int  sudokuA [][9]){	
srand(time(0));
int n = rand() % 2 ; 
int sudoku1[9][9] = {0}; 
 for(int i=0;i<=n;i++) {
   for (int l=0;l<9;l++){
	  for (int c=0;c<9;c++){
	   sudoku1 [l][c] = sudokuA [l][c] ; 
	  }   
   } 
   for(int a=0, l=0 ; a<9 ; a++, l++) {
      for(int b=0 ,c=8; b<9  ; b++,c--) {
	    sudokuA [a][b] = sudoku1 [l][c];
      }
  }
 }			
}	

void visib(int sudokuA[9][9],int sudokuM[9][9],bool sudokuV[9][9], int def){
	int nbcv;
	switch(def){
		case 1 : nbcv=65;break;
		case 2 : nbcv=45;break;
		case 3 : nbcv=31;break;
    }
    if(def>3){
    	for(int i=0;i<9;i++){
    		for(int j=0;j<9;j++){
    			if(i==j || i+j==8){
    				sudokuV[i][j]=true;
					sudokuM[i][j]=sudokuA[i][j]; 	
				}	
			}
		}
	}
	else{
			int a ,b;
			srand(time(NULL));
		for(int i=1;i<=nbcv;i++){
			 a=rand()%9;
			 b=rand()%9;
			 sudokuV[a][b]=true;
			 sudokuM[a][b]=sudokuA[a][b]; 			
		}
		
	}
	
}

void gen(int sudoku[9][9],int sudokuA[9][9],int sudokuM[9][9], bool sudokuV[9][9],bool sudokuVe[9][9],int def){
	afect(sudoku,sudokuA,sudokuM,sudokuV,sudokuVe);
	chll(sudokuA);
	chcc(sudokuA);
	chbl(sudokuA);
	chbc(sudokuA);
	chtr(sudokuA);
	chmr(sudokuA);
	visib(sudokuA,sudokuM,sudokuV,def);	
}
