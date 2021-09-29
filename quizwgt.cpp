#include "quizwgt.h"

QuizWgt::QuizWgt(QWidget *parent, QString filename) :
    QWidget(parent), filename(filename)
{

    qDebug() << "QuizWgt(constructor): Success";
}

QuizWgt::~QuizWgt(){

    qDebug() << "QuizWgt(destructor): Success";
}
