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
              gb.display.printf("**** tour %d ****\n\n", tour);
              hero1.attack(hero2);
              if (hero2.isAlive()) {
                 gb.display.printf("\nIl reste %d  points de vie a %s\n\n", hero2.getHealtPoints(), hero2.getName());
                 delay(TimeBeforeNextScreen);                 
                 gb.display.clear();
                 gb.display.setCursor(1, 1);
                 gb.display.printf("**** tour %d ****\n\n", tour);
                 hero2.attack(hero1);
                 if (!hero1.isAlive()) {
                    delay(TimeBeforeNextScreen);
                    gb.display.clear();
                    gb.display.setCursor(1, 1);
                    gb.display.printf("**** tour %d ****\n\n", tour);
                    gb.display.printf("%s  est mort !\n\n", hero1.getName());
                    game.gameStatus=GAMEOVER;
                    gb.display.printf("  APPUYEZ SUR  <A>\n   POUR COMMENCER");
                 } else {
                    gb.display.printf("\nIl reste %d points de vie a %s\n\n",hero1.getHealtPoints(),hero1.getName());
                    delay(TimeBeforeNextScreen);
                 }
              } else {
                 delay(TimeBeforeNextScreen);
                 gb.display.clear();
                 gb.display.setCursor(1, 1);
                 gb.display.printf("**** tour %d ****\n\n", tour);
                 gb.display.printf("%s  est mort !\n\n", hero2.getName());
                 game.gameStatus=GAMEOVER;
                 gb.display.printf("  APPUYEZ SUR  <A>\n   POUR COMMENCER");
              }

         break; 

         //#################################### 
         case GAMEOVER:
              if(gb.buttons.pressed(BUTTON_A)){
                  tour = 0;
                  hero1.setHealtPoints(NB_HEALTHPOINTS);
                  hero2.setHealtPoints(NB_HEALTHPOINTS);
                  game.gameStatus=ROUND;
              }
         break; 
      } 
   } 
}
