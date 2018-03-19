#ifndef UNITICON_H
#define UNITICON_H

#include "units/unit.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QTime>

class UnitIcon : public QLabel {
Q_OBJECT

public:
    explicit UnitIcon(QWidget* parent = 0, int width = 64, int height = 64);
    ~UnitIcon();

    void setUnitIcon(QString racename, QString unitname);
    void setUnitIcon(QImage icon);
    void resize(int w, int h);
    void unsetUnitIcon();

    Unit* getUnit();
    void setUnit(Unit* unit);

    void deactivate();
    void activate();

    void setState(int state);

protected:
    void mousePressEvent(QMouseEvent* event);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);


signals:
    void clicked(UnitIcon*);
    void doubleclicked(UnitIcon*);
    void hovered(UnitIcon*);
    void unhovered(UnitIcon*);

private:
    void drawIcon();

    int width_;
    int height_;

    int state_; // 0 = not initialized;
                // 1 = default;
                // 2 = hover;
                // 3 = active;

    QPixmap pixmap_;
    QImage active_border_;
    QImage hover_border_;
    QImage default_border_;
    QImage icon_;

    QTime previous_click_time_;

    QImage result_;

    Unit* unit_;
};



#endif // UNITICON_H
