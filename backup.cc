// /**
//  * @file othello.cc
//  * @author Alec Martell
//  * @brief Implementation of othello class 
//  * @version 0.1
//  * @date 2022-11-17
//  * 
//  * 
//  */
// #include "othello.h"
// /**
//  * @brief Construct a new Othello:: Othello object
//  * 
//  */
// Othello::Othello(){
//     //fills board with empties
//     for(int i = 0; i < 8; i++){
//         for(int j = 0; j < 8; j++){
//             board[i][j].set_state('-');
//             board[i][j].set_value(1);
//         }
//     }
//     for(int i = 0; i < 8; ++i){
//         board[0][i].set_value(2);
//         board[i][0].set_value(2);
//         board[7][i].set_value(2);
//         board[i][7].set_value(2);
//     }
//     board[0][0].set_value(3);
//     board[0][7].set_value(3);
//     board[7][0].set_value(3);
//     board[7][7].set_value(3);

//     //sets beggining values
//     p_score = 2;
//     c_score = 2;
//     num_moves = 0;
//     skip_times = 0;
//     //sets beggining board
//     board[3][3].set_state('X');
//     board[3][3].set_empty(0);

//     board[3][4].set_state('O');
//     board[3][4].set_empty(0);

//     board[4][4].set_state('X');
//     board[4][4].set_empty(0);

//     board[4][3].set_state('O');
//     board[4][3].set_empty(0);
// }


// /**
//  * @brief displays the current board
//  * 
//  */
// void Othello::display_status() const{
//     //sets the top letters in magenta and the top border in white
//     cout << MAGENTA << "    A   B   C   D   E   F   G   H   " << endl << WHITE << "   ___ ___ ___ ___ ___ ___ ___ ___ " << endl;
//     for(int i = 0, j = 1; i < 8; i++, j++){
//         //sets numbers of the right of board in Magenta
//         cout << MAGENTA << j;
//         //puts starting | of board in white
//         cout << WHITE << " | ";
//         //prints out the values of the space along with the surrounding | pieces
//         for(int k = 0; k < 8; k++){
//             //empty piece
//             if(board[i][k].get_state() == '-'){
//                 cout << WHITE << board[i][k].get_state();
//                 cout << " | ";
//             }
//             //computer piece
//             else if(board[i][k].get_state() == 'X'){
//                 cout << BLUE << board[i][k].get_state();
//                 cout << WHITE << " | ";
//             }
//             //player piece
//             else if(board[i][k].get_state() == 'O'){
//                 cout << GREEN << board[i][k].get_state();
//                 cout << WHITE << " | ";
//             }
//         }
//         cout << endl;
//         //puts barrier in between 
//         cout << WHITE << "  |---|---|---|---|---|---|---|---| " << endl;
//     }
//     cout << "Player Score: " << p_score << "         Computer Score: " << c_score << endl;

//     cout << RESET;
// }



// /**
//  * @brief flips space from person1 to person2
//  * 
//  */
// void Space::flip(){

//     //if O flip to X
//     if(get_state() == 'O'){
//         set_state('X');    
//     }
//     //if X flip to O
//     else if(get_state() == 'X'){
//         set_state('O');    
//     }
// }


// /**
//  * @brief Resets the board to its base value
//  * 
//  */
// void Othello::restart(){
//     //sets all spaces to empty
//     for(int i = 0; i < 8; i++){
//         for(int j = 0; j < 8; j++){
//             board[i][j].set_state('-');
//         }
//     }
//     //sets base player scores
//     p_score = 2;
//     c_score = 2;
//     num_moves = 0;
//     skip_times = 0;
//     //sets middle values to starting values
//     board[3][3].set_state('X');
//     board[3][3].set_empty(0);

//     board[3][4].set_state('O');
//     board[3][4].set_empty(0);

//     board[4][4].set_state('X');
//     board[4][4].set_empty(0);

//     board[4][3].set_state('O');
//     board[4][3].set_empty(0);
// }

// /**
//  * @brief displays the message
//  * 
//  * @param message - message to be displayed
//  */
// void Othello::display_message(const string& message) const{
//     char current;
//     //if the message is your move - displays turn and skip message before the message
//     if(message == "Your move, please: "){
//         //sets pieces
//         if(last_mover() == HUMAN){
//             current = 'O';
//         }
//         if(last_mover() == COMPUTER){
//             current = 'X';
//         }
//         //pre-message
//         cout << "                " << current << "\'s move" << endl <<"      " << "If no move possible put skip" << endl;

