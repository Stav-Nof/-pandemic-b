/**
 * Author: Mayan Bashan
 */

#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic{
   
    class Scientist : public Player{                
        public:
            int n;

            Scientist();
            Scientist(Board &_board, City _city, int _n) : Player(_board, _city){
                this->n = _n;
            }
           
            ~Scientist(){}; // destructor
            string role();
            Scientist& discover_cure(Color color);
    };
}