//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

Player::Player(const char _name[], int _health, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed, true, _experience) {
    level = 1;
    //experience = 0;
}

void Player::doAttack(Character *target) {
    target->takeDamage(attack);
}

void Player::takeDamage(int damage) {
    int trueDamage = damage - defense;

    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;

    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
}

void Player::saveToFile() {
    ofstream file("player.txt");
    if (file.is_open()) {
        file << name << endl;
        file << health << endl;
        file << attack << endl;
        file << defense << endl;
        file << speed << endl;
        file << level << endl;
        file.close();
        cout << "Game saved" << endl;
    } else {
        cerr << "Unable to save game" << endl;
    }
}

void Player::loadFromFile() {
    ifstream file("player.txt");
    if (file.is_open()) {
        file.getline(name, 50);
        file >> health >> attack >> defense >> speed;
        file.close();
        cout << "Game loaded" << endl;
    } else {
        cerr << "Unable to load game" << endl;
    }
}

void Player::displayStats() {
    cout << "Name: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Speed: " << speed << endl;
    cout << "Level: " << level << endl;
}

void Player::levelUp() {
    level++;
    //int experiencia2 = 10;
    //experience -= experiencia2;

    health += 5;
    attack += 5;
    defense += 5;
    speed += 5;

    cout << name << " ha subido de nivel " << level << "!" << endl;
    cout << "Nivel de experiencia: " << experience << endl;

   // if (experience >= experiencia2){
   //     cout << "Tienes experiencia para subir de nivel" <<endl;
   //     levelUp();
    //}

}

void Player::gainExperience(int exp) {
    //int experiencia2 = 10;
    //experience = getExperience();
    //cout << "experience" << getExperience() << endl;
    experience += exp;
    cout << "experience + enemy " << experience << endl;
    while (experience >= 100) {
        levelUp();
        experience -= 100;
        cout << "experience after level up " << experience << endl;
    }
}

Character* Player::selectTarget(vector<Enemy*> possibleTargets) {
    int selectedTarget = 0;
    cout << "Select a target: " << endl;
    for (int i = 0; i < possibleTargets.size(); i++) {
        cout << i << ". " << possibleTargets[i]->getName() << endl;
    }

    //TODO: Add input validation
    cin >> selectedTarget;
    return possibleTargets[selectedTarget];
}

Action Player::takeAction(vector<Enemy*> enemies) {
    int action = 0;
    int defending = 0;
    cout << "Select an action: " << endl
         << "1. Attack" << endl;
    cout << "2. Defend" << endl;
    cout << "3. Save file " << endl;

    //TODO: Validate input
    cin >> action;
    Action currentAction;
    Character* target = nullptr;

    switch(action) {
        case 1:
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target](){
                doAttack(target);
            };
            currentAction.speed = getSpeed();
            break;

        case 2:
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target](){
                doDefense();
            };
            currentAction.speed = getSpeed();
            break;
        default:
            cout << "Invalid action" << endl;
            break;

        case 3:
            saveToFile();
            return takeAction(enemies);
            break;

    }

    return currentAction;
}