//     }
//     cout << message;
        
// }



// //part B start


// /**
//  * @brief checks to make sure the current move is legal
//  * 
//  * @param move - user inputed move
//  * @return true - if legal
//  * @return false - if not legal
//  */
// bool Othello::is_legal(const string& move) const{
//     string num_move = ""; 
//     //makes a queue of strings
//     queue<string> q;
    
//     //fills queue of strings with legal moves using compute_moves function
//     compute_moves(q);

//     //creates a copy of the queue to be used later
//     queue<string> q_copy = q;

//     //checks to see if queue is empty to see if skip is legal
//     if(move == "skip"){
//         if(q.empty() == 1){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }

//     //correctly sets row and column
//     int col = int (toupper(move[0]) - 'A');
//     int row = int (move[1] - '1');

//     //if row and column were entered within the bounds of the board
//     if(col >= 0 && col <= 7 && row >= 0 && row <=7){
//         //while the copied queue is not empty
//         while(!q_copy.empty()){
//             //variable equal to the front data of the queue
//             string front = q_copy.front();

//             //makes a string of the move to compare to the copied queue
//             num_move = to_string(row) + to_string(col);

//             //if they are the same return the move as legal
//             if(front==num_move){
//                 return 1;
//             }
//             //if false remove the front and continue checking next piece
//             else{
//                 q_copy.pop();
//             }
//         }
//         //if nothing legal is found
//         return 0;
        
//     }
//     //if move is outside bounds of board
//     else{
//         return 0;
//     }

// }





// /**
//  * @brief Makes move based on the user input
//  * 
//  * @param move - user inputed move
//  */
// void Othello::make_move(const string& move){
//     cout << endl << endl << "move: " << move << endl << endl;
//     char current;
//     bool legal = is_legal(move);

//     //if it is a legal move
//     if(legal == 1){
//         //sets current mover
//         if(last_mover() == HUMAN){
//             current = 'O';
//         }
//         if(last_mover() == COMPUTER){
//             current = 'X';
//         }

//         //if the move is not skip
//         if(move != "skip"){
//             //reset skip counter to zero
//             skip_times = 0;

//             //correctly sets column and row
//             int col = int (toupper(move[0]) - 'A');
//             int row = int (move[1] - '1');

//             //variables to determine whether a move is valid
//             bool u = 0, d = 0, l = 0, r = 0, ul = 0, ur = 0, ll = 0, lr = 0; 

//             //checking which direction had the valid move
//             u = up(row, col);
//             d = down(row, col);
//             l = left(row, col);
//             r = right(row, col);
//             ul = D_U_L(row, col);
//             ur = D_U_R(row, col);
//             ll = D_L_L(row, col);
//             lr = D_L_R(row, col);
//             int row_hold = row;
//             int col_hold = col;

//             //depending on which values come back true it executes corresponding code 
//             //checks for legal move up
//             if(u == 1){
//                 //checks up
//                 for(int i = --row_hold; i >= 0; i--){
//                     //for enemy pieces that need to be flipped
//                     if(board[i][col].get_state() != current && board[i][col].get_state() != '-'){
//                         board[i][col].flip();
//                     }
//                     //stops when it hits your own piece
//                     else if(board[i][col].get_state() == current){
//                         break;
//                     }
                    
//                 }
//                 //resets row_hold
//                 row_hold = row;
//             }
//             //checks for legal move down
//             if(d == 1){
//                 //checks down
//                 for(int i = ++row_hold; i <= 7; i++){
//                     //for enemy pieces that need to be flipped
//                     if(board[i][col].get_state() != current && board[i][col].get_state() != '-'){
//                         board[i][col].flip();
//                     }
//                     //stops when own piece hit
//                     else if(board[i][col].get_state() == current){
//                     break;
//                     }

//                 }
//                 //resets hold
//                 row_hold = row;

