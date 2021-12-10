#include <Gamebuino-Meta.h>
#include "game.h"
#include "Personnage.h"

Personnage hero1, hero2;      // On créait 2 instances de la classe Personnage
GameInfo game;
uint8_t tour;

void setup() {
  // initialiser la gamebuino
  gb.begin();
  hero1.setName("Superman");
  hero2.setName("METAman");
  game.gameStatus = TITLESCREEN;
}

void loop() {
  if(gb.update()){
      
      switch ( game.gameStatus ) {
         //#################################### 
         case TITLESCREEN:
              gb.display.clear();
              gb.display.setCursor(1, 10);
              // gb.display.setColor(YELLOW);
              gb.display.println("  APPUYEZ SUR  <A>");
              gb.display.println("   POUR COMMENCER");
              if(gb.buttons.pressed(BUTTON_A)){
                  tour = 0;
                  game.gameStatus=ROUND;
              }
         break; 

         //#################################### 
         case ROUND:
              gb.display.clear();
              tour++;
              gb.display.setCursor(1, 1);
              // gb.display.setColor(YELLOW);
              gb.display.print("**** TOUR ");
              gb.display.print(tour); 
              gb.display.println(" ****");
              gb.display.println(" ");
              hero1.attack(hero2);
              if (hero2.isAlive()) {
                 gb.display.println(" ");
                 gb.display.print("Il reste ");
                 gb.display.print(hero2.getHealtPoints());
                 gb.display.print(" points de vie a ");
                 gb.display.print(hero2.getName());
                 delay(TimeBeforeNextScreen);                 
                 gb.display.clear();
                 gb.display.setCursor(1, 1);
                 // gb.display.setColor(YELLOW);
                 gb.display.print("**** TOUR ");
                 gb.display.print(tour); 
                 gb.display.println(" ****");
                 gb.display.println(" ");
                 hero2.attack(hero1);
                 if (!hero1.isAlive()) {
                    delay(TimeBeforeNextScreen);
                    gb.display.clear();
                    gb.display.setCursor(1, 1);
                    gb.display.print("**** TOUR ");
                    gb.display.print(tour); 
                    gb.display.println(" ****");
                    gb.display.println(" ");
                    gb.display.print(hero1.getName());
                    gb.display.println(" est mort !");
                    gb.display.println(" ");
                    game.gameStatus=GAMEOVER;
                    gb.display.println("  APPUYEZ SUR  <A>");
                    gb.display.println("   POUR COMMENCER");
                 } else {
                    gb.display.println(" ");
                    gb.display.print("Il reste ");
                    gb.display.print(hero1.getHealtPoints());
                    gb.display.print(" points de vie a ");
                    gb.display.print(hero1.getName());
                    delay(TimeBeforeNextScreen);
                 }
              } else {
                 delay(TimeBeforeNextScreen);
                 gb.display.clear();
                 gb.display.setCursor(1, 1);
                 gb.display.print("**** TOUR ");
                 gb.display.print(tour); 
                 gb.display.println(" ****");
                 gb.display.println(" ");
                 gb.display.print(hero2.getName());
                 gb.display.println(" est mort !");
                 gb.display.println(" ");
                 game.gameStatus=GAMEOVER;
                 gb.display.println("  APPUYEZ SUR  <A>");
                 gb.display.println("   POUR COMMENCER");
              }

         break; 

         //#################################### 
         case GAMEOVER:
              if(gb.buttons.pressed(BUTTON_A)){
                  tour = 0;
                  hero1.setHealtPoints(Nb_HealthPoints);
                  hero2.setHealtPoints(Nb_HealthPoints);
                  game.gameStatus=ROUND;
              }
         break; 
      } 
   } 
}
