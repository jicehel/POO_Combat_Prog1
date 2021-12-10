#include <Gamebuino-Meta.h>
#include "Personnage.h"
#include "game.h"

// Définition du constructeur de la classe Personnage sans paramètre
Personnage::Personnage() {
    this->attackValue = 17;
    this->defenseValue = 12;
    this->healthPoints = Nb_HealthPoints;
    this->name = "Undefined";
};

/*
// Définition du constructeur de la classe Personnage avec 4 paramètres */
Personnage::Personnage(uint8_t newAttack, uint8_t newDefense, int8_t hp, char* newName) {
    // Le constructeur doit initialiser tous les attributs de la classe
    this->attackValue = newAttack;
    this->defenseValue = newDefense;
    this->healthPoints = hp;
    this->name = newName;
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
          strcpy (message,cible.name);
          strcat (message," a esquive l'attaque");
    }
    gb.display.println(message);
};

bool Personnage::isAlive() const{
    if (this->healthPoints > 0) return true; else return false;
};
