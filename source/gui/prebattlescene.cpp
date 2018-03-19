
#include "gui/prebattlescene.h"

#include "player.h"
#include "playermanager.h"
#include "race.h"
#include "racemanager.h"

#include "gui/raceicon.h"
#include "gui/uniticon.h"
#include "gui/guiscenemanager.h"
#include "ui_prebattlescene.h"

#include <QMessageBox>

PreBattleScene::PreBattleScene(QWidget *parent) :
    Scene(parent),
    ui(new Ui::PreBattleScene)
{
    ui->setupUi(this);
}

PreBattleScene::~PreBattleScene()
{
    delete ui;
}

void PreBattleScene::init() {
    Player *player = PlayerManager::getInstance().getPlayer(0);

    ui->race_icon_1_->setRaceIcon(player->getRace()->getRaceIcon());
    ui->race_icon_1_->resize(128, 128);
    ui->race_icon_1_->setState(5);

    units_player_1_.resize(10);
    auto units = player->getUnitsAsVector();
    for (int i = 0; i < 10; i++) {
        units_player_1_[i] = new UnitIcon();
        if (i < units.size())
            units_player_1_[i]->setUnitIcon(units[i]->getUnitIcon());
        else
            units_player_1_[i]->setUnitIcon("norace", "nounit");
        units_player_1_[i]->setState(5);
        ui->units_player_1_layout_->addWidget(units_player_1_[i], i / 5, i % 5);
    }

    player = PlayerManager::getInstance().getPlayer(1);
    ui->race_icon_2_->setRaceIcon(player->getRace()->getRaceIcon());
    ui->race_icon_2_->resize(128, 128);
    ui->race_icon_2_->setState(5);

    units_player_2_.resize(10);
    units = player->getUnitsAsVector();
    for (int i = 0; i < 10; i++) {
        units_player_2_[i] = new UnitIcon();
        if (i < units.size())
            units_player_2_[i]->setUnitIcon(units[i]->getUnitIcon());
        else
            units_player_2_[i]->setUnitIcon("norace", "nounit");
        units_player_2_[i]->setState(5);
        ui->units_player_2_layout_->addWidget(units_player_2_[i], i / 5, i % 5);
    }
}

void PreBattleScene::on_start_battle_clicked()
{
    QMessageBox msg(QMessageBox::Information, "Нельзя сотворить здесь!", "Не ну имейте терпение! Всё будет! Но попозже... :)");
    msg.exec();

    GuiSceneManager::getInstance().changeScene("main_menu");
}
