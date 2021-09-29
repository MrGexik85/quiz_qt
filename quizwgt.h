#ifndef QUIZWGT_H
#define QUIZWGT_H

#include <QWidget>
#include <QtWidgets>

class QuizWgt : public QWidget
{
    Q_OBJECT
private:
    QString filename;
public:
    explicit QuizWgt(QWidget *parent = nullptr, QString filename="");
    ~QuizWgt();
signals:
    void backEvent();
};

#endif // QUIZWGT_H
