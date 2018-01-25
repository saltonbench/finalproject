
#include "chess.c"




int evalboard(struct board * board){
  int value = 0;
  int king[8][8];
  int queen[8][8];
  int rook[8][8];
  int knight[8][8];
  int bishop[8][8];
  int pawn[8][8];

  king[0][0] = -30;
  king[0][1] = -40;
  king[0][2] = -40;
  king[0][3] = -50;
  king[0][4] = -50;
  king[0][5] = -40;
  king[0][6] = -40;
  king[0][7] = -30;

  king[1][0] = -30;
  king[1][1] = -40;
  king[1][2] = -40;
  king[1][3] = -50;
  king[1][4] = -50;
  king[1][5] = -40;
  king[1][6] = -40;
  king[1][7] = -30;

  king[2][0] = -30;
  king[2][1] = -40;
  king[2][2] = -40;
  king[2][3] = -50;
  king[2][4] = -50;
  king[2][5] = -40;
  king[2][6] = -40;
  king[2][7] = -30;
  
  king[3][0] = -30;
  king[3][1] = -40;
  king[3][2] = -40;
  king[3][3] = -50;
  king[3][4] = -50;
  king[3][5] = -40;
  king[3][6] = -40;
  king[3][7] = -30;
  
  king[4][0] = -20;
  king[4][1] = -30;
  king[4][2] = -30;
  king[4][3] = -40;
  king[4][4] = -40;
  king[4][5] = -30;
  king[4][6] = -30;
  king[4][7] = -20;
  
  king[5][0] = -10;
  king[5][1] = -20;
  king[5][2] = -20;
  king[5][3] = -20;
  king[5][4] = -20;
  king[5][5] = -20;
  king[5][6] = -20;
  king[5][7] = -10;
  
  king[6][0] = 20;
  king[6][1] = 20;
  king[6][2] = 0;
  king[6][3] = 0;
  king[6][4] = 0;
  king[6][5] = 0;
  king[6][6] = 20;
  king[6][7] = 20;
  
  king[7][0] = 20;
  king[7][1] = 30;
  king[7][2] = 10;
  king[7][3] = 0;
  king[7][4] = 0;
  king[7][5] = 10;
  king[7][6] = 30;
  king[7][7] = 20;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  queen[0][0] = -20;
  queen[0][1] = -10;
  queen[0][2] = -10;
  queen[0][3] = -5;
  queen[0][4] = -5;
  queen[0][5] = -10;
  queen[0][6] = -10;
  queen[0][7] = -20;

  queen[1][0] = -10;
  queen[1][1] = 0;
  queen[1][2] = 0;
  queen[1][3] = 0;
  queen[1][4] = 0;
  queen[1][5] = 0;
  queen[1][6] = 0;
  queen[1][7] = -10;

  queen[2][0] = -10;
  queen[2][1] = 0;
  queen[2][2] = 5;
  queen[2][3] = 5;
  queen[2][4] = 5;
  queen[2][5] = 5;
  queen[2][6] = 0;
  queen[2][7] = -10;
  
  queen[3][0] = -5;
  queen[3][1] = 0;
  queen[3][2] = 5;
  queen[3][3] = 5;
  queen[3][4] = 5;
  queen[3][5] = 5;
  queen[3][6] = 0;
  queen[3][7] = -5;
  
  queen[4][0] = 0;
  queen[4][1] = 0;
  queen[4][2] = 5;
  queen[4][3] = 5;
  queen[4][4] = 5;
  queen[4][5] = 5;
  queen[4][6] = 0;
  queen[4][7] = -5;
  
  queen[5][0] = -10;
  queen[5][1] = 5;
  queen[5][2] = 5;
  queen[5][3] = 5;
  queen[5][4] = 5;
  queen[5][5] = 5;
  queen[5][6] = 0;
  queen[5][7] = -10;
  
  queen[6][0] = -10;
  queen[6][1] = 0;
  queen[6][2] = 5;
  queen[6][3] = 0;
  queen[6][4] = 0;
  queen[6][5] = 0;
  queen[6][6] = 0;
  queen[6][7] = -10;
  
  queen[7][0] = -20;
  queen[7][1] = -10;
  queen[7][2] = -10;
  queen[7][3] = -5;
  queen[7][4] = -5;
  queen[7][5] = -10;
  queen[7][6] = -10;
  queen[7][7] = -20;

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  bishop[0][0] = -20;
  bishop[0][1] = -10;
  bishop[0][2] = -10;
  bishop[0][3] = -10;
  bishop[0][4] = -10;
  bishop[0][5] = -10;
  bishop[0][6] = -10;
  bishop[0][7] = -20;

  bishop[1][0] = -10;
  bishop[1][1] = 0;
  bishop[1][2] = 0;
  bishop[1][3] = 0;
  bishop[1][4] = 0;
  bishop[1][5] = 0;
  bishop[1][6] = 0;
  bishop[1][7] = -10;

  bishop[2][0] = -10;
  bishop[2][1] = 0;
  bishop[2][2] = 5;
  bishop[2][3] = 10;
  bishop[2][4] = 10;
  bishop[2][5] = 5;
  bishop[2][6] = 0;
  bishop[2][7] = -10;
  
  bishop[3][0] = -10;
  bishop[3][1] = 5;
  bishop[3][2] = 5;
  bishop[3][3] = 10;
  bishop[3][4] = 10;
  bishop[3][5] = 5;
  bishop[3][6] = 5;
  bishop[3][7] = -10;
  
  bishop[4][0] = -10;
  bishop[4][1] = 0;
  bishop[4][2] = 10;
  bishop[4][3] = 10;
  bishop[4][4] = 10;
  bishop[4][5] = 10;
  bishop[4][6] = 0;
  bishop[4][7] = -10;
  
  bishop[5][0] = -10;
  bishop[5][1] = 10;
  bishop[5][2] = 10;
  bishop[5][3] = 10;
  bishop[5][4] = 10;
  bishop[5][5] = 10;
  bishop[5][6] = 10;
  bishop[5][7] = -10;
  
  bishop[6][0] = -10;
  bishop[6][1] = 5;
  bishop[6][2] = 0;
  bishop[6][3] = 0;
  bishop[6][4] = 0;
  bishop[6][5] = 0;
  bishop[6][6] = 5;
  bishop[6][7] = -10;
  
  bishop[7][0] = -20;
  bishop[7][1] = -10;
  bishop[7][2] = -10;
  bishop[7][3] = -10;
  bishop[7][4] = -10;
  bishop[7][5] = -10;
  bishop[7][6] = -10;
  bishop[7][7] = -20;

  //////////////////////////////////////////////////////////////////////////////////////////////////////

  knight[0][0] = -50;
  knight[0][1] = -40;
  knight[0][2] = -30;
  knight[0][3] = -30;
  knight[0][4] = -30;
  knight[0][5] = -30;
  knight[0][6] = -40;
  knight[0][7] = -50;

  knight[1][0] = -40;
  knight[1][1] = -20;
  knight[1][2] = 0;
  knight[1][3] = 0;
  knight[1][4] = 0;
  knight[1][5] = 0;
  knight[1][6] = -20;
  knight[1][7] = -40;

  knight[2][0] = -30;
  knight[2][1] = 0;
  knight[2][2] = 10;
  knight[2][3] = 15;
  knight[2][4] = 15;
  knight[2][5] = 10;
  knight[2][6] = 0;
  knight[2][7] = -30;
  
  knight[3][0] = -30;
  knight[3][1] = 5;
  knight[3][2] = 15;
  knight[3][3] = 20;
  knight[3][4] = 20;
  knight[3][5] = 15;
  knight[3][6] = 5;
  knight[3][7] = -30;
  
  knight[4][0] = -30;
  knight[4][1] = 0;
  knight[4][2] = 15;
  knight[4][3] = 20;
  knight[4][4] = 20;
  knight[4][5] = 15;
  knight[4][6] = 0;
  knight[4][7] = -30;
  
  knight[5][0] = -30;
  knight[5][1] = 5;
  knight[5][2] = 10;
  knight[5][3] = 15;
  knight[5][4] = 15;
  knight[5][5] = 10;
  knight[5][6] = 5;
  knight[5][7] = -30;
  
  knight[6][0] = -40;
  knight[6][1] = -20;
  knight[6][2] = 0;
  knight[6][3] = 5;
  knight[6][4] = 5;
  knight[6][5] = 0;
  knight[6][6] = -20;
  knight[6][7] = -40;
  
  knight[7][0] = -50;
  knight[7][1] = -40;
  knight[7][2] = -30;
  knight[7][3] = -30;
  knight[7][4] = -30;
  knight[7][5] = -30;
  knight[7][6] = -40;
  knight[7][7] = -50;

  ////////////////////////////////////////////////////////////////////////////////////////////////////

  rook[0][0] = 0;
  rook[0][1] = 0;
  rook[0][2] = 0;
  rook[0][3] = 0;
  rook[0][4] = 0;
  rook[0][5] = 0;
  rook[0][6] = 0;
  rook[0][7] = 0;

  rook[1][0] = 5;
  rook[1][1] = 10;
  rook[1][2] = 10;
  rook[1][3] = 10;
  rook[1][4] = 10;
  rook[1][5] = 10;
  rook[1][6] = 10;
  rook[1][7] = 5;

  rook[2][0] = -5;
  rook[2][1] = 0;
  rook[2][2] = 0;
  rook[2][3] = 0;
  rook[2][4] = 0;
  rook[2][5] = 0;
  rook[2][6] = 0;
  rook[2][7] = -5;
  
  rook[3][0] = -5;
  rook[3][1] = 0;
  rook[3][2] = 0;
  rook[3][3] = 0;
  rook[3][4] = 0;
  rook[3][5] = 0;
  rook[3][6] = 0;
  rook[3][7] = -5;
  
  rook[4][0] = -5;
  rook[4][1] = 0;
  rook[4][2] = 0;
  rook[4][3] = 0;
  rook[4][4] = 0;
  rook[4][5] = 0;
  rook[4][6] = 0;
  rook[4][7] = -5;
  
  rook[5][0] = -5;
  rook[5][1] = 0;
  rook[5][2] = 0;
  rook[5][3] = 0;
  rook[5][4] = 0;
  rook[5][5] = 0;
  rook[5][6] = 0;
  rook[5][7] = -5;
  
  rook[6][0] = -5;
  rook[6][1] = 0;
  rook[6][2] = 0;
  rook[6][3] = 0;
  rook[6][4] = 0;
  rook[6][5] = 0;
  rook[6][6] = 0;
  rook[6][7] = -5;
  
  rook[7][0] = 0;
  rook[7][1] = 0;
  rook[7][2] = 0;
  rook[7][3] = 5;
  rook[7][4] = 5;
  rook[7][5] = 0;
  rook[7][6] = 0;
  rook[7][7] = 0;

  //////////////////////////////////////////////////////////////////////////////////////////////////

  pawn[0][0] = 0;
  pawn[0][1] = 0;
  pawn[0][2] = 0;
  pawn[0][3] = 0;
  pawn[0][4] = 0;
  pawn[0][5] = 0;
  pawn[0][6] = 0;
  pawn[0][7] = 0;

  pawn[1][0] = 50;
  pawn[1][1] = 50;
  pawn[1][2] = 50;
  pawn[1][3] = 50;
  pawn[1][4] = 50;
  pawn[1][5] = 50;
  pawn[1][6] = 50;
  pawn[1][7] = 50;

  pawn[2][0] = 10;
  pawn[2][1] = 10;
  pawn[2][2] = 20;
  pawn[2][3] = 30;
  pawn[2][4] = 30;
  pawn[2][5] = 20;
  pawn[2][6] = 10;
  pawn[2][7] = 10;
  
  pawn[3][0] = 5;
  pawn[3][1] = 5;
  pawn[3][2] = 10;
  pawn[3][3] = 25;
  pawn[3][4] = 25;
  pawn[3][5] = 10;
  pawn[3][6] = 5;
  pawn[3][7] = 5;
  
  pawn[4][0] = 0;
  pawn[4][1] = 0;
  pawn[4][2] = 0;
  pawn[4][3] = 20;
  pawn[4][4] = 20;
  pawn[4][5] = 0;
  pawn[4][6] = 0;
  pawn[4][7] = 0;
  
  pawn[5][0] = 5;
  pawn[5][1] = -5;
  pawn[5][2] = -10;
  pawn[5][3] = 0;
  pawn[5][4] = 0;
  pawn[5][5] = -10;
  pawn[5][6] = -5;
  pawn[5][7] = 5;
  
  pawn[6][0] = 5;
  pawn[6][1] = 10;
  pawn[6][2] = 10;
  pawn[6][3] = -20;
  pawn[6][4] = -20;
  pawn[6][5] = 10;
  pawn[6][6] = 10;
  pawn[6][7] = 5;
  
  pawn[7][0] = 0;
  pawn[7][1] = 0;
  pawn[7][2] = 0;
  pawn[7][3] = 0;
  pawn[7][4] = 0;
  pawn[7][5] = 0;
  pawn[7][6] = 0;
  pawn[7][7] = 0;

  //////////////////////////////////////////////////////////////////////////

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      char aa = (*board).a[i][j];
      if(aa == 'P'){
	value += pawn[i][j];
      }
      if(aa == 'p'){
	value -= pawn[7 - i][j];
      }
      if(aa == 'R'){
	value += rook[i][j];
      }
      if(aa == 'r'){
	value -= rook[7 - i][j];
      }
      if(aa == 'N'){
	value += knight[i][j];
      }
      if(aa == 'n'){
	value -= knight[7-i][j];
      }
      if(aa == 'B'){
	value += bishop[i][j];
      }
      if(aa == 'b'){
	value -= bishop[7 - i][j];
      }
      if(aa == 'K'){
	value += king[i][j];
      }
      if(aa == 'k'){
	value -= king[7 - i][j];
      }
      if(aa == 'Q'){
	value += queen[i][j];
      }
      if(aa == 'q'){
	value -= queen[7 - i][j];
      } 
    }
  }

  return value;
}

int main(){
  struct board* board = startgame();
  printboard(board);
  while(1){
    char input[10];
    fgets(input, sizeof(input), stdin);
    char i = input[0] - '0';
    char j = input[1] - '0';
    char m = input[2] - '0';
    char n = input[3] - '0';
    movepieceWrap(board,i,j,m,n);
    printboard(board);
    printf("%d\n", evalboard(board));
  }  
  return 0;
}
