/*!
    @file Cashier.cpp
    @author Ghilas KASMI
    @author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Cashier.h"
#include "Poisson.h"

Cashier::Cashier(){
    //Sert à reconnaitre les caissiers vides des initialisés
    exists = false; 
}

Cashier::Cashier(double averageServiceTime, Bank *bank){
    this->bank = bank; 
    this->averageServiceTime = averageServiceTime; 
    exists = true;
    clientCount = 0;
    available = true;
    isBusy = 0.0;
}

double Cashier::getOccupationRate(){
    occupationRate = isBusy/bank->getCurrentTime(); 
    return occupationRate; 
}
int Cashier::getClientCount(){
    return clientCount; 
}
double Cashier::getAverageServiceTime(){
    double average = 0; 
    
    for(int i=0; i<bank->getCashierCount(); i++){
        average += averageServiceTime; 
    }
    return average/bank->getCashierCount(); 
}
bool Cashier::isAvailable(){
    return available; 
}
void Cashier::serve(Client* client){
    double rand = Poisson::next(averageServiceTime);
    double departureTime = bank->getCurrentTime()+rand;

    //On prévoit le propchain départ 
    bank->add(new Departure(client, this, departureTime, bank));

    //On met à jour les stats de la banque, et on bloque le caissier
    isBusy += rand;
    clientCount++;
    available = false;
}
void Cashier::free(){
    available = true; 
}

bool Cashier::getExists(){
    return exists; 
}