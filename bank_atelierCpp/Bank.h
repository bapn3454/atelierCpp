/**
 * 
 * @file Bank.h
 *  @author Ghilas KASMI
 *  @author Mourtada HOUARI
 *  @author Rabah BELKHIR
 * @date 23/09/2022
 * 
 *
 */

#ifndef BANK_H
#define BANK_H

#include "Cashier.h"
#include "Queue.h"
#include "SED.h"

//class Departure;
class Queue;
class Cashier;

using namespace std; 

/**
 * 
 *  \class Bank
 * @brief Cette class simule une banque, avec le nombre de caissiers passés en paramètres.
 * 
 */
class Bank : public SED{
    private:
        int cashierCount; ///< Nombre de caissiers
        Cashier *cashiers; ///< Liste des caissiers
        Queue *queue; ///< File d'attente
        double averageServiceTime; ///< Temps de service moyen d'un client 
        
        double expectedDuration;///< Temps pendant laquelle la banque reçoit du monde
        double interval;///< Intervalle entre les arrivées

    public:
        /*! @fn Bank(int cashierCount, double averageServiceTime, Simulation *simulation)
            @brief Crée une instance de bank.
            @param cashierCount : Nombre de caissiers
            @param averageServiceTime : Temps de service moyen
            @param expectedDuration durée initiale de la simulation
            @param interval Intervalle entre les arrivées
            @param cashierCount Nombre de caissiers
         */
        Bank(int cashierCount, double averageServiceTime, double expectedDuration, double interval);


        /*! @fn int getCashierCount()
            @brief Getter pour le nombre de caissier
            @return Nombre de caissiers
         */
        int getCashierCount();


        /*! @fn Cashier * freeCashier()
            @brief Renvoie le premier caissier libre, si aucun n'est disponible renvoie un caissier vide 
            @return Caissier, sa valeur peut être initialisée ou vide
         */
        Cashier* freeCashier();


        /*! 
            @fn Queue * getQueue()
            @brief Getter de file d'attente
            @return Pointeur vers la file d'attente
         */
        Queue *getQueue();


        /*! @fn Cashier * getCashiers()
            @brief Getter vers la liste des caissiers
            @return Liste des caissiers
         */ 
        Cashier *getCashiers();

        /**
         * 
         * @fn double getInterval()
         * @brief Getter pour l'attribut interval
         * @return attribut interval
         * 
         */ 
        double getInterval();

        /**
         * 
         * @fn double getExpectedDuration()
         * @brief Getter pour l'attribut expectedDuration
         * @return attribut expectedDuration
         * 
         */ 
        double getExpectedDuration(); 

        /**
         * 
         * @fn void printResults()
         * @brief Affiche le résultat de la simulation
         * 
         */
        void printResults();
};

#endif
