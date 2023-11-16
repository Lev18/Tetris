#include "Grid.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Colors.h"

Grid::Grid() : m_num_row{20}, m_num_col{10}, m_cell_size{30} {
  Initialize();
  colors = get_cell_color();
}

void Grid::Initialize() {
  for (int row = 0; row < m_num_row; ++row) {
    for (int col = 0; col < m_num_col; ++col) {
      grid[row][col] = 0;
    }
  }
}

void Grid::Print() {
 for (int row = 0; row < m_num_row; ++row) {
    for (int col = 0; col < m_num_col; ++col) {
      std::cout << "0" << " ";
    }
    std::cout << '\n';
  }

}

void Grid::Draw(sf::RenderWindow& window, int offsetX, int offsetY) {
  for (int row = 0; row < m_num_row; ++row) {
    for(int col = 0; col < m_num_col; ++col) {
      int cellVal = grid[row][col];
      sf::RectangleShape rectangle(sf::Vector2f(m_cell_size - 1, m_cell_size - 1));
      rectangle.setPosition(col * m_cell_size + offsetX, row * m_cell_size + offsetY);
      rectangle.setOutlineColor(sf::Color::White);
      rectangle.setFillColor(colors[cellVal]);
      window.draw(rectangle);
    }
  }
}

bool Grid::is_cell_outside(int row, int col) {
  if(row >= 0 && row < m_num_row && col >= 0 && col < m_num_col) {
    return false;
  }
  return true;
}

bool Grid::is_cell_empty(int row, int column) {
  if (grid[row][column] == 0) {
    return true;
  }
  return false;
}

int Grid::clear_full_row() {
  int completed_row = 0;

  for(int row = m_num_row - 1; row >= 0; --row) {
    if (is_row_full(row)) {
      clear_row(row);
      ++completed_row;
    } 
    else if (completed_row > 0) {
      move_row_down(row, completed_row);
    }
  }
  return completed_row;
}

// private methods
bool Grid::is_row_full(int row) {
  for (int col = 0; col < m_num_col; ++col) {
    if (grid[row][col] == 0) {
      return false;
    } 
  }
  return true;
}

void Grid::clear_row(int row) {
  for (int col = 0; col < m_num_col; ++col) {
    grid[row][col] = 0;
  }
}

void Grid::move_row_down(int row, int num_row) {
  for (int col = 0; col < m_num_col; ++col) {
    grid[row + num_row][col] = grid[row][col];
    grid[row][col] = 0;
  }
}























