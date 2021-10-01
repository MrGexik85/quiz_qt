#ifndef DELQUESTIONWGT_H
#define DELQUESTIONWGT_H

#include <QWidget>
#include <QtWidgets>

class DelQuestionWgt : public QWidget
{
    Q_OBJECT
private:
    QString filename = "";
    QTableView *pQuestionsTable = nullptr;
    QStringListModel *pDataModel = nullptr;

    QPushButton *pBackBtn = nullptr;
    QPushButton *pDelBtn = nullptr;

    void initTable();
    void initButtons();
public:
    explicit DelQuestionWgt(QWidget *parent = nullptr, QString questFile = "");
    ~DelQuestionWgt();

private slots:
    void backBtnClicked();
    void delBtnClicked();
signals:
    void backEvent();

};

#endif // DELQUESTIONWGT_H
