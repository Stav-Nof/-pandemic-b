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
   
    class Medic : public Player{
        public:
            Medic(Board &_board, City _city) : Player(_board, _city){}
            ~Medic(){}; // destructor
            string role();
            Medic& treat(City city);
            Medic& drive(City city);
            Medic& fly_direct(City city);
            Medic& fly_charter(City city);
            Medic& fly_shuttle(City city);
    };
}