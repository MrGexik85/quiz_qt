#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
    * Constructor for mainWindow
    */

    qDebug("Start constructor main window");

    centralWgt = new QWidget(); // Init central widget
    this->setCentralWidget(centralWgt); // set central widget to MainWindow

    showStartMenu();

    qDebug("Success constructor for main window");
}

MainWindow::~MainWindow()
{
    /*
    * Destructor for mainWindow
    */
}

bool MainWindow::initStartMenu(){
    /*
    *   Init start menu interface
    *
    *   Init buttons and layout, check not null points, add buttons to layout
    *   connect btn signal(clicked) to neccessary slots
    *
    *   return: bool (success)
    */

    qDebug("Start init main menu");

    // Init main menu buttons
    pStartBtn = new QPushButton("Начать тест");
    pAddQuestionsBtn = new QPushButton("Добавить вопросы");
    pDelQuestionsBtn = new QPushButton("Удалить вопросы");
    pStatisticsBtn = new QPushButton("Посмотреть статистику");

    pVLayoutMain = new QVBoxLayout(); // Init layout

    // If some of widgets dont create -> close app
    if(!(pStartBtn && pAddQuestionsBtn && pDelQuestionsBtn && pStatisticsBtn && pVLayoutMain)){
        qDebug("Fail init main menu");
        return false;
    }

    // Init layout and adding buttons
    pVLayoutMain = new QVBoxLayout();
    pVLayoutMain->addWidget(pStartBtn);
    pVLayoutMain->addWidget(pAddQuestionsBtn);
    pVLayoutMain->addWidget(pDelQuestionsBtn);
    pVLayoutMain->addWidget(pStatisticsBtn);
    centralWgt->setLayout(pVLayoutMain);

    // connecting btnClicked event to the necessary slots
    connect(pStartBtn, SIGNAL(clicked()), this, SLOT(onStartClicked()));
    connect(pAddQuestionsBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
    connect(pDelQuestionsBtn, SIGNAL(clicked()), this, SLOT(onDelClicked()));
    connect(pStatisticsBtn, SIGNAL(clicked()), this, SLOT(onStatisticsClicked()));

    qDebug("Success init main menu");
    return true;
}

void MainWindow::showStartMenu(){
    /*
    *   Show main menu (start, add, del, stat)
    *
    *   If layout for main menu is exists, then add this layout to central widget
    *   without reinit, else init and check success (false - close app)
    *
    *   return: void
    */
    qDebug("Start show main menu");
    if(!pVLayoutMain) {
        if(!initStartMenu()) {
            qDebug("Fail show main menu");
            this->close();
            return;
        }
    }
    centralWgt->setLayout(pVLayoutMain);

    qDebug("Success show main menu");
}

void MainWindow::onStartClicked(){
    /*
    *   Action for start quiz button clicked
    *   show window with quiz
    */

    qDebug("Start btn clicked");
}

void MainWindow::onAddClicked(){
    /*
    *   Action for add questions button clicked
    *   show window with funcs to add some questions
    */

    qDebug("Add btn clicked");
}

void MainWindow::onDelClicked(){
    /*
    *   Action for delete questions button clicked
    *   show window with funcs to delete some questions
    */

    qDebug("Del btn clicked");
}

void MainWindow::onStatisticsClicked(){
    /*
    *   Action for statistics button clicked
    *   show window with user's statistics at quiz
    */

    qDebug("Statistics btn clicked");
}

