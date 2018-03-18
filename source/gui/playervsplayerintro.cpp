#include "gui/playervsplayerintro.h"
#include "gui/guiscenemanager.h"
#include "player.h"
#include "gui/scene.h"

#include "ui_playervsplayerintro.h"

PlayerVsPlayerIntro::PlayerVsPlayerIntro(QWidget *parent) :
    Scene(parent),
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
    Player<1>::getInstance().init();
    Player<2>::getInstance().init();
    GuiSceneManager::getInstance().changeScene("recruit_army", "2");
}
