/**
 * @file othello.h
 * @author Alec Martell
 * @brief Header file for Othello game
 * @version 0.1
 * @date 2022-11-17
 * 
 * 
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include "game.h"
#include "colors.h"
#include "space.h"

using namespace main_savitch_14;
using namespace std;


class Othello:public game{
    public:
        //constructor
        Othello();

        //accessors
        int get_skip_time()const{return skip_times;}

        //mutators
        void set_skip_time(int new_skip) {skip_times = new_skip;}
        //virtual functions being overided 
        void display_status() const;

        bool is_legal(const string& move) const;

        void restart();

        void display_message(const string& message) const;
        
        void make_move(const string& move);

        //virtual stubs
        game* clone()const{return new Othello(*this);}

        void compute_moves(queue<string>& moves)const;

        int evaluate()const;

        bool is_game_over()const;

        //check direction funtions
        bool up(int row, int col)const;
        bool down(int row, int col)const;
        bool left(int row, int col)const;
        bool right(int row, int col)const;
        bool D_U_R(int row, int col)const;
        bool D_U_L(int row, int col)const;
        bool D_L_L(int row, int col)const;
        bool D_L_R(int row, int col)const;

        virtual who last_mover( ) const 
			{return (num_moves % 2 == 1 ? HUMAN : COMPUTER); }

        void get_score();



    protected:
        Space board[8][8];
        int p_score;
        int c_score;
        int num_moves;
        int skip_times;




};

