#ifndef SUDOKUGEN_H 
  #define SUDOKUGEN_H 
  #include<iostream>
  using namespace std;
  void afect(int sudoku[9][9],int sudokuA[9][9],int sudokuM[9][9],bool sudokuV[9][9],bool sudokuVe[9][9]);
  void chll(int sudokuA[9][9]); 
  void chcc(int sudokuA[9][9]);
  void chbc(int sudokuA[9][9]);
  void chbl(int sudokuA[9][9]);
  void chtr(int sudokuA[9][9]);
  void chmr(int sudokuA[9][9]);
  void visib(int sudokuA[9][9],int sudokuM[9][9],bool sudokuV[9][9], int def);
  void gen(int sudoku[9][9],int sudokuA[9][9],int sudokuM[9][9], bool sudokuV[9][9],bool sudokuVe[9][9],int def);  
#endif 
