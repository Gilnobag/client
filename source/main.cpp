#include <gui/guiscenemanager.h>
#include <gui/gui.h>
#include <gui/recruitmentscene.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GuiSceneManager::getInstance().changeScene("main_menu");
    return a.exec();
}