//             }
//             //checks for legal move left
//             if(l == 1){
//                 //checks left
//                 for(int i = --col_hold; i >= 0; i--){
//                     //for enemy pieces that need to be flipped
//                     if(board[row][i].get_state() != current && board[row][i].get_state() != '-'){
//                         board[row][i].flip();
//                     }
//                     //stops when own is hit
//                     else if(board[i][col].get_state() == current){
//                         break;
//                     }
//                 }
//                 //resets hold
//                 col_hold = col;
//             }
//             //checks for legal move right
//             if(r == 1){
//                 //checks right
//                 for(int i = ++col_hold; i >= 0; i++){
//                     //for enemy pieces that need to be flipped
//                     if(board[row][i].get_state() != current && board[row][i].get_state() != '-'){
//                         board[row][i].flip();
//                     }
//                     //stops when own is hit
//                     else if(board[row][i].get_state() == current){
//                         break;
//                     }
//                 }
//                 //resets hold
//                 col_hold = col;
//             }
//             //Checks for legal move diagonal upper right
//             if(ur == 1){
//                 //checks diaganol upper right
//                 for(int c = ++col_hold, r = --row_hold; c <= 7 || r >= 0; c++, r--){
//                     //for enemy pieces that need to be flipped
//                     if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                         board[r][c].flip();
//                     }
//                     //stops when own is hit
//                     else if(board[r][c].get_state() == current){
//                         break;
//                     }

//                 }
//                 //resets holds
//                 col_hold = col;
//                 row_hold = row;
//             }
//             //checks for legal move diagonal upper left
//             if(ul == 1){
//                 //checks diagonal upper left
//                 for(int c = --col_hold, r = --row_hold; c >= 0 || r >= 0; c--, r--){
//                     //for enemy pieces that need to be flipped
//                     if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                         board[r][c].flip();
//                     }
//                     //when own piece is hit
//                     else if(board[r][c].get_state() == current){
//                         break;
//                     }


//                 }
//                 //resets holds
//                 col_hold = col;
//                 row_hold = row;

//             }
//             //checks for legal move diagonal lower right
//             if(lr == 1){
//                 //checks diagonal lower right
//                 for(int c = ++col_hold, r = ++row_hold; c <= 7 || r <= 7; c++, r++){
//                     //for enemy pieces that need to be flipped
//                     if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                         board[r][c].flip();                
//                     }
//                     //when own piece is hit
//                     else if(board[r][c].get_state() == current){
//                         break;
//                     }
//                 }
//                 //resets holds
//                 col_hold = col;
//                 row_hold = row;
                

//             }
//             //checks for legal move diagonal lower left
//             if(ll == 1){
//                 //checks diagonal lower left
//                 for(int c = --col_hold, r = ++row_hold; c >= 0 || r <= 7; c--, r++){
//                     //for enemy pieces that need to be flipped
//                     if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                         board[r][c].flip();                
//                     }
//                     //stops when own piece is hit
//                     else if(board[r][c].get_state() == current){
//                         break;
//                     }
//                 }
//                 //resets holds
//                 col_hold = col;
//                 row_hold = row;

//             }
        






//             //sets legal move to the current piece and sets it to a not empty space
//             board[row][col].set_state(current);
//             board[row][col].set_empty(0);
//             //increments number of moves
//             num_moves++;
//             //gets score of game
//             get_score();
//             //checks if the game is over
//             if(is_game_over() == 1){
//                 exit(0);
//             }
            
//         }
//         //if skip
//         else{
//             //increments skip
//             int skp = skip_times;
//             num_moves++;
//             cout << "else skip time" << skip_times;
//             skip_times = (skp + 1);
//             //checks to see if the game is over
//             if(is_game_over() == 1){
//                 exit(0);
//             }
//         }
//     }


// }

// /**
//  * @brief Checks all available moves and moves legal moves into a queue
//  * 
//  * @param moves - queue of legal moves
//  */
// void Othello::compute_moves(queue<string>& moves)const{
//     //bool variables used to determine whether a move is valid
//     bool u = 0, d = 0, l = 0, r = 0, ul = 0, ur = 0, ll = 0, lr = 0; 
//     string good_move = "";
//     for(int row = 0; row < 8; row++){
//         for(int col = 0; col < 8; col++){
//             //if the spot where the move is supposed to be is not empty
//             if(board[row][col].get_empty() == 1){
//                 //checks to see if any direction has a valid move
//                 u = up(row, col);
//                 d = down(row, col);
//                 l = left(row, col);
//                 r = right(row, col);
//                 ul = D_U_L(row, col);
//                 ur = D_U_R(row, col);
//                 ll = D_L_L(row, col);
//                 lr = D_L_R(row, col);

//                 //if there was a valid move it pushes it into the queue
//                 if(u == 1 || d == 1 || l == 1 || r ==1 || ul == 1 || ur == 1 || ll == 1 || lr == 1){


