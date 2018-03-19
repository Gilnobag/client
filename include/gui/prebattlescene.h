#ifndef PREBATTLESCENE_H
#define PREBATTLESCENE_H

#include <QWidget>

#include "gui/scene.h"

#include <vector>

class UnitIcon;

namespace Ui {
class PreBattleScene;
}

class PreBattleScene : public Scene
{
    Q_OBJECT

public:
    explicit PreBattleScene(QWidget *parent = 0);
    ~PreBattleScene();

    void init() override;

private slots:
    void on_start_battle_clicked();

private:
    std::vector<UnitIcon*> units_player_1_;
    std::vector<UnitIcon*> units_player_2_;
    Ui::PreBattleScene *ui;
};

#endif // PREBATTLESCENE_H
