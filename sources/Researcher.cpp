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
#include "Researcher.hpp"

using namespace std;


namespace pandemic{
    const int FIVE = 5;
    string Researcher::role(){
        return "Researcher";
    }
    Researcher& Researcher::discover_cure(Color color){
        int count = 0;
        set<City> cities_in_color;
        for (City c : this->cards){
            if (pandemic::Board::city_color[this->city] == color){
                cities_in_color.insert(c);
                count++;
            }
            if(count == FIVE){
                break;
            }
        }
        if (count < FIVE){
            throw("Player doesn't have 5 cards in given color");
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