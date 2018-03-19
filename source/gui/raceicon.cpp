#include <gui/raceicon.h>.h>
#include <QDebug>
#include <QTime>
#include <QEvent>
#include <QMouseEvent>

RaceIcon::RaceIcon(QWidget* parent, int width, int height)
    : QLabel(parent)
{
    state_ = 0;
    width_ = width;
    height_ = height;

    setAttribute(Qt::WA_Hover, false);
    installEventFilter(this);

    default_border_.load(":/assets/common/unit_icon_default.png");
    hover_border_.load(":/assets/common/unit_icon_hover.png");
    active_border_.load(":/assets/common/unit_icon_active.png");
    icon_.load(":/assets/units/norace/nounit/icon.png");

    drawIcon();
}

RaceIcon::~RaceIcon()
{}

void RaceIcon::drawIcon() {
    QPixmap combined(width_, height_);
    combined.fill(Qt::black);

    if (state_ >= 5) {
        combined.fill(QColor(0, 0, 0, 0));
    }

    QPainter p(&combined);

    if (state_ != 0) {
        p.drawImage(QPoint(4, 4), icon_.scaled(width_ - 8, height_ - 8, Qt::KeepAspectRatio));
    }

    if (state_ == 0 || state_ == 1)
        p.drawImage(QPoint(0, 0), default_border_.scaled(width_, height_, Qt::KeepAspectRatio));

    if (state_ == 2)
        p.drawImage(QPoint(0, 0), hover_border_.scaled(width_, height_, Qt::KeepAspectRatio));

    if (state_ == 3)
        p.drawImage(QPoint(0, 0), active_border_.scaled(width_, height_, Qt::KeepAspectRatio));

    p.end();
    setPixmap(combined);
}

Race* RaceIcon::getRace() {
    return race_;
}

void RaceIcon::setRace(Race* race) {
    race_ = race;
}

int RaceIcon::getState() {
    return state_;
}

void RaceIcon::setState(int state) {
    state_ = state;
    drawIcon();
}

void RaceIcon::setRaceIcon(QImage icon) {
    icon_ = icon;
    if (state_ == 0)
        state_ = 1;
    drawIcon();
}


void RaceIcon::unsetRaceIcon() {
    state_ = 0;
    drawIcon();
}

void RaceIcon::resize(int w, int h) {
    width_ = w;
    height_ = h;
    drawIcon();
}

void RaceIcon::deactivate() {
    if (state_ > 1)
        state_ = 1;
    drawIcon();
}

void RaceIcon::activate() {
    state_ = 3;
    drawIcon();
}

void RaceIcon::mousePressEvent(QMouseEvent* event)
{
    if (state_ == 0 || state_ >= 5)
        return;

    activate();

    QTime current_time = QTime::currentTime();
    if (current_time.msecsSinceStartOfDay() - previous_click_time_.msecsSinceStartOfDay() < 350) {
        deactivate();
        emit doubleclicked(this);
    } else {
        previous_click_time_ = current_time;
        emit clicked(this);
    }
}

void RaceIcon::enterEvent(QEvent* event)
{

    if (state_ == 0 || state_ == 3 || state_ >= 5)
        return;

    state_ = 2;
    drawIcon();
    emit hovered(this);
}

void RaceIcon::leaveEvent(QEvent* event)
{
    if (state_ == 0 || state_ == 3 || state_ >= 5)
        return;

    state_ = 1;
    drawIcon();
    emit unhovered(this);
}
