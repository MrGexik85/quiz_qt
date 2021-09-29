#include "delquestionwgt.h"

DelQuestionWgt::DelQuestionWgt(QWidget *parent, QString questFile) :
    QWidget(parent), filename(questFile)
{
    QVBoxLayout *layout = new QVBoxLayout();
    pQuestionsTable = new QTableView(this);
    pDataModel = new QStringListModel(QStringList() << "Коммит бомба"
                                                       "Честно говоря");
    pQuestionsTable->setModel(pDataModel);
    layout->addWidget(pQuestionsTable);

    this->setLayout(layout);

    qDebug() << "delQuestionWgt(constructor): Success";
}

DelQuestionWgt::~DelQuestionWgt() {
    // Save local questions list to xml file
    qDebug() << "delQuestionWgt(destructor): Success";
}

/* SLOTS */
void DelQuestionWgt::backBtnClicked() {
    /*
     *  Do something and emit back signal
     *
     *  return: void
    */
    emit backEvent();
}

void DelQuestionWgt::delBtnClicked() {
    /*
     *  Delete focus record from local memory
     *
     *  return: void
    */
}
