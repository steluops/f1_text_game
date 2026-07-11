#include <iostream>
#include <vector>
#include "driver.h"
#include "team.h"
#include "circuit.h"

using namespace std;

int main()
{
    vector<Driver> drivers = 
    {
     {"Max Verstappen", 95}, {"Isack Hadjar", 84}, 
     {"George Russell", 92}, {"Kimi Antonelli", 83},
     {"Charles Leclerc", 92}, {"Lewis Hamilton", 87},
     {"Lando Norris", 92}, {"Oscar Piastri", 91},
     {"Fernando Alonso", 87}, {"Lance Stroll", 80},
     {"Carlos Sainz", 89}, {"Alex Albon", 84},
     {"Pierre Gasly", 84}, {"Franco Colapinto", 79},
     {"Oliver Bearman", 84}, {"Esteban Ocon", 82},
     {"Arvid Lindblad", 83}, {"Liam Lawson", 83},
     {"Nico Hulkenberg", 83}, {"Gabriel Bortoleto", 82},
     {"Sergio Perez", 84}, {"Valterri Bottas", 84}
    };

    vector<string> teamNames = {"Red Bull", "Red Bull", 
                                "Mercedes", "Mercedes", 
                                "Ferrari", "Ferrari",
                                "McLaren", "McLaren", 
                                "Aston Martin", "Aston Martin",
                                "Williams", "Williams",
                                "Alpine", "Alpine", 
                                "Haas", "Haas", 
                                "Racing Bulls", "Racing Bulls",
                                "Audi", "Audi", 
                                "Cadillac", "Cadillac"};
    
    vector<int> carPerf = {92, 92, 96, 96, 94, 94, 88, 88, 65, 65, 77, 77, 78, 78,
                           83, 83, 73, 73, 74, 74, 69, 69};
    vector<Team> grid;
    for(size_t i = 0; i < drivers.size(); i++)
    {
        grid.push_back(Team(teamNames[i], drivers[i], carPerf[i]));
    }

    cout << "Welcome to the F1 Simulator" << endl;
    bool circuitChosen = false;
    int circuitChoice;

    Circuit selectedCircuit("Not selected", 0, 0.0);
    while(circuitChosen == false)
    {
        cout << "Please choose a circuit." << endl;
        cout << "1. Albert Park" << endl;
        cout << "2. Suzuka" << endl;
        cout << "3. Montreal" << endl;
        cout << "4. Singapore" << endl;
        cout << "5. Silverstone" << endl;
        cout << "Enter number: " << endl;
        cin >> circuitChoice;

        switch(circuitChoice)
        {
        case 1:
        {
            selectedCircuit = Circuit("Albert Park", 58, 83.0);
            circuitChosen = true;
            break;
        }
        case 2:
        {   selectedCircuit = Circuit("Suzuka", 53, 88.0);
            circuitChosen = true;
            break;
        }
        case 3:
        {
            selectedCircuit = Circuit("Montreal", 70, 88.0);   
            circuitChosen = true;
            break;
        }
        case 4:
        {
            selectedCircuit = Circuit("Singapore", 62, 91.0);
            circuitChosen = true;
            break;
        }
        case 5:
        {
            selectedCircuit = Circuit("Silverstone", 52, 87.0);
            circuitChosen = true;
            break;
        }
        default:
        {
            cout << "Error: Please try again." << endl;
        }
        }
    }
    selectedCircuit.startRace(grid);

    return 0;
}