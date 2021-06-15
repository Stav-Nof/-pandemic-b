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
   
    class Virologist : public Player{
        public:
            Virologist(Board &_board, City _city) : Player(_board, _city){}
            ~Virologist(){}; // destructor
            string role();
            Virologist& treat(City city);
    };
}