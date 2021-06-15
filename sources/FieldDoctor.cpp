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
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace std;


namespace pandemic{
    string FieldDoctor::role(){
        return "FieldDoctor";
    }
    FieldDoctor& FieldDoctor::treat(City city){
        if (this->city != city && pandemic::Board::neighbors[this->city].count(city) == 0){
            throw("Player not in given city");
        }
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
}