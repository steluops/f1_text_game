#include <iostream>
#include <string>
#include "driver.h"
using namespace std;

Driver::Driver()
{
    name = "";
    skillRating = 0;
}

Driver::Driver(string name, int skill) : name(name), skillRating(skill) {}

string Driver::getName() const {return name;}

int Driver::getSkillRating() const {return skillRating;}
