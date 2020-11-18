/******************************************
* Filename: wumpus.h
* Description: header file for bat class
* Input:
* Output: Prototypes for default constructor, getters, setters
******************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"

class Wumpus : public Event
{
public:
    
    Wumpus();
    string get_message();
    string get_encounter();
    string get_name();
    ~Wumpus();
};

#endif