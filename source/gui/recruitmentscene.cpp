#include <gui/recruitmentscene.h>
#include <gui/uniticon.h>
#include <gui/raceicon.h>
#include <gui/guiscenemanager.h>
#include <gui/scene.h>
#include <playermanager.h>
#include <player.h>
#include <racemanager.h>
#include <race.h>

#include <ui_recruitmentscene.h>
#include <QHBoxLayout>
#include <QString>
#include <QStringList>

#include <cassert>

RecruitmentScene::RecruitmentScene(QWidget *parent)
    : Scene(parent)
    , ui(new Ui::RecruitmentScene)
{
    ui->setupUi(this);

    for (int i = 0; i < 5; i++) {
        available_units_icons_[i] = new UnitIcon(ui->available_units_list_);
        ui->available_units_layout_->addWidget(available_units_icons_[i], 0, i);
        available_units_icons_[i]->setUnitIcon("norace", "nounit");
    }

    for (int i = 0; i < 10; i++) {
        chosen_units_icons_[i] = new UnitIcon(ui->chosen_units_grid_);
        chosen_units_icons_[i]->setUnitIcon("warcraft", "rogue");
        ui->chosen_units_layout_->addWidget(chosen_units_icons_[i], i / 5, i % 5);
    }

    ui->parent_spec_unit_->resize(45, 45);
    ui->parent_spec_unit_->setUnitIcon("warcraft", "chaosorc");

    ui->current_spec_unit_->resize(45, 45);
    ui->current_spec_unit_->setUnitIcon("warcraft", "chaosorc");

    ui->next_spec_unit_1_->resize(45, 45);
    ui->next_spec_unit_2_->resize(45, 45);
    ui->next_spec_unit_3_->resize(45, 45);
    ui->next_spec_unit_4_->resize(45, 45);

    ui->next_spec_unit_1_->setUnitIcon("warcraft", "chaosorc");
    ui->next_spec_unit_2_->setUnitIcon("warcraft", "chaosorc");
    ui->next_spec_unit_3_->setUnitIcon("warcraft", "chaosorc");
    ui->next_spec_unit_4_->setUnitIcon("warcraft", "chaosorc");


    available_units_icons_[0]->setUnitIcon("warcraft", "blademaster");
    available_units_icons_[1]->setUnitIcon("warcraft", "chaosorc");
    available_units_icons_[2]->setUnitIcon("warcraft", "nagasummoner");
    available_units_icons_[3]->setUnitIcon("warcraft", "rogue");
    available_units_icons_[4]->setUnitIcon("norace", "nounit");
}

RecruitmentScene::~RecruitmentScene()
{
    delete ui;
}

void RecruitmentScene::parseArgs(QString args) {
    QStringList list = args.split("|");
    assert(list.size() >= 2);

    current_player_id_ = list[0].toInt();
    current_player_ = PlayerManager::getInstance().getPlayer(current_player_id_);
    available_money_ = list[1].toInt();
}

void RecruitmentScene::init() {
    current_money_ = available_money_;
    initAvailableRaces();
    initAvailableUnits();
    initChosenUnits();
}

void RecruitmentScene::initAvailableRaces() {
    auto races = RaceManager::getInstance().getAvailableRacesList();

    int race_id = 0;
    for (QString race_name : races) {
        assert(race_id < 5);
        auto race = RaceManager::getInstance().getRace(race_name);
        available_races_icons_[race_id]->setRaceIcon(race_name);
        race_id++;
    }


}

void RecruitmentScene::initAvailableUnits() {
    int unit_id = 0;
    for (Unit* unit : current_player_->getRace()->getAllUnitsList()) {
        available_units_icons_[unit_id]->setUnitIcon(unit->getUnitIcon());
        unit_id++;
    }
}

void RecruitmentScene::initChosenUnits() {

}


void RecruitmentScene::on_back_button_clicked()
{
    GuiSceneManager::getInstance().changeScene("main_menu");
}
