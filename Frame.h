#ifndef FRAME_H 
  #define FRAME_H
  #include <iostream>
  using namespace std; 
  void mainFrame1(int,int,int,bool,int); 
  void mainFrame2(int,int,int,int,int); 
  void mainFrame3(int,int,int,bool,int);
  void mainFrame4(int,int,int,bool,int); 
  void mainFrame(int);
  void labelFrame(int x ,int y , int xD, int yD,int colorT,string label); 
  void sudokuFrame(int,int,int);
  void menu (int y , string menuTab [] , bool enabled );
  void options(int y,string colorList [],string yesNoTab [],string songNames [2] [5],bool,int,int,int,int,int,int,int,int);
  void confirmation(string message , int x,int);
  void difficultyFrame(string difficulty,int colorT);
  void howToPlayFrame(int colorT); 
  void inserer( int sudokuM[][9],bool sudokuV[][9],int x,int y ,char choix);
  void printSudoku(int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],int,int );
#endif
