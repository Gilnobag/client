#include "gui/guiscenemanager.h"
#include "gui/gui.h"
#include "gui/detatchedwidget.h"
#include "gui/mainmenu.h"
#include "gui/playervsplayerintro.h"

GuiSceneManager::GuiSceneManager(QObject *parent) : QObject(parent) {
    gui_ = new GUI();
    gui_->show();
    current_scene_ = "none";

    registerScene("main_menu", new MainMenu(gui_->mainContentScene()));
    registerScene("pvp_intro", new PlayerVsPlayerIntro(gui_->mainContentScene()));
    registerScene("recruit_army", new RecruitmentScene(gui_->mainContentScene()));

    changeScene("main_menu");
}

GuiSceneManager::~GuiSceneManager() {}


bool GuiSceneManager::registerScene(QString scene_name, Scene* name) {
    if (scene_name == "none")
        return false;

    if (scenes_.count(scene_name) != 0) {
        delete name;
        return false;
    }

    scenes_[scene_name] = name;
    return true;
}

bool GuiSceneManager::changeScene(QString scene_name, QString args) {
    if (scene_name == "main_window") {
        return false;
    }

    if (current_scene_ != "none")
        scenes_[current_scene_]->hide();

    scenes_[scene_name]->parseArgs(args);
    scenes_[scene_name]->show();
    current_scene_ = scene_name;
    return true;
}

void GuiSceneManager::createDetachedScene(QString scene_name) {
    /// TO BE DONE!!!
}

void GuiSceneManager::destroyDetachedScene(QString scene_name) {
    /// TO BE DONE!!!
}

