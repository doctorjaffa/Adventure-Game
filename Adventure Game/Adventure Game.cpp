#include <iostream>
#include <vector>
#include "Player.h"
#include "Area.h"
#include "Monster.h"


int main()
{

    //Create different areas.
    Area area1("Woodlands", "The trees seem to stretch endlessly in every direction.");
    Area area2("Forgotten Shrine", "The walls seem ready to crumble at any moment.");
    Area area3("Pond of Sacrifice", "It's said the Merciful One saved these lands by diving into this pond.");
    Area area4("Stone Tower", "Peering from the top, you can just make out an end to these old woods.");
    Area area5("Tomb of Mercy", "A soft yellow hue fainlty lightens the small room. A giant tomb stands before you.");

    //Connect areas to others accordingly.
    area1.SetExits(&area3);
    area1.SetExits(&area4);

    area2.SetExits(&area3);
    area2.SetExits(&area5);

    area3.SetExits(&area1);
    area3.SetExits(&area2);

    area4.SetExits(&area1);

    area5.SetExits(&area2);

    //Create a new player.
    Player player("Sylokyr", "Shaman", 35, 4, "Staff", "Robes", &area1);

    //Create monster(s).
    Monster monster1("Tree Spirit", "Once a friend of the forest, this spirit now roams endlessly with bloodlust.", 15, 3);

    //Set monsters to areas.
    area1.AddMonster(&monster1);

    //Opening text. Take first command from player.
    std::cout << "\nYou awaken in a small opening, surrounded by trees." << "\n";

    while (true) {

        std::string userIn = "";
        std::cout << "\nWhat would you like to do? ";
        std::cin >> userIn;

        //If the user enters "help", display a list of commands.
        if (userIn == "help")
        {
            std::cout << "\nCOMMANDS:" << "\n";
            std::cout << "clear - Clears screen.\n";
            std::cout << "look - Inspect current area. Lists possible exits." << "\n";
            std::cout << "go - Travel to a new area accessible from current area." << "\n";
            std::cout << "attack - Attack a monster in the current area. Must enter monster name on prompt to fight it. Fight will end when something dies." << "\n";
        }
        //If the user enters "clear", clear the screen.
        else if (userIn == "clear")
        {
            system("CLS");
        }
        //If the user enters "look", run the Look() function.
        else if (userIn == "look")
        {
            player.GetCurrentArea()->Look();
        }
        //If the user enters "go", run the Go() function.
        else if (userIn == "go")
        {
            std::string userArea;
            std::cout << "\nWhere do you want to go? ";
            std::getline(std::cin >> std::ws, userArea);

            player.GetCurrentArea()->Go(&player, userArea);
        }
        else if (userIn == "attack")
        {
            std::string targetMonster;
            std::cout << "\nWhat monster do you want to attack? ";
            std::getline(std::cin >> std::ws, targetMonster);

            player.DealDamage(targetMonster);
        }

        if (player.GetHealth() < 1)
        {
            std::abort();
        }
    }
}


