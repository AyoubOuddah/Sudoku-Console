void initsudokuVe(bool sudokuVe[][9]){
	for (int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			sudokuVe[i][j]=false;
		}
	}
}
bool isVisible(bool sudokuV [][9],int x,int y){
	return (sudokuV[y][x]==true);
}

bool virifLine(int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],int x,int y){
	bool virif=false; 
	if (!isVisible(sudokuV,x,y)){
		for(int i=0;i<9;i++){
			for(int j=0;j<8;j++){
				for(int k=j+1;k<9;k++){
					if(sudokuM[i][j]==sudokuM[i][k]){
					   sudokuVe[i][j]=true;
					   sudokuVe[i][k]=true;
			           virif=true;
				   }
				}
		    }
		}	
	}
return virif; 
}

bool virifColom(int sudokuM[][9],bool sudokuV [][9],bool sudokuVe [][9],int x,int y){
	bool virif=false; 
	if (!isVisible(sudokuV,x,y)){
	  for(int i=0;i<9;i++){
	  		for(int j=0;j<8;j++){
		 	    for(int k=j+1;k<9;k++){
				    if(sudokuM[j][i]==sudokuM[k][i]){
					   sudokuVe[j][i]=true;
					   sudokuVe[k][i]=true;
					   virif=true;
			        }
		         }
	          }	
	  }
    }
return virif; 
}

bool virifBlock(int sudokuM[][9],bool sudokuV [][9],bool sudokuVB [][9],int x,int y){
	bool virif=false;
	if (!isVisible(sudokuV,x,y)){
		 int a , b ;
	     a = (int) x / 3 ;
	     b = (int) y / 3 ;
	     a *=3;
	     b *=3; 
	     for(int i=b;i<b+3;i++){
	        for(int j=a;j<a+3;j++){	
              if ((sudokuM[y][x]==sudokuM[i][j])){
              	   if (y!=i&&x!=j){
					   sudokuVB[i][j]=true;  
				       sudokuVB[y][x]=true; 
                       virif=true; 
					 }
	          }else 
	              sudokuVB[i][j]=false; 
		    }
		 }
	}     
return virif; 
}

bool virification (int sudokuA[][9],int sudokuM[][9],bool sudokuV[][9],bool sudokuVe[][9],bool sudokuVB[][9],int x,int y){
   initsudokuVe(sudokuVe);
   bool b1=false,b2=false,b3=false,b4=true;
   b1=virifBlock(sudokuM,sudokuV,sudokuVB,x,y);
   b2=virifLine(sudokuM,sudokuV,sudokuVe,x,y);
   b3=virifColom(sudokuM,sudokuV,sudokuVe,x,y);         
  for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++){
	  	    sudokuVe[i][j]=(sudokuVB[i][j]||sudokuVe[i][j]);
			if((sudokuA[i][j]!=sudokuM[i][j])&&(b4==true))
     			b4=false;
		}	
   } 
return b4;
}
