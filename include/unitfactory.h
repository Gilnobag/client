#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include <QObject>
#include <QImage>

class UnitFactory : public QObject
{
    Q_OBJECT
public:
    explicit UnitFactory(QObject *parent = nullptr);
private:
    QImage race_icon_;

signals:

public slots:
};

#endif // UNITFACTORY_H
