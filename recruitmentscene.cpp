#include "recruitmentscene.h"
#include "ui_recruitmentscene.h"

RecruitmentScene::RecruitmentScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecruitmentScene)
{
    ui->setupUi(this);
}

RecruitmentScene::~RecruitmentScene()
{
    delete ui;
}
