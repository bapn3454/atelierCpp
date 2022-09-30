/*!
    @file Event.cpp
    @author Ghilas KASMI
    @author Mourtada HOUARI
    @author Rabah BELKHIR
    @date 23/09/2022
*/
#include "Event.h"

Event::Event(double hour)
{
    this->time = hour;
}

Event::~Event() {}

double Event::getTime() {
	return time;
}
