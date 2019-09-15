#include <windows.h>
#include <MMSystem.h>
void songPlayer(int i,int songN){
    switch(i){
    	case 1: {
			switch(songN){  // menu  songs 
		          case 0 : { 
			            PlaySound(TEXT("resources/sound/Menu/Bomberguy.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			      break;
	        	  }
		          case 1 : {
                        PlaySound(TEXT("resources/sound/Menu/Retro.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			      break;
		          }
		          case 2 : {
                        PlaySound(TEXT("resources/sound/Menu/Sequence.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			      break;
		          }
		          case 3 : {
 	    		        PlaySound(TEXT("resources/sound/Menu/Sonic-Power.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			      break;
		          }
		          case 4 : {
		          	 	PlaySound(TEXT("resources/sound/Menu/Type-Zero.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
					break;
				  }
	        }
		break; 
		}
	    case 2: {
		     switch(songN){ // sudoku songs
		          case 0 : {
 	    		        PlaySound(TEXT("resources/sound/Sudoku/Androids.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			
			      break;
	        	  }
		          case 1 : {
 	    		        PlaySound(TEXT("resources/sound/Sudoku/Brave-Worm.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			
			      break;
		          }
		          case 2 : {
 	    		        PlaySound(TEXT("resources/sound/Sudoku/Gamey.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			      break;
		          }
		          case 3 : {
 	    		        PlaySound(TEXT("resources/sound/Sudoku/Pinball.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			      break;
		          }
		          case 4 : {
		          	 	PlaySound(TEXT("resources/sound/Sudoku/Star-Commander.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
					break;
				  }
	        }
	    break;
 	    }
        /* case 1 : {    // start Animation  
 	    		  PlaySound(TEXT("resources/sound/POL-type-zero-short.wav"),NULL,SND_ASYNC|SND_FILENAME|SND_LOOP); 
			break;
		}
		case 4 : {  // congrat Animation
			
			break;
		}*/ 
		case 3: {
			     PlaySound(NULL,NULL,0); 
			break;
		}
	}
}
