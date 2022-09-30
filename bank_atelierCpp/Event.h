/**
 * @file Event.h
 * @author Ghilas KASMI
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 * 
 * @class Event
 * @brief Représzntation de l'événement, cette classe est abstraite et sert de modèle pour d'autre classes qui vont représenter les evenements 
 * 
*/

#ifndef EVENT_H
#define EVENT_H


class SED;


/**
 * 
 * @class Event
 * @brief Représentation d'un événement dans la simulation, classe abstraite 
 * 
 */
class Event{
	protected:
		double time;///< Heure de l'événement

	public:
		/**
		 * 
		 * @fn Event(double hour)
		 * @brief Constructeur, doit uniquement etre appelé depuis ses classes filles.
		 * @param hour Heure de l'événement
		 * 
		 */
		Event(double hour);

		virtual ~Event();

		/**
		 * 
		 * @fn double getTime()
		 * @brief Getter pour l'attribut time
		 * @return attribut time
		 * 
		 */
		double getTime();

		/**
		 * 
		 * @fn virtual void process()
		 * @brief fonction Virutal, représente les actions à effectuer quand l'heure de l'événement arrive.
		 * 
		 */
		virtual void process() = 0;
};

/**
 * 
 * @class EventComparator
 * @brief Classe utilisaire, sert à ordonner les evenements de manière chronologique.
 * 
 */
class EventComparator {
	public:
	  int operator() ( Event *e1, Event *e2) {
	    return e1->getTime() > e2->getTime();
	  }
};

#endif