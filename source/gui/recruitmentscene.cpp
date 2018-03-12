#include <gui/recruitmentscene.h>
#include <gui/uniticon.h>

#include <ui_recruitmentscene.h>
#include <QHBoxLayout>

RecruitmentScene::RecruitmentScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecruitmentScene)
{
    ui->setupUi(this);

    for (int i = 0; i < 5; i++) {
        available_units_icons_[i] = new UnitIcon(ui->available_units_list_);
        ui->available_units_layout_->addWidget(available_units_icons_[i]);
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


    //available_units_icons_[0]->setUnitIcon("warcraft", "blademaster");
    //available_units_icons_[1]->setUnitIcon("warcraft", "chaosorc");
    //available_units_icons_[2]->setUnitIcon("warcraft", "nagasummoner");
    //available_units_icons_[3]->setUnitIcon("warcraft", "rogue");
    //available_units_icons_[4]->setUnitIcon("warcraft", "ogremagi");
}

RecruitmentScene::~RecruitmentScene()
{
    delete ui;
}
