#include "addquestionwgt.h"

AddQuestionWgt::AddQuestionWgt(QWidget *parent, QString filename) :
    QWidget(parent), filename(filename)
{
    qDebug() << "addQuestionWgt(constructor): Success";
}

AddQuestionWgt::~AddQuestionWgt() {

    qDebug() << "addQuestionWgt(destructor): Success";
}
