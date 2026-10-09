/* Avani Lakhotia
   10/09/2027
   This is a tictactoe game designed for two players. It reads players' inputs places them on the board, checks for wins, and finally lets the player know if they won and asks if they wanna play again and keeps showing scores.

*/




#include <iostream> 
#include <array>
#include <string>
using namespace std;


// a modern 3x3 std::array of chars, declared the board outside main so all functions can access it
array<array<char, 3>, 3> board = {{
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
  }};

// functions decration
bool  player_turn(char player); // prototype, have it defined at the top
bool is_valid_move( int row_index,int col_index);//bool so it returns true or false
void  place_player (char player,int row_index,int col_index);//places player
void print_board (); //prints board
void reset_board(); // resets board


bool check_row_win( char player); //row win
bool check_col_win( char player); //col win
bool check_tie(); //tie check
bool check_win( char player); //final checking win where i call on all the fuctions above
bool check_diag_win (char player); //check diag win


//main 
int main(){
  char player = 'X'; //x always starts 

  // these variables keep track of scores 
  int x_wins = 0;
    int o_wins = 0;
    int ties = 0;

    print_board(); // prints empty board

    while (true) {
        // asks the current player to make a move and also if the move is wrong the same player gets a turn
        if (!player_turn(player)) {
            continue;
        }

        // check if the current player won
        if (check_win(player)) {
            cout << "Player " << player << " wins!" << endl;

            if (player == 'X') { // adds one to the total score of that player
                x_wins++;
            }
            else {
                o_wins++;
            }
        }
	// checks if the game ended in a tie
        else if (check_tie()) {
            cout << "It's a tie!" << endl;
	    ties++;
	}
        else {
            // switch players after a valid move
            if (player == 'X') {
                player = 'O';
            }
            else {
                player = 'X';
            }
	    
            continue; // starts next turn
        }

        // Display the total wins after a game ends
        cout << "X wins: " << x_wins << endl;
        cout << "O wins: " << o_wins << endl;
	cout << "Ties: "<< ties << endl;

	// asks if the players want another turn
	char again;
	cout << "Do you wanna play again? (y/n): ";
	cin >> again;

	// ends loop if player says no
	if (again == 'n' || again == 'N'){
	  break;
	}
        // reset the board and start a new game
        reset_board();
        player = 'X';
        print_board();
    }

    return 0;
}


//all the functions written here

//resets the board
void reset_board(){
    for (int row_index = 0; row_index < 3; row_index++){
        for (int col_index = 0; col_index < 3; col_index++){
            board[row_index][col_index] = '_';
        }
    }
}

// takes the current player's move and checks if its valid
bool  player_turn(char player){
      //asking player for move                                                                          
  cout << "Player " << player<<  " enter your row: "<<endl;
    char row;
    cin >> row;
    cout << "Player " << player <<" enter your col: "<<endl;
    int  col;
    cin >> col;
    // handles input that cannot be read as the data type, i had to research about this one
    if (cin.fail()) {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Invalid input!" << endl;
      return false;
    }
    // converting answers to indexes                                                                  
    int row_index = row - 'a';// converts a-c to 0-2
    int col_index = col - 1; // converts 1-3 to 0-2

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

// checks whether the selected position is indie the board and also if its valid

bool is_valid_move(int row_index, int col_index) {
  if (row_index < 0 || row_index >= 3 || //making sure row and col are in between range
        col_index < 0 || col_index >= 3) {
        return false;
    }
  // if the postion is open 
    if (board[row_index][col_index] != '_') {
        return false;
    }

    return true;
}

// places x or o at this position
void place_player(char player, int row_index, int col_index) {
    board[row_index][col_index] = player;
}

// displays the baord with colun numbers and row letters
void print_board(){
     cout << "\n  1 2 3 " << endl;
     // stores these letters to identity my rows
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


// checks if the player has 3 in a row 
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
// checks if the player has 3 in a col
bool check_col_win( char player){
  for (int col_index = 0; col_index < 3; col_index++) {
    if (board [0][col_index] == player  &&
        board [1] [col_index] == player &&
        board [2] [col_index] == player) {
	return true;
	}}

  return false;
}

// diagonal posibility
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

//checks tie

bool check_tie(){
  for (int row_index = 0; row_index < 3; row_index++){ // looks for any empty remaining empty positons
        for (int col_index = 0; col_index < 3; col_index++){
           if (board[row_index][col_index] == '_'){
                return false;
            }
        }
    }
  
  // checks if another player has won alr
    if (check_win('X') || check_win('O')){
        return false;
    }

    return true;
}
// combines all those top 3 functions into one check win
bool check_win(char player){
   if (check_row_win (player)){
     return true; }
   if (check_col_win (player)){
     return true;}
   if (check_diag_win (player)){
     return true;}

   return false;
}
