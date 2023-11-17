#ifndef ALL_BLOCK_H
#define ALL_BLOCK_H

#include "Block.h"
#include "Position.h"


class LBlock : public Block {
public:
  LBlock() {
    id = 1;
    m_cells[0] = {Position{0, 2}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
    m_cells[1] = {Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{2, 2}};
    m_cells[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 0}};
    m_cells[3] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{2, 1}};
    Move(0, 3);
  }
};

class JBlock : public Block {
public:
  JBlock() {
    id = 2;
    m_cells[0] = {Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
    m_cells[1] = {Position{0, 1}, Position{0, 2}, Position{1, 1}, Position{2, 1}};
    m_cells[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 2}};
    m_cells[3] = {Position{0, 1}, Position{1, 1}, Position{2, 0}, Position{2, 1}};
    Move(0, 3);
  }
};

class IBlock : public Block {
public:
  IBlock() {
    id = 3;
    m_cells[0] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{1, 3}};
    m_cells[1] = {Position{2, 0}, Position{2, 1}, Position{2, 2}, Position{2, 3}};
    m_cells[2] = {Position{0, 1}, Position{1, 1}, Position{2, 1}, Position{3, 1}};
    m_cells[3] = {Position{0, 2}, Position{1, 2}, Position{2, 2}, Position{3, 2}};
    Move(-1, 3);
  }
};

class SBlock : public Block {
public:
  SBlock() {
    id = 4;
    m_cells[0] = {Position{0, 1}, Position{0, 2}, Position{1, 0}, Position{1, 1}};
    m_cells[1] = {Position{0, 0}, Position{1, 0}, Position{1, 1}, Position{2, 1}};
    m_cells[2] = {Position{1, 1}, Position{1, 2}, Position{2, 0}, Position{2, 1}};
    m_cells[3] = {Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 2}};
    Move(0, 3);
  }
};

class ZBlock : public Block {
public:
  ZBlock() {
    id = 5;
    m_cells[0] = {Position{0, 0}, Position{0, 1}, Position{1, 1}, Position{1, 2}};
    m_cells[1] = {Position{0, 2}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
    m_cells[2] = {Position{1, 0}, Position{1, 1}, Position{2, 1}, Position{2, 2}};
    m_cells[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 0}};
    Move(0, 3);
  }
};

class TBlock : public Block {
public:
  TBlock() {
    id = 6;
    m_cells[0] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{1, 2}};
    m_cells[1] = {Position{0, 1}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
    m_cells[2] = {Position{1, 0}, Position{1, 1}, Position{1, 2}, Position{2, 1}};
    m_cells[3] = {Position{0, 1}, Position{1, 0}, Position{1, 1}, Position{2, 1}};
    Move(0, 3);
  }
};

class OBlock : public Block {
public:
  OBlock() {
    id = 7;
    m_cells[0] = {Position{0, 0}, Position{0, 1}, Position{1, 0}, Position{1, 1}};
    Move(0, 4);
  }
};

#endif
