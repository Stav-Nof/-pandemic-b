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
#include "Medic.hpp"
using namespace std;


namespace pandemic{
    
    string Medic::role(){
        return "Medic";
    }

    Medic& Medic::treat(City city){
        if (this->city != city){
            throw("Player not in given city");
        }
        if (this->board.desease_cubes[city] == 0){
            throw("Error - no desease in city");
        }
        this->board.desease_cubes[city] = 0;
        return *this;
    }

    Medic& Medic::drive(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (pandemic::Board::neighbors[this->city].count(city) == 1){ // player's city is connected to the given city
            if(this->board.cured_colors.count(pandemic::Board::city_color[city]) == 1){
                this->board.desease_cubes[city] = 0;
            }
            this->city = city;
            return *this;
        }
        throw ("Player's city is not connected to given city");
    }

    Medic& Medic::fly_direct(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (this->cards.count(city) == 0){
             throw ("Player doesn't have city's card");
        }
        if(this->board.cured_colors.count(pandemic::Board::city_color[city]) == 1){
                this->board.desease_cubes[city] = 0;
        }
        this->cards.erase(city);
        this->city = city;
        return *this;
    }

    Medic& Medic::fly_charter(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (this->cards.count(this->city) == 0){
            throw ("Player doesn't have city's card");
        }
        if(this->board.cured_colors.count(pandemic::Board::city_color[city]) == 1){
                this->board.desease_cubes[city] = 0;
        }
        this->cards.erase(this->city);
        this->city = city;
        return *this;
    }

    Medic& Medic::fly_shuttle(City city){
        if (this->city == city){
            throw ("Player cannot fly from city to itself");
        }  
        if ((this->board.research_stations.count(this->city) == 0) || (this->board.research_stations.count(city) == 0)){
            throw ("City has no research station");
        }
        if(this->board.cured_colors.count(pandemic::Board::city_color[city]) == 1){
                this->board.desease_cubes[city] = 0;
        }
        this->city = city;
        return *this;
    } 
}