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


void MainWindow::showStartMenu(){
    /*
    *   Show main menu (start, add, del, stat)
    *
    *   If layout for main menu is exists, then add this layout to central widget
    *   without reinit, else - init
    *
    *   return: void
    */
    qDebug("Start show main menu");
    if(!pMainMenuLayout) {
        pMainMenuLayout = new MainMenuLayout();
        connect(pMainMenuLayout->pStartBtn, SIGNAL(clicked()), this, SLOT(onStartClicked()));
        connect(pMainMenuLayout->pAddQuestionsBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
        connect(pMainMenuLayout->pDelQuestionsBtn, SIGNAL(clicked()), this, SLOT(onDelClicked()));
        connect(pMainMenuLayout->pStatisticsBtn, SIGNAL(clicked()), this, SLOT(onStatisticsClicked()));
    }
    centralWgt->setLayout(pMainMenuLayout);

    qDebug("Success show main menu");
}

void MainWindow::onStartClicked(){
    /*
    *   Action for start quiz button clicked
    *   show window with quiz
    */

    qDebug("Start btn clicked");

//    qDeleteAll(centralWgt->children());
//    this->pMainMenuLayout = nullptr;
//    centralWgt->setLayout(new QHBoxLayout());
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

