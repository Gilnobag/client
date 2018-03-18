#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:

    void on_exit_button_clicked();

    void on_pvp_local_battle_button_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
