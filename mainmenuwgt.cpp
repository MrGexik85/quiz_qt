#include "mainmenuwgt.h"

MainMenuWgt::MainMenuWgt(QWidget *parent) : QWidget(parent)
{
    initButtons();
    initLayout();

    this->setLayout(pLayout);

    qDebug("mainMenuWgt(constructor): Success");
}

MainMenuWgt::~MainMenuWgt() {
    qDeleteAll(this->children());
    qDebug("mainMenuWgt(destructor): Success");
}

bool MainMenuWgt::initButtons() {
    /*
    *   Initialize buttons for this widget
    *
    *   return: bool (success)
    */
    pStartBtn = new QPushButton("Начать тест");
    pAddQuestionsBtn = new QPushButton("Добавить вопросы");
    pDelQuestionsBtn = new QPushButton("Удалить вопросы");
    pStatisticsBtn = new QPushButton("Посмотреть статистику");

    // If some of buttons dont create
    if(!(pStartBtn && pAddQuestionsBtn && pDelQuestionsBtn && pStatisticsBtn)){
        qDebug("mainMenuWgt(initButtons): Some button was not init");
        return false;
    }

    qDebug("mainMenuWgt(initButtons): Success init buttons");
    return true;
}

bool MainMenuWgt::initLayout() {
    /*
    *   Initialize layout for this widget
    *
    *   return: bool (success)
    */
    pLayout = new QVBoxLayout();
    if(pLayout == nullptr) {
        qDebug("mainMenuWgt(initLayout): Layout was not init");
        return false;
    }

    pLayout->addWidget(pStartBtn);
    pLayout->addWidget(pAddQuestionsBtn);
    pLayout->addWidget(pDelQuestionsBtn);
    pLayout->addWidget(pStatisticsBtn);

    qDebug("mainMenuWgt(initLayout): Success init layout");
    return true;
}
