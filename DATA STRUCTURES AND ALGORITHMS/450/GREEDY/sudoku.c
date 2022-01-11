#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void SetColor(int ForgC){
     WORD wColor;
     //This handle is needed to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
      }
}

//function to display the grid
void display_board(int board[9][9],int prev[9][9]){ 
	int i,j;
	printf("\n\n");
	SetColor(2);
    printf(" ___________________________________\n");
    SetColor(4);
	for(i=0;i<9;i++){		
		for(j=0;j<9;j++){
			if(j%3 == 0){
				SetColor(2);
				printf("|");
			}
			else{
			    SetColor(4);
			    printf("|");
			}
			if(board[i][j]==0){
			   printf("   ");
			   continue;
			}
			if(prev[i][j])
				SetColor(1);
			else
				SetColor(6);
			printf(" %d ",board[i][j]);
			SetColor(4);
		}
		SetColor(2);
		printf("|\n");		
	    SetColor(4);
	    char s[100] = "|___|___|___|___|___|___|___|___|___";
	    int k;
		for(k=0;k<strlen(s);k++){
			if(s[k]=='_'){
				if((i+1)%3 == 0)
				    SetColor(2);									
			    printf("%c",s[k]);	
				SetColor(4);									
			}
			else{
				if(k%12==0)
					SetColor(2);				
                printf("%c",s[k]);
                SetColor(4);
				}
			}
		SetColor(2);
		printf("|\n");
	}
}

// function to check whether the given number is a valid choice for the given position
int check(int board[9][9],int i,int j,int num){	
	int k,l;
	// loop to check whether the number already exists in the given row
	for(k=0;k<9;k++){
		if(board[i][k] == num)
		   return 0;
	}

	// loop to check whether the number already exists in the given column
	for(k=0;k<9;k++){
		if(board[k][j] == num)
		   return 0;
	}

    int p = i/3 * 3;
    int q = j/3 * 3;

    // loop to check whether the number already exists in it's 3X3 matrix
    for(k=p;k<p+3;k++){
    	for(l=q;l<q+3;l++){
    		if(board[k][l] == num)
    			return 0;
    	}
    }
    return 1;
}

// function which uses backtracking to solve the grid
int sudoku(int board[9][9],int r,int c,int prev[9][9]){
	int i;
	// checks if the grid is completely filled
	if(r==9){
	  display_board(board,prev);
	  return 1;
	}

	int rf=0,cf=0;
	//checks if the next cell is the last cell of the row
	if(c==8){
	   // move to the next row
       cf=0;
       rf = r + 1;
	}
	else{
		// move to the next column
		rf = r;
		cf = c + 1;
	}

	// checks if the current cell already contains a value
	if(board[r][c]!=0){
		if(sudoku(board,rf,cf,prev))
			return 1;
	}

	//loop to check for the valid values which can be placed in the given cell
	for(i=1;i<=9;i++){
		if(check(board,r,c,i)){
            board[r][c] = i;
            if(sudoku(board,rf,cf,prev))
            	return 1;
            board[r][c] = 0;
		}
	}
	return 0;
}

int main(){	
    int board[9][9];
    int prev[9][9];
    int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			scanf("%d",&board[i][j]);
			if(board[i][j]==0)
			  prev[i][j]=1;
			else
			  prev[i][j]=0;
		}
	}
	display_board(board,prev);
	printf("\n\npress any key to solve this puzzle\n");
	getch();
	sudoku(board,0,0,prev);	
}









