/******************************************
* Filename: event.h
* Description: header file for event class
* Input: 
* Output: Prototypes for default constructor, getters, setters, functions
******************************************/
#ifndef EVENT_H
#define EVENT_H
#include <string>

using namespace std;
class Event
{
protected:
    
    string message;
    string encounter;
    string name;

public:
    
    Event();
    ~Event();
    virtual string get_encounter();
    virtual string get_message();
    virtual string get_name();

};

#endif