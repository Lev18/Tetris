#ifndef  BLOCK_H
#define  BLOCK_H

#include <map>
#include <vector>
#include "Colors.h"
#include "Position.h"

class Block {
public:
  Block();
  int id;
  std::map<int, std::vector<Position>> m_cells;
  void Draw(sf::RenderWindow& window, int offsetX, int offsetY);
  void Rotate();
  void Undo_Rotation();
  void Move(int row, int column);
  std::vector<Position> get_cells_position();

private:
  int m_cell_size;
  int m_rotationState;
  int m_row_offset;
  int m_column_offset;
  std::vector<sf::Color> color;
};

#endif
