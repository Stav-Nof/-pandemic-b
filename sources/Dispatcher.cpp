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
#include "Dispatcher.hpp"
using namespace std;


namespace pandemic{
    string Dispatcher::role(){
        return "Dispatcher";
    }
    Dispatcher& Dispatcher::fly_direct(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (this->board.research_stations.count(this->city) == 0){ // if there isn't research station in player->city
            if (this->cards.count(city) == 0){ // if does not have city's card
                throw("Dispatcher is not in research station and does not have city card");
            }
            this->cards.erase(city);
            this->city = city;
            return *this;
        }
        // Dispatcher is in city with a research station
        this->city = city;
        return *this;
    }
}