#ifndef VERIFICATION_H
  #define VERIFICATION_H
  #include<iostream> 
  using namespace std; 
  void initsudokuVe(bool sudokuVe[][9]);
  bool isVisible(bool sudokuV [][9],int x,int y); 
  bool virifLine(int sudokuM[][9],bool sudokuV [][9],bool sudokuVe [][9],int x,int y); 
  bool virifColom(int sudokuM[][9],bool sudokuV [][9],bool sudokuVe [][9],int x,int y); 
  bool virifBlock(int sudokuM[][9],bool sudokuV [][9],bool sudokuVe [][9],int x,int y); 
  bool virification (int sudokuA[][9],int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],bool sudokuVB[][9],int x , int y); 
#endif
