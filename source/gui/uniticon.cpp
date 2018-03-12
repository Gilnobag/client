#include <gui/uniticon.h>
#include <QDebug>
#include <QTime>

UnitIcon::UnitIcon(QWidget* parent, int width, int height)
    : QLabel(parent)
{
    state_ = 0;
    width_ = width;
    height_ = height;

    setAttribute(Qt::WA_Hover, true);
    installEventFilter(this);

    default_border_.load(":/assets/common/unit_icon_default.png");
    hover_border_.load(":/assets/common/unit_icon_hover.png");
    active_border_.load(":/assets/common/unit_icon_active.png");

    drawIcon();
}

UnitIcon::~UnitIcon()
{
}

void UnitIcon::drawIcon() {
    QPixmap combined(width_, height_);
    QPainter p(&combined);

    if (state_ == 0) {
        p.setBrush(Qt::NoBrush);
        p.setPen(Qt::black);
        p.drawRect(0, 0, width_, height_);
    } else {
        p.drawImage(QPoint(0, 0), icon_.scaled(width_, height_, Qt::KeepAspectRatio));
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

void UnitIcon::setUnitIcon(QString racename, QString unitname) {
    icon_.load(":/assets/units/" + racename + "/" + unitname + "/icon.png");
    if (state_ == 0)
        state_ = 1;
    drawIcon();
}

void UnitIcon::unsetUnitIcon() {
    state_ = 0;
    drawIcon();
}

void UnitIcon::resize(int w, int h) {
    width_ = w;
    height_ = h;
    drawIcon();
}

void UnitIcon::deactivate() {
    if (state_ > 1)
        state_ = 1;
    drawIcon();
}

void UnitIcon::activate() {
    state_ = 3;
    drawIcon();
}

void UnitIcon::mousePressEvent(QMouseEvent*)
{
    if (state_ == 0)
        return;

    activate();

    QTime current_time = QTime::currentTime();
    if (current_time.msecsSinceStartOfDay() - previous_click_time_.msecsSinceStartOfDay() < 200) {
        deactivate();
        emit doubleclicked();
    } else {
        previous_click_time_ = current_time;
        emit clicked();
    }
}

void UnitIcon::enterEvent(QEvent*)
{
    if (state_ == 0 || state_ == 3)
        return;

    state_ = 2;
    drawIcon();
    emit hovered();
}

void UnitIcon::leaveEvent(QEvent*)
{
    if (state_ == 0 || state_ == 3)
        return;

    state_ = 1;
    drawIcon();
    emit unhovered();
}
