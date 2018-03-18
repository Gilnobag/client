#ifndef PLAYERVSPLAYERINTRO_H
#define PLAYERVSPLAYERINTRO_H

#include <QWidget>

namespace Ui {
class PlayerVsPlayerIntro;
}

class PlayerVsPlayerIntro : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerVsPlayerIntro(QWidget *parent = 0);
    ~PlayerVsPlayerIntro();

private slots:
    void on_back_to_menu_clicked();

    void on_go_next_clicked();

private:
    Ui::PlayerVsPlayerIntro *ui;
};

#endif // PLAYERVSPLAYERINTRO_H
