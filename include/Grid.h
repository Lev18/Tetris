#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>

class Grid {
public:
  Grid();
  void Initialize();
  int grid[20][10];
  bool is_cell_outside(int row, int col);
  void Print();
  void Draw(sf::RenderWindow& win, int offsetX, int offsetY);
  int clear_full_row();
  bool is_cell_empty(int row, int column);
 
private:
  int m_num_row;;
  int m_num_col;
  int m_cell_size;
  bool is_row_full(int row);
  void clear_row(int row);
  void move_row_down(int row, int num_rows);
  std::vector<sf::Color> colors;
};

#endif
