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
#include <vector>

RecruitmentScene::RecruitmentScene(QWidget *parent)
    : Scene(parent)
    , ui(new Ui::RecruitmentScene)
{
    ui->setupUi(this);

    for (int i = 0; i < 5; i++) {
        available_units_icons_[i] = new UnitIcon();
        ui->available_units_layout_->addWidget(available_units_icons_[i], 0, i);

        connect(available_units_icons_[i], SIGNAL(clicked(UnitIcon*)), this, SLOT(onUnitIconClicked(UnitIcon*)));
        connect(available_units_icons_[i], SIGNAL(hovered(UnitIcon*)), this, SLOT(onUnitIconHovered(UnitIcon*)));
        connect(available_units_icons_[i], SIGNAL(unhovered(UnitIcon*)), this, SLOT(onUnitIconUnHovered(UnitIcon*)));
        connect(available_units_icons_[i], SIGNAL(doubleclicked(UnitIcon*)), this, SLOT(onUnitIconDoubleClicked(UnitIcon*)));
    }

    for (int i = 0; i < 3; i++) {
        available_races_icons_[i] = new RaceIcon();
        ui->availableRacesLayout_->addWidget(available_races_icons_[i], i);

        connect(available_races_icons_[i], SIGNAL(clicked(RaceIcon*)), this, SLOT(onRaceIconClicked(RaceIcon*)));
        connect(available_races_icons_[i], SIGNAL(hovered(RaceIcon*)), this, SLOT(onRaceIconHovered(RaceIcon*)));
        connect(available_races_icons_[i], SIGNAL(unhovered(RaceIcon*)), this, SLOT(onRaceIconUnHovered(RaceIcon*)));
        connect(available_races_icons_[i], SIGNAL(doubleclicked(RaceIcon*)), this, SLOT(onRaceIconDoubleClicked(RaceIcon*)));

    }

    for (int i = 0; i < 10; i++) {
        chosen_units_icons_[i] = new UnitIcon();
        ui->chosen_units_layout_->addWidget(chosen_units_icons_[i], i / 5, i % 5);

        connect(chosen_units_icons_[i], SIGNAL(clicked(UnitIcon*)), this, SLOT(onChosenUnitIconClicked(UnitIcon*)));
        connect(chosen_units_icons_[i], SIGNAL(hovered(UnitIcon*)), this, SLOT(onChosenUnitIconHovered(UnitIcon*)));
        connect(chosen_units_icons_[i], SIGNAL(unhovered(UnitIcon*)), this, SLOT(onChosenUnitIconUnHovered(UnitIcon*)));
        connect(chosen_units_icons_[i], SIGNAL(doubleclicked(UnitIcon*)), this, SLOT(onChosenUnitIconDoubleClicked(UnitIcon*)));
    }

    for (int i = 0; i < 4; i++) {
        prev_grade_units_icons[i] = new UnitIcon();
        ui->prev_gen_units_layout->addWidget(prev_grade_units_icons[i]);

        connect(prev_grade_units_icons[i], SIGNAL(clicked(UnitIcon*)), this, SLOT(onGradeUnitIconClicked(UnitIcon*)));
        connect(prev_grade_units_icons[i], SIGNAL(hovered(UnitIcon*)), this, SLOT(onGradeUnitIconHovered(UnitIcon*)));
        connect(prev_grade_units_icons[i], SIGNAL(unhovered(UnitIcon*)), this, SLOT(onGradeUnitIconUnHovered(UnitIcon*)));
        connect(prev_grade_units_icons[i], SIGNAL(doubleclicked(UnitIcon*)), this, SLOT(onGradeUnitIconDoubleClicked(UnitIcon*)));


        next_grade_units_icons[i] = new UnitIcon();
        ui->next_gen_units_layout_->addWidget(next_grade_units_icons[i]);

        connect(next_grade_units_icons[i], SIGNAL(clicked(UnitIcon*)), this, SLOT(onGradeUnitIconClicked(UnitIcon*)));
        connect(next_grade_units_icons[i], SIGNAL(hovered(UnitIcon*)), this, SLOT(onGradeUnitIconHovered(UnitIcon*)));
        connect(next_grade_units_icons[i], SIGNAL(unhovered(UnitIcon*)), this, SLOT(onGradeUnitIconUnHovered(UnitIcon*)));
        connect(next_grade_units_icons[i], SIGNAL(doubleclicked(UnitIcon*)), this, SLOT(onGradeUnitIconDoubleClicked(UnitIcon*)));
    }

    ui->description_icon_->resize(45, 45);
    ui->description_text_->setWordWrap(true);

    ui->current_spec_unit_->resize(45, 45);
    ui->current_spec_unit_->setUnitIcon("warcraft", "chaosorc");
}

