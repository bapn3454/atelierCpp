/*!
    @file Queue.cpp
    @author Ghilas KASMI
    @author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Queue.h"
#include "Bank.h"

Queue::Queue(Bank *bank){
    this->bank = bank;
    maxLength = 0;
    averageLength = 0.0;
}

int Queue::getMaxLength(){
    return maxLength; 
}

double Queue::getAverageLength(){
    return maxLength / bank->getExpectedDuration(); 
}

bool Queue::isEmpty(){
    return clients.empty();
}

void Queue::add(Client client){
    clients.push_back(client); 

    //Si nécessaire, on augmente la taille
    if(maxLength< (int) clients.size())
        maxLength++;
}

Client Queue::pop(){
    Client client = clients.front(); 

    //On calcule la taille moyenne
    averageLength += (bank->getCurrentTime() - client.getArrivalTime()) * clients.size(); 
    clients.pop_front(); 
    
    return client; 
}

