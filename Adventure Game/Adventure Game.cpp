#include <iostream>
#include <vector>
#include "Player.h"
#include "Area.h"
#include "Monster.h"
#include "Thing.h"
#include "Potion.h"
#include "Item.h"


int main()
{

    /* ------------------------------------------------------------------------------------------------ START OF SET-UP ------------------------------------------------------------------------------------------------ */
    //Create areas.
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

    //Create monsters.
    Monster monster1("Tree Spirit", "Once a friend of the forest, this spirit now roams endlessly with bloodlust.", 15, 3);
    Monster monster2("Wood Goblin", "Since the fall of the woods, this goblin has been scavenging for valuables.", 7, 2);
    Monster monster3("Corrupt Shrine Maiden", "It's unknown how long this shrine maiden has been waiting, but you can tell it's been far too long.", 30, 5);
    Monster monster4("Baby Hydra", "Despite being a child, you can tell a hydra is no joke. This is probably the only time you could kill one.", 16, 4);
    Monster monster5("Water Spirit", "Similar to its forest counterpart, this spirit seems mindless and angry.", 12, 3);

    //Set monsters to areas.
    area1.AddMonster(&monster1);
    area1.AddMonster(&monster2);
    
    area2.AddMonster(&monster3);

    area3.AddMonster(&monster4);
    area3.AddMonster(&monster5);

    //Create items.
    Potion potion1("Healing Herb", "This herb provides the basic level of healing (+5HP)", 5);

    //Place items in areas.
    area1.SetItems(&potion1);


    /* ------------------------------------------------------------------------------------------------- END OF SET-UP ------------------------------------------------------------------------------------------------- */

    //Opening text. Take first command from player.
    std::cout << "\nYou awaken in a small opening, surrounded by trees.";

    while (true) {

        std::string userIn = "";
        std::cout << "\n\nWhat would you like to do? ";
        std::cin >> userIn;

        //If the user enters "help", display a list of commands.
        if (userIn == "help")
        {
            std::cout << "\nCOMMANDS:" << "\n";
            std::cout << "clear - Clears screen.\n";
            std::cout << "look - Inspect something. Enter 'area' to see exits and monsters. Enter 'inventory' to view player inventory." << "\n";
            std::cout << "go - Travel to a new area accessible from current area." << "\n";
            std::cout << "grab - Collect an item that is available in a given area." << "\n";
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
            std::string userAnswer;
            std::cout << "\nLook at what? ";
            std::getline(std::cin >> std::ws, userAnswer);

            if (userAnswer == "area")
            {
                player.GetCurrentArea()->Look();
            }
            else if (userAnswer == "inventory")
            {
                player.PrintInventory();
            }
            else if (userAnswer == player.GetCurrentArea()->GetMonster(userAnswer)->GetName())
            {
                player.GetCurrentArea()->GetMonster(userAnswer)->Look();
            }
        }
        //If the user enters "go", run the Go() function.
        else if (userIn == "go")
        {
            std::string userArea;
            std::cout << "\nWhere do you want to go? ";
            std::getline(std::cin >> std::ws, userArea);

            player.GetCurrentArea()->Go(&player, userArea);
        }
        //If the user enters "grab", ask what item the user would like to collect.
        else if (userIn == "grab")
        {
            std::string userItem;
            std::cout << "\nWhat would you like to collect? ";
            std::getline(std::cin >> std::ws, userItem);

            player.AddItem(player.GetCurrentArea()->GetItem(userItem));
        }
        //If the user enters "attack", ask what monster to target then deal damage.
        else if (userIn == "attack")
        {
            std::string targetMonster;
            std::cout << "\nWhat monster do you want to attack? ";
            std::getline(std::cin >> std::ws, targetMonster);

            player.DealDamage(targetMonster);
        }

        //If player's health drops to 0, kill them and end the game.
        if (player.GetHealth() < 1)
        {
            std::abort();
        }
    }
}


