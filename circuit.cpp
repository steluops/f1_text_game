#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <random>
#include "team.h"
#include "circuit.h"
using namespace std;

Circuit::Circuit(string track, int laps, int time) : circuitName(track), totalLaps(laps), baseTime(time) {}

void Circuit::startRace(vector<Team>& grid)
{
    vector<Competitor> standings;

    for(const auto& team : grid)
    {
        standings.push_back({team, 0.0});
    }
    mt19937 rng(random_device{}());
    uniform_real_distribution<double> variance(-1.5, 1.5);

    cout << "Welcome to " << circuitName << "!" << endl;
    this_thread::sleep_for(chrono::seconds(5));

    for(int lap = 1; lap <= totalLaps; lap++)
    {
        cout << "\033[2J\033[1;1H"; 
        cout << "F1 RACE: " << circuitName << endl;
        cout << "===============\n";
        cout << "LAP: " << lap << "/" << totalLaps << endl;
        cout << "===============\n";
        
    }

    for(auto& comp : standings)
    {
        double driverModifier = (100 - comp.team.getDriver().getSkillRating() / 100.0) * 2.0;
        double carModifier = (100 - comp.team.getCarRating() / 100.0) * 3.0;
        double randomFactor = variance(rng);

        comp.totalTime += baseTime + driverModifier + carModifier + randomFactor;
    }

    sort(standings.begin(), standings.end(), [](const Competitor& a, const Competitor& b)
    {
        return a.totalTime < b.totalTime;
    });

    for(size_t i = 0; i < standings.size(); i++)
    {
        string interval;
        if(i == 0)
        {
            interval = "Leader";
        }
        else
        {
            double timeGap = standings[i].totalTime - standings[0].totalTime;
            interval = "+" + to_string(timeGap).substr(0,5) + "s";
        }

        cout << i + 1 << endl;
        cout << standings[i].team.getDriver().getName() << "\t\t"
             << standings[i].team.getTeamName() << "\t\t"
             << interval << endl;
    

        this_thread::sleep_for(chrono::milliseconds(800));

    }

    cout << "===========\n";
    cout << "There's the chequered flag! The winner of the race is: "
         << standings[0].team.getDriver().getName() << "!!!" << endl;
}