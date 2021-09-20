/*
    Author: Max Edward
    Email: maxedwar@uat.edu
    Assignment Name: Text Adventure Game - Night Racer
*/

// Night Racer 
// A personalized racing game

//These bring in the iostream for console readout as well as string to use strings.
#include <iostream>
#include <string>

// I decided to bring in the entire std namespace as to not forget to include an object while I am coding and wind up with an error.
using namespace std;

int main() {
    // Setup Variables - used for starting speed as well as getting racer and rival names from user.
    int speed = 100;
    string racer;
    string rival;

    // Opening - game name, author, and backstory explained.
gameStart:
    cout << "\n------------------------------------\n\n";
    cout << "Welcome to Night Racer by Max Edward\n\n";
    cout << "The game will change depending on your choices.\n";
    cout << "You will start at 100% speed. Depending on the actions you make, you will either speed up or lose speed.\n";
    cout << "Have fun and good luck!\n\n";
    cout << "------------------------------------\n";
    system("pause"); // Pause to make sure the player is ready to play. Almost like a "Click start to start game".

    // User's personalized input
    cout << "Please enter the following information to get started on your racing adventure!\n";
    cout << "Enter your Racer's Name:"; // Used for main player - racer. 
    cin >> racer; // User input.
    cout << "Enter your Rival's Name:"; // Used for rival player - the player's opponent. Not a CPU in this case.
    cin >> rival; // User input.

    // Dialogue for player.
    cout << "\nWelcome all to tonights race!\n";
    cout << "We have some tough challengers tonight, so lets not waste any time!\n";
    cout << "On the left, we have " << racer << ", the all time Night City champion! And on the right we have " << rival << ", who seeks to be the new champ!\n";
    cout << "Tonights race will put each racer's skills to the test. Both racers will compete head-to-head in a race from the South end of Night City to the North end of the city.\n";
    cout << "Without further ado, lets make some noise and get racing!\n\n";

    //Race Variables - used throughout the game.
    string start = "";
    string trashCan = "";
    string crowdStreet = "";
    string bridgeCollapse = "";
    string speedUp = "";

    // Ending Options - win or lose.
    string winChoice = "";
    string lostChoice = "";

    // Race Start Scenario
    cout << "Racers, ready your engines!\n";
engine: // Anchor point to be able to come back to this point. Used multiple anchor points throughout code.
    cout << "\nTo ready your engine, type start.\n\n";
    cin >> start; // User input.
    
    if (start == "start" || start == "Start") { // First "if" statement. Basically if the player types "start" or "Start", the game continues. 
        cout << "\nGood work!\n";
        goto begin;
    }
    else { // Otherwise, it will go back to engine anchor until the player types start.
        cout << "\nNot quite. Try typing start.\n";
        goto engine;
    }
begin: // Another anchor point.
    cout << "\n3...2...1...GO!\n";

    // Engine Stall Scenario
    cout << "Both racers slam on the gas and their cars shoot out from the starting line. All is going well until... your car stalls!\n\n";
    cout << "Quick! Type start to restart your engine!\n\n";
    cin >> start; // User input.
    if (start == "start" || start == "Start") { // If player types start, game continues and player loses 10% speed.
        cout << "\nGreat work! We can get back to racing. You only lost 10% speed. You now have " << speed - 10 << "% speed.\n";
        goto engineStallContinue;
    }
    else { // Otherwise, player misspells or doesn't type speed. Game still continues but instead player loses 25% speed.
        cout << "\nOh no! You didn't type start. You were able to start your car, but you lost 25% of your speed! You now have " << speed - 25 << "% speed.\n";
        goto engineStallContinue;
    }

engineStallContinue: // Another anchor point.

    // Trash Can Scenario
    cout << "\nAfter some time racing through downtown Night City, you catch back up with " << rival << ".\n";
    cout << "But as soon as you are neck-and-neck with " << rival << ", they drive through some trash cans knocking them all into your path.\n";
    cout << "You see a shortcut down an alley, but its risky as you cannot see where it will take you.\n";
    cout << "\nDo you take the shortcut and try and speed up, or do you drive straight through the trash cans?\n";
    cout << "Type shortcut to take the shortcut. Type straight to drive over the trash cans.\n\n";
    cin >> trashCan; // User input.
    if (trashCan == "shortcut" || trashCan == "Shortcut") { // If player types shortcut, then player speeds up 10% and game continues.
        cout << "\nYou took the shortcut. Down the alley you drove and to your surprise, it sped you up! You come out right next to " << rival << ". You now have " << speed + 10 << "% speed.\n";
        goto trashCanContinue;
    }
    if (trashCan == "straight" || trashCan == "Straight") { // If player types straight, player doesn't lose or gain any speed and game continues.
        cout << "\nYou went straight through the trash cans. You wind up slightly behind " << rival << ". You didn't lose any speed, but you didn't gain any either. You now have " << speed - 10 << " % speed.\n";
        goto trashCanContinue;
    }
    else { // Otherwise, if player mistypes or doesn't type out either option, player loses.
        cout << "\nIt looks like you didn't go anywhere. You wound up sitting in your car doing nothing. You forfiet your title as Champion to " << rival << ".\n";
        goto endingLost;
    }

trashCanContinue: // Another anchor point.

    // Crowded Street Scenario
    cout << "\nEntering uptown Night City, it seems to be busier than expected. " << rival << " takes a sharp right and turns down an alley way to get around all of the street vendors.\n";
    cout << "You, however, do not see any other alley ways to drive down and have two options to move forward, but make them quick as you are falling behind!\n";
    cout << "\nYou can either drive through the crowded streets and hope to make it out without crashing, or you can take the highway and hope it doesn't lead you astray. Which do you choose?\n";
    cout << "Type street to take the crowded streets or type highway to jump on the I-10.\n\n";
    cin >> crowdStreet; // User input.
    if (crowdStreet == "street" || crowdStreet == "Street") { // If player types street, player loses 35% speed and game continues.
        cout << "\nYou decide to take your chances on the crowded streets. You weave your way in and out of street vendors but luckily did not crash into any of them.\n";
        cout << "Because you took your time to not crash into any of the street vendors, you lost a lot of speed. You now have " << speed - 35 << "% speed.\n";
        goto crowdStreetContinue;
    }
    if (crowdStreet == "highway" || crowdStreet == "Highway") { // If player types highway, player gains 15% speed and game continues.
        cout << "\nYou jump on the I-10 and race through the empty freeway. You aren't getting slowed down by anyone and by only luck you see an exit that will take you to North Night City.\n";
        cout << "You've gained some speed and should now right behind " << rival << ". You now have " << speed + 15 << "% speed.\n";
        goto crowdStreetContinue;
    }
    else { // Otherwise, if player mistypes or doesn't type out either option, player loses.
        cout << "\nIt looks like you didn't go anywhere. You wound up sitting in your car doing nothing. You forfiet your title as Champion to " << rival << ".\n";
        goto endingLost;
    }

crowdStreetContinue: // Another anchor point.

    // Broken Bridge Scenario
    cout << "\nYou are nearing the North end of Night City - and with that, the finish line.\n";
    cout << "You see " << rival << " take the only bridge that goes from uptown Night City to the North end.\n";
    cout << "As you race up behind them, the bridge cables snap and you slam on your brakes to avoid driving into the river below.\n";
    cout << "As you watch " << rival << " drive off, nearing closer to the finish line every second, you feel as if all hope is lost.\n\n";
    cout << "Just as you put your car into reverse and begin to drive back to the South end, you see a ramp pointing towards the other side of the river.\n";
    cout << "It looks like your only chance to make it to the North end is to jump the river using this ramp.\n";
    cout << "You need to make a decision now or you won't have enough time to make up all of your lost speed.\n";
finalChoice: // Anchor point for finalChoice.
    cout << "\nDo you decide to take the ramp and risk everything to keep your title as Champion, or do you give up now and drive back home, forfeiting your title as Champion Racer of Night City?\n";
    cout << "Type ramp to jump the river and have a chance to win the race or type home to drive back home, winning nothing.\n\n";
    cin >> bridgeCollapse; // User input.
    if (bridgeCollapse == "ramp" || bridgeCollapse == "Ramp") { // If player types ramp, game continues and player gains 50% speed.
        cout << "\nYou turn your car towards the ramp. Crossing your fingers that you'll make it. You put your foot on the gas and gun it towards the ramp.\n";
        cout << "As your car drives up and off the ramp, you feel weightless as you and your car soar through the air.\n";
        cout << "You feel your stomach churn as your car falls to the ground. As if it was by fate, your car hits the sand on the bank of the river.\n";
        cout << "You made it across the river in one piece! You waste no time celebrating and continue speeding onto the street towards the finish line.\n";
        cout << "The jump across the river gave you a big boost in speed! You now have " << speed + 50 << "% speed!\n";
        goto brokenBridgeContinue;
    }
    if (bridgeCollapse == "home" || bridgeCollapse == "Home") { // If player types home, game ends and player loses.
        cout << "\nYou decide to cut your losses and turn towards home. Defeated, you know you'll be able to try again next time. At least you'll live another day.\n";
        goto endingLost;
    }
    else { // Otherwise, if player mistypes or doesn't type out either option, go back to start of choice.
        cout << "\nYou didn't make a decision, try again.\n";
        goto finalChoice;
    }

brokenBridgeContinue: // Another anchor point.

    //Race to the Finish Line
    /*
        I wanted to use while or possibly switches for this, don't know what would've been the best option. 
        I also wanted to be able to use the speed variable but everything I tried kept erroring out. Only way to make the ending part possible was with if and else.

        The idea is that the player would have to keep typing out speed in order to increase their speed. If they mistyped or didn't type out speed their speed would either decrease until 
        they had 0% speed and lost or if they typed speed until they got 250% speed, then they passed the rival and won. 
    */
    cout << "\nYour speed boost from the river jump was just enough to get you neck-and-neck with " << rival << ".\n";
    cout << "You both see the finish line in sight. It's less than a mile away. If you want to win, you need to speed up!\n";

finishLine: // Another anchor point.
    cout << "\nType speed to speed up!\n\n";
    cin >> speedUp; // User input.
    if (speedUp == "speed" || speedUp == "Speed") { // If player types speed, they speed up and game continues.
        cout << "\nGreat, keep speeding up!";
        goto speedUpNext;
    }
    else { // Otherwise, if they mistype or do not type speed, they have to try again and are sent back to finishLine anchor. 
        cout << "\nOh no, you missed speeding up. Try again.";
            goto finishLine;
    }

speedUpNext: // Another anchor point.
    cout << "\nType speed to speed up!\n\n";
    cin >> speedUp; // User input.
    if (speedUp == "speed" || speedUp == "Speed") { // If player types speed, they speed up and game continues.
        cout << "\nGood job, keep speeding up! You're almost there.";
        goto speedUpFinal;
    }
    else {
        cout << "\nOh no, you missed speeding up. Try again.";
        goto speedUpNext;
    }

speedUpFinal: // Another anchor point.
    cout << "\nOne last time, type speed to speed up!\n\n";
    cin >> speedUp; // User input.
    if (speedUp == "speed" || speedUp == "Speed") { // If player types speed, they speed up and win the game.
        cout << "\nExcellent! You should be past " << rival <<" now!\n";
        goto endingWin;
    }
    else { // Otherwise, if they mistype or do not type speed, they lose the game and must try again. 
        cout << "\nOh no, you missed speeding up!\n";
        cout << rival << " is still ahead of you. They reached the finish line before you and claimed the title as Champion Racer of Night City.\n";
        goto endingLost;
    }

    //Endings

    // Ending Win - You Win
endingWin: // Another anchor point.
    cout << "\nWith enough speed, you passed " << rival << " and made it through the finish line first! You kept your title as Champion Racer of Night City!\n";
    cout << "\nYou Won! Type restart to restart the game and try again to see different outcomes. Type quit to quit playing.\n\n";
    cin >> winChoice; // User input.
    if (winChoice == "restart" || winChoice == "Restart") { // Player won. If they type restart, game restarts.
        goto gameStart;
    }
    if (winChoice == "quit" || winChoice == "Quit") { //  If they type quit, game closes out.
        return 0;
    }

    // Ending Lost - You Lose
endingLost: // Another anchor point.
    cout << "\nYou lost! Type restart to restart the game and get another chance to keep your title as Champion! Type quit to quit playing.\n\n";
    cin >> lostChoice; // User input.
    if (lostChoice == "restart" || lostChoice == "Restart") { // Player lost. If they type restart, game restarts. 
        goto gameStart;
    }
    if (lostChoice == "quit" || lostChoice == "Quit") { // If they type quit, game closes out.
        return 0;
    }
}