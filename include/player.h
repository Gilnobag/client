#ifndef INCLUDEPLAYER_H
#define INCLUDEPLAYER_H

#include <QObject>

#include <set>

class Unit;
class Faction;

template<class Obj, class Identifier>
class ObjectFactory;

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);

signals:

public slots:

private:
    QString player_name_;
    //std::set<Unit*> units_;
    //Faction* faction_;

};

#endif // INCLUDEPLAYER_H
