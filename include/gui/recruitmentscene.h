#ifndef RECRUITMENTSCENE_H
#define RECRUITMENTSCENE_H

#include "gui/scene.h"

#include <QWidget>

#include <vector>

class UnitIcon;
class RaceIcon;
class Player;

namespace Ui {
class RecruitmentScene;
}

class RecruitmentScene : public Scene
{
    Q_OBJECT

public:
    explicit RecruitmentScene(QWidget *parent = 0);
    ~RecruitmentScene();

    void parseArgs(QString args) override;
    void init() override;

private:
    void initAvailableRaces();
    void initAvailableUnits();
    void initChosenUnits();

private slots:
    void on_back_button_clicked();

private:
    int available_money_;
    int current_money_;

    int current_player_id_;
    Player* current_player_;

    Ui::RecruitmentScene *ui;
    UnitIcon* available_units_icons_[5];
    UnitIcon* chosen_units_icons_[10];

    RaceIcon* available_races_icons_[3];
};

#endif // RECRUITMENTSCENE_H
