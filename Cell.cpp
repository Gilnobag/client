#include "Cell.h"
//#include "unit.h"
#include <queue>
#include <vector>

/*
 * Добавьте в Unit эту функцию
 */
class Unit {
public:
	bool canAttackForDistance(int) { return true; }
	bool canAttackUnit(Unit*) { return true; }
};

Cell::Cell(Unit * character) {
	left_up_ = left_ = left_down_ = nullptr;
	right_up_ = right_ = right_down_ = nullptr;
	character_ = character;
	clearCell_();
	AddedToQuery_ = true;
}

Cell::Cell(int i, int j) :i(i), j(j), AddedToQuery_(true) {}

Cell * Cell::getLeftUp() {
	return left_up_;
}
void Cell::setLeftUp(Cell * t) {
	left_up_ = t;
}

Cell * Cell::getLeft() {
	return left_;
}
void Cell::setLeft(Cell * t) {
	left_ = t;
}

Cell * Cell::getLeftDown() {
	return left_down_;
}
void Cell::setLeftDown(Cell * t) {
	left_down_ = t;
}

Cell * Cell::getRightUp() {
	return right_up_;
}
void Cell::setRightUp(Cell * t) {
	right_up_ = t;
}

Cell * Cell::getRight() {
	return right_;
}
void Cell::setRight(Cell * t) {
	right_ = t;
}

Cell * Cell::getRightDown() {
	return right_down_;
}
void Cell::setRightDown(Cell * t) {
	right_down_ = t;
}

Unit * Cell::getCharacter() {
	return character_;
}
void Cell::setCharacter(Unit * t) {
	character_ = t;
}

bool Cell::getIsMoveable() {
	return isMoveable_;
}
void Cell::setIsMoveable(bool t) {
	isMoveable_ = t;
}

bool Cell::getIsAttackable() {
	return isAttackable_;
}
void Cell::setIsAttackable(bool t) {
	isAttackable_ = t;
}

int Cell::getDistance() {
	return distance_;
}
void Cell::setDistance(int t) {
	distance_ = t;
}

bool Cell::isEmpty() {
	return character_ == NULL;
}

void Cell::clearCell_() {
	setIsMoveable(false);
	setDistance(-1);
}

void Cell::clearTable_(bool NeedClearCell = true) {
	std::queue<Cell*> q;
	q.push(this);
	setIsAttackable(false);
	if (NeedClearCell) {
		clearCell_();
	}
	this->AddedToQuery_ = false;
	auto f = [&q](Cell * t) {
		if (t && t->AddedToQuery_ == true) {
			q.push(t);
			t->AddedToQuery_ = false;
		}
	};
	while (!q.empty()) {
		Cell * Now = q.front();
		q.pop();
		Now->setIsAttackable(false);
		if (NeedClearCell) {
			Now->clearCell_();
		}
		f(Now->getLeftUp());
		f(Now->getLeft());
		f(Now->getLeftDown());
		f(Now->getRightUp());
		f(Now->getRight());
		f(Now->getRightDown());
	}
}

void Cell::handleAllMoveableCellsAndUnmoveableCells_(std::queue<Cell*> & Q) {
	std::queue<Cell*> q;
	q.push(this);
	setDistance(0);
	AddedToQuery_ = true;
	setIsMoveable(true);
	setIsAttackable(true);
	auto f = [&q, &Q](Cell * t, Cell * parent) {
		if (t && !t->AddedToQuery_) {
			t->AddedToQuery_ = true;
			t->setDistance(parent->getDistance() + 1);
			if (t->getCharacter() != NULL) {
				t->setIsMoveable(false);
				Q.push(t);
				return;
			}
			q.push(t);
		}
	};
	while (!q.empty()) {
		Cell * Now = q.front();
		Now->setIsMoveable(true);
		if (getCharacter() != NULL && getCharacter()->canAttackForDistance(Now->getDistance()) &&
			(Now->getCharacter() == NULL || getCharacter()->canAttackUnit(Now->getCharacter()))) {
			Now->setIsAttackable(true);
		}
		else {
			Now->setIsAttackable(false);
		}
		q.pop();
		f(Now->getLeftUp(), Now);
		f(Now->getLeft(), Now);
		f(Now->getLeftDown(), Now);
		f(Now->getRightUp(), Now);
		f(Now->getRight(), Now);
		f(Now->getRightDown(), Now);
	}
}

void Cell::handleAllUnmoveableCells_(std::queue<Cell*> & Q) {
	auto f = [&Q](Cell * t, Cell * parent) {
		if (t && !t->AddedToQuery_) {
			t->AddedToQuery_ = true;
			t->setDistance(parent->getDistance() + 1);
			Q.push(t);
		}
	};
	while (!Q.empty()) {
		Cell * Now = Q.front();
		Now->setIsMoveable(false);
		Now->setIsAttackable(false);
		Q.pop();
		f(Now->getLeftUp(), Now);
		f(Now->getLeft(), Now);
		f(Now->getLeftDown(), Now);
		f(Now->getRightUp(), Now);
		f(Now->getRight(), Now);
		f(Now->getRightDown(), Now);
	}
}

void Cell::recalculateTableWithCenterThisPoint() {
	clearTable_();
	std::queue<Cell*> qWithoutMoveable;
	handleAllMoveableCellsAndUnmoveableCells_(qWithoutMoveable);
	handleAllUnmoveableCells_(qWithoutMoveable);
}

void Cell::buffTableinDistance(int distance) {
	clearTable_(false);
	std::queue<Cell*> q;
	q.push(this);
	setIsAttackable(true);
	auto f = [&q, &distance](Cell * Now) {
		if (Now != NULL && Now->getDistance() <= distance && !Now->AddedToQuery_) {
			q.push(Now);
			Now->AddedToQuery_ = true;
			Now->setIsAttackable(true);
		}
	};
	while (!q.empty()) {
		Cell * Now = q.front();
		q.pop();
		f(Now->getLeftUp());
		f(Now->getLeft());
		f(Now->getLeftDown());
		f(Now->getRightUp());
		f(Now->getRight());
		f(Now->getRightDown());
	}
}

std::vector <Cell*> Cell::actualPath(Cell* to) {
	if (!to || !to->getIsMoveable())return std::vector<Cell*>();
	auto ret = std::vector<Cell*>(1, to);
	while (to != this) {
		Cell * parent = NULL;
		auto f = [&parent](Cell * TestParent, Cell * Now) {
			if (TestParent && TestParent->getDistance() + 1 == Now->getDistance() && TestParent->getIsMoveable()) {
				parent = TestParent;
			}
		};
		f(to->getLeftUp(), to);
		f(to->getLeft(), to);
		f(to->getLeftDown(), to);
		f(to->getRightUp(), to);
		f(to->getRight(), to);
		f(to->getRightDown(), to);
		to = parent;
		ret.push_back(to);
	}
	return ret;
}
