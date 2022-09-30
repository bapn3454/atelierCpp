/**
 * @mainpage Index de la documentation
 * 
 * Ce projet a été effectué par Ghilas KASMI pour valider les acquis de l'atelier c++ enseigné par Philippe Laroque dans le cadre 
 * la formation Master IISC de l'université CYU.  
 * 
*/

#include "Simulation.h"
#include "Bank.h"

#include "Arrival.h"
#include "Poisson.h"

#include <getopt.h>
#include <iostream>
#include <string>

using namespace std;

void printHelp(){
    cout << "Les arguments fournis sont incorrects, verifiez que vous avez bien fourni tous les arguments necessaires \n"
        "\t----- Arguments : -----\n\n"
        "-n <n> : Nombre de caissiers \n"
        "-d <n> : Duree de la simulation \n"
        "-s <val> : Temps de service moyen \n"
        "-t <val> : Temps entre les arrivees" << endl;
    exit(0); 
}


int main(int argc, char **argv){
    double st = 0, tm = 0; 
    int dp = 0, nc = 0; 
    const char* const short_opts = "n:d:s:t:h";
    const option long_opts[] = {
            {"nc", required_argument, nullptr, 'n'},
            {"dp", required_argument, nullptr, 'd'},
            {"st", required_argument, nullptr, 's'},
            {"tm", required_argument, nullptr, 't'},
            {"help", no_argument, nullptr, 'h'}
    };

    if(argc < 8){
        printHelp();
    } 
    
    while (true){
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (opt < 0)
           break; 
           
        switch (opt){
            case 'n' : 
                nc = stoi(optarg);
                cout << "Nombre de caissiers configure à : " << nc << endl;
                break;
            case 's' : 
                st = stod(optarg);
                cout << "Temps de service moyen configure à : " << st << endl;
                break;
            case 't' :
                tm = stod(optarg);
                cout << "Temps moyen entre les arrivees configure à : " << tm << endl;
                break;
            case 'd' :
                dp = stoi(optarg);
                cout << "Duree prevue de la simulation configuree à : " << dp << endl;
                break;
            case 'h' :
            case '?' :
            default :
                printHelp();    
                break;
        }
    }
    
    cout << "\n------- Debut Simulation -------" << endl; 
    
    Poisson::init();
    Bank* bank = new Bank(nc,st,dp, tm);
    //Simulation simulation(dp, st, tm, nc);
    bank->start();
    bank->printResults();

    cout << "\n ------- Fin Simulation -------" << endl; 
    return 0;
}
