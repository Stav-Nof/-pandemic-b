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
#include "OperationsExpert.hpp"
using namespace std;


namespace pandemic{
    string OperationsExpert::role(){
        return "OperationsExpert";
    }
    
    //can make this operation in any city without throwing the matching card
    OperationsExpert& OperationsExpert::build(){
        this->board.research_stations.insert(this->city);
        return *this;
    }
    


}