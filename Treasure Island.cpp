#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool win;

// ASCII art for the game title
void printTitle() {
cout<<"_________ _______  _______  _______  _______           _______  _______   _________ _______  _        _______  _        ______" << endl;  
cout<<"\\__   __/(  ____ )(  ____ \\(  ___  )(  ____ \\|\\     /|(  ____ )(  ____ \\  \\__   __/(  ____ \\( \\      (  ___  )( (    /|(  __  \\"<<endl;
cout<<"   ) (   | (    )|| (    \\/| (   ) || (    \\/| )   ( || (    )|| (    \\/     ) (   | (    \\/| (      | (   ) ||  \\  ( || (  \\  )"<<endl;
cout<<"   | |   | (____)|| (__    | (___) || (_____ | |   | || (____)|| (__         | |   | (_____ | |      | (___) ||   \\ | || |   ) |"<<endl;
cout<<"   | |   |     __)|  __)   |  ___  |(_____  )| |   | ||     __)|  __)        | |   (_____  )| |      |  ___  || (\\ \\) || |   | |"<<endl;
cout<<"   | |   | (\\ (   | (      | (   ) |      ) || |   | || (\\ (   | (           | |         ) || |      | (   ) || | \\   || |   ) |"<<endl;
cout<<"   | |   | ) \\ \\__| (____/\\| )   ( |/\\____) || (___) || ) \\ \\__| (____/\\  ___) (___/\\____) || (____/\\| )   ( || )  \\  || (__/  )"<<endl;
cout<<"   )_(   |/   \\__/(_______/|/     \\|\\_______)(_______)|/   \\__/(_______/  \\_______/\\_______)(_______/|/     \\||/    )_)(______/"<<endl << endl;
                                                                                                                                
}

// Class representing a player
class Player {
private:
    string name;
    int score;

public:
    Player(string playerName) {
        name = playerName;
        score = 0;
    }

    string getName() {
        return name;
    }

    int getScore() {
        return score;
    }

    void addToScore(int points) {
        score += points;
    }
};

// Class representing a game-within-a-game
class MiniGame {
public:
    
    void play() {
        
        int randomNumber = rand() % 3 + 1;
        cout << "Quick! Pick the correct amount of poisonous compounds to mix between 1 and 3 to correctly make your potion to use on the dragon: ";
        int guess;
        cin >> guess;

        if (guess == randomNumber) {
            cout << "You guessed the correct number!" << endl;
            win = true;
        } else {
            cout << "Yikes! Wrong guess. The secret number was: " << randomNumber << endl;
            win = false;
        }
    }
};

// Function to display the player's score
void displayScore(Player player) {
    cout << "Score: " << player.getScore() << " ⭐" << endl;
}

