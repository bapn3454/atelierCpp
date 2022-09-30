/**
 * 
 * @file Departure.h
 * @author Ghilas KASMI
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 * 
 */
#ifndef DEPART_H
#define DEPART_H

#include "Event.h"
#include "Bank.h"

class Cashier;
class Client;
class Bank;

/**
 * 
 * \class Departure
 * @brief Type d'événement qui réprésente le départ d'un client. Cette classe est une dérivée d'Event.
 *
 */
class Departure : public Event
{
	private:
		Bank *const bank; ///< Pointeur vers la Bank
		Cashier *const cashier; ///< Pointeur vers le caissier lié à l'événement
		Client *const client; ///< Pointeur vers le client lié à l'événement

	public:
        Departure(const Departure&) = delete;

		/*! @fn Departure(Client *const client, Cashier *const cashier, double time, Bank *const bank)
			@brief Construceur de Departure
			@param client : Le client qui a été servi
			@param cashier : Le caissier qui a servi le client
			@param time : Temps du depart
			@param bank : Pointeur vers la bank
		*/
		Departure(Client *const client, Cashier *const cashier, double time, Bank *const bank);

		/*! @fn void process()
			@brief Redéfinition de la méthode Virual d'Event
			
			Vérifie si la file est vide, le caissier est libéré, sinon il reçoit un autre client
		 */
		void process();
};

#endif