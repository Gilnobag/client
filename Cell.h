#pragma once
#include <queue>
#include <vector>

class Unit;

class Cell {

private:
	Cell * leftUp_;
	Cell *left_;
	Cell * leftDown_;

	Cell *rightUp_;
	Cell *right_;
	Cell *rightDown_;

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

	explicit Cell(Unit * character);

	Cell * getleftUp();
	void setleftUp(Cell *);

	Cell * getleft();
	void setleft(Cell *);
	
	Cell * getleftDown();
	void setleftDown(Cell *);
	
	Cell * getrightUp();
	void setrightUp(Cell *);
	
	Cell * getright();
	void setright(Cell *);
	
	Cell * getrightDown();
	void setrightDown(Cell *);
	
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
