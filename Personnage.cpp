#include <Gamebuino-Meta.h>
#include "Personnage.h"
#include "game.h"

// Définition du constructeur de la classe Personnage sans paramètre
Personnage::Personnage() {
    this->attackValue = 17;
    this->defenseValue = 12;
    this->healthPoints = NB_HEALTHPOINTS;
    strncpy(this->name,"Undefined",MAX_NAME_LENGTH);
};

/*
// Définition du constructeur de la classe Personnage avec 4 paramètres */
Personnage::Personnage(uint8_t newAttack, uint8_t newDefense, int8_t hp, char newName[MAX_NAME_LENGTH]) {
    // Le constructeur doit initialiser tous les attributs de la classe
    this->attackValue = newAttack;
    this->defenseValue = newDefense;
    this->healthPoints = hp;
    strncpy(this->name,newName,MAX_NAME_LENGTH);
};
/* ------------------------------------------------------------------------ */

void Personnage::receiveDamages(uint8_t damages){
    this->healthPoints -= damages;
    if (this->healthPoints < 0) this->healthPoints = 0;
};
    
// méthodes de la classe
void Personnage::attack(Personnage &cible){
    uint8_t attackDices, defenseDices;
    int8_t result;
    char message[128];

    attackDices = this->attackValue + random(1,6);
    attackDices = attackDices + random(1,6);
    attackDices = attackDices + random(1,6);

    defenseDices = this->attackValue + random(1,6);
    defenseDices = defenseDices + random(1,6);
    defenseDices = defenseDices + random(1,6);

    result = attackDices - defenseDices;

    if (result > 0) {
          cible.receiveDamages(result);
          sprintf(message, "%s blesse pour %d points de vie", this->name, result);
    } else {
          sprintf(message, "%s a esquive l'attaque", cible.name );
    }
    gb.display.println(message);
};

bool Personnage::isAlive() const{
    if (this->healthPoints > 0) return true; else return false;
};
