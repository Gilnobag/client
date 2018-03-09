#pragma once
#include <queue>
#include <vector>

class Unit;

class Cell {

private:
	Cell *upLeft_;
	Cell *up_;
	Cell *upRight_;
	Cell * downLeft_;
	Cell *down_;
	Cell *downRight_;

	Unit *character_;
	
	bool isMoveable_;
	bool  isAttackable_;
	
	int distance_;
	bool AddedToQuery_;

	void clearTable_();
	void clearCell_();
	
	void handleAllMoveableCellsAndUnmoveableCells_(std::queue<Cell*> & Q);
	void handleAllUnmoveableCells_(std::queue<Cell*> & Q);

public:
	
	explicit Cell(Unit & character);
	
	Cell * getUpLeft();
	void setUpLeft(Cell *);
	Cell * getUp();
	void setUp(Cell *);
	Cell * getUpRight();
	void setUpRight(Cell *);
	Cell * getDownLeft();
	void setDownLeft(Cell *);
	Cell * getDown();
	void setDown(Cell *);
	Cell * getDownRight();
	void setDownRight(Cell *);
	Unit * getCharacter();
	void setCharacter(Unit *);
	bool getisMoveable();
	void setisMoveable(bool);
	bool getisAttackable();
	void setisAttackable(bool);
	int getDistance();
	void setDistance(int);
	bool isEmpty();

	void RecalculateTableWithCenterThisPoint();
	std::vector <Cell*> actualPath(Cell*);
};