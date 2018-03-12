#ifndef RECRUITMENTSCENE_H
#define RECRUITMENTSCENE_H

#include <QWidget>

#include <vector>

class UnitIcon;

namespace Ui {
class RecruitmentScene;
}

class RecruitmentScene : public QWidget
{
    Q_OBJECT

public:
    explicit RecruitmentScene(QWidget *parent = 0);
    ~RecruitmentScene();

private:
    Ui::RecruitmentScene *ui;
    UnitIcon* available_units_icons_[5];
    UnitIcon* chosen_units_icons_[10];
};

#endif // RECRUITMENTSCENE_H
