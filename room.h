/******************************************
* Filename: room.h
* Description: header file for room class
* Input:
* Output: Prototypes for default constructor, getters, setters
******************************************/
#ifndef ROOM_H
#define ROOM_H
#include "event.h"
#include "gold.h"
#include "wumpus.h"
#include "bat.h"
#include "pit.h"

using namespace std;

class Room
{
protected:
    
    Event* events;
    int event_type;
    bool player;
    int event_checker;

public:
    
    Room();
   ~Room();
    
    //setters and getters
    int get_event_type();
    void set_event_type(int);
    bool get_player();
    void set_player(bool);
    void set_event(int);
    int get_event_check();
    void set_event_check(int);
    string get_in();
    string get_event();

};


#endif