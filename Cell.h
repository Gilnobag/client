#pragma once
#include <queue>
#include <vector>

class Unit;

class Cell {
	int i, j;
private:
	Cell * left_up_;
	Cell *left_;
	Cell * left_down_;

	Cell *right_up_;
	Cell *right_;
	Cell *right_down_;

	Unit *character_;

	bool isMoveable_;
	bool  isAttackable_;

	int distance_;
	bool AddedToQuery_;

	void clearTable_(bool);
	void clearCell_();

	void handleAllMoveableCellsAndUnmoveableCells_(std::queue<Cell*> & Q);
	void handleAllUnmoveableCells_(std::queue<Cell*> & Q);

public:

	explicit Cell(Unit * character);

	explicit Cell(int, int);

	Cell * getLeftUp();
	void setLeftUp(Cell *);

	Cell * getLeft();
	void setLeft(Cell *);

	Cell * getLeftDown();
	void setLeftDown(Cell *);

	Cell * getRightUp();
	void setRightUp(Cell *);

	Cell * getRight();
	void setRight(Cell *);

	Cell * getRightDown();
	void setRightDown(Cell *);

	Unit * getCharacter();
	void setCharacter(Unit *);

	bool getIsMoveable();
	void setIsMoveable(bool);

	bool getIsAttackable();
	void setIsAttackable(bool);

	int getDistance();
	void setDistance(int);

	bool isEmpty();

	void recalculateTableWithCenterThisPoint();
	void buffTableinDistance(int);
	std::vector <Cell*> actualPath(Cell*);
};
