#include "../include/Block.h"
#include <map>
#include <vector>

Block::Block() {
  m_cell_size = 30;
  m_rotationState = 0;
  m_row_offset = 0;
  m_column_offset = 0;
  color = get_cell_color();
}

void Block::Draw(sf::RenderWindow& window, int offsetX, int offsetY) {
  std::vector<Position> titles = get_cells_position(); 
  for(auto item : titles) {
    sf::RectangleShape rectangle(sf::Vector2f(m_cell_size - 1, m_cell_size - 1));
      rectangle.setPosition(item.m_column * m_cell_size + offsetY, item.m_row * m_cell_size + offsetY);
      rectangle.setOutlineColor(sf::Color::White);
      rectangle.setFillColor(color[id]);
      window.draw(rectangle);
  }
}

void Block::Move(int row, int column) {
  m_column_offset += column;
  m_row_offset += row;
}


std::vector<Position> Block::get_cells_position() {
  std::vector<Position> tiles = m_cells[m_rotationState];
  std::vector<Position> moved_tiles{};

  for(auto item : tiles) {
    Position new_pos = Position(item.m_row + m_row_offset, item.m_column + m_column_offset);
    moved_tiles.push_back(new_pos);
  }

  return moved_tiles;
}

void Block::Rotate() {
  m_rotationState++;

  if(m_rotationState == (int)m_cells.size()) {
    m_rotationState = 0;
  }
}

void Block::Undo_Rotation() {
  m_rotationState--;
  if(m_rotationState == -1) {
    m_rotationState = m_cells.size() - 1;
  }
}
