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
   
    class Dispatcher : public Player{
        public:    
            Dispatcher(Board &_board, City _city) : Player(_board, _city){}
            ~Dispatcher(){}; // destructor
            string role();
            Dispatcher& fly_direct(City city);
    };
}