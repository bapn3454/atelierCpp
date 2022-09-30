/*!
    @file Bank.cpp
    @author Ghilas KASMI
    @author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Bank.h"

Bank::Bank(int cashierCount, double averageServiceTime, double expectedDuration, double interval) : SED(), expectedDuration(expectedDuration), averageServiceTime(averageServiceTime), interval(interval), cashierCount(cashierCount) {
    this->cashierCount = cashierCount; 
    this->averageServiceTime = averageServiceTime; 
    Arrival* first = new Arrival(0.0,this);
    this->add(first);
    cashiers = new Cashier[cashierCount];

    //Initialise les caissiers
    for(int i=0; i<cashierCount; i++)
        cashiers[i] =  Cashier(averageServiceTime, this); 
        
    queue = new Queue(this); 
}

double Bank::getInterval(){
    return interval;
}

double Bank::getExpectedDuration(){
    return expectedDuration;
}

int Bank::getCashierCount(){
    return cashierCount; 
}

Cashier* Bank::freeCashier(){
    for(int i=0; i<cashierCount; i++){
        if(cashiers[i].isAvailable()) return &cashiers[i]; 
    }
    return new Cashier(); 
}

Queue *Bank::getQueue(){
    return queue; 
}

Cashier *Bank::getCashiers(){
    return cashiers; 
}

void Bank::printResults(){
    cout << "Duree reelle: " << currentTime << endl;
    cout << "Longueur max de la file: " << queue->getMaxLength() << endl;
    cout << "Longueur moyenne de la file: " << queue->getAverageLength() << endl;

    Cashier* crew = cashiers;
    int sum = 0;
    for (int i = 0; i < cashierCount; i++){
        if(crew[i].getExists()){
             sum += crew[i].getClientCount();
            cout << "Taux d'occupation du Caissier n" << i << " : " << crew[i].getOccupationRate() << endl;
        }
    }
    cout << "Nombre de clients: " << sum << endl;
    double avgWait = totalWaitTime / sum;
    cout << "Temps d'attente moyen: " << avgWait << endl;    
}