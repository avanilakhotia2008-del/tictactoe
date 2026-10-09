#include <iostream> 
#include <array>
#include <string>
using namespace std;


// A modern 3x3 std::array of chars, declared the board outside main so all functions can access it
array<array<char, 3>, 3> board = {{
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
  }};

bool  player_turn(char player); // prototype, have it defined at the top
bool is_valid_move( int row_index,int col_index);//bool so it returns true or false
void  place_player (char player,int row_index,int col_index);
void print_board ();
void reset_board();


bool check_row_win( char player);
bool check_col_win( char player);
bool check_tie();
bool check_win( char player);
bool check_diag_win (char player);


int main(){

    char player = 'X';
    print_board();

    return 0;
}

bool  player_turn(char player){
      //asking player for move                                                                          
    cout << "Player  enter your row: "<<endl;
    char row;
    cin >> row;
    cout << "Player enter your col: "<<endl;
    int  col;
    cin >> col;

    // converting answers to indexes                                                                  
    int row_index = row - 'a';
    int col_index = col - 1;

    //checks and moves player to the place                                                            
    if (is_valid_move(row_index, col_index)) {
      place_player(player, row_index, col_index);
      print_board();
    }
    else {
      cout << "Invalid move!" << endl;
      return false;
    }
   
}

bool is_valid_move(int row_index, int col_index) {
    if (row_index < 0 || row_index >= 3 ||
        col_index < 0 || col_index >= 3) {
        return false;
    }

    if (board[row_index][col_index] != '_') {
        return false;
    }

    return true;
}

void place_player(char player, int row_index, int col_index) {
    board[row_index][col_index] = player;
}

void print_board(){
     cout << "\n  1 2 3 " << endl;
    array<char, 3> letters = {'a', 'b', 'c'};

    int counter = 0;
    for (const auto& row : board) { // outer loop that goes through every row of my 2d array
      cout << letters [counter] << " "; //prints letters based on the row                           
    for (const auto& cell : row) { // this is the inner loop, it visits every individual elements   
      cout << cell << " "; // this space is the space between the underscores                    
        }
    cout << "\n";
    counter++;
    }
}

bool check_row_win( char player){
  for (int row_index = 0; row_index < 3;row_index++) {
    if (board[row_index][0] == player  &&
	board [row_index][1] == player &&
	board [row_index][2] == player) {
	return true;
	}}

  return false;
}

bool check_col_win( char player){
  for (int col_index = 0; col_index < 3; col_index++) {
    if (board [0][col_index] == player  &&
        board [1] [col_index] == player &&
        board [2] [col_index] == player) {
	return true;
	}}

  return false;
}


bool check_diag_win (char player){
  if (board [0][0] == player &&
      board [1][1] == player &&
      board [2][2] == player){

    return true;
  }
  if (board [0][2] == player &&
      board [1][1] == player &&
      board [2][0] == player){

    return true;
  }

  return false;
}

bool check_tie(){
    for (int row_index = 0; row_index < 3; row_index++){
        for (int col_index = 0; col_index < 3; col_index++){
            if (board[row_index][col_index] == '_'){
                return false;
            }
        }
    }

    if (check_win('X') || check_win('O')){
        return false;
    }

    return true;
}

bool check_win(char player){
   if (check_row_win (player)){
     return true; }
   if (check_col_win (player)){
     return true;}
   if (check_diag_win (player)){
     return true;}

   return false;
}
