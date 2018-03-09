#include "Cell.h"
#include <queue>
#include <vector>

struct Unit {
	bool canAttack(int distance) {
		return true;
	}
};

Cell::Cell(Unit & character) {
	upLeft_ = up_ = upRight_ = nullptr;
	downLeft_ = down_ = downRight_ = nullptr;
	character_ = &character;
	clearCell_();
	AddedToQuery_ = true;
}

Cell * Cell::getUpLeft() {
	return upLeft_;
}
void Cell::setUpLeft(Cell * t) {
	upLeft_ = t;
}
Cell * Cell::getUp() {
	return up_;
}
void Cell::setUp(Cell * t) {
	up_ = t;
}
Cell * Cell::getUpRight() {
	return upRight_;
}
void Cell::setUpRight(Cell * t) {
	upRight_ = t;
}
Cell * Cell::getDownLeft() {
	return downLeft_;
}
void Cell::setDownLeft(Cell * t) {
	downLeft_ = t;
}
Cell * Cell::getDown() {
	return down_;
}
void Cell::setDown(Cell * t) {
	down_ = t;
}
Cell * Cell::getDownRight() {
	return downRight_;
}
void Cell::setDownRight(Cell * t) {
	downRight_ = t;
}
Unit * Cell::getCharacter() {
	return character_;
}
void Cell::setCharacter(Unit * t) {
	character_ = t;
}
bool Cell::getisMoveable() {
	return isMoveable_;
}
void Cell::setisMoveable(bool t) {
	isMoveable_ = t;
}
bool Cell::getisAttackable() {
	return isAttackable_;
}
void Cell::setisAttackable(bool t) {
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
	setisMoveable(false);
	setisAttackable(false);
	setDistance(-1);
}
void Cell::clearTable_() {
	std::queue<Cell*> q;
	q.push(this);
	clearCell_();
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
		Now->clearCell_();
		f(Now->getUpLeft());
		f(Now->getUp());
		f(Now->getUpRight());
		f(Now->getDownLeft());
		f(Now->getDown());
		f(Now->getDownRight());
	}
}
void Cell::handleAllMoveableCellsAndUnmoveableCells_(std::queue<Cell*> & Q) {
	std::queue<Cell*> q;
	q.push(this);
	setDistance(0);
	while (!q.empty()) {
		Cell * Now = q.front();
		Now->setisMoveable(true);
		if (getCharacter() != NULL && getCharacter()->canAttack(Now->getDistance())) {
			Now->setisAttackable(true);
		}
		else {
			Now->setisAttackable(false);
		}
		q.pop();
		auto f = [&q, &Q](Cell * t, Cell * parent) {
			if (t && !t->AddedToQuery_) {
				t->AddedToQuery_ = true;
				if (t->getCharacter() != NULL) {
					t->setisMoveable(false);
					Q.push(t);
					return;
				}
				q.push(t);
				t->setDistance(parent->getDistance() + 1);
			}
		};
		f(Now->getUpLeft(), Now);
		f(Now->getUp(), Now);
		f(Now->getUpRight(), Now);
		f(Now->getDownLeft(), Now);
		f(Now->getDown(), Now);
		f(Now->getDownRight(), Now);
	}
}
void Cell::handleAllUnmoveableCells_(std::queue<Cell*> & Q) {
	while (!Q.empty()) {
		Cell * Now = Q.front();
		Now->setisMoveable(false);
		Now->setisAttackable(false);
		Q.pop();
		auto f = [&Q](Cell * t, Cell * parent) {
			if (t && !t->AddedToQuery_) {
				t->AddedToQuery_ = true;
				Q.push(t);
			}
		};
		f(Now->getUpLeft(), Now);
		f(Now->getUp(), Now);
		f(Now->getUpRight(), Now);
		f(Now->getDownLeft(), Now);
		f(Now->getDown(), Now);
		f(Now->getDownRight(), Now);
	}
}
void Cell::RecalculateTableWithCenterThisPoint() {
	clearTable_();
	std::queue<Cell*> qWithoutMoveable;
	handleAllMoveableCellsAndUnmoveableCells_(qWithoutMoveable);
	handleAllUnmoveableCells_(qWithoutMoveable);
}
std::vector <Cell*> Cell::actualPath(Cell* to) {//std::vector<Cell*> âêëþ÷àåòñÿ â ñåáÿ è this, è end
	if (!to || !to->getisMoveable())return std::vector<Cell*>();
	auto ret = std::vector<Cell*>(1, to);
	while (to != this) {
		Cell * parent = NULL;
		auto f = [&parent](Cell * TestParent, Cell * Now) {
			if (TestParent && TestParent->getDistance() + 1 == Now->getDistance() && TestParent->getisMoveable()) {
				parent = TestParent;
			}
		};
		f(to->getUpLeft(), to);
		f(to->getUp(), to);
		f(to->getUpRight(), to);
		f(to->getDownLeft(), to);
		f(to->getDown(), to);
		f(to->getDownRight(), to);
		to = parent;
		ret.push_back(to);
	}
	return ret;
}
