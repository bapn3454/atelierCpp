/*!
    @file Client.cpp
    @author Ghilas KASMI
    @author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Client.h"

Client::Client(double arrivalTime){
    this->arrivalTime = arrivalTime; 
}
double Client::getArrivalTime(){
    return arrivalTime; 
}

Client::Client(){
    
}