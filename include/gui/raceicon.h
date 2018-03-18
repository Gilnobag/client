#ifndef RACEICON_H
#define RACEICON_H

#include "units/unit.h"

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QTime>

class RaceIcon : public QLabel {
Q_OBJECT

public:
    explicit RaceIcon(QWidget* parent = 0, int width = 64, int height = 64);
    ~RaceIcon();

    void setRaceIcon(QString racename);
    void setRaceIcon(QImage icon);
    void resize(int w, int h);
    void unsetRaceIcon();

    void deactivate();
    void activate();


protected:
    void mousePressEvent(QMouseEvent* event);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);


signals:
    void clicked();
    void doubleclicked();
    void hovered();
    void unhovered();

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

    Unit* unit_;
};

#endif // RACEICON_H
