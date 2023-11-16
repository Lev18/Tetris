#include "Game.h"
#include <math.h>

Game::Game(): m_window{sf::VideoMode(500, 620), "Tetris"} {
  grid = Grid();
  m_score = 0;
  m_blocks = get_all_blocks(); 
  m_current_block = get_random_block();
  m_next_block = get_random_block();
  game_is_over = false;
  move_right_pressed = false;
  move_left_pressed = false;
  move_down_pressed = false;
  move_round = false;
}


Block Game::get_random_block() {
  if(m_blocks.empty()) {
    m_blocks = get_all_blocks();
  }

  int randInd = rand() % m_blocks.size();
  Block block = m_blocks[randInd];
  m_blocks.erase(m_blocks.begin() + randInd);

  return block;
}


std::vector<Block> Game::get_all_blocks() {
  return {LBlock(), JBlock(), IBlock(), TBlock(), OBlock(), SBlock(), ZBlock()};
}

void Game::Draw() {
  grid.Draw(m_window, 11, 11);
  m_current_block.Draw(m_window, 11, 11);
  m_next_block.Draw(m_window, 270, 270);
}

bool Game::window_isOpen() {
  return m_window.isOpen();
}


bool Game::window_poll_event(sf::Event& event) {
  return m_window.pollEvent(event);
}

void Game::close_window() {
  m_window.close();
}

void Game::clear_window() {
  m_window.clear();
}

void Game::display_window() {
  m_window.display();
}

void Game::input_handler() {
  if (game_is_over && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    game_is_over = false;
    reset_game();
  }
  // Move Right
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !move_right_pressed) {
    move_block_right();
  } 
  else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    move_right_pressed = false;
  }

  // Move Left
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !move_left_pressed) {
    move_block_left();
  } 
  else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    move_left_pressed = false;
  } 

  // Move Down
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !move_down_pressed) {
    move_block_down();
  }
  else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
      move_down_pressed = false;
  }

  // rotate_block
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !move_round || block_fits() == false) {
    rotate_block();
    move_round = true;
  }
  else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
      move_round = false;
  }
} 

void Game::move_block_left() {
  if (!game_is_over) {
    m_current_block.Move(0, -1);
   
    if (is_block_outside() || block_fits() == false) {
      m_current_block.Move(0, 1);
    }
    move_left_pressed = true;
  }
}

void Game::move_block_right() {
  if(!game_is_over) {
    m_current_block.Move(0, 1);

    if(is_block_outside() || block_fits() == false) {
      m_current_block.Move(0, -1);
    }
    move_right_pressed = true;  
  }
}

void Game::move_block_down() {
  if (!game_is_over) {
    m_current_block.Move(1, 0);
   
    if(is_block_outside() || block_fits() == false) {
      m_current_block.Move(-1, 0);
      lock_blocks();
    }
    move_down_pressed = true;    
  }
}

bool Game::is_block_outside() {
  std::vector<Position> tiles = m_current_block.get_cells_position();
  for (auto item : tiles) {
    if (grid.is_cell_outside(item.m_row, item.m_column)) {
      return true;  
    }
  }
  return false;
}

void Game::rotate_block() {
  if (!game_is_over) {
    m_current_block.Rotate();
    if (is_block_outside()) {
      m_current_block.Undo_Rotation();
    }
  }
}

void Game::lock_blocks() {
  std::vector<Position> tiles = m_current_block.get_cells_position();
  for(auto item : tiles) {
    grid.grid[item.m_row][item.m_column] = m_current_block.id;
  }
  m_current_block = m_next_block;
  if (block_fits() == false) {
    game_is_over = true;
  }
  m_next_block = get_random_block();
  int cleared_row = grid.clear_full_row(); 
  switch (cleared_row) {
    case 1:
      m_score += 100;
      break;
    case 2:
      m_score += 150;
      break;
    case 3:
      m_score += 200;
      break;
    case 4:
      m_score += 300;
      break;
    default:
      m_score += 10;
  }
  cleared_row = 0;
}

bool Game::block_fits() {
  std::vector<Position> tiles = m_current_block.get_cells_position();
  for(auto item : tiles) {
    if(grid.is_cell_empty(item.m_row, item.m_column) == false) {
      return false;
    }
  }
  return true;
}

void Game::reset_game() {
  grid.Initialize();
  m_blocks = get_all_blocks();
  m_current_block = get_random_block();
  m_next_block = get_random_block();
  m_score = 0;
}

void Game::draw_rounded_rectangle(sf::ConvexShape& rrect, float x, float y, float rectHeight, float rectWidth,
    float radius, float POINTS, const sf::Color& color) {
  float X = 0, Y = 0;
	for(int i = 0; i < POINTS; i++) {
		X += radius / POINTS;
		Y = sqrt(radius * radius - X * X);
		rrect.setPoint(i, sf::Vector2f(X + x + rectWidth-radius, y - Y + radius));
	}

	Y=0;
	for(int i = 0; i < POINTS; i++)
	{
		Y += radius / POINTS;
		X = sqrt(radius * radius - Y * Y);
		rrect.setPoint(i + POINTS, sf::Vector2f(x + rectWidth + X-radius, y + rectHeight - radius+ Y));
	}

	X=0;
	for(int i=0; i < POINTS; i++)
	{
		X += radius / POINTS;
		Y = sqrt(radius * radius - X * X);
		rrect.setPoint(i + 2 * POINTS, sf::Vector2f(x + radius - X, y + rectHeight - radius + Y));
	}

	Y=0;
	for(int i=0; i < POINTS; i++)
	{
		Y += radius / POINTS;
		X = sqrt(radius * radius - Y * Y);
		rrect.setPoint(i + 3 * POINTS , sf::Vector2f(x - X + radius, y + radius - Y));
	}
  rrect.setFillColor(color);
  m_window.draw(rrect);
}

void Game::display_text(const std::string& txt, int char_size, int posX, int posY) {
  sf::Font font;
  std::string fnt = "../Font/Oxygen-Bold.ttf";
  font.loadFromFile(fnt);
  text.setFont(font);
  text.setString(txt);
  text.setCharacterSize(char_size);
  text.setPosition(posX, posY);
  text.setFillColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold);
  m_window.draw(text);
}


void Game::display_score() {
  sf::Font font;
  std::string fnt = "../Font/Oxygen-Bold.ttf";
  font.loadFromFile(fnt);
  game_score.setFont(font);
  text.setString(std::to_string(m_score));
  text.setCharacterSize(24);
  text.setPosition(385, 75);
  text.setFillColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold);
  m_window.draw(text);
}

bool Game::get_game_isover_status() {
  return game_is_over;
}

int Game::get_score() const {
  return m_score;
}
