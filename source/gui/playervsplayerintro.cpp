#include "gui/playervsplayerintro.h"
#include "gui/guiscenemanager.h"
#include "ui_playervsplayerintro.h"

PlayerVsPlayerIntro::PlayerVsPlayerIntro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerVsPlayerIntro)
{
    ui->setupUi(this);
}

PlayerVsPlayerIntro::~PlayerVsPlayerIntro()
{
    delete ui;
}

void PlayerVsPlayerIntro::on_back_to_menu_clicked()
{
    GuiSceneManager::getInstance().changeScene("main_menu");
}

void PlayerVsPlayerIntro::on_go_next_clicked()
{
    GuiSceneManager::getInstance().changeScene("recruit_army");
}
