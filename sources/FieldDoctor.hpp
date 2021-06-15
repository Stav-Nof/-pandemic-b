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
   
    class FieldDoctor : public Player{
        public:
            FieldDoctor(Board &_board, City _city) : Player(_board, _city){}
            ~FieldDoctor(){}; // destructor
            string role();
            FieldDoctor& treat(City city);
    };
}