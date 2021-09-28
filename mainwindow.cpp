#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    statsFile = "stats.json";
    questionsFile = "questions.xml";

    // Check stats and questions files are exist
    if ((checkFilesExistOrCreate(statsFile) && checkFilesExistOrCreate(questionsFile)) == false) {
        exit(1);
    }

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

bool MainWindow::checkFilesExistOrCreate(QString &path_file) {
    /*
     *  Get file path, check file is exist, else create it
     *
     *  return: bool (success)
    */
    QFileInfo fileInfo(path_file);
    if(fileInfo.exists() && fileInfo.isFile()) {
        qDebug() << "mainWindow(checkFilesExistOrCreate):" << path_file << "is exist";
        return true;
    } else {
        QFile file(path_file);
        if (file.open(QIODevice::WriteOnly)) {
            file.close();
            qDebug() << "mainWindow(checkFilesExistOrCreate):" << path_file << "created";
            return true;
        } else {
            qDebug() << "mainWindow(checkFilesExistOrCreate):" << path_file << "didnt create";
            return false;
        }
    }
}

/* SLOTS */

void MainWindow::onStartClicked(){
    /*
    *   Action for start quiz button clicked
    *   show window with quiz
    */

    // Проверку что xml существует
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

    pStatisticsWgt = new StatisticsWgt(this);
    if(pStatisticsWgt == nullptr) {
        qDebug("mainWindow(onStatisticsClicked): fail to init Statistics widget");
        return;
    }

    this->setCentralWidget(pStatisticsWgt);
    delete pMainMenuWgt;
}

