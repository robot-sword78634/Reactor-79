#include <iostream>
#include <string>
using namespace std;

void eventCards(int&pump1, int&pump2, int&condenser, int&turbine, int&coolingTower, int&generator, int&steamLine, int&reactor, int&turn)
{
    int randomCards;
    srand(time(0));
    randomCards = rand()%(1-100)+1;
    //cout << randomCards;

    if (randomCards < 20) {
        cout << "Water Pump #1 FAILURE!\n\n";
        pump1 = pump1 - 1;
        }
        else if (randomCards < 30) {
            cout << "Water Pump #2 FAILURE!\n\n";
            pump2 = pump2 - 1;
        }
        else if (randomCards < 40) {
            cout << "Condenser FAILURE!\n\n";
            condenser = condenser - 1;
        }
        else if (randomCards < 50) {
            cout << "Turbine FAILURE!\n\n";
            turbine = turbine - 1;
        }
        else if (randomCards < 60) {
            cout << "Cooling Tower FAILURE!\n\n";
            coolingTower = coolingTower + 1;
        }
        else if (randomCards < 70) {
            cout << "Back-Up Generator FAILURE!\n\n";
            generator = generator - 1;
            pump1 = pump1 - 1;
            pump2 = pump2 - 1;
            condenser = condenser - 1;
        }
        else if (randomCards < 80) {
            cout << "Steam Line FAILURE!\n\n";
            steamLine = steamLine - 1;
        }
        else if (randomCards < 90) {
            cout << "Reactor FAILURE!\n\n";
            reactor = reactor + 1;
        }
        else if (randomCards < 101) {
            cout << "Civil UNREST!\n";
            cout << "Skip a turn.\n\n";
            turn = turn + 1;
        }
        
    }
     

int main()
{
    
cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  
cout << "          ) ) )                     ) ) ) \n";
cout << "        ( ( (                      ( ( ( \n";
cout << "      ) ) )                       ) ) ) \n";
cout << "   (~~~~~~~~~)                 (~~~~~~~~~) \n";
cout << "    | R     |                   | '79   | \n";
cout << "    | E     |                   |       | \n";
cout << "    I A    _._                  I       _._ \n";
cout << "    I C  /'   `\\                I     /'   `\\ \n";
cout << "    I T |   N   |               I    |   N   | \n";
cout << "    f O |   |~~~~~~~~~~~~~~|    f    |    |~~~~~~~~~~~~~~| \n";
cout << "  .'  R |   ||~~~~~~~~|    |  .'     |    | |~~~~~~~~|   | \n";
cout << " //'____|___||__###___|____|/'_______|____|_|__###___|___| \n";
cout << "Attemmpt to stabilize a nuclear power plant in crisis over 10 turns.\n";
cout << "Each machinery value may be adjusted up or down by one. A cumulative value (RAD score)\n";
cout << "of 26 at the end of turn #10 stabilizes the power plant and wins the game.\n";
    
    int turn, reactor, steamLine, turbine, generator, pump1, pump2, condenser, coolingTower, rad;
    reactor = 9;
    steamLine = 3;
    turbine = 3;
    generator = 3;
    pump1 = 3;
    pump2 = 3;
    condenser = 5;
    coolingTower = 4;
    turn = 1;
    
    while (turn < 11 && reactor < 12 && coolingTower < 6 && steamLine > 0 && turbine > 0 && generator > 0 && pump1 > 0 && pump2 > 0 && condenser < 6 && coolingTower < 6) {
    cout << "\n";
    cout << "TURN #" << turn << "\n";
    turn++;
    
    int random;
    srand(time(0));
    random = rand()%(1-100)+1;

    if (random < 21) {
        cout << "No event.\n\n";
    } else {
        cout << "Event occurs.\n";
        eventCards(pump1, pump2, condenser, turbine, coolingTower, generator, steamLine, reactor, turn);
    }
    //display HUD
    cout << "(1)REACTOR: " << reactor << "|(2)STEAM LINE: " << steamLine << "|(3)TURBINE: " << turbine << "|(4)GENERATOR: " << generator << "\n";
    cout << "(5)WATER PUMP #1: " << pump1 << "|(6)WATER PUMP #2: " << pump2 << "|(7)CONDENSER: " << condenser << "|(8)COOLING TOWER: " << coolingTower << "\n";
        rad = reactor + steamLine + turbine + generator + pump1 + pump2 + condenser + coolingTower;
        cout << "RAD SCORE: " << rad << "\n";
        cout << "Repair (1 to 8 or -1 to -8) or Pass (0): ";
        int action;
        cin >> action;
        if (action == 1){
            reactor = reactor +1;
        }
        else if (action == -1){
            reactor = reactor -1;
        }
        else if (action == 2){
            steamLine = steamLine + 1;
        }
        else if (action == -2){
            steamLine = steamLine -1;
        }
        else if (action == 3){
            turbine = turbine +1;
        }
        else if (action == -3){
            turbine = turbine -1;
        }
        else if (action == 4){
            generator = generator +1;
        }
        else if (action == -4){
            generator = generator -1;
        }
        else if (action == 5){
            pump1 = pump1 +1;
        }
        else if (action == -5){
            pump1 = pump1 -1;
        }
        else if (action == 6){
            pump2 = pump2 + 1;
        }
        else if (action == -6){
            pump2 = pump2 -1;
        }
        else if (action == 7){
            condenser = condenser + 1;
        }
        else if (action == -7){
            condenser = condenser -1;
        }
        else if (action == 8){
            coolingTower = coolingTower + 1;
        }
        else if (action == -8){
            coolingTower = coolingTower - 1;
        }
        else if (action == 0){
            cout << "No repair attempted.\n";
        }
        
    
    }
    
    cout << "\n";
    int final;
    final = reactor + steamLine + turbine + generator + pump1 + pump2 + condenser + coolingTower;
    cout << "END OF GAME\n"; //end of game result
    if (reactor >= 12){
        cout << "Reactor meltdown!\n";
    }
    if (coolingTower >= 6){
        cout << "Cooling tower collapse!\n";
    }
    cout << "FINAL RAD SCORE: " << final << "\n";
    if (final == 26) {
        cout << "WIN!\n";
    } else {
    cout << "LOSE!\n";
    }
    
    return 0;
}



