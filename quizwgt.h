#ifndef QUIZWGT_H
#define QUIZWGT_H

#include <QWidget>
#include <QtWidgets>
#include "questionsmodel.h"

class QuizWgt : public QWidget
{
    Q_OBJECT
private:
    QuestionsModel *pQuestModel;
    QVBoxLayout *layout;

    QLabel *pQuestionHead;
    QVector<QRadioButton*> radioBtns;
    QVector<QLabel*> answs;

    int questionsCount;
    int nRight;
    int nWrong;

    bool initForm();
    bool initButtons();
    bool saveResultTo(QString file);
    void setQuestion(int index);
    bool checkQuestion(QVector<bool> userAnsw, QVector<bool> rightAnsw);
public:
    explicit QuizWgt(QWidget *parent = nullptr, QString filename="");
    ~QuizWgt();

private slots:
    void onBackBtnClicked();
    void onRespondBtnClicked();
signals:
    void backEvent();
};

#endif // QUIZWGT_H
