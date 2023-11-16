#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "AllBlocks.h"
#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  
  std::vector<Block> get_all_blocks();
  void Draw();
  bool window_isOpen();
  bool window_poll_event(sf::Event& event);
  void close_window();
  void clear_window();
  void display_window();
  void input_handler();
  void move_block_left();
  void move_block_right();
  void move_block_down();
  void display_text(const std::string& txt, int char_size, int posX, int posY);
  void draw_rounded_rectangle(sf::ConvexShape& shape,float x, float y, float rectHeight, float rectWidth, float radius, float point, const sf::Color& color);
  void display_score();
  bool get_game_isover_status();
  Block get_random_block();
  int get_score() const;

private:
  Grid grid;
  std::vector<Block> m_blocks;
  Block m_current_block;
  Block m_next_block;
  sf::RenderWindow m_window;
  sf::RectangleShape rect;
  sf::Text text;
  sf::Text game_score;
  int m_score = 0;
  bool move_left_pressed;
  bool move_right_pressed;
  bool move_down_pressed;
  bool move_round;
  bool game_is_over;
  bool is_block_outside();
  void rotate_block();
  void lock_blocks();
  bool block_fits();
  void reset_game();
};

#endif
