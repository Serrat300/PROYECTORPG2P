#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    Player *player = new Player("Link", 100, 8, 3, 10);
    Enemy *enemy = new Enemy("Bokoblin", 50, 5, 2, 5, 10);

    cout << player->toString() << endl;
    cout << enemy->toString() << endl;

    cout << "=====================" << endl;

    int round=1;

    while(player->getHealth() > 0 && enemy->getHealth() > 0){

        cout << "Round " << round++ << endl;

        player->doAttack(enemy);
        cout << player->getName() << ": Con su espada logro lastimarlo " << endl;
        cout << "Salud de " << enemy->getName() << ": " << enemy->getHealth() << endl;
        cout << "Defensa de " << enemy->getName() << ": " << enemy->getDefense() << endl;

        enemy->doAttack(player);
        cout << enemy->getName() << ": Con su machete logro lastimarlo " << endl;
        cout << "Salud de " << player->getName() << ": " << player->getHealth() << endl;
        cout << "Defensa de " << player->getName() << ": " << player->getDefense() << endl;

        cout << "=====================" << endl;

        if(player->getHealth() <= 0){
            cout << "Game over " << endl;}
        else if(enemy->getHealth() <= 0){
            cout << "You Won!! Wopeeee " << endl;}
    }

    delete player;
    delete enemy;
    return 0;
}
