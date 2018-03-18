#include <gui/gui.h>
#include <ui_gui.h>
#include <gui/recruitmentscene.h>
#include <QDebug>

GUI::GUI(QWidget *parent) :
    QMainWindow(parent, Qt::Window | Qt::FramelessWindowHint),
    ui_(new Ui::GUI), dx_(0), dy_(0)
{
    ui_->setupUi(this);

    //rq_scene_ = new RecruitmentScene(ui_->main_content_);   /// Инициализируем графическую сцену выбора юнитов
    //rq_scene_->show();
}

GUI::~GUI()
{
    delete ui_;
}

QWidget* GUI::mainContentScene() {
    return ui_->main_content_;
}


void GUI::mouseMoveEvent( QMouseEvent* e ) {
    if( e->buttons() | Qt::LeftButton ) {
        QPoint pt=mapFromGlobal(QCursor::pos());
        QWidget* child=childAt(pt);

        if (child == 0) {
            setGeometry(pos().x() + (pt.x() - dx_ ), pos().y() + (pt.y() - dy_ ), width(), height());
            return;
        }
        QString cname = child->metaObject()->className();
        if (cname != "QPushButton" && cname != "QComboBox"){ // отключаем перетягивание при наведение на активные элементы
            setGeometry(pos().x() + ( pt.x() - dx_ ), pos().y() + ( pt.y() - dy_ ), width(), height());
        } else {
            dx_ = pt.x();
            dy_ = pt.y();
        }
    }
}

void GUI::mousePressEvent( QMouseEvent* e ) {
    if(e->button() == Qt::LeftButton) {
        QPoint pt = mapFromGlobal(QCursor::pos());
        QWidget* child=childAt(pt);

        if (child == 0)
            return;

        QString cname = child->metaObject()->className();
        if (cname == "QPushButton" || cname == "QComboBox" || cname == "QLabel")
           return;

        dx_ = pt.x();
        dy_ = pt.y();
        setCursor( Qt::OpenHandCursor );
    }
}

void GUI::mouseReleaseEvent( QMouseEvent* e ) {
    if( e->button() == Qt::LeftButton ) {
        QPoint pt=mapFromGlobal(QCursor::pos());
        setCursor( Qt::ArrowCursor );
        dx_ = pt.x();
        dy_ = pt.y();
    }
}
