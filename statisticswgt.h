#ifndef STATISTICSWGT_H
#define STATISTICSWGT_H

#include <QWidget>
#include <QtWidgets>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>

class StatisticsWgt : public QWidget
{
    Q_OBJECT

private:
    QString filename;
    QTableWidget *pDataTable = nullptr;
    QPushButton *pBackBtn = nullptr;

    QVector<QStringList> getDataFromFile(QJsonArray data);
    QStringList getLabelsFromFile(QJsonArray data);
    QTableWidget* getTable();
    QJsonDocument getJsonDocument();
public:
    explicit StatisticsWgt(QWidget *parent = nullptr, QString dataFile = "");
    ~StatisticsWgt();

private slots:
    void backBtnClicked();
signals:
    void backEvent();
};

#endif // STATISTICSWGT_H
