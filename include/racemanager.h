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
    const std::vector<QString>& getAvailableRacesList();

private:
    std::vector<QString> available_races_;
    std::map<QString, Race*> races_;

signals:

public slots:
};

#endif // INCLUDEACEMANAGER_H
