#include "mainmenulayout.h"

MainMenuLayout::MainMenuLayout(QWidget *parent) : QVBoxLayout(parent)
{
    /*
    * Constructor for mainMenu
    */
    qDebug("Start constructor main menu");
    initMainMenu();
    qDebug("Success constructor main menu");
}

MainMenuLayout::~MainMenuLayout(){
    /*
    * Destructor for mainMenu
    */
    qDebug("Success destructor main menu");
}

bool MainMenuLayout::initMainMenu(){
    /*
    *   Init start menu interface
    *
    *   Init buttons and layout, check not null points,
    *   add buttons to layout
    *
    *   return: bool (success)
    */

    qDebug("Start init main menu");

    // Init main menu buttons
    pStartBtn = new QPushButton("Начать тест");
    pAddQuestionsBtn = new QPushButton("Добавить вопросы");
    pDelQuestionsBtn = new QPushButton("Удалить вопросы");
    pStatisticsBtn = new QPushButton("Посмотреть статистику");

    // If some of widgets dont create -> return false
    if(!(pStartBtn && pAddQuestionsBtn && pDelQuestionsBtn && pStatisticsBtn)){
        qDebug("Fail init main menu");
        return false;
    }

    // Init layout and adding buttons
    this->addWidget(pStartBtn);
    this->addWidget(pAddQuestionsBtn);
    this->addWidget(pDelQuestionsBtn);
    this->addWidget(pStatisticsBtn);

    qDebug("Success init main menu");
    return true;
}
