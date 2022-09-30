/**
 * 
 * @file SED.h
 * @author Ghilas KASMI
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 * 
 */ 

#ifndef SED_H
#define SED_H

#include <vector>
#include <queue>

#include "Event.h"

using namespace std;


/**
 * 
 * @class SED
 * @brief Simulation qui gérer les evenements
 * 
 * Utilise une pirority_queue pour qauvegarder des evenements, les ordonner selon leur heure de déclanchement dans l'ordre ascendant. 
 * 
 */
class SED{
	protected:
		double currentTime; ///< Heure actuelle de la simultion
		double totalWaitTime; ///< Temps total d'attente de tous les evenements non traités
		priority_queue<Event*, vector<Event*>, EventComparator> schedule; ///< structure de données utilisée pour sauvegarder et ordonner les evenements

	public:
		/**
		 * 
		 * @fn SED()
		 * @brief COnstructeur de SED
		 * 
		 */
		SED();

		/**
		 * 
		 * @fn void start()
		 * @brief lance la simulation.
		 * 
		 */
		void start();

		/**
		 * 
		 * @fn void add(Event* e)
		 * @brief Ajoute un evenement.
		 * @param e Pointeur vers l'evenement à ajouter 
		 * 
		 */
		void add(Event *e);

		/**
		 * 
		 * @fn double getCurrentTime() const
		 * @brief Getter pour l'heure actuelle.
		 * @return Renvoie l'heure actuelle dans la simulation
		 * 
		 */
		double getCurrentTime() const;

		/**
		 * 
		 * @fn void provideWaitTimeEntry(doublr time)
		 * @brief Recalcule le temps total d'attente en y ajoutant le temps passé en paramètre.
		 * @param time Le temps à ajouter 
		 * 
		 */
		void provideWaitTimeEntry(double time);
};

#endif