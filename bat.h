/******************************************
* Filename: bat.h
* Description: header file for bat class
* Input: 
* Output: Prototypes for default constructor, getters, setters, functions
******************************************/
#ifndef BAT_H
#define BAT_H

#include "event.h"

using namespace std;

class Bat : public Event
{
public:
    Bat();
    string get_message();
    string get_encounter();
    string get_name();
    ~Bat();
};


#endif