#ifndef INCLUDEACEMANAGER_H
#define INCLUDEACEMANAGER_H

#include <QObject>

#include <vector>

class Race;

class RaceManager : public QObject
{
    Q_OBJECT
private:
    explicit RaceManager(QObject *parent = nullptr);
public:
    static RaceManager& getInstance() {
        static RaceManager instance;
        return instance;
    }

    Race* getRace(QString race_name);
    std::vector<QString> getAvailableRacesList();
signals:

public slots:
};

#endif // INCLUDEACEMANAGER_H
