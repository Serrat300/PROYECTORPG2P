//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>

using namespace std;

class Character {
protected:
    char name[50];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    int experience;
public:
    Character(const char _name[], int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _experience);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;
    virtual void gainExperience(int exp) = 0;
    void doDefense();
    //TODO: Implementar metodo de defensa
    //Incrementar la defensa un 20% solo por el turno actual

    bool flee(Character* target);
    string getName();
    int getHealth();
    int getAttack();
    bool getIsPlayer();
    int getSpeed();
    string toString();
    int getExperience();
};


#endif //RPG_CHARACTER_H