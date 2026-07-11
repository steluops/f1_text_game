#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <iostream>
#include <string>
#include <vector>
#include "team.h"

using namespace std;

struct Competitor
{
    Team team;
    double totalTime;
};

class Circuit
{
    string circuitName;
    int totalLaps;
    int baseTime;
public:
    Circuit(string circuitName, int totalLaps, int baseTime);
    void startRace(vector<Team>& grid);

};

#endif