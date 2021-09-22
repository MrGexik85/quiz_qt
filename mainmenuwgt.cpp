#include "mainmenuwgt.h"

MainMenuWgt::MainMenuWgt(QWidget *parent) : QWidget(parent)
{
    /*
    *  Constructor for main menu widget
    */

    initButtons();
    initLayout();

    this->setLayout(pLayout);

    qDebug("mainMenuWgt: success constructor");
}

MainMenuWgt::~MainMenuWgt() {
    /*
    * Destructor for main menu widget
    */

    qDeleteAll(this->children());
    qDebug("mainMenuWgt: success destructor");
}

bool MainMenuWgt::initButtons() {
    /*
    *   Initialize buttons for this widget
    *
    *   return: bool (success)
    */

    qDebug("mainMenuWgt: start init buttons");

    // Init main menu buttons
    pStartBtn = new QPushButton("Начать тест");
    pAddQuestionsBtn = new QPushButton("Добавить вопросы");
    pDelQuestionsBtn = new QPushButton("Удалить вопросы");
    pStatisticsBtn = new QPushButton("Посмотреть статистику");

    // If some of widgets dont create -> return false
    if(!(pStartBtn && pAddQuestionsBtn && pDelQuestionsBtn && pStatisticsBtn)){
        qDebug("mainMenuWgt: fail init buttons");
        return false;
    }

    qDebug("mainMenuWgt: success init buttons");
    return true;
}

bool MainMenuWgt::initLayout() {
    /*
    *   Initialize layout for this widget
    *
    *   return: bool (success)
    */

    qDebug("mainMenuWgt: start init layout");

    pLayout = new QVBoxLayout();
    if(pLayout == nullptr) {
        qDebug("mainMenuWgt: fail to init layout");
        return false;
    }

    pLayout->addWidget(pStartBtn);
    pLayout->addWidget(pAddQuestionsBtn);
    pLayout->addWidget(pDelQuestionsBtn);
    pLayout->addWidget(pStatisticsBtn);

    qDebug("mainMenuWgt: success init layout");
    return true;
}
