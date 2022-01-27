#include<stdio.h>

char square[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void board()
{
	system("cls");
	puts("Welcome to tictactoe\n");
	puts("Player 1 (X) 	Player 2(O)\n");
	printf("|%c |%c | %c|\n", square[0][0],square[0][1],square[0][2]);
	printf("----------\n");
	printf("|%c |%c | %c|\n", square[1][0],square[1][1],square[1][2]);
	printf("----------\n");
	printf("|%c |%c | %c|", square[2][0],square[2][1],square[2][2]);
}

int checkwin()
{
		if(square[0][0]==square[0][1] && square[0][1]==square[0][2])
				return 1;  
		else if (square[1][0]==square[1][1] && square[1][1]==square[1][2])
		 		return 1; 
		else if	(square[2][0]==square[2][1] && square[2][1]==square[2][2])
				return 1;
		else if (square[0][0]==square[1][0] && square[1][0]==square[2][0])
				return 1;
		else if (square[0][1]==square[1][1] && square[1][1]==square[2][1])
				return 1;
		else if (square[0][2]==square[1][2] && square[1][2]==square[2][2])
				return 1;
		else if	(square[0][0]==square[1][1] && square[1][1]==square[2][2])
				return 1;
		else if (square[2][0]==square[1][1] && square[1][1]==square[0][2] )//checks if the player already won the game by assessing if each index contains the same input, whether x or o
				return 1;
		else
				return -1;
}

int main()
{
	int player=1, row, coloum,itr,itc,i;
	char mark;
	do{
		board();
		player=(player%2)? 1:2;
		printf("\nPlayer %d enter what row and coloum: \n" ,player);
		puts("enter row and coloum: ");
		scanf("%d%d", &row, &coloum);
		mark=(player==1)? 'X':'O';
		if(square[row][coloum]== ' ')
		{
			square[row][coloum]=mark;
		}else 
		{
			puts("the cell is already taken. enter another cell");
			player--;
			getch();
		}
		i=checkwin();
		player++;		
	}while(i==-1);
	board();
	if(i==1)
		printf("\nplayer %d win the game", --player);
	else
		printf("game draw");
		getch();		
		return 0;
}