// Function representing a game location
void exploreIsland(Player& player) {
    cout << "You stand at the entrance of a mystical jungle, exorting reeking smells of unfamiliar herbs." << endl;
    cout << "In front of you, there are two paths. Which one do you choose?" << endl;
    cout << "1. Serpent's Passage 🐍" << endl;
    cout << "2. Monkey's Maze 🐵" << endl;
    int choice;
    cin >> choice;
    cout << " ------------------------------------------------------------------------------------ \n";
    if (choice == 1) {
        cout << "You chose the Serpent's Passage. \n" ;
        cout << "\"Hopefully I still have that anti-snake chemical I made in the plane.\""  << endl;
        cout << "+10" << endl;
        player.addToScore(10);
        displayScore(player);
    } else if (choice == 2) {
        cout << "You chose the Monkey Maze. \n";
        cout << "\"Anything BUT snakes.\"" << endl;
        cout << "+10" << endl;
        player.addToScore(10);
        displayScore(player);
    } else {
        cout << "Invalid choice. Try again." << endl;
        exploreIsland(player);
        return;
    }

    cout << "As you walk deeper into the island, you encounter a river blocking your path." << endl;
    cout << "You need to cross it to continue. What do you do?" << endl;
    cout << "1. Build a raft ⛵" << endl;
    cout << "2. Look for a bridge 🌉" << endl;
    cout << "3. Swim across 🏊" << endl;
    cin >> choice;
    cout << " ------------------------------------------------------------------------------------ \n";
    if (choice == 1) {
        cout << "You build a sturdy raft and successfully cross the river." << endl;
        cout << "+15" << endl;
        player.addToScore(15);
        displayScore(player);
    } else if (choice == 2) {
        cout << "You find a hidden bridge and safely cross the river." << endl;
        cout << "+10" << endl;
        player.addToScore(10);
        displayScore(player);
    } else if (choice == 3) {
        cout << "You attempt to swim across the river but get swept away by the strong current." << endl;
        cout << "You wake up later, bruised and farther from your goal." << endl;
        cout << "-5" << endl;
        player.addToScore(-5);
        displayScore(player);
    } else {
        cout << "Invalid choice. Try again." << endl;
        exploreIsland(player);
        return;
    }

    cout << "You have reached a clearing in the island." << endl;
    cout << "You see a small hut and a cave entrance. Which one do you explore?" << endl;
    cout << "1. Tiki Hut 🗿" << endl;
    cout << "2. Dragon's Cave 🐉" << endl;
    cin >> choice;
    cout << " ------------------------------------------------------------------------------------ \n";
    if (choice == 1) {
        cout << "You enter the hut and find a friendly old man who offers you a potion." << endl;
        cout << "You feel empowered and gain extra strength." << endl;
        cout << "+20" << endl;
        player.addToScore(20);
        displayScore(player);
    } else if (choice == 2) {
        cout << "You enter the dark cave and encounter a huge fire-breathing dragon! Think fast!" << endl;
        cout << "1. Use your flare gun for help 🔫" << endl;
        cout << "2. Use your chemicals to make a damaging potion 🧪" << endl;
        cin >> choice;
        while (choice == 1){
            cout << "\"The flare gun won't work, I'm inside of a cave!\"" << endl;
            cout << "1. Use your flare gun for help 🔫" << endl;
            cout << "2. Use your chemicals to make a damaging potion 🧪" << endl;
            cin >> choice;
        }
        if (choice == 2){
        bool win;
        MiniGame dragonGame;
        dragonGame.play();
  
        if (win==true) {
            cout << "You defeated the dragon and found the exit to the cave." << endl;
            cout << "+50" << endl;
            player.addToScore(50);
          displayScore(player);
        } else if(win==false) {
            cout << "The dragon overwhelms you, and you flee as fast as you can." << endl;
          cout << "-5" << endl;
            player.addToScore(-5);
          displayScore(player);
        }
    }
        }
    else {
        cout << "Invalid choice. Try again." << endl;
        exploreIsland(player);
        return;
    }
    cout << " ------------------------------------------------------------------------------------ \n";
    cout << "Leaving the cave, you stumble upon an enchanted waterfall." << endl;
    cout << "The waterfall appears to have a sensational aura. What do you do?" << endl;
    cout << "1. Drink from the waterfall 🥤" << endl;
    cout << "2. Take a closer look 👀" << endl;
    cout << "3. Ignore and move on 🙄" << endl;
    cin >> choice;
    cout << " ------------------------------------------------------------------------------------ \n";
    if (choice == 1) {
        cout << "You take a sip from the waterfall and feel extremely replenished. Almost a bit TOO replenished. What was in that water?" << endl;
        cout << "+10" << endl;
        player.addToScore(10);
      displayScore(player);
    } else if (choice == 2) {
        cout << "You take a closer look at the waterfall and notice a hidden message carved on a stone." << endl;
        cout << "The message reads: 'Follow the eastern path to reach the treasure.'" << endl;
        cout << "+100" << endl;
        player.addToScore(100);
      displayScore(player);
    } else if (choice == 3) {
        cout << "You decide to ignore the waterfall and continue your journey." << endl;
    } else {
        cout << "Invalid choice. Try again." << endl;
        exploreIsland(player);
        return;
    }
    cout << " ------------------------------------------------------------------------------------ \n";
    cout << "You come across a division in the path." << endl;
    cout << "To the east, you see a narrow trail. To the west, there is a dense amount of bushes." << endl;
    cout << "Which path do you choose?" << endl;
    cout << "1. East" << endl;
    cout << "2. West" << endl;
    cin >> choice;
    cout << " ------------------------------------------------------------------------------------ \n";
    if (choice == 1) {
        cout << "You follow the narrow trail to the east." << endl;
        cout << "+15" << endl;
        player.addToScore(15);
        displayScore(player);
            cout << " ------------------------------------------------------------------------------------ \n";
    cout << "After a long journey, you reach the heart of the island." << endl;
    cout << "You find an ancient tree with a keyhole. This must be the final step." << endl;
    cout << "You reach into your pocket and find a key. It fits perfectly." << endl;
    cout << "As you turn the key, the tree opens to reveal the hidden treasure!" << endl;
    cout << "Congratulations, " << player.getName() << "! You have found the legendary treasure!" << endl;
    cout << "\"Should I flare out for the others, or should I keep the treasure for myself...?\"" << endl;
    cout << "1. Shoot your flare gun 🔫" << endl;
    cout << "2. Keep the treasure and use the escape raft 💰" << endl;
      cin >> choice;
      cout << " ------------------------------------------------------------------------------------ \n";
      if (choice == 1){
        cout << "You shoot your flare gun in the air to alert your team of the treasure you found." << endl;
        cout << "\"" << player.getName() << "! Looks like you found some treasure! Lucky for you, I grouped up with everyone else and look! We also found a gold mine! We'll split it up amongst ourselves and use the escape raft to get back home together. Good work doc.\"" << endl;
        cout << "+1000" << endl;
        player.addToScore(1000); 
    
      }
      else if(choice ==2){
        cout << "You hurry to the escape raft with whatever amount of the treasure you could grab. Suddenly, you hear a loud yell..." << endl;
        cout << "\"HEY! WHAT'RE YOU DOING?! YOU TRAITOR!\"" << endl;
        cout << " ------------------------------------------------------------------------------------ \n";
        cout << "The team that trusted you with their lives take you as their captive. Once you get back to the village, the king decides:" << endl;
        cout << "\"Off with the head of " << player.getName() << "!\"" << endl;
        
      }
    } else if (choice == 2) {
        cout << "You push through the dense bushes on the west side." << endl;
        cout << "+10" << endl;
        player.addToScore(10);
        displayScore(player);
            cout << " ------------------------------------------------------------------------------------ \n";
            cout << " \"WATCH OUT!\"\n";
            cout << "But it is too late. You fall into a deep pit trap that was covered by leaves. Maybe you should've looked closer at that waterfall...\n";
        
    } 
    else {
        cout << "Invalid choice. Try again." << endl;
        exploreIsland(player);
        return;
    }

}

int main() {
    srand(time(0)); // Seed the random number generator

    printTitle();

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    Player player(playerName);

    cout << "Welcome, to Treasure Island, " << player.getName() << "!" << endl; 
    cout << "\"You might not remember what happened after the crash, but we were on a mission to find the ancient treasure hidden on this island. "; 
    cout << "We composed a team of high skilled individuals with different backgrounds, with you being our chemist. Here, take this healing potion you made and let's split up to find the treasure. ";
    cout << "Shoot your flare gun in the air if you need me.\"" << endl;
    cout << " ------------------------------------------------------------------------------------ \n";
    exploreIsland(player);

    cout << "Game Over" << endl;
    displayScore(player);

    return 0;
}