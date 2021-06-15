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
   
    class Researcher : public Player{
        public:
            Researcher(Board &_board, City _city) : Player(_board, _city){}
            ~Researcher(){}; // destructor
            string role();
            Researcher& discover_cure(Color color);
    };
}