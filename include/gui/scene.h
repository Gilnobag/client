#ifndef INCLUDEGUISCENE_H
#define INCLUDEGUISCENE_H

#include <QWidget>

class Scene : public QWidget
{
    Q_OBJECT
public:
    explicit Scene(QWidget *parent = nullptr);

    virtual ~Scene() {}

    virtual void parseArgs(QString args) {}

    virtual void init() {}

signals:

public slots:
};

#endif // INCLUDEGUISCENE_H
