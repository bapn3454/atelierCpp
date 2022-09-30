/**
 * @file Arrival.h
 * @author Ghilas KASMI
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 *
 */
#ifndef ARRIVAL_H
#define ARRIVAL_H

#include "Event.h"

class Bank;


/**
 * 
 * @class Arrival
 * @brief Type d'événement représentant l'arrivée d'un client. Cette class est une dérivée d'Event.
 * 
 */
class Arrival : public Event{
    private:
		Bank *const bank; /// Pointeur vers la Bank

	public:
		//Suppression du Copy Constructor
        Arrival(const Arrival&) = delete;

		/*! @fn Arrival(double time, Bank *const bank)
			@brief Produit une instance d' Arrival
			@param time : Le temps de déclanchement de l'événement
			@param bank : Pointeur vers Bank
		*/
		Arrival(double time, Bank *const bank);

		/*! @fn void process()
			@brief Redéfinition de la méthode virtual de la classe mère Event

			Elle crée un nouveau client, l'assigne à un caissier libre, ou à défaut l'envoie dans la file d'attente
			Elle prédit une nouvelle arrivée en utilisant la loi de Poisson 

		*/
		void process();
};

#endif