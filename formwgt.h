#ifndef FORMWGT_H
#define FORMWGT_H

#include <QWidget>
#include <QtWidgets>

class FormWgt : public QWidget
{
    Q_OBJECT
private:
    QVector<QRadioButton*> answBtns;
    QVector<QLineEdit*> answInputs;
    QLineEdit *pQuestionLine = nullptr;

    QLayout* createNewAnswField();
public:
    explicit FormWgt(QWidget *parent = nullptr);
    ~FormWgt();

    bool isFieldsValid();
    QString getQuestionString();
    QVector<bool> getRightAnsw();
    QStringList getAnsws();
    void clearFields();
signals:

};

#endif // FORMWGT_H
