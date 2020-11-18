/******************************************
* Filename: pit.h
* Description: header file for pit class
* Input: 
* Output:  Prototypes for default constructor, getters, setters
******************************************/
#ifndef PIT_H
#define PIT_H

#include "event.h"

class Pit : public Event
{
public:
    
    Pit();
    string get_message();
    string get_encounter();
    string get_name();
    ~Pit();
};


#endif