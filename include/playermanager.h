#ifndef INCLUDEPLAYERMANAGER_H
#define INCLUDEPLAYERMANAGER_H

#include <player.h>

#include <QObject>

#include <vector>

class PlayerManager : public QObject
{
    Q_OBJECT
private:
    explicit PlayerManager(QObject *parent = nullptr);
public:
    static PlayerManager& getInstance() {
        static PlayerManager instance;
        return instance;
    }

    Player* getPlayer(int id);
    int getPlayersNum();
    void setPlayersNum(int num);

private:
    std::vector<Player> players_;

signals:

public slots:
};

#endif // INCLUDEPLAYERMANAGER_H
