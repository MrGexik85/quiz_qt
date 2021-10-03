#include "addquestionwgt.h"

AddQuestionWgt::AddQuestionWgt(QWidget *parent, QString filename) :
    QWidget(parent)
{
    initForm();
    initButtons();

    pQuestionsModel = new QuestionsModel(filename);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(pFormWgt);
    layout->addWidget(pSaveBtn);
    layout->addWidget(pBackBtn);

    this->setLayout(layout);

    qDebug() << "addQuestionWgt(constructor): Success";
}

AddQuestionWgt::~AddQuestionWgt() {
    delete pQuestionsModel;
    qDebug() << "addQuestionWgt(destructor): Success";
}

void AddQuestionWgt::initForm() {
    /*
     *  Initialize form for get questions info
     *
     *  return: void
    */

    pFormWgt = new FormWgt();
}

void AddQuestionWgt::initButtons() {
    /*
     *  Initialize buttons and set seignals to slots
     *
     * return: void
    */

    pBackBtn = new QPushButton("Назад", this);
    connect(pBackBtn, SIGNAL(clicked()), this, SLOT(onBackBtnClicked()));

    pSaveBtn = new QPushButton("Сохранить", this);
    connect(pSaveBtn, SIGNAL(clicked()), this, SLOT(onSaveBtnClicked()));


    qDebug() << "addQuestionWgt(initButtons): Success";
}

/* SLOTS */

void AddQuestionWgt::onBackBtnClicked() {
    /*
     *  Do something and emit backEvent
     *
     *  return: void
    */
    qDebug() << "addQuestionWgt(onBackBtnClicked): Button clicked";
    emit backEvent();
}

void AddQuestionWgt::onSaveBtnClicked() {
    /*
     *  Get data form form and save to XML file
     *
     *  return: void
    */
    qDebug() << "addQuestionWgt(onSaveBtnClicked): Button clicked";
    if(pFormWgt->isFieldsValid()) {
        QString question = pFormWgt->getQuestionString();
        QVector<bool> answRight = pFormWgt->getRightAnsw();
        QStringList answStrList = pFormWgt->getAnsws();

        QMessageBox::about(this, "Сохранить вопрос", "Успешно");

        pFormWgt->clearFields();
        pQuestionsModel->addNewRecord(question, answStrList.toVector(), answRight);
        // Сохранить в XML
    } else {
        QMessageBox::about(this, "Сохранить вопрос", "Ошибка, заполните все поля");
    }


}
