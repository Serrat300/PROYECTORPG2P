//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
#include<iostream>
#include <cstring>

using namespace std;
Character::Character(const char _name[], int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _experience) {
    strcpy(name, _name);
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
    experience = _experience;

}

int Character::getExperience(){
    return experience;
}

string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getSpeed() {
    return speed;
}

void Character::doDefense() {
    int increaseAmount = defense * 0.20;
    defense += increaseAmount;
    cout << name << "'s defense increased by 20%!" << endl;
}

string Character::toString() {
    string aux = "Name: ";
    aux.append("\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed));
    return name;
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::flee(Character*target) {
    if(this->speed > target->speed)
        return true;

    int chance = rand() % 100;
    return chance > 30;
}

