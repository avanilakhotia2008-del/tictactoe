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
    int x_wins = 0;
    int o_wins = 0;
    int ties = 0;

    print_board();

    while (true) {
        // Ask the current player to make a move
        if (!player_turn(player)) {
            continue;
        }

        // Check if the current player won
        if (check_win(player)) {
            cout << "Player " << player << " wins!" << endl;

            if (player == 'X') {
                x_wins++;
            }
            else {
                o_wins++;
            }
        }
	// Check if the game ended in a tie
        else if (check_tie()) {
            cout << "It's a tie!" << endl;
	    ties++;
	}
        else {
            // Switch players after a valid move
            if (player == 'X') {
                player = 'O';
            }
            else {
                player = 'X';
            }

            continue;
        }

        // Display the total wins after a game ends
        cout << "X wins: " << x_wins << endl;
        cout << "O wins: " << o_wins << endl;
	cout << "Ties: "<< ties << endl;

	char again;
	cout << "Do you wanna play again? (y/n): ";
	cin >> again;


	if (again == 'n' || again == 'N'){
	  break;
	}
        // Reset the board and start a new game
        reset_board();
        player = 'X';
        print_board();
    }

    return 0;
}


void reset_board(){
    for (int row_index = 0; row_index < 3; row_index++){
        for (int col_index = 0; col_index < 3; col_index++){
            board[row_index][col_index] = '_';
        }
    }
}

bool  player_turn(char player){
      //asking player for move                                                                          
  cout << "Player " << player<<  " enter your row: "<<endl;
    char row;
    cin >> row;
    cout << "Player " << player <<" enter your col: "<<endl;
    int  col;
    cin >> col;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid input!" << endl;
      return false;
    }
    // converting answers to indexes                                                                  
    int row_index = row - 'a';
    int col_index = col - 1;

    //checks and moves player to the place                                                            
    if (is_valid_move(row_index, col_index)) {
      place_player(player, row_index, col_index);
      print_board();
      return true;
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
  for (int row_index = 0; row_index < 3; row_index++) {
    if (board[row_index][0] == player  &&
	board [row_index][1] == player &&
	board [row_index][2] == player) {
	return true;
	}

  }
  

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