//                     good_move =to_string(row) + to_string(col);
//                     moves.push(good_move);

//                 }
//             }
//         }
//     }
// }


// /**
//  * @brief Checks up for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::up(int row, int col)const {
//     //holding for rows
//     int row_hold = row;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     //character piece
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     else if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if it cant go up
//     if(row == 0){
//         return 0;
//     }
//     //if one space up is empty
//     else if (board[row-1][col].get_empty() == 1)
//     {
//         return 0;
//     }
//     else{
//         //go up
//         for(int i = --row_hold; i >= 0; i--){
//             //if its empty break 
//             if(board[i][col].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if it hits your piece break
//             else if(board[i][col].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if it hits enemy piece keep going
//             else if(board[i][col].get_state() != current && board[i][col].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if it hits enemy pieces, one of your pieces, and no empty spots its a valid move
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }



// /**
//  * @brief Checks down for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::down(int row, int col)const{
//     //holding for rows
//     int row_hold = row;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     else if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if it cant go down
//     if(row == 7){
//         return 0;
//     }
//     //checks if one spot down is empty
//     else if (board[row_hold +1][col].get_empty() == 1)
//     {
//         return 0;
//     }
//     else{
//         //checks down
//         for(int i = ++row_hold; i <= 7; i++){
//             //if spot is empty
//             if(board[i][col].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if space has current players piece
//             else if(board[i][col].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if space has enemies piece
//             else if(board[i][col].get_state() != current && board[i][col].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //test piece
//         //cout << endl << "enemy: " << enemy << endl << "empty: " << empty << endl << "you: " << you << endl << "Row: " << row << endl << "Col: " << col << endl;

//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }


// /**
//  * @brief checks left for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::left(int row, int col)const{
//     //holding for columns 
//     int col_hold = col;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     else if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if it cant go left
//     if(col == 0){

//         return 0;
//     }
//     //if first space left is empty
//     else if (board[row][--col_hold].get_empty() == 1)
//     {
//         return 0;
//     }
//     else{
//         //checks left
//         for(int i = --col; i >= 0; i--){
//             //if it is empty
//             if(board[row][i].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if it is players piece
//             else if(board[row][i].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if it is enemies piece
//             else if(board[row][i].get_state() != current && board[row][i].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }


// /**
//  * @brief checks right for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::right(int row, int col)const{
//     //holding for columns
//     int col_hold = col;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     else if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if it cant go right
//     if(col == 7){
//         return 0;
//     }
//     //if first space right is empty
//     else if (board[row][++col].get_empty() == 1)
//     {
//         return 0;
//     }
//     else{
//         //checks right
//         for(int i = ++col_hold; i >= 0; i++){
//             //if space is empty
//             if(board[row][i].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if space is players piece
//             else if(board[row][i].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if space is enemies piece
//             else if(board[row][i].get_state() != current && board[row][i].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }

// /**
//  * @brief checks Diagonal Upper Right for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::D_U_R(int row, int col)const{
//     //holding for columns and rows
//     int row_hold = row;
//     int col_hold = col;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if it cant move up right
//     if(row == 0 || col == 7){
//         return 0;
//     }
//     //if first space up right is empty
//     else if(board[--row][++col].get_empty() == 1){
//         return 0;
//     } 
//     else{
//         //checks up right
//         for(int c = ++col_hold, r = --row_hold; c <= 7 || r >= 0; c++, r--){
//             //if empty
//             if(board[r][c].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if piece is players piece
//             else if(board[r][c].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if piece is enemy piece
//             else if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }

// /**
//  * @brief checks Diagonal Upper Left for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::D_U_L(int row, int col)const{
//     //holding for columns and rows
//     int row_hold = row;
//     int col_hold = col;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if up left cant be done
//     if(row == 0 || col == 0){
//         return 0;
//     }

//     //if up left is empty
//     else if(board[--row][--col].get_empty() == 1){
//         return 0;
//     } 
//     else{
//         //goes up right
//         for(int c = --col_hold, r = --row_hold; c >= 0 || r >= 0; c--, r--){
//             //if space is empty
//             if(board[r][c].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if space is players piece
//             else if(board[r][c].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if space is enemy piece
//             else if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }

