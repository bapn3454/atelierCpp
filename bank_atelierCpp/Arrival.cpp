/*!
    @file Arrival.cpp
    @author Ghilas KASMI
	@author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Arrival.h"
#include "Event.h"
#include "Poisson.h"
#include "Client.h"
#include "Cashier.h"


Arrival::Arrival(double hour, Bank *const bank) 
    :Event(hour), bank(bank) {}

void Arrival::process() {
	Client *client = new Client(bank->getCurrentTime());
	Cashier* cashier = bank->freeCashier();

	//Si un caissier est libre, alors il sert le client, sinon le client est placé dans la file d'attente
	if (cashier->getExists())
		cashier->serve(client);
	else
		bank->getQueue()->add(*client);

	//On prédit l'arrivée du prochain client avec la loi de poisson
	double departureTime = bank->getCurrentTime() + Poisson::next(bank->getInterval());
	if(departureTime <= bank->getExpectedDuration()){
		bank->add(new Arrival(departureTime, bank));
	}
}
