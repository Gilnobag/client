#include "playermanager.h"

#include <cassert>

PlayerManager::PlayerManager(QObject *parent) : QObject(parent)
{

}

Player* PlayerManager::getPlayer(int id) {
    assert(id < players_.size());
    return &players_[id];
}

int PlayerManager::getPlayersNum() {
    return players_.size();
}

void PlayerManager::setPlayersNum(int num) {
    players_.resize(num);
    for (int i = 0; i < num; i++)
        players_[i].init(i);
}
