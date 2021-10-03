#ifndef QUESTIONSMODEL_H
#define QUESTIONSMODEL_H

#include <QtWidgets>

struct Question {
    QString questionHeader;
    QVector<QString> answs;
    QVector<bool> rightAnsws;
};

class QuestionsModel
{
private:
    bool opened;
    QString filename;
    QVector<Question> data;

    bool readDataFrom(QString filename);
    bool saveDataTo(QString filename);
public:
    QuestionsModel(QString filename);
    ~QuestionsModel();

    bool isOpened();
    bool deleteRecord(int index);
    bool addNewRecord(QString header, QVector<QString> answs, QVector<bool> rightAnsws);
    QStringList getQuestionsHead();
    Question getQuestionData(int index);
    int size();
};

#endif // QUESTIONSMODEL_H
