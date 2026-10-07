#include <iostream>
#include <vector> 
#include <array>
using namespace std;


void player_turn(); // prototype, have it defined at the top

int main(){
    // A modern 3x3 std::array of chars
    array<array<char, 3>, 3> board = {{
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    }};

    // Using range-based for loops for modern, safer iteration
    for (const auto& row : board) { // outer loop that goes through every row of my 2d structure, it is referencing & and const so that it doesn't make extra copies of my data
      for (const auto& cell : row) { // this is the inner loop, it visits every individual element from left to right
	  cout << cell << " "; // this space is the space between the underscores 
        }
        cout << "\n"; 
    }

    string player = "X";
    cout << player <<endl;

    return 0;

}

void playerturn(){
  // now write the function in here

}
