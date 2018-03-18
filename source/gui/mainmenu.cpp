#include "gui/mainmenu.h"
#include "gui/guiscenemanager.h"
#include "ui_mainmenu.h"

#include <QString>
#include <QApplication>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_exit_button_clicked()
{
    QApplication::quit();
}

void MainMenu::on_pvp_local_battle_button_clicked()
{
    GuiSceneManager::getInstance().changeScene("pvp_intro");
}
