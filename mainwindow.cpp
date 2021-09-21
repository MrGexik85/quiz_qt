#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    centralWgt = new QWidget(); // Init central widget
    // Init main menu buttons
    pStartBtn = new QPushButton("Начать тест");
    connect(pStartBtn, SIGNAL(clicked()), this, SLOT(onStartClicked()));
    pAddQuestionsBtn = new QPushButton("Добавить вопросы");
    connect(pAddQuestionsBtn, SIGNAL(clicked()), this, SLOT(onAddClicked()));
    pDelQuestionsBtn = new QPushButton("Удалить вопросы");
    connect(pDelQuestionsBtn, SIGNAL(clicked()), this, SLOT(onDelClicked()));
    pStatisticsBtn = new QPushButton("Посмотреть статистику");
    connect(pStatisticsBtn, SIGNAL(clicked()), this, SLOT(onStatisticsClicked()));

    // Init layout and adding buttons
    pVlayout = new QVBoxLayout();
    pVlayout->addWidget(pStartBtn);
    pVlayout->addWidget(pAddQuestionsBtn);
    pVlayout->addWidget(pDelQuestionsBtn);
    pVlayout->addWidget(pStatisticsBtn);
    centralWgt->setLayout(pVlayout);

    this->setCentralWidget(centralWgt); // set central widget to MainWindow
}

MainWindow::~MainWindow()
{

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