// /**
//  * @brief checks Diagonal Lower Left for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::D_L_L(int row, int col)const{
//     //holding for columns and rows
//     int row_hold = row;
//     int col_hold = col;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //if cant go down left
//     if(row == 7 || col == 0){
//         return 0;
//     }
//     //if first spot down left is empty
//     else if(board[++row][--col].get_empty() == 1){
//         return 0;
//     } 
//     else{
//         //goes down left
//         for(int c = --col_hold, r = ++row_hold; c >= 0 || r <= 7; c--, r++){
//             //if space is empty
//             if(board[r][c].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if space is current players piece
//             else if(board[r][c].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if space is enemy piece
//             else if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }


// /**
//  * @brief checks Diagonal Lower Right for legal move
//  * 
//  * @param row -starting row
//  * @param col -starting column
//  * @return true -true if move
//  * @return false -false if no move
//  */
// bool Othello::D_L_R(int row, int col)const{
//     //holding for columns and rows
//     int row_hold = row;
//     int col_hold = col;
//     //Holding pieces for different types of spaces
//     int enemy = 0;
//     int empty = 0;
//     int you = 0;
//     char current = ' ';

//     //if human if computer
//     if(last_mover() == HUMAN){
//         current = 'O';
//     }
//     if(last_mover() == COMPUTER){
//         current = 'X';
//     }

//     //If it cant go down right
//     if(row == 7 || col == 7){
//         return 0;
//     }
//     //if first space down right is empty
//     else if(board[++row][++col].get_empty() == 1){
//         return 0;
//     } 
//     else{
//         //goes down right
//         for(int c = ++col_hold, r = ++row_hold; c <= 7 || r <= 7; c++, r++){
//             //if space is empty
//             if(board[r][c].get_state() == '-'){
//                 empty++;
//                 break;
//             }
//             //if space is current players piece
//             else if(board[r][c].get_state() == current){
//                 you++;
//                 break;
//             }
//             //if space is enemeies piece
//             else if(board[r][c].get_state() != current && board[r][c].get_state() != '-'){
//                 enemy++;
//             }
            
//         }
//         //if there are at least one enemy pieces and one of your pieces and no empty spaces the move is legal
//         if(enemy >= 1 && empty == 0 && you == 1){
//             return 1;
//         }
//         else{return 0;}
//     }
// }


// /**
//  * @brief Checks different variables to see if the game is over
//  * 
//  * @return true - if game is over
//  * @return false - if game is not over
//  */
// bool Othello::is_game_over()const{
//     int empty_space = 0;
//     int skp = skip_times;

//     //if it has been skipped twice... or more for some reason
//     if(skp >= 2){

//         //if the player won
//         if(p_score > c_score){
//             cout << "You Win!" << endl;
//         }
//         //if computer won
//         else if(c_score > p_score){
//             cout << "You Lose" << endl;
//         }
//         //if they tied
//         else if(c_score == p_score){
//             cout << "You Tied" << endl;
//         }
//         return 1;
//     }
//     //goes through board and checks amount of empty pieces
//     for(int r = 0; r <= 7; r++){
//         for(int c = 0; c <= 7; c++){
//             if(board[r][c].get_state() == '-'){
//                 empty_space++;
//             }
//         }
//     }
//     //if there are 0 empty spaces the game is over and the previous steps repeat of determining victor
//     if(empty_space == 0){
//         cout << empty_space << " :empty space";
//         if(p_score > c_score){
//             cout << "You Win!" << endl;
//         }
//         if(c_score > p_score){
//             cout << "You Lose" << endl;
//         }
//         if(c_score == p_score){
//             cout << "You Tied" << endl;
//         }
//         return 1;
//     }
//     else{
//         return 0;
//     }

// }

// /**
//  * @brief gets the score of both sets of pieces
//  * 
//  */
// void Othello::get_score(){
//     //sets scores to zero
//     p_score = 0;
//     c_score = 0;

//     //goes through the board and adds points based on amount of pieces they have
//     for(int r = 0; r <= 7; r++){
//         for(int c = 0; c <= 7; c++){
//             //if player piece add one to p_score
//             if(board[r][c].get_state() == 'O'){
//                 p_score++;
//             }
//             //if computer piece add one to c_score
//             if(board[r][c].get_state() == 'X'){
//                 c_score++;
//             }

//         }
//     }
// }


// //Part C
// int Othello::evaluate()const{
//     int comp_score = 0;
//     for(int i = 0; i < 8; ++i){
//         for(int j = 0; j < 8; ++j){
//             if(board[i][j].get_state() == 'X'){
//                 ++comp_score;
//             }
//         }
//     }
//     return comp_score;
// }