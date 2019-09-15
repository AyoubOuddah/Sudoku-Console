#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 

using namespace std ; 

void sudokuSave (int sudokuA [][9],int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],bool sudokuVB[][9]){
	FILE *sudokuFile  = NULL ;
	sudokuFile  = fopen("resources/Save/sudoku.res","wb+"); 
	fclose(sudokuFile);
	sudokuFile  = fopen("resources/Save/sudoku.res","ab+"); 
	if (sudokuFile != NULL ){
		rewind(sudokuFile); 
		fwrite(sudokuA,sizeof(int),81,sudokuFile);
		fwrite(sudokuM,sizeof(int),81,sudokuFile);
		fwrite(sudokuV,sizeof(bool),81,sudokuFile);
		fwrite(sudokuVe,sizeof(bool),81,sudokuFile);
		fwrite(sudokuVB,sizeof(bool),81,sudokuFile);
        fclose(sudokuFile); 
	}	
}

void sudokuLoad (int sudokuA[][9],int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],bool sudokuVB[][9]) {
	FILE *sudokuFile = NULL;  
	sudokuFile  = fopen("resources/Save/sudoku.res","ab+"); 
	if (sudokuFile != NULL ){
	    rewind(sudokuFile);
		fread(sudokuA,sizeof(int),81,sudokuFile);
		fread(sudokuM,sizeof(int),81,sudokuFile);
		fread(sudokuV,sizeof(bool),81,sudokuFile);
		fread(sudokuVe,sizeof(bool),81,sudokuFile);
		fread(sudokuVB,sizeof(bool),81,sudokuFile);  
        fclose(sudokuFile);    			
	}	
}

void settingSvae(bool &mute,int &setSongMenu,int &setSongSudoku,int &setColorBackground,int &setColorMainFrame,int &setColorSudoku1,int &setColorSudoku2,int &setColorText1,int &setColorText2) {
	FILE * settingFile = NULL; 
	settingFile = fopen("resources/Save/setting.res","wb+");
	fclose(settingFile);  
	settingFile = fopen("resources/Save/setting.res","ab+");
	if (settingFile != NULL){
		rewind(settingFile); 
		fwrite(&mute,sizeof(bool),1,settingFile); 
	    fwrite(&setSongMenu,sizeof(int),1,settingFile); 
	    fwrite(&setSongSudoku,sizeof(int),1,settingFile); 
	    fwrite(&setColorBackground,sizeof(int),1,settingFile); 
	    fwrite(&setColorMainFrame,sizeof(int),1,settingFile); 
	    fwrite(&setColorSudoku1,sizeof(int),1,settingFile); 
	    fwrite(&setColorSudoku2,sizeof(int),1,settingFile);
	    fwrite(&setColorText1,sizeof(int),1,settingFile); 
	    fwrite(&setColorText2,sizeof(int),1,settingFile); 

        fclose(settingFile); 
	}	
}

void settingLoad(bool &mute,int &setSongMenu,int &setSongSudoku,int &setColorBackground,int &setColorMainFrame,int &setColorSudoku1,int &setColorSudoku2,int &setColorText1,int &setColorText2) {
    FILE * settingFile = NULL; 
	settingFile = fopen("resources/Save/setting.res","ab+");
	if (settingFile != NULL){
	    fread(&mute,sizeof(bool),1,settingFile); 
	    fread(&setSongMenu,sizeof(int),1,settingFile); 
	    fread(&setSongSudoku,sizeof(int),1,settingFile); 
	    fread(&setColorBackground,sizeof(int),1,settingFile); 
	    fread(&setColorMainFrame,sizeof(int),1,settingFile); 
	    fread(&setColorSudoku1,sizeof(int),1,settingFile); 
	    fread(&setColorSudoku2,sizeof(int),1,settingFile);
	    fread(&setColorText1,sizeof(int),1,settingFile); 
	    fread(&setColorText2,sizeof(int),1,settingFile); 
        fclose(settingFile); 
	}		
}
