#ifndef RECRUITMENTSCENE_H
#define RECRUITMENTSCENE_H

#include <QWidget>

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
};

#endif // RECRUITMENTSCENE_H
