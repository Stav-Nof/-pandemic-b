/**
 * Author: Mayan Bashan
 */

#pragma once
#include <string>
#include <map>
#include "Color.hpp"
#include "City.hpp"

#include <set>
using namespace std;

namespace pandemic{
    
    class Board{
        
        public:
            static map<City, set<City>> neighbors; // cities connections
            static map<City, Color> city_color;
            set<City> research_stations;
            set<Color> cured_colors;
            map<City, int> desease_cubes;
            Board(){};
            ~Board(){}; // destructor
            
            int& operator[](City city);
            bool is_clean();
            void remove_cures();
            friend ostream& operator <<(ostream& output, const Board& board);
    };
}