#include "questionsmodel.h"

QuestionsModel::QuestionsModel(QString filename) : filename(filename)
{
    opened = readDataFrom(filename);
    qDebug() << "questionsModel(constructor): Success";
}

QuestionsModel::~QuestionsModel() {
    saveDataTo(filename);
    qDebug() << "questionsModel(destructor): Success";
}

bool QuestionsModel::isOpened() {
    /*
     *  Check that data of questions is valid
     *
     *  return: bool (data in not null)
    */
    return opened;
}

bool QuestionsModel::readDataFrom(QString filename) {
    /*
     *  Method performing XML data to buffer data
     *
     *  return: bool (Success)
    */
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly) == false) {
        qDebug() << "questionsModel(readDataFrom): Can't open file:" << filename;
        return false;
    }
    QXmlStreamReader xmlReader(&file);
    while(!xmlReader.atEnd()) {
        if(xmlReader.isStartElement()) {
            if(xmlReader.name().toString() == "body") {
                xmlReader.readNextStartElement();
                continue;
            }
            if(xmlReader.name().toString() == "question") {
                xmlReader.readNextStartElement();
                continue;
            }
            if(xmlReader.name().toString() == "content") {
                Question tmp;
                tmp.questionHeader = xmlReader.readElementText();
                xmlReader.readNextStartElement();
                while(xmlReader.name().toString() == "answer") {
                    foreach (const QXmlStreamAttribute &attr, xmlReader.attributes()) {
                        if(attr.name().toString() == "right") {
                            QString attrValue = attr.value().toString();
                            tmp.rightAnsws.push_back(attrValue == "true");
                        }
                    }
                    tmp.answs.push_back(xmlReader.readElementText());
                    xmlReader.readNextStartElement();
                }
                qDebug() << "questionsModel(readDataFrom): read new question element";
                data.push_back(tmp);
            }
        }
        xmlReader.readNextStartElement();
    }

    file.close();

    qDebug() << "questionsModel(readDataFrom): Success read from:" << filename;
    return true;
}

bool QuestionsModel::saveDataTo(QString filename) {
    /*
     *  Method performing data to XML file
     *
     *  return: bool (Success)
    */
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly) == false) {
        qDebug() << "questionsModel(saveDataTo): Can't open file:" << filename;
        return false;
    }
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("body");

    // Write question from buffer data to xml file
    for(int i = 0; i < data.size(); i++) {
        xmlWriter.writeStartElement("question");
            xmlWriter.writeStartElement("content");
            xmlWriter.writeCharacters(data[i].questionHeader);
            xmlWriter.writeEndElement();
            for(int j = 0; j < data[i].answs.size(); j++) {
                xmlWriter.writeStartElement("answer");
                xmlWriter.writeAttribute("right", data[i].rightAnsws[j] ? "true" : "false");
                xmlWriter.writeCharacters(data[i].answs[j]);
                xmlWriter.writeEndElement();
            }
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();

    qDebug() << "questionsModel(saveDataTo): Success save to:" << filename;
    return true;
}

bool QuestionsModel::deleteRecord(int index) {
    /*
     *  Return question from data
     *
     * return: bool (success)
    */
    data.remove(index);

    qDebug() << "questionsModel(deleteRecord): Success deleted from:" << index << "index";
    return true;
}

bool QuestionsModel::addNewRecord(QString header, QVector<QString> answs, QVector<bool> rightAnsws) {
    /*
     *  Create Question object and save to data
     *
     *  return: bool (success)
    */
    Question question;
    question.questionHeader = header;
    question.answs = answs;
    question.rightAnsws = rightAnsws;

    data.push_back(question);

    qDebug() << "questionsModel(deleteRecord): Success added";
    return true;
}

Question QuestionsModel::getQuestionData(int index) {
    /*
     *  Get Questions DS from index
     *
     *  return: Question
    */
    qDebug() << "qestionsModel(getQuestionData): Success";
    return data[index];
}

QStringList QuestionsModel::getQuestionsHead() {
    /*
     *  Get list of question's text
     *
     *  return: QStringList
    */

    QStringList list;
    for(int i = 0; i < data.size(); i++) {
        list << data[i].questionHeader;
    }

    qDebug() << "questionsModel(getQuestionsHead): Success returned:" << list;
    return list;
}

int QuestionsModel::size() {
    /*
     *  Get count of questions at now
     *
     *  return: int
    */
    return data.size();
}



