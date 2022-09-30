/*!
    @file Departure.cpp
    @author Ghilas KASMI
	@author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Departure.h"
#include "Event.h"

Departure::Departure(Client *const client, Cashier *const cashier, double time, Bank *const bank) : Event(time), bank(bank), cashier(cashier), client(client) {}

void Departure::process() {
	Client next;
	Queue *queue = bank->getQueue();

	//Cas ou la file contient des clients
	if (!queue->isEmpty()){

		//On retire le premier client arrivé, on met à jour les stats de la simulation, et on le sert
		next = queue->pop();
		double waitTime = bank->getCurrentTime()-next.getArrivalTime();
		bank->provideWaitTimeEntry(waitTime);
		cashier->serve(&next);
	}
	else
		cashier->free();
	delete client;
}
