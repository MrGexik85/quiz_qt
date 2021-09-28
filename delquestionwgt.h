#ifndef DELQUESTIONWGT_H
#define DELQUESTIONWGT_H

#include <QWidget>
#include <QtWidgets>

class DelQuestionWgt : public QWidget
{
    Q_OBJECT
private:
    QString filename = "";
public:
    explicit DelQuestionWgt(QWidget *parent = nullptr, QString questFile = "");
    ~DelQuestionWgt();
signals:
    void backEvent();
    void YuraGey();
};

#endif // DELQUESTIONWGT_H
