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


void  player_turn(); // prototype, have it defined at the top
bool is_valid_move( int row_index,int col_index);//bool so it returns true or false
void  place_player (char player,int row_index,int col_index);
void print_board ();
int main(){

    char player = 'X';
    print_board();
    

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
    }

    return 0;
}

void player_turn(){
  // now write the function in here

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
