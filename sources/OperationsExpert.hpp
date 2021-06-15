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
    
    class OperationsExpert : public Player{
        public:
            OperationsExpert(Board &_board, City _city) : Player(_board, _city){}
            ~OperationsExpert(){}; // destructor
            string role();
            OperationsExpert& build();
    };
}