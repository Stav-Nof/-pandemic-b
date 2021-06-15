/**
 * Author: Mayan Bashan
 */

#pragma once

#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iterator>
#include <set>
using namespace std;

namespace pandemic{
    
    class Player{
        public:
            pandemic::Board &board;
            pandemic::City city;
            set<pandemic::City> cards;

            Player(Board &_board, City _city) : board(_board){
                this->city = _city;
            }
            ~Player(){}; // destructor
            virtual Player& drive(City city);
            virtual Player& fly_direct(City city); //for Dispatcher
            virtual Player& fly_charter(City city);
            virtual Player& fly_shuttle(City city);
            virtual Player& build(); //for OperationsExpert
            virtual Player& discover_cure(Color color); //for Scientist | for Researcher | for GeneSplicer
            virtual Player& treat(City city); //for Medic | for Virologist | for FieldDoctor
            virtual string role();
            Player& take_card(City city);
            Player& remove_cards();
    };
    
}