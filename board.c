#include "chess.h"



struct board {char a[8][8];};


struct board* startgame(){
  struct board* b = malloc(sizeof(struct board));


  (*b).a[0][0] = 'r';
  (*b).a[0][1] = 'n';
  (*b).a[0][2] = 'b';
  (*b).a[0][3] = 'q';
  (*b).a[0][4] = 'k';
  (*b).a[0][5] = 'b';
  (*b).a[0][6] = 'n';
  (*b).a[0][7] = 'r';

  
  (*b).a[7][0] = 'R';
  (*b).a[7][1] = 'N';
  (*b).a[7][2] = 'B';
  (*b).a[7][3] = 'Q';
  (*b).a[7][4] = 'K';
  (*b).a[7][5] = 'B';
  (*b).a[7][6] = 'N';
  (*b).a[7][7] = 'R';

  //MAKES PAWNS
  for(int n = 0; n < 8; n++){
    (*b).a[1][n] = 'O';
    (*b).a[6][n] = 'O';
  }

  for(int i = 2; i < 6; i++){
    for(int j = 0; j < 8; j++){
      (*b).a[i][j] = 'O';
    }
  }

  
  return b;


}

void movepiece(struct board* board, int i, int j, int m, int n){
  char a = (*board).a[i][j];
  (*board).a[i][j] = 'O';
  (*board).a[m][n] = a;
}

int movepieceWrap(struct board* board, int i, int j, int m, int n){
  char a = (*board).a[i][j];
  if(a == 'O'){
    return -1;
  }
  //KING
  if(a == 'K'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( ((i - m) * (i - m) == 0 || (i - m) * (i - m) == 1) && ((j - n) * (j - n) == 0 || (j - n) * (j - n) == 1)){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }    
  }
  
  if(a == 'k'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( ((i - m) * (i - m) == 0 || (i - m) * (i - m) == 1) && ((j - n) * (j - n) == 0 || (j - n) * (j - n) == 1)){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }    
  }


  

  //Pawns///////////////////////////////////////////////////////////////////
  if(a == 'P'){

    if(m == i - 1 && n == j && (*board).a[i - 1][j] == 'O'){ //move one
      movepiece(board, i, j, m, n);
      return 0;
    }
       
    if(m == i - 2 && n == j && i == 6 && (*board).a[i - 1][j] == 'O' && (*board).a[i - 2][j] == 'O'){ //move two
      movepiece(board, i, j, m, n);
      return 0;
    }
    
    if(m == i - 1 && (n == j - 1 || n == j + 1) && (*board).a[m][n] != 'O' && (*board).a[m][n] > 90){ //capture
      movepiece(board, i, j, m, n);
      return 0;
    }

    return -1;
    
  }

  
  if(a == 'p'){

    if(m == i + 1 && n == j && (*board).a[i + 1][j] == 'O'){ //move one
      movepiece(board, i, j, m, n);
      return 0;
    }
       
    if(m == i + 2 && n == j && i == 1 && (*board).a[i + 1][j] == 'O' && (*board).a[i + 2][j] == 'O'){ //move two
      movepiece(board, i, j, m, n);
      return 0;
    }
    
    if(m == i + 1 && (n == j - 1 || n == j + 1) && (*board).a[m][n] != 'O' && (*board).a[m][n] < 90){ //capture
      movepiece(board, i, j, m, n);
      return 0;
    }

    return -1;
    
  }


  ////////////////////////////////////////////////////////////////////////////
  //Rooks//////////////////////////////////////////////////////////////////////


  if(a == 'R'){
   
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    
    if(i == m){ //horizontal move
      if( j < n ){ //move to the right
	int yes = 0;
	
	for(int count = j + 1; count < n; count++){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      else if( j > n ){ //move to the left
	int yes = 0;
	for(int count = j - 1; count > n; count--){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }



    }

    if(j == n){ //vertical move



      if(i < m){ //downward move
	int yes = 0;

	for(int count = i + 1; count < m; count++){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }




      else if(i > m){ //upward move
	int yes = 0;

	for(int count = i - 1; count > m; count--){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      



    }





    else{
      return -1;
    }
  }


  if(a == 'r'){
   
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    
    if(i == m){ //horizontal move
      if( j < n ){ //move to the right
	int yes = 0;
	
	for(int count = j + 1; count < n; count++){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      else if( j > n ){ //move to the left
	int yes = 0;
	for(int count = j - 1; count > n; count--){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }



    }

    if(j == n){ //vertical move



      if(i < m){ //downward move
	int yes = 0;

	for(int count = i + 1; count < m; count++){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }




      else if(i > m){ //upward move
	int yes = 0;

	for(int count = i - 1; count > m; count--){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      



    }





    else{
      return -1;
    }
  }
  
  //////////////////////////////////////////////////////////////////////////////////////
  //KNIGHT
  
  if(a == 'N'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( (i - m == 2 || i - m == -2) && (j - n == 1 || j - n == -1) ){
      movepiece(board, i, j, m, n);
      return 0;
    }

    if( (i - m == 1 || i - m == -1) && (j - n == 2 || j - n == -2) ){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
  }
  if(a == 'n'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( (i - m == 2 || i - m == -2) && (j - n == 1 || j - n == -1) ){
      movepiece(board, i, j, m, n);
      return 0;
    }

    if( (i - m == 1 || i - m == -1) && (j - n == 2 || j - n == -2) ){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
  }

  
  
  //////////////////////////////////////////////////////////////////////////////////////
  //BISHOP

  if(a == 'B'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( !( (i - m == j - n) || (i - m == n - j)) ){ //valid moves
      return -1;
    }

    int hor = 0;
    int ver = 0;
    if(i < m){ //going down
      ver = 1;
    }
    else{ //going up
      ver = -1;
    }

    if(j < n){ //going to the right
      hor = 1;
    }
    else{ //going to the left
      hor = -1;
    }

    int ci = i + ver;
    int cj = j + hor;
    int yes = 0;
    while(ci != m){
      if((*board).a[ci][cj] != 'O'){
	yes = -1;
      }
      ci += ver;
      cj += hor;
    }

    if(yes == 0){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
    

  }
  
  if(a == 'b'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( !( (i - m == j - n) || (i - m == n - j)) ){ //valid moves
      return -1;
    }

    int hor = 0;
    int ver = 0;
    if(i < m){ //going down
      ver = 1;
    }
    else{ //going up
      ver = -1;
    }

    if(j < n){ //going to the right
      hor = 1;
    }
    else{ //going to the left
      hor = -1;
    }

    int ci = i + ver;
    int cj = j + hor;
    int yes = 0;
    while(ci != m){
      if((*board).a[ci][cj] != 'O'){
	yes = -1;
      }
      ci += ver;
      cj += hor;
    }

    if(yes == 0){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
    

  }

  //////////////////////////////////////////////////////////////////////////////////////
  //QUEEN

  if( a == 'Q'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    //like a bishop
    if((i - m == j - n) || (i - m == n - j)){
      int hor = 0;
      int ver = 0;
      if(i < m){ //going down
	ver = 1;
      }
      else{ //going up
	ver = -1;
      }
      
      if(j < n){ //going to the right
	hor = 1;
      }
      else{ //going to the left
	hor = -1;
      }
      
      int ci = i + ver;
      int cj = j + hor;
      int yes = 0;
      while(ci != m){
	if((*board).a[ci][cj] != 'O'){
	  yes = -1;
	}
	ci += ver;
	cj += hor;
      }
      
      if(yes == 0){
	movepiece(board, i, j, m, n);
	return 0;
      }
      else{
	return -1;
      }    
    }
    //like a rook
    if(i == m || j == n){ 
      if(i == m){ //horizontal move
	if( j < n ){ //move to the right
	  int yes = 0;
	  
	  for(int count = j + 1; count < n; count++){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	else if( j > n ){ //move to the left
	  int yes = 0;
	  for(int count = j - 1; count > n; count--){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
      }
      
      if(j == n){ //vertical move
	
	
	
	if(i < m){ //downward move
	  int yes = 0;
	  
	  for(int count = i + 1; count < m; count++){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
	
	else if(i > m){ //upward move
	  int yes = 0;
	  
	  for(int count = i - 1; count > m; count--){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}	
      }
      
    }
    else{
      return -1;
    }   
  }

  if( a == 'q'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    //like a bishop
    if((i - m == j - n) || (i - m == n - j)){
      int hor = 0;
      int ver = 0;
      if(i < m){ //going down
	ver = 1;
      }
      else{ //going up
	ver = -1;
      }
      
      if(j < n){ //going to the right
	hor = 1;
      }
      else{ //going to the left
	hor = -1;
      }
      
      int ci = i + ver;
      int cj = j + hor;
      int yes = 0;
      while(ci != m){
	if((*board).a[ci][cj] != 'O'){
	  yes = -1;
	}
	ci += ver;
	cj += hor;
      }
      
      if(yes == 0){
	movepiece(board, i, j, m, n);
	return 0;
      }
      else{
	return -1;
      }    
    }
    //like a rook
    if(i == m || j == n){ 
      if(i == m){ //horizontal move
	if( j < n ){ //move to the right
	  int yes = 0;
	  
	  for(int count = j + 1; count < n; count++){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	else if( j > n ){ //move to the left
	  int yes = 0;
	  for(int count = j - 1; count > n; count--){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
      }
      
      if(j == n){ //vertical move
	
	
	
	if(i < m){ //downward move
	  int yes = 0;
	  
	  for(int count = i + 1; count < m; count++){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
	
	else if(i > m){ //upward move
	  int yes = 0;
	  
	  for(int count = i - 1; count > m; count--){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}	
      }
      
    }
    else{
      return -1;
    }   
  }

  return -1;
}


void printboard(struct board* board){
   for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf("%c ", (*board).a[i][j]);
    }
    printf("\n");
  }  
}



void main(){
  printf("insert command:");
  char command[256];
  fgets(command, sizeof(command), stdin);
  command[strlen(command)-1] = 0;
  if(strcmp(command, "ai")==0){
    char name[256];
    printf("choose file to write into:");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) -1] = 0;
    printf("initializing game\n");
    struct board* board = startgame();
    printboard(board);
    while(1){
      
      char line[4];
      fgets(line, 10, stdin);
      int i = line[0] - '0';
      int j = line[1] - '0';
      int m = line[2] - '0';
      int n = line[3] - '0';
      
      movepieceWrap(board, i, j, m, n);
      printboard(board);
      //write game states
      remove(name);
      int file = open(name, O_CREAT | O_WRONLY, 0600);
      write(file, board,4*8*8);
      
   
    }
  }
  else if (strcmp(command, "load")==0){
    printf("file to load:");
    char name[256];
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1]=0;
    int file = open(name, O_RDWR, 0600);
    struct board* b = malloc(sizeof(struct board));
    read(file, b,4*8*8);
    close(file);
    printboard(b);
    while(1){
      
      char line[4];
      fgets(line, 10, stdin);
      int i = line[0] - '0';
      int j = line[1] - '0';
      int m = line[2] - '0';
      int n = line[3] - '0';
      
      movepieceWrap(b, i, j, m, n);
      printboard(b);
      //write game states
      remove(name);
      int file = open(name, O_CREAT | O_WRONLY, 0600);
      write(file, b,4*8*8);
    }
  }
  else{
    printf("invalid command");
  }
  return;
}
