#include "gui.h"
#include "ui_gui.h"
#include "recruitmentscene.h"
#include <QDebug>

GUI::GUI(QWidget *parent) :
    QMainWindow(parent, Qt::Window | Qt::FramelessWindowHint),
    ui_(new Ui::GUI), dx_(0), dy_(0)
{
    ui_->setupUi(this);
    rq_scene_ = new RecruitmentScene(ui_->main_content_);   /// Инициализируем графическую сцену
    rq_scene_->show();
    //rq_scene_->hide();
}

GUI::~GUI()
{
    delete ui_;
}

void GUI::mouseMoveEvent( QMouseEvent* e ) {
    if( e->buttons() | Qt::LeftButton ) {
        QPoint pt=mapFromGlobal(QCursor::pos());
        QWidget* child=childAt(pt);
        if (child == 0) {
            setGeometry(pos().x() + ( e->x() - dx_ ), pos().y() + ( e->y() - dy_ ), width(), height());
            return;
        }
        QString cname = child->metaObject()->className();
        qDebug() << cname;
        if (cname != "QPushButton" && cname != "QComboBox"){ // отключаем перетягивание при наведение на активные элементы
            setGeometry(pos().x() + ( e->x() - dx_ ), pos().y() + ( e->y() - dy_ ), width(), height());
        } else {
            dx_ = e->x();
            dy_ = e->y();
        }
    }
}

void GUI::mousePressEvent( QMouseEvent* e ) {
    if( e->button() == Qt::LeftButton ) {
        dx_ = e->x();
        dy_ = e->y();
        setCursor( Qt::OpenHandCursor );
    }
}

void GUI::mouseReleaseEvent( QMouseEvent* e ) {
    if( e->button() == Qt::LeftButton ) {
        setCursor( Qt::ArrowCursor );
        dx_ = e->x();
        dy_ = e->y();
    }
}
