/******************************************
* Filename: gold.h
* Description: header file for gold class
* Input: 
* Output: Prototypes for default constructor, getters, setters
******************************************/
#ifndef GOLD_H

#define GOLD_H

#include "event.h"

using namespace std;

class Gold : public Event
{
public:
    
    Gold();
    ~Gold();
    string get_message();
    string get_encounter();
    string get_name();
    
};

#endif