RecruitmentScene::~RecruitmentScene()
{
}

void RecruitmentScene::parseArgs(QString args) {
    QStringList list = args.split("|");
    assert(list.size() >= 2);

    current_player_id_ = list[0].toInt();
    current_player_ = PlayerManager::getInstance().getPlayer(current_player_id_);
    available_money_ = list[1].toInt();

    init();
}

void RecruitmentScene::init() {
    current_money_ = available_money_;
    initAvailableRaces();
    initAvailableUnits();
    showChosenUnits();

    ui->title_->setText(
        "<html><head/><body><p align=\"center\"><span style=\"font-size:24pt; color:#b12d2d;\">Набор юнитов - "
        + current_player_->getPlayerName()
        + "</span></p></body></html>"
    );

    setDescriptionIcon(current_player_->getRace()->getRaceIcon());
    setDescriptionText(current_player_->getRace()->getRaceDescr());
    setDescriptionTitle(current_player_->getRace()->getRaceName());

    ui->chosen_race_image_->resize(100, 100);
    ui->chosen_race_image_->setRaceIcon(current_player_->getRace()->getRaceIcon());
    ui->chosen_race_image_->setState(5);

    ui->unit_spec_widget_->hide();

    setMoney(current_money_);
}

void RecruitmentScene::initAvailableRaces() {
    auto races = RaceManager::getInstance().getAvailableRacesList();

    int race_id = 0;
    for (QString race_name : races) {
        assert(race_id < 3);
        auto race = RaceManager::getInstance().getRace(race_name);
        available_races_icons_[race_id]->setRaceIcon(race->getRaceIcon());
        available_races_icons_[race_id]->setRace(race);
        race_id++;
    }


}

void RecruitmentScene::initAvailableUnits() {
    int unit_id = 0;
    for (int i = 0; i < 5; i++) {
        available_units_icons_[i]->setUnitIcon("norace", "nounit");
        available_units_icons_[i]->setState(5);
    }

    for (Unit* unit : current_player_->getRace()->getAllUnitsList()) {
        available_units_icons_[unit_id]->setState(0);
        available_units_icons_[unit_id]->setUnitIcon(unit->getUnitIcon());
        available_units_icons_[unit_id]->setUnit(unit);
        unit_id++;
    }
}

void RecruitmentScene::showChosenUnits() {
    for (int i = 0; i < 10; i++) {
        chosen_units_icons_[i]->unsetUnitIcon();
        chosen_units_icons_[i]->setUnit(nullptr);
    }

    int counter = 0;
    for (auto unit : current_player_->getUnits()) {
        chosen_units_icons_[counter]->setUnitIcon(unit->getUnitIcon());
        chosen_units_icons_[counter]->setUnit(unit);
        counter++;
    }
}

