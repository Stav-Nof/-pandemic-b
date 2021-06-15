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
#include "Scientist.hpp"
using namespace std;


namespace pandemic{
    string Scientist::role(){
        return "Scientist";
    }

    Scientist& Scientist::discover_cure(Color color){
        int count = 0;
        set<City> cities_in_color;
        for (City c : this->cards){
            if (pandemic::Board::city_color[this->city] == color){
                cities_in_color.insert(c);
                count++;
            }
            if(count == this->n){
                break;
            }
        }
        if (count < this->n){
            throw("Player doesn't have n cards in given color");
        }
        if (this->board.research_stations.count(this->city) == 0){ // Player is not in a city with research station
            throw("Player is not in a city with research station");
        }
        if (this->board.cured_colors.count(color) == 1){ // Given color is already cured
            return *this;
        }
        // city has a research station & player have n cards in given color & deasese color hasn't cured yet
        for (City c : cities_in_color){ //throw n cards in the desease color
            this->cards.erase(c);
        }
        this->board.cured_colors.insert(color);
        return *this;
    }
    
}