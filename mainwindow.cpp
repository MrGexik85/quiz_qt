#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setStartMenuWgt();

    qDebug("mainWindow(constructor): Success");
}

MainWindow::~MainWindow()
{
    qDeleteAll(this->children());
    qDebug("mainWindow(destrucor): Succes");
}

void MainWindow::setStartMenuWgt() {
    /*
    *   Create mainMenu widget, connect signals to slots,
    *   set to central widget of main window
    *
    *   return: void
    */
    pMainMenuWgt = new MainMenuWgt(this);
    this->setCentralWidget(pMainMenuWgt);

    connect(pMainMenuWgt->pStartBtn, SIGNAL(clicked()), this, SLOT(onStartClicked()));
    connect(pMainMenuWgt->pAddQuestionsBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
    connect(pMainMenuWgt->pDelQuestionsBtn, SIGNAL(clicked()), this, SLOT(onDelClicked()));
    connect(pMainMenuWgt->pStatisticsBtn, SIGNAL(clicked()), this, SLOT(onStatisticsClicked()));

    qDebug("mainWindow(setStartMenuWgt): Success");
}

/* SLOTS */

void MainWindow::onStartClicked(){
    /*
    *   Action for start quiz button clicked
    *   show window with quiz
    */

    qDebug("mainWindow(onStartClicked): Start btn clicked");
}

void MainWindow::onAddClicked(){
    /*
    *   Action for add questions button clicked
    *   show window with funcs to add some questions
    */

    qDebug("mainWindow(onAddClicked): Add btn clicked");
}

void MainWindow::onDelClicked(){
    /*
    *   Action for delete questions button clicked
    *   show window with funcs to delete some questions
    */

    qDebug("mainWindow(onDelClicked): Del btn clicked");
}

void MainWindow::onStatisticsClicked(){
    /*
    *   Action for statistics button clicked
    *   show window with user's statistics at quiz
    */

    qDebug("mainWindow(onStatisticsClicked): Statistics btn clicked");
}

