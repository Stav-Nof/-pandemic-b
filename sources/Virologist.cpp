/**
 * Author: Mayan Bashan
 */

#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <string>
#include <map>
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
using namespace std;


namespace pandemic{
    string Virologist::role(){
        return "Virologist";
    }
    Virologist& Virologist::treat(City city){
        if (this->city == city){ // player is in given city
            if (this->board.desease_cubes[city] == 0){
                throw("Error - no desease in city");
            }
            if (this->board.cured_colors.count(pandemic::Board::city_color[city]) == 1){ // cure already discovered
                this->board.desease_cubes[city] = 0;
            }
            else{
                this->board.desease_cubes[city] -= 1;
            }
            return *this;
        }
        if (this->cards.count(city) == 1){ //player is not in given city, buy can treat because he is Virologist and has city's card
            if (this->board.desease_cubes[city] == 0){
                throw("Error - no desease in city");
            }
            if (this->board.cured_colors.count(pandemic::Board::city_color[city]) == 1){ // cure already discovered
                this->board.desease_cubes[city] = 0;
            }
            else{
                this->cards.erase(city);
                this->board.desease_cubes[city] -= 1;
            }
        return *this;
        }
        throw("Cannot treat because has not city card");
        
    }
}