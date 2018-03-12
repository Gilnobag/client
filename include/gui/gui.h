#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include "recruitmentscene.h"

namespace Ui {
class GUI;
}

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUI(QWidget *parent = 0);
    ~GUI();

private:
    Ui::GUI *ui_;
    QGraphicsScene *scene_;
    RecruitmentScene *rq_scene_;

    QImage left_border_;
    QImage left_up_corner_;
    QImage up_border_;
    QImage up_right_corner_;
    QImage right_border_;
    QImage right_bottom_corner_;
    QImage bottom_border_;
    QImage bottom_left_corner_;

protected:
    void mouseMoveEvent( QMouseEvent* e );
    void mousePressEvent( QMouseEvent* e );
    void mouseReleaseEvent( QMouseEvent* e );
private:
    int dx_;
    int dy_;
};

#endif // GUI_H
