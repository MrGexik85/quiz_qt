#ifndef ADDQUESTIONWGT_H
#define ADDQUESTIONWGT_H

#include <QWidget>
#include <QtWidgets>

class AddQuestionWgt : public QWidget
{
    Q_OBJECT
private:
    QString filename;
public:
    explicit AddQuestionWgt(QWidget *parent = nullptr, QString filename = "");
    ~AddQuestionWgt();
signals:
    void backEvent();
};

#endif // ADDQUESTIONWGT_H
