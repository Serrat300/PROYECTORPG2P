#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"


int main() {
    Player *player = new Player("Victor", 5, 10, 10, 3, 99);
    Enemy *enemy = new Enemy("Goblin", 15, 6, 2, 5, 22);
    Enemy *enemy2 = new Enemy("Orc", 15, 6, 2, 5, 300);



    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete combat;
    return 0;
}
