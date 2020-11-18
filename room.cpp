/******************************************
* Filename: room.cpp
* Description: implementation file for room class
* Input: header
* Output: default constructor, getters, setters
******************************************/
#include "room.h"

using namespace std;
//constructor
Room::Room()
{
    this->events = NULL;
    event_type = 0;
    player = false;
    event_checker = 0;
}
//setter
void Room::set_event_type(int new_event_type)
{
    event_type = new_event_type;
}
//getter
int Room::get_event_type()
{
    return event_type;
}
//getter
bool Room::get_player()
{
    return player;
}
//setter
void Room::set_player(bool new_player)
{
    player = new_player;
}
//getter
int Room::get_event_check()
{
    return event_checker;
}
//setter
void Room::set_event_check(int new_event_checker)
{
    event_checker = new_event_checker;
}
/*********************************************************************
** Function: set_event
** Description: This function populates events depending on event type
** Parameters: int new_event
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/ 
void Room::set_event(int new_event){
  
   switch(new_event){
       case 2:
           events = new Wumpus;
           break;
       case 3:
           events = new Gold;
           break;
       case 4:
           events = new Pit;
           break;
       case 5:
           events = new Bat;
           break;
       default:
           events = new Event;
           break;
   }
}
//getter
string Room::get_event()
{
    return events->get_message();
}
//getter
string Room::get_in()
{
    return events->get_encounter();
}
//destructor for room
Room::~Room()
{
    if(events != NULL){
        delete events;
        events = NULL;
    }
}