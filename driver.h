#ifndef F1TEXTGAME_H
#define F1TEXTGAME_H
#include <iostream>
#include <string>
using namespace std;

class Driver
{
    string name;
    int skillRating;
public:
    Driver();
    Driver(string name, int skillRating);
    string getName() const;
    int getSkillRating() const;
};



#endif