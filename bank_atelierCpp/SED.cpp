/*!
    @file SED.cpp
    @author Ghilas KASMI
	@author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/

#include "SED.h"
#include <iostream>

SED::SED() {
	currentTime = 0.0;
	totalWaitTime = 0.0;
}

void SED::start() {
	Event *e = nullptr;

	//On traite les clients de manière chronologique
	while (!schedule.empty()){
		e = schedule.top();
		currentTime = e->getTime();
		schedule.pop();
		e->process();

		delete e;
	}
}

void SED::add(Event *e) {
	schedule.push(e);
}

double SED::getCurrentTime() const {
	return currentTime;
}

void SED::provideWaitTimeEntry(double time){
	totalWaitTime += time;
}
