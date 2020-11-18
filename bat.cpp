/******************************************
* Filename: bat.cpp
* Description: implementation file for bat class
* Input: header
* Output: default constructor, getters, setters
******************************************/
#include "bat.h"

using namespace std;

Bat::Bat()
{
    message = "You hear wings flapping";
    encounter = "Room with bats";
    name = "B";
}

string Bat::get_message()
{
    return message;
}

string Bat::get_encounter()
{
    return encounter;
}

string Bat::get_name()
{
    return name;
}

Bat::~Bat(){}