#include <iostream>
#include <vector>
#include "Player.h"
#include "Area.h"


int main()
{

    //Create different areas.
    Area area1("Woodlands", "The trees seem to stretch endlessly in every direction.", "");
    Area area2("Forgotten Shrine", "The walls seem ready to crumble at any moment.", "");
    Area area3("Pond of Sacrifice", "It's said the Merciful One saved these lands by diving into this pond.", "");
    Area area4("Stone Tower", "Peering from the top, you can just make out an end to these old woods.", "");
    Area area5("Tomb of Mercy", "A soft yellow hue fainlty lightens the small room. A giant tomb stands before you.", "");

    //Connect areas to one another accordingly.
    area1.exits.push_back(&area3);
    area1.exits.push_back(&area4);

    area2.exits.push_back(&area3);
    area2.exits.push_back(&area5);

    area3.exits.push_back(&area1);
    area3.exits.push_back(&area2);

    area4.exits.push_back(&area1);

    area5.exits.push_back(&area2);

    //Create a new player.
    Player player("Sylokyr", "Shaman", 35, 4, "Staff", "Robes", &area1);

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
            std::cout << "look - Inspect current area. Lists possible exits." << "\n";
            std::cout << "go - Travel to a new area." << "\n";
        }
        //If the user enters "look", run the Look() function.
        else if (userIn == "look")
        {
            player.currentArea->Look();
        }
        //If the user enters "go", run the Go() function.
        else if (userIn == "go")
        {
            std::string userArea;
            std::cout << "\nWhere do you want to go? ";
            std::getline(std::cin >> std::ws, userArea);

            //Loop through the exits available from the current area.
            for (int i = 0; i < player.currentArea->exits.size(); ++i)
            {
                //If the user-inputted area matches one of the exit names, pass that exit into the Go() function.
                if (player.currentArea->exits[i]->name == userArea)
                {
                    player.Go(player.currentArea->exits[i]);
                    std::cout << "\nNew Area: " << player.currentArea->name << "\n";
                    std::cout << player.currentArea->description << "\n";
                }
            }
        }
    }
}


