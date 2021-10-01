#include "delquestionwgt.h"

DelQuestionWgt::DelQuestionWgt(QWidget *parent, QString questFile) :
    QWidget(parent), filename(questFile)
{
    QVBoxLayout *layout = new QVBoxLayout();

    initTable();
    initButtons();

    layout->addWidget(pQuestionsTable);
    layout->addWidget(pDelBtn);
    layout->addWidget(pBackBtn);

    this->setLayout(layout);

    qDebug() << "delQuestionWgt(constructor): Success";
}

DelQuestionWgt::~DelQuestionWgt() {
    // Save local questions list to xml file
    qDebug() << "delQuestionWgt(destructor): Success";
}

void DelQuestionWgt::initTable() {
    /*
    *   Initialize TableView and dataModel for this view
    *
    *   return: void
    */

    pQuestionsTable = new QTableView(this);
    pQuestionsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    pDataModel = new QStringListModel(this);
    pDataModel->setStringList(QStringList() << "Считать нормальными?"
                              << "Купить хлеба?");
    pQuestionsTable->setModel(pDataModel);

    qDebug() << "delQuestionWgt(initTable): Success";
}

void DelQuestionWgt::initButtons() {
    /*
     *  Initialize buttons and connect signals to slots
     *
     * return: void
    */

    pBackBtn = new QPushButton("Назад", this);
    connect(pBackBtn, SIGNAL(clicked()), this, SLOT(backBtnClicked()));

    pDelBtn = new QPushButton("Удалить вопрос", this);
    connect(pDelBtn, SIGNAL(clicked()), this, SLOT(delBtnClicked()));

    qDebug() << "delQuestionWgt(initButtons): Success";
}

/* SLOTS */
void DelQuestionWgt::backBtnClicked() {
    /*
     *  Do something and emit back signal
     *
     *  return: void
    */
    emit backEvent();
    qDebug() << "delQuestionWgt(backBtnClicked): Success";
}

void DelQuestionWgt::delBtnClicked() {
    /*
     *  Delete focus record from local memory
     *
     *  return: void
    */

    qDebug() << "delQuestionWgt(delBtnClicked): Success";
}
