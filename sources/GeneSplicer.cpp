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
#include "GeneSplicer.hpp"

using namespace std;


namespace pandemic{
    const int FIVE = 5;
    string GeneSplicer::role(){
        return "GeneSplicer";
    }
    GeneSplicer& GeneSplicer::discover_cure(Color color){ // can throw 5 cards (they dont have to be in the given color)
        int count = 0;
        set<City> cities_in_color;
        for (City c : this->cards){
            cities_in_color.insert(c);
            count++;
            if(count == FIVE){
                break;
            }
        }
        if (count < FIVE){
            throw("Player doesn't have 5 cards to throw");
        }
        if (this->board.research_stations.count(this->city) == 0){ // Player is not in a city with research station
            throw("Player is not in a city with research station");
        }
        if (this->board.cured_colors.count(color) == 1){ // Given color is already cured
            return *this;
        }
        // city has a research station & player have 5 cards in given color & deasese color hasn't cured yet
        for (City c : cities_in_color){ //throw 5 cards in the desease color
            this->cards.erase(c);
        }
        this->board.cured_colors.insert(color);
        return *this;
        
    }
    
}