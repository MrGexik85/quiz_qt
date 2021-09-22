#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
    * Constructor for mainWindow
    */

    qDebug("Start constructor main window");

    setStartMenuWgt();

    qDebug("mainWindow: success constructor");
}

MainWindow::~MainWindow()
{
    /*
    * Destructor for mainWindow
    */

    qDeleteAll(this->children());
    qDebug("mainWindow: Succes destructor");
}

void MainWindow::setStartMenuWgt() {
    /*
    *   Set start menu on main window
    *
    *   create mainMenu widget, connect signals to slots,
    *   set to central widget of main window
    *
    *   return: void
    */

    qDebug("mainWindow: start set start main menu");
    pMainMenuWgt = new MainMenuWgt(); // Init central widget
    this->setCentralWidget(pMainMenuWgt); // set central widget to MainWindow

    connect(pMainMenuWgt->pStartBtn, SIGNAL(clicked()), this, SLOT(onStartClicked()));
    connect(pMainMenuWgt->pAddQuestionsBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
    connect(pMainMenuWgt->pDelQuestionsBtn, SIGNAL(clicked()), this, SLOT(onDelClicked()));
    connect(pMainMenuWgt->pStatisticsBtn, SIGNAL(clicked()), this, SLOT(onStatisticsClicked()));

    qDebug("mainWindow: success set start main menu");
}

void MainWindow::onStartClicked(){
    /*
    *   Action for start quiz button clicked
    *   show window with quiz
    */

    qDebug("mainWindow: Start btn clicked");
}

void MainWindow::onAddClicked(){
    /*
    *   Action for add questions button clicked
    *   show window with funcs to add some questions
    */

    qDebug("mainWindow: Add btn clicked");
}

void MainWindow::onDelClicked(){
    /*
    *   Action for delete questions button clicked
    *   show window with funcs to delete some questions
    */

    qDebug("mainWindow: Del btn clicked");
}

void MainWindow::onStatisticsClicked(){
    /*
    *   Action for statistics button clicked
    *   show window with user's statistics at quiz
    */

    qDebug("mainWindow: Statistics btn clicked");
}

