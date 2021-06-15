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
   
    class GeneSplicer : public Player{
        public:
            GeneSplicer(Board &_board, City _city) : Player(_board, _city){}
            ~GeneSplicer(){}; // destructor
            string role();
            GeneSplicer& discover_cure(Color color);
    };
}