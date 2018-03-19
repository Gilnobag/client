#include <gui/uniticon.h>
#include <QDebug>
#include <QTime>
#include <QBitmap>

UnitIcon::UnitIcon(QWidget* parent, int width, int height)
    : QLabel(parent)
{
    state_ = 0;
    width_ = width;
    height_ = height;
    unit_ = nullptr;

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

Unit* UnitIcon::getUnit() {
    if (!unit_)
        return nullptr;

    return unit_;
}

void UnitIcon::setUnit(Unit* unit) {
    unit_ = unit;
    if (unit_ != nullptr)
        setUnitIcon(unit_->getUnitIcon());
    return;
}

void UnitIcon::setState(int state) {
    state_ = state;
}


void UnitIcon::drawIcon() {
    QPixmap combined(width_, height_);
    combined.fill(QColor(253, 234, 168));
    QPainter p(&combined);

    if (state_ != 0)
        p.drawImage(QPoint(4, 4), icon_.scaled(width_ - 8, height_ - 8, Qt::KeepAspectRatio));

    if (state_ != 2 && state_ != 3)
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

void UnitIcon::setUnitIcon(QImage icon) {
    icon_ = icon;
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
    if (state_ == 0 || unit_ == nullptr || state_ >= 5)
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

void UnitIcon::enterEvent(QEvent*)
{
    if (state_ == 0 || state_ == 3 || unit_ == nullptr || state_ >= 5)
        return;

    state_ = 2;
    drawIcon();
    emit hovered(this);
}

void UnitIcon::leaveEvent(QEvent*)
{
    if (state_ == 0 || state_ == 3 || unit_ == nullptr || state_ >= 5)
        return;

    state_ = 1;
    drawIcon();
    emit unhovered(this);
}
