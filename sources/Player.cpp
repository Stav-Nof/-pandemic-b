/**
 * Author: Mayan Bashan
 */

#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <string>
#include <map>
using namespace std;

#include <iterator>
#include <set>
#include <exception>

namespace pandemic{
    const int FIVE = 5;
    Player& Player::drive(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (pandemic::Board::neighbors[this->city].count(city) == 1){ // player's city is connected to the given city
            this->city = city;
            return *this;
        }
        throw ("Player's city is not connected to given city");
    }

    Player& Player::fly_direct(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (this->cards.count(city) != 1){
             throw ("Player doesn't have city's card");
        }
        this->cards.erase(city);
        this->city = city;
        return *this;
    }

    Player& Player::fly_charter(City city){
        if (this->city == city){
            throw ("Player is already in this city");
        }
        if (this->cards.count(this->city) == 0){
            //cout << this->cards.count(this->city) << endl;
            throw ("Player doesn't have city's card");
        }
        this->cards.erase(this->city);
        this->city = city;
        return *this;
    }

    Player& Player::fly_shuttle(City city){
        if (this->city == city){
            throw ("Player cannot fly from city to itself");
        }  
        if ((this->board.research_stations.count(this->city) == 0) || (this->board.research_stations.count(city) == 0)){
            throw ("City has no research station");
        }
        this->city = city;
        return *this;
    } 

    Player& Player::build(){
        if (this->board.research_stations.count(this->city) == 0 && this->cards.count(this->city) == 1){
            this->board.research_stations.insert(this->city); // build research station in city
            this->cards.erase(this->city);
        }
        else if (this->board.research_stations.count(this->city) == 0 && this->cards.count(this->city) == 0){
            throw ("Cannot build a research station");
        }    
        return *this;
    }

    Player& Player::discover_cure(Color color){
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

    Player& Player::treat(City city){
        if (this->city != city){
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

    string Player::role(){
        return "Player";
    }
    
    Player& Player::take_card(City city){
        this->cards.insert(city);
        return *this;
    }

    Player& Player::remove_cards(){
        this->cards.clear();
        return *this;
    }
    


}