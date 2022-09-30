/**
 * 
 * @file Cashier.h
 * @author Ghilas KASMI
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 *
 */
#ifndef CASHIER_H
#define CASHIER_H

#include "Client.h"
#include "Departure.h"
#include "Arrival.h"
#include "Bank.h"

#include <random>

using namespace std;

class Bank; 


/**
 * 
 * @class Cashier
 * @brief Cette classe représante les caissiers qui traiteront les evenements dans la banque
 * 
 */
class Cashier{
    private:
        double occupationRate; ///< Taux d'occupation du caissier
        int clientCount; ///< Nombre de clients servi
        double averageServiceTime; ///< Temps moyen pour servir un client
        bool available; ///< Vaut true si le caissier est libre, sinon false
        Bank *bank; ///< Pointeur vers la banque
        bool exists; ///< booléen servant à différencier les "vrais" caissiers des "faux", c'est une mesure utilisée pour éviter des problèmes de mémoire
        double isBusy; ///< Représente le temps ou le caissier a été occupé
    public:
        /*! @fn Cashier() 
            @brief constructeur : Crée un "faux" caissier
        */  
        Cashier();


        /*! @fn Cashier(double averageServiceTime, Bank *bank)
            @brief Crée une instance initialisée de Caissier
            @param averageServiceTime Temps moyen pour servir un client
            @param bank  Pointeur vers la banque
        */ 
        Cashier(double averageServiceTime, Bank *bank);


        /*! @fn double getOccupationRate()
            @brief Calcule le temps d'occupation 
            @return Taux d'occupation 
         */
        double getOccupationRate();


        /*! @fn int getClientCount()
            @brief Getter pour le nombre de client servis
            @return Nombre de lcients servis
         */
        int getClientCount();


        /*! @fn double getAverageServiceTime()
            @brief Getter pour le temps de service moyen
            @return Temps de service moyen
         */
        double getAverageServiceTime();


        /*! @fn bool isAvailable()
            @brief Getter pour l'attribut available
            @return return true si le caissier est libre, false sinon
         */
        bool isAvailable();


        /*! @fn void serve(Client *client)
            @brief Sert un client, planifie son départ, et met à jour les stats de la simultion
            @param client : Client  
         */
        void serve(Client* client);


        /*! @fn void free()
            @brief Libère un caissier après avoir fini de servir un client
         */
        void free();


        /*! @fn bool getExists()
            @brief Getter pour l'attribut exists
            @return La valeur de l'attribut exists 
         */
        bool getExists(); 
};

#endif