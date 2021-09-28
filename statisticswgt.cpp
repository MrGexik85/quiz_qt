#include "statisticswgt.h"

StatisticsWgt::StatisticsWgt(QWidget *parent, QString dataFile) : QWidget(parent)
{
    filename = dataFile;
    pBackBtn = new QPushButton("Назад", this);
    connect(pBackBtn, SIGNAL(clicked()), this, SLOT(backBtnClicked()));

    pDataTable = getTable();
    pDataTable->setEnabled(false);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(pDataTable);
    pLayout->addWidget(pBackBtn);

    this->setLayout(pLayout);

    qDebug("statisticsWgt(constructor): Success");
}

StatisticsWgt::~StatisticsWgt() {
    qDebug("statisticsWgt(destructor): Success");
}

QStringList StatisticsWgt::getLabelsFromFile(QJsonArray data){
    /*
    *   Get labels for table from json
    *
    *   return: QStringList (list with labels)
    */

    QStringList list;

    foreach(QJsonValue value, data){
        list << value.toString();
    }
    qDebug() << "StatisticsWgt(getLabelsFromFile): success get labels for statistics table:" << list;
    return list;
}

QVector<QStringList> StatisticsWgt::getDataFromFile(QJsonArray data) {
    /*
    *   Get main data with results from json
    *
    *   return: QVector<QStrinList> (items with data for each string)
    */

    QVector<QStringList> vector;
    foreach(QJsonValue value, data) {
        QStringList list;
        QJsonObject obj = value.toObject();
        QString id = QString::number(obj["id"].toInt());

        QDateTime timestamp;
        timestamp.setTime_t(obj["timestamp"].toInt());
        QDate date = timestamp.date();
        QString day = QString::number(date.day());
        QString month = QString::number(date.month());
        month = month.size() < 2 ? "0" + month : month;
        QString year = QString::number(date.year());
        QString resDate = day + "." + month + "." + year;

        QString resultView = QString::number(obj["right"].toInt()) + "/" + QString::number(obj["wrong"].toInt()) + "/" + QString::number(obj["total"].toInt());

        list << resDate << resultView;
        vector.append(list);
        qDebug() << "statisticsWgt(getDataFromFile): add new list element:" << list;
    }
    qDebug() << "statisticsWgt(getDataFromFile): create vector with stat information";
    return vector;
}

QJsonDocument StatisticsWgt::getJsonDocument() {
    /*
     *  Open file with json, parse it and return JsonDocument object
     *
     *  return: QJsonDocument
    */

    QString val;

    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8(), &error);
    if(error.error != error.NoError) {
        qDebug() << "statisticsWgt(getTable): error: " << error.errorString() << error.offset << error.error;
        exit(1);
    }

    qDebug() << "statisticsWgt(getJsonDocument): Success get json document";
    return doc;
}

QTableWidget* StatisticsWgt::getTable() {
    /*
     *  Init and fill table with statistics (in work)
     *
     *  return: QTableWidget*
    */

    QJsonDocument doc = getJsonDocument();
    QJsonObject json = doc.object();
    QStringList labels = getLabelsFromFile(json["labels"].toArray());
    QVector<QStringList> data = getDataFromFile(json["stats"].toArray());

    QTableWidget *table = new QTableWidget(0, labels.size(), this);
    for(int i = 0; i < data.count(); i++) {
        table->insertRow(i);
        for(int j = 0; j < data[i].size(); j++){
            table->setItem(i, j, new QTableWidgetItem(data[i].at(j)));
        }
        qDebug() << "statisticsWgt(getTable): insert item in table:" << data[i];
    }
    table->setHorizontalHeaderLabels(labels);

    qDebug() << "statisticsWgt(getTable): Success init statistics table";
    return table;
}

/* SLOTS */

void StatisticsWgt::backBtnClicked() {
    /*
     *  Do something usefull and emit backEvent signal
     *
    */

    // Что-то сделать, выслать сигнал выхода из виджета
    qDebug() << "statisticsWgt(backBtnClicked): btn back clicked -> return to previous wgt";
    emit backEvent();
}
