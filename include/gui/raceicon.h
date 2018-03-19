#ifndef RACEICON_H
#define RACEICON_H

#include "race.h"

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

    void setRaceIcon(QImage icon);
    void resize(int w, int h);
    void unsetRaceIcon();

    Race* getRace();
    void setRace(Race* race);

    int getState();
    void setState(int state);

    void deactivate();
    void activate();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;

signals:
    void clicked(RaceIcon*);
    void doubleclicked(RaceIcon*);
    void hovered(RaceIcon*);
    void unhovered(RaceIcon*);

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

    Race* race_;
};

#endif // RACEICON_H
