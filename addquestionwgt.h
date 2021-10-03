#ifndef ADDQUESTIONWGT_H
#define ADDQUESTIONWGT_H

#include <QWidget>
#include <QtWidgets>
#include "formwgt.h"
#include "questionsmodel.h"

class AddQuestionWgt : public QWidget
{
    Q_OBJECT
private:
    QuestionsModel *pQuestionsModel;

    FormWgt *pFormWgt = nullptr;
    QPushButton *pBackBtn = nullptr;
    QPushButton *pSaveBtn = nullptr;

    void initForm();
    void initButtons();
public:
    explicit AddQuestionWgt(QWidget *parent = nullptr, QString filename = "");
    ~AddQuestionWgt();

private slots:
    void onBackBtnClicked();
    void onSaveBtnClicked();
signals:
    void backEvent();
};

#endif // ADDQUESTIONWGT_H