void RecruitmentScene::updateSpecsWidget(Unit *unit) {
    auto next_specs = unit->getUpgradeSpecs();
    auto prev_specs = unit->getParentSpecs();

    ui->prev_gen_units_list_->resize(45 * prev_specs.size(), 45);
    ui->next_gen_units_list_->resize(45 * next_specs.size(), 45);

    ui->prev_gen_units_list_->move((180 - 45 * prev_specs.size()) / 2, 40);
    ui->next_gen_units_list_->move((180 - 45 * next_specs.size()) / 2, 240);

    for (int i = 0; i < 4; i++) {
        prev_grade_units_icons[i]->hide();
        next_grade_units_icons[i]->hide();
    }

    int prev_specs_num = 0;
    for (unsigned i = 0; i < prev_specs.size(); i++) {
        if (prev_specs[i].length() <= 2)
            continue;

        delete prev_grade_units_icons[i]->getUnit();

        prev_grade_units_icons[i]->resize(45, 45);
        prev_grade_units_icons[i]->unsetUnitIcon();
        prev_grade_units_icons[i]->setUnit(current_player_->getRace()->createUnit(prev_specs[i]));
        prev_grade_units_icons[i]->show();

        prev_specs_num++;
    }

    if (prev_specs_num == 0) {
        ui->spec_title_->move(0, 110);
        ui->prev_gen_units_list_->hide();
        ui->arrow_down_1_->hide();
    } else {
        ui->spec_title_->move(0, 10);
        ui->prev_gen_units_list_->show();
        ui->arrow_down_1_->show();
    }

    int next_specs_num = 0;
    for (unsigned i = 0; i < next_specs.size(); i++) {
        if (next_specs[i].length() <= 2)
            continue;

        delete next_grade_units_icons[i]->getUnit();

        next_grade_units_icons[i]->resize(45, 45);
        next_grade_units_icons[i]->unsetUnitIcon();
        next_grade_units_icons[i]->setUnit(current_player_->getRace()->createUnit(next_specs[i]));
        next_grade_units_icons[i]->show();

        next_specs_num++;
    }

    if (next_specs_num == 0) {
        ui->next_gen_units_list_->hide();
        ui->arrow_down_2_->hide();
    } else {
        ui->next_gen_units_list_->show();
        ui->arrow_down_2_->show();
    }

    ui->current_spec_unit_->setUnit(unit);
    ui->current_spec_unit_->setState(5);
}

void RecruitmentScene::changeRace(Race *race) {
    current_player_->clearUnits();
    current_player_->setRace(race);
    init();
}

void RecruitmentScene::setMoney(int money_) {
   ui->available_money_text_->setText("<html><head/><body><p>"
                                      "<span style=\"font-size:10pt; color:#ff0000;\">Ресурсы: "
                                      + QString::number(money_) +
                                      "</span></p></body></html>");
}



void RecruitmentScene::on_back_button_clicked()
{
    GuiSceneManager::getInstance().changeScene("main_menu");
}



void RecruitmentScene::setDescriptionTitle(QString title) {
    ui->desctiption_title_->setText("<html><head/><body><p align=\"center\">"
                                    "<span style=\" font-weight:600; font-size:16px; color:#000080;\">"
                                    + title +
                                    "</span></p></body></html>");
}

void RecruitmentScene::setDescriptionText(QString text) {
    ui->description_text_->setText("<html><head/><body><p><span style=\"color:#000080;\">"
                                   + text
                                   + "</span></p></body></html>");
}

void RecruitmentScene::setDescriptionIcon(QImage icon) {
    ui->description_icon_->setUnitIcon(icon);
    ui->description_icon_->setState(0);
}




void RecruitmentScene::onUnitIconHovered(UnitIcon*) {

}

void RecruitmentScene::onUnitIconUnHovered(UnitIcon*) {

}

void RecruitmentScene::onUnitIconClicked(UnitIcon* icon) {
    setDescriptionIcon(icon->getUnit()->getUnitIcon());
    setDescriptionText(icon->getUnit()->getUnitDescr());
    setDescriptionTitle(icon->getUnit()->getUnitName());

    for (int i = 0; i < 5; i++) {
        if (available_units_icons_[i] != icon)
            available_units_icons_[i]->deactivate();
    }

    for (int i = 0; i < 10; i++) {
        chosen_units_icons_[i]->deactivate();
    }

    for (int i = 0; i < 3; i++) {
        available_races_icons_[i]->deactivate();
    }

    ui->unit_spec_widget_->hide();
}

void RecruitmentScene::onUnitIconDoubleClicked(UnitIcon* icon) {
    if (current_player_->getUnits().size() >= 10)
        return;

    current_player_->addUnit(current_player_->getRace()->createUnit(icon->getUnit()->getUnitId()));
    showChosenUnits();
}



