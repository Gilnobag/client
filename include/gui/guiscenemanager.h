#ifndef INCLUDEGUIGUISCENEMANAGER_H
#define INCLUDEGUIGUISCENEMANAGER_H

#include "gui/scene.h"

#include <QObject>

#include <map>

class GUI;

class GuiSceneManager : public QObject
{
    Q_OBJECT
private:
    explicit GuiSceneManager(QObject *parent = nullptr);
    ~GuiSceneManager();

public:
    static GuiSceneManager& getInstance() {
        static GuiSceneManager instance;
        return instance;
    }

    bool registerScene(QString scene_name, Scene* name);

    bool changeScene(QString scene_name, QString args = "");

    void createDetachedScene(QString scene_name);

    void destroyDetachedScene(QString scene_name);

private:
    std::map<QString, Scene*> scenes_;
    QString current_scene_;
    GUI* gui_;

signals:

public slots:
};

#endif // INCLUDEGUIGUISCENEMANAGER_H
