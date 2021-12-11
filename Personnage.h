#ifndef CLASS_PERSONNAGE
#define CLASS_PERSONNAGE

#include "game.h"
 
class Personnage { 
	  private :
      uint8_t attackValue, defenseValue;
      int8_t healthPoints ; 
      char name[MAX_NAME_LENGTH];;
      
    public :
      Personnage();             // Déclaration du constructeur de la classe Personnage sans paramètre
      Personnage(uint8_t newAttack, uint8_t newDefense, int8_t hp, char newName[MAX_NAME_LENGTH]); // Constructeur de la classe Personnage
	    
      // manipulateurs des attributs
      void setAttack(uint8_t newAttack)   { this->attackValue = newAttack ;  };  // Le manipulateur de attack 
	    void setDefense(uint8_t newDefense) { this->defenseValue = newDefense ; }; // Le manipulateur de defense
      void setHealtPoints(int8_t newHP)  { this->healthPoints = newHP ; };      // Le manipulateur de healthPoints
      void setName(char newName[MAX_NAME_LENGTH]) { strncpy(this->name,newName,MAX_NAME_LENGTH) ; };                    // Le manipulateur de name
	    
      // accesseurs des attributs
      uint8_t getAttack() const { return attackValue;} ;            // L’assesseur de l’attribut attack
      uint8_t getDefense() const { return defenseValue;};           // L’assesseur de l’attribut defense
      int8_t getHealtPoints() const { return healthPoints;};       // L’assesseur de l’attribut healthPoints
      char* getName() { return name;};                      // L'assesseur de l'attribut name

      // méthodes de la classe
      void attack(Personnage &cible);
      void  receiveDamages(uint8_t damages);
      bool  isAlive() const;
};

#endif
