#include "Cell.h"
#include "unit.h"
#include <queue>
#include <vector>

Cell::Cell(Unit * character) {
	leftUp_ = left_ = leftDown_ = nullptr;
	rightUp_ = right_ = rightDown_ = nullptr;
	character_ = &character;
	clearCell_();
	AddedToQuery_ = true;
}

Cell * Cell::getleftUp() {
	return leftUp_;
}
void Cell::setleftUp(Cell * t) {
	leftUp_ = t;
}

Cell * Cell::getleft() {
	return left_;
}
void Cell::setleft(Cell * t) {
	left_ = t;
}

Cell * Cell::getleftDown() {
	return leftDown_;
}
void Cell::setleftDown(Cell * t) {
	leftDown_ = t;
}

Cell * Cell::getrightUp() {
	return rightUp_;
}
void Cell::setrightUp(Cell * t) {
	rightUp_ = t;
}

Cell * Cell::getright() {
	return right_;
}
void Cell::setright(Cell * t) {
	right_ = t;
}

Cell * Cell::getrightDown() {
	return rightDown_;
}
void Cell::setrightDown(Cell * t) {
	rightDown_ = t;
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
		f(Now->getleftUp());
		f(Now->getleft());
		f(Now->getleftDown());
		f(Now->getrightUp());
		f(Now->getright());
		f(Now->getrightDown());
	}
}

void Cell::handleAllMoveableCellsAndUnmoveableCells_(std::queue<Cell*> & Q) {
	std::queue<Cell*> q;
	q.push(this);
	setDistance(0);
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
	while (!q.empty()) {
		Cell * Now = q.front();
		Now->setisMoveable(true);
		if (getCharacter() != NULL && getCharacter()->СanAttack(Now->getDistance())) {
			Now->setisAttackable(true);
		}
		else {
			Now->setisAttackable(false);
		}
		q.pop();
		f(Now->getleftUp(), Now);
		f(Now->getleft(), Now);
		f(Now->getleftDown(), Now);
		f(Now->getrightUp(), Now);
		f(Now->getright(), Now);
		f(Now->getrightDown(), Now);
	}
}

void Cell::handleAllUnmoveableCells_(std::queue<Cell*> & Q) {
	auto f = [&Q](Cell * t, Cell * parent) {
		if (t && !t->AddedToQuery_) {
			t->AddedToQuery_ = true;
			Q.push(t);
		}
	};
	while (!Q.empty()) {
		Cell * Now = Q.front();
		Now->setisMoveable(false);
		Now->setisAttackable(false);
		Q.pop();
		f(Now->getleftUp(), Now);
		f(Now->getleft(), Now);
		f(Now->getleftDown(), Now);
		f(Now->getrightUp(), Now);
		f(Now->getright(), Now);
		f(Now->getrightDown(), Now);
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
		f(to->getleftUp(), to);
		f(to->getleft(), to);
		f(to->getleftDown(), to);
		f(to->getrightUp(), to);
		f(to->getright(), to);
		f(to->getrightDown(), to);
		to = parent;
		ret.push_back(to);
	}
	return ret;
}
