/**
 * 
 * @file Queue.h
 * @author Ghilas KASMI
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 *
 */
#ifndef Queue_H
#define Queue_H

#include "Client.h"
#include <iostream> 
#include <deque> 
  
using namespace std;

class Bank; 


/**
 * 
 * \class Queue
 * @brief Représentation de la file d'attente
 * 
 *  la classe Queue est une structure de données qui suit une loi de départ FIFO, elle est une file d'attente 
 * ou les clients sont servis dans l'ordre de leur arrivée
 * 
 */
class Queue{
    private :
        deque<Client> clients; ///< std::deque implémentation d'une file de clients
        int maxLength; ///< Longueur maximale
        double averageLength;  ///< Longueur moyenne de la file
        Bank *bank; ///< Pointeur vers la banque
    public :
        /*! @fn Queue(Bank *bank)
            @brief Constructeur de la file
            @param Bank Pointeur vers la banque
        */
        Queue(Bank *bank);


        /*!
            @fn int getMaxLength()
            @brief Getter pour l'attribut maxLength
            @return attribut maxLength
         */
        int getMaxLength();


        /*! @fn double getAverageLength()
            @brief Calcule la taille moyenne de la file
            @return la taille moyenne de la file
         */
        double getAverageLength();


        /*! @fn bool isEmpty()
            @brief vérifie si la file est vide  
            @return True si la file est vide, false sinon
         */
        bool isEmpty();


        /*! @fn void add(Client client) 
            @brief Ajoute un client dans la file et modifie les attributs liées à la file
            @param client Le client à ajouter
         */
        void add(Client client);

        
        /*! @fn Client pop()
            @brief Retire le premier client arrivé qui n'a pas encore été servi
            @return Le plus ancien client de la file
         */
        Client pop();
};

#endif
