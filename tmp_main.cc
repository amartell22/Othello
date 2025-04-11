#include "colors.h"
#include <iostream>
#include <string>
#include "othello.h"
using namespace std;

int main(){
    Othello my_game;    
    my_game.play();
    // int row = 1;
    // int col = 4;
    // string move = to_string(row) + to_string(col);
    // cout << move << "   HELLO";



}




    // char board[8][8];
    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         board[i][j] = '-';
    //     }

    // }  
    // board[3][3] = 'X';
    // board[3][4] = 'O';
    // board[4][4] = 'X';
    // board[4][3] = 'O';


    // cout << MAGENTA << "    A   B   C   D   E   F   G   H   " << endl << WHITE << "   ___ ___ ___ ___ ___ ___ ___ ___ " << endl;
    // for(int i = 0, j = 1; i < 8; i++, j++){

    //     cout << MAGENTA << j;
    //     cout << WHITE << " | ";
    //     for(int k = 0; k < 8; k++){
    //         cout << WHITE << board[i][k];
    //         cout << " | ";

    //     }
    //     cout << endl;
    //     cout << WHITE << "  |---|---|---|---|---|---|---|---| " << endl;
    // }

    // cout << RESET;