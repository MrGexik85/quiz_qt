#include "questionsmodel.h"

QuestionsModel::QuestionsModel(QString filename) : filename(filename)
{
    opened = readDataFrom(filename);
    qDebug() << "questionsModel(constructor): Success";
}

QuestionsModel::~QuestionsModel() {
    saveDataTo(filename);
    qDebug() << "questionsModel(destructor): Success";
}

bool QuestionsModel::isOpened() {
    /*
     *  Check that data of questions is valid
     *
     *  return: bool (data in not null)
    */
    return opened;
}

bool QuestionsModel::readDataFrom(QString filename) {
    /* (in work)
     *
     *
     *  return: bool (Success)
    */

    qDebug() << "questionsModel(readDataFrom): Success read from:" << filename;
    return true;
}

bool QuestionsModel::saveDataTo(QString filename) {
    /* (in work)
     *
     *
     *  return: bool (Success)
    */

    qDebug() << "questionsModel(saveDataTo): Success save to:" << filename;
    return true;
}

bool QuestionsModel::deleteRecord(int index) {
    /* (in work)
     *
     *
     * return: bool (success)
    */
    qDebug() << "questionsModel(deleteRecord): Success deleted from:" << index << "index";
    return true;
}

bool QuestionsModel::addNewRecord(QString header, QVector<QString> answs, QVector<bool> rightAnsws) {
    /*
     *  Create Question object and save to data
     *
     *  return: bool (success)
    */
    Question question;
    question.questionHeader = header;
    question.answs = answs;
    question.rightAnsws = rightAnsws;

    data.push_back(question);

    qDebug() << "questionsModel(deleteRecord): Success added";
    return true;
}

Question QuestionsModel::getQuestionData(int index) {
    /*
     *  Get Questions DS from index
     *
     *  return: Question
    */
    qDebug() << "qestionsModel(getQuestionData): Success";
    return data[index];
}

QStringList QuestionsModel::getQuestionsHead() {
    /*
     *  Get list of question's text
     *
     *  return: QStringList
    */

    QStringList list;
    for(int i = 0; i < data.size(); i++) {
        list << data[i].questionHeader;
    }

    qDebug() << "questionsModel(getQuestionsHead): Success returned:" << list;
    return list;
}

int QuestionsModel::size() {
    /*
     *  Get count of questions at now
     *
     *  return: int
    */
    return data.size();
}



