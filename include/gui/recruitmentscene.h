#ifndef RECRUITMENTSCENE_H
#define RECRUITMENTSCENE_H

#include "gui/scene.h"

#include <QWidget>

#include <vector>

class UnitIcon;
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

    void ParseArgs(QString args) {
        current_player_id_ = args.toInt();
    }

    void init() {

    }

private slots:
    void on_back_button_clicked();

private:
    int current_player_id_;
    Ui::RecruitmentScene *ui;
    UnitIcon* available_units_icons_[5];
    UnitIcon* chosen_units_icons_[10];
};

#endif // RECRUITMENTSCENE_H
