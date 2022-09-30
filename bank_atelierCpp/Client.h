/**
 * 
 * @file Client.h
 * @author Ghilas 
 * @author Mourtada HOUARI
 * @author Rabah BELKHIR
 * @date 23/09/2022
 * 
 */
#ifndef CLIENT_H
#define CLIENT_H


/**
 * 
 *  \class Client
 * @brief Class représentant les client de la banque 
 * 
 */
class Client {
    public:
        /*! @fn Client
            @brief constructor par défaut
         */
        Client(); 


        /*! @fn Client(double arrivalTime)
            @brief Crée une instance de Client avec son temps d'arrivée
            @param arrivalTime : Temps de la simmulation ou le client arrive
        */
        Client(double arrivalTime);

        
        /*! @fn double getArrivalTime()
            @brief Getter pour l'attribut arrivalTime
            @return Temps d'arrivéee
         */
        double getArrivalTime(); 
    private :
        double arrivalTime; ///< Temps d'arrivée

}; 


#endif