void RecruitmentScene::onChosenUnitIconHovered(UnitIcon*) {}

void RecruitmentScene::onChosenUnitIconUnHovered(UnitIcon*) {}

void RecruitmentScene::onChosenUnitIconClicked(UnitIcon* icon) {
    setDescriptionIcon(icon->getUnit()->getUnitIcon());
    setDescriptionText(icon->getUnit()->getUnitDescr());
    setDescriptionTitle(icon->getUnit()->getUnitName());

    for (int i = 0; i < 5; i++) {
        available_units_icons_[i]->deactivate();
    }

    for (int i = 0; i < 10; i++) {
        if (chosen_units_icons_[i] != icon)
            chosen_units_icons_[i]->deactivate();
    }

    for (int i = 0; i < 3; i++) {
        available_races_icons_[i]->deactivate();
    }

    updateSpecsWidget(icon->getUnit());
    ui->unit_spec_widget_->show();
}

void RecruitmentScene::onChosenUnitIconDoubleClicked(UnitIcon* icon) {
    current_player_->deleteUnit(icon->getUnit());
    showChosenUnits();
    ui->unit_spec_widget_->hide();
}



void RecruitmentScene::onRaceIconHovered(RaceIcon*) {

}

void RecruitmentScene::onRaceIconUnHovered(RaceIcon*) {

}

void RecruitmentScene::onRaceIconClicked(RaceIcon* icon) {
    setDescriptionIcon(icon->getRace()->getRaceIcon());
    setDescriptionText(icon->getRace()->getRaceDescr());
    setDescriptionTitle(icon->getRace()->getRaceName());

    for (int i = 0; i < 5; i++) {
        available_units_icons_[i]->deactivate();
    }

    for (int i = 0; i < 10; i++) {
        chosen_units_icons_[i]->deactivate();
    }

    for (int i = 0; i < 3; i++) {
        if (available_races_icons_[i] != icon)
            available_races_icons_[i]->deactivate();
    }

    ui->unit_spec_widget_->hide();
}

void RecruitmentScene::onRaceIconDoubleClicked(RaceIcon* icon) {
    if (icon->getRace() != current_player_->getRace())
        changeRace(icon->getRace());
}


void RecruitmentScene::onGradeUnitIconHovered(UnitIcon*) {}

void RecruitmentScene::onGradeUnitIconUnHovered(UnitIcon*) {}

void RecruitmentScene::onGradeUnitIconClicked(UnitIcon* icon) {
    setDescriptionIcon(icon->getUnit()->getUnitIcon());
    setDescriptionText(icon->getUnit()->getUnitDescr());
    setDescriptionTitle(icon->getUnit()->getUnitName());

    for (int i = 0; i < 4; i++) {
        if (prev_grade_units_icons[i] != icon)
            prev_grade_units_icons[i]->deactivate();
        if (next_grade_units_icons[i] != icon)
            next_grade_units_icons[i]->deactivate();
    }
}

void RecruitmentScene::onGradeUnitIconDoubleClicked(UnitIcon* icon) {
    current_player_->deleteUnit(ui->current_spec_unit_->getUnit());

    auto new_unit = current_player_->getRace()->createUnit(icon->getUnit()->getUnitId());

    current_player_->addUnit(new_unit);

    updateSpecsWidget(new_unit);
    showChosenUnits();

    for (int i = 0; i < 10; i++) {
        if (chosen_units_icons_[i]->getUnit() == new_unit)
            chosen_units_icons_[i]->activate();
    }
    current_money_ -= 100;
    setMoney(current_money_);
}


void RecruitmentScene::on_apply_clicked()
{
    qDebug() << "Exiting recruit army scene with player_id =" << current_player_id_;
    if (current_player_id_ == 0) {
        qDebug() << "Changing to 1";
        GuiSceneManager::getInstance().changeScene("recruit_army", "1|" + QString::number(available_money_));
    } else {
        GuiSceneManager::getInstance().changeScene("prebattle");
    }
}
