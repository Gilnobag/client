#ifndef RECRUITMENTSCENE_H
#define RECRUITMENTSCENE_H

#include "gui/scene.h"

#include <QWidget>

#include <vector>

class UnitIcon;
class RaceIcon;
class Player;
class Unit;
class Race;

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

public slots:
    void onUnitIconHovered(UnitIcon*);
    void onUnitIconUnHovered(UnitIcon*);
    void onUnitIconClicked(UnitIcon*);
    void onUnitIconDoubleClicked(UnitIcon*);

    void onChosenUnitIconHovered(UnitIcon*);
    void onChosenUnitIconUnHovered(UnitIcon*);
    void onChosenUnitIconClicked(UnitIcon*);
    void onChosenUnitIconDoubleClicked(UnitIcon*);

    void onRaceIconHovered(RaceIcon*);
    void onRaceIconUnHovered(RaceIcon*);
    void onRaceIconClicked(RaceIcon*);
    void onRaceIconDoubleClicked(RaceIcon*);

    void onGradeUnitIconHovered(UnitIcon*);
    void onGradeUnitIconUnHovered(UnitIcon*);
    void onGradeUnitIconClicked(UnitIcon*);
    void onGradeUnitIconDoubleClicked(UnitIcon*);

private:
    void initAvailableRaces();
    void initAvailableUnits();
    void showChosenUnits();

    void setDescriptionTitle(QString title);
    void setDescriptionText(QString text);
    void setDescriptionIcon(QImage icon);

    void updateSpecsWidget(Unit* unit);
    void changeRace(Race* race);
    void setMoney(int money_);

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

    UnitIcon* prev_grade_units_icons[4];
    UnitIcon* next_grade_units_icons[4];
};

#endif // RECRUITMENTSCENE_H
