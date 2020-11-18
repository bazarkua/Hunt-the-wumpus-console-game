/******************************************
* Filename: event.cpp
* Description: implementation of event class
* Input: header file
* Output: default constructor, getters, setters
******************************************/
#include "event.h"
using namespace std;

Event::Event()
{
    message = "";
    encounter = "";
    name = "";
}
string Event::get_message()
{
    return message;
}
string Event::get_encounter() 
{
    return encounter;
}
string Event::get_name()
{
    return name;
}
Event::~Event(){}