/*  _____                                                                             _____  */
/* ( ___ )                                                                           ( ___ ) */
/*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |  */
/*  |   |                                                                             |   |  */
/*  |   |                                                                             |   |  */
/*  |   |    _   _                       ____                  ____   ___  _ ____     |   |  */
/*  |   |   | | | | __ _ _ __ _ __ _   _|  _ \  ___  _ __ ___ |___ \ / _ \/ |___ \    |   |  */
/*  |   |   | |_| |/ _` | '__| '__| | | | | | |/ _ \| '_ ` _ \  __) | (_) | | __) |   |   |  */
/*  |   |   |  _  | (_| | |  | |  | |_| | |_| | (_) | | | | | |/ __/ \__, | |/ __/    |   |  */
/*  |   |   |_| |_|\__,_|_|  |_|   \__, |____/ \___/|_| |_| |_|_____|  /_/|_|_____|   |   |  */
/*  |   |                          |___/                                              |   |  */
/*  |   |                                                                             |   |  */
/*  |   |                                                                             |   |  */
/*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|  */
/* (_____)                                                                           (_____) */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int light_x;    // the X position of the light of power
    int light_y;    // the Y position of the light of power
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position
    cin >> light_x >> light_y >> initial_tx >> initial_ty;
    cin.ignore();

    cerr << "Debug messages..." << endl;

    // game loop
    while (1)
    {
        int remaining_turns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remaining_turns;
        cin.ignore();
        if (remaining_turns != 0)
        {
            if (light_x == initial_tx && light_y == initial_ty)
                break;
            else
            {
                if (light_x == initial_tx || light_y == initial_ty)
                {
                    if (light_x > initial_tx)
                    {
                        cout << "E" << endl;
                        initial_tx++;
                    };
                    if (light_x < initial_tx)
                    {
                        cout << "W" << endl;
                        initial_tx--;
                    };
                    if (light_y > initial_ty)
                    {
                        cout << "S" << endl;
                        initial_ty++;
                    };
                    if (light_y < initial_ty)
                    {
                        cout << "N" << endl;
                        initial_ty--;
                    };
                }
                else
                {
                    if (light_x > initial_tx && light_y > initial_ty)
                    {
                        cout << "SE" << endl;
                        initial_tx++;
                        initial_ty++;
                    }
                    if (light_x > initial_tx && light_y < initial_ty)
                    {
                        cout << "NE" << endl;
                        initial_tx++;
                        initial_ty--;
                    }
                    if (light_x < initial_tx && light_y > initial_ty)
                    {
                        cout << "SW" << endl;
                        initial_tx--;
                        initial_ty++;
                    }
                    if (light_x < initial_tx && light_y < initial_ty)
                    {
                        cout << "NW" << endl;
                        initial_tx--;
                        initial_ty--;
                    }
                }
            }
            remaining_turns--;
        }
        else
            break;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}