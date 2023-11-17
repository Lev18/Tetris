#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../include/Game.h"
#include "../include/Colors.h"
#include <iostream>

namespace ColisCntrl {
  // speeds of collision
  const double LOW_SPEED = 0.6;
  const double MID_SPEED_1 = 0.4;
  const double MID_SPEED_2 = 0.2;
  const double HIGH_SPEED = 0.1;
  double updated_time = 0;

  // contorl speed of colision
  bool EventTrigger(const double interval, const sf::Clock& clock) {
    sf::Time elaps_time = clock.getElapsedTime();
    double current_time = elaps_time.asSeconds();
    
     //if elapsed time is greater or equalinterval update time
     if ( current_time - updated_time >= interval) {
       updated_time = current_time;
       return true;
     }
   return false;
  }

  void MoveBlockDown(Game& game, const double speed, sf::Clock& clock) {
     if (ColisCntrl::EventTrigger(speed, clock)) {
         game.move_block_down();
      }
  }
}

int main() {
  // creating game controled object for starting game
 Game game;
 sf::Music music;
 music.openFromFile("../music/zoekk-cbla4.wav");
 music.setVolume(70);
 music.setPitch(0.7f);
 music.setLoop(true);
 music.play();
 
 // creating clock for colision control
 sf::Clock clock;
 const float POINT = 6;
 // for UI... creating new rounded shape
 sf::ConvexShape shape(4 * POINT);
 
 // we are using sf::RenderWindow to create game window
 // is was encapsulatetin Game class
  while (game.window_isOpen()) {
    sf::Event event;
    while (game.window_poll_event(event)) {
      if (event.type == sf::Event::Closed) {
       game.close_window();
      }
    }

    // call input_handler function for controlling block state 
    game.input_handler();
    if (game.get_score() > 4000) {
      ColisCntrl::MoveBlockDown(game, ColisCntrl::HIGH_SPEED, clock);
      music.setPitch(1.2f);
    }
    else  if (game.get_score() > 2000 && game.get_score() <= 4000 ) {
      ColisCntrl::MoveBlockDown(game, ColisCntrl::MID_SPEED_2, clock);
      music.setPitch(1.1f);
    }
    else if (game.get_score() < 2000 && game.get_score() > 500) {
       ColisCntrl::MoveBlockDown(game, ColisCntrl::MID_SPEED_1, clock);
       music.setPitch(0.9);
    } 
    else {
      ColisCntrl::MoveBlockDown(game, ColisCntrl::LOW_SPEED, clock);
    }

    // freshing window state 
    game.clear_window();
    // score shape
    game.draw_rounded_rectangle(shape, 360, 65, 55, 75, 17.f, 6, lightBlue);
    // next block shape 
    game.draw_rounded_rectangle(shape, 340, 250, 130, 145, 17.f, 6, lightBlue);
    // game over shape 
    game.draw_rounded_rectangle(shape, 319, 450, 115, 172, 17.f, 6, lightBlue);

    // Drawing game grid 
    game.Draw();

    game.display_text("Score", 24, 360, 15);
    game.display_score();

    if (game.get_game_isover_status()) {    
      game.display_text("Game over", 32, 319, 450); 
      music.stop();
    }
    game.display_window();
    }
  std::cout << "hello" ;
}
