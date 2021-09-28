#include "delquestionwgt.h"

DelQuestionWgt::DelQuestionWgt(QWidget *parent, QString questFile) :
    QWidget(parent), filename(questFile)
{

    qDebug() << "delQuestionWgt(constructor): Success";
}

DelQuestionWgt::~DelQuestionWgt() {

    qDebug() << "delQuestionWgt(destructor): Success";
}
