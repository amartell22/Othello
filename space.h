/**
 * @file othello.h
 * @author Alec Martell
 * @brief Class to hold and change state of board pieces
 * @version 0.1
 * @date 2022-11-17
 * 
 * 
 */
#include <queue>
#include <iostream>

class Space{
    public:
        //constructor
        Space(){state = '-'; empty = 1; value = 1;}

        //accesor
        char get_state()const {return state;}
        bool get_empty()const {return empty;}
        int get_value()const {return value;}
        //mutator
        void set_state(char new_s) {state = new_s;}
        void set_empty(int i) {empty = i;}
        void set_value(int i) {value = i;}
        
        void flip();

    private:
        bool empty;
        int value;
        char state;
};

