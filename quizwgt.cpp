#include "quizwgt.h"

QuizWgt::QuizWgt(QWidget *parent, QString filename) :
    QWidget(parent), questionsCount(0), nRight(0), nWrong(0)
{
    layout = new QVBoxLayout();
    pQuestModel = new QuestionsModel(filename);

    initForm();
    initButtons();
    this->setLayout(layout);

    qDebug() << "QuizWgt(constructor): Success";
}

QuizWgt::~QuizWgt(){
    saveResultTo("stat.json");
    delete pQuestModel;
    qDebug() << "QuizWgt(destructor): Success";
}

bool QuizWgt::initForm() {
    /*
     * Init question form
     *
     *  return: bool (success)
    */
    pQuestionHead = new QLabel(this);
    layout->addWidget(pQuestionHead);

    for(int i = 0; i < 4; i++) {
        QHBoxLayout *hL = new QHBoxLayout();
        radioBtns.push_back(new QRadioButton(this));
        answs.push_back(new QLabel(this));
        hL->addWidget(radioBtns[i], 1);
        hL->addWidget(answs[i], 10);
        layout->addLayout(hL);
    }

    setQuestion(0);

    qDebug() << "quizWgt(initForm): success";
    return true;
}

void QuizWgt::setQuestion(int index) {
    /*
     *  Fill question form to new question
     *
     *  return: void
    */

    Question cur = pQuestModel->getQuestionData(index);
    pQuestionHead->setText(cur.questionHeader);
    for(int i = 0; i < 4; i++) {
        radioBtns[i]->setChecked(false);
        answs[i]->setText(cur.answs[i]);
    }

    qDebug() << "quizWgt(setQuestion): success set" << index << "question";
}

bool QuizWgt::initButtons() {
    /*
     *  Init wgt buttons and connect signals to slots
     *
     *  return: bool (success)
    */
    QPushButton *pBackBtn = new QPushButton("Закончить попытку", this);
    connect(pBackBtn, SIGNAL(clicked()), this, SLOT(onBackBtnClicked()));

    QPushButton *pRespondBtn = new QPushButton("Ответить", this);
    connect(pRespondBtn, SIGNAL(clicked()), this, SLOT(onRespondBtnClicked()));

    layout->addWidget(pRespondBtn);
    layout->addWidget(pBackBtn);

    qDebug() << "quizWgt(initButtons): Success";
    return true;
}

bool QuizWgt::saveResultTo(QString file) {
    /*
     *  Get user result and save to json file
     *
     *  return: bool (success)
    */
    QFile jsonFile(file);
    if (!jsonFile.open(QIODevice::ReadOnly)){
        qDebug() << "quizWgt(saveResultTo): fail save result to:" << file;
        return false;
    }

    QByteArray saveData = jsonFile.readAll();
    jsonFile.close();
    QJsonDocument jsonDocument(QJsonDocument::fromJson(saveData));
    QJsonObject m_currentJsonObject = jsonDocument.object();

    QJsonObject textObject;
    textObject["timestamp"] = QDateTime::currentSecsSinceEpoch();
    textObject["right"] = nRight;
    textObject["wrong"] = nWrong;
    textObject["total"] = pQuestModel->size();

    QJsonArray textsArray = m_currentJsonObject["stats"].toArray();
    textsArray.append(textObject);
    m_currentJsonObject["stats"] = textsArray;

    if (!jsonFile.open(QIODevice::WriteOnly)) {
        qDebug() << "quizWgt(saveResultTo): fail save result to:" << file;
        return false;
    }
    jsonFile.write(QJsonDocument(m_currentJsonObject).toJson(QJsonDocument::Indented));
    jsonFile.close();

    qDebug() << "quizWgt(saveResultTo): success save result to:" << file;
    return true;
}

bool QuizWgt::checkQuestion(QVector<bool> userAnsw, QVector<bool> rightAnsw) {
    /*
     *  Check user answer
     *
     *  return: bool (user respond right)
    */
    for(int i = 0; i < userAnsw.size(); i++) {
       if(userAnsw[i] != rightAnsw[i]) {
           qDebug() << "quizWgt(checkQuestion): wrong answer";
           return false;
       }
    }
    qDebug() << "quizWgt(checkQuestion): right answer";
    return true;
}

/* SLOTS */

void QuizWgt::onBackBtnClicked() {
    /*
     * Do something and emit backEvent() signal
     *
     *  return: void
    */
    qDebug() << "quizWgt(onBackBtnClicked): btn clicked";
    emit backEvent();
}

void QuizWgt::onRespondBtnClicked() {
    /*
     *  Compare current answ with answTable, Inc questionsCount and request next question
     *
     *  return: void
    */

    QVector<bool> right = pQuestModel->getQuestionData(questionsCount).rightAnsws;
    QVector<bool> usr;
    for(int i = 0; i < radioBtns.size(); i++) {
        usr.push_back(radioBtns[i]->isChecked());
    }

    // Проверить правильность ответа
    if(checkQuestion(usr, right)) {
        nRight++;
    } else {
        nWrong++;
    }

    questionsCount++;
    if(questionsCount >= pQuestModel->size()) {
        QString resStr = "Ваш результат:\nПравильных: " + QString::number(nRight) + "\nНеправильных: " + QString::number(nWrong) + "\nВсего: " + QString::number(pQuestModel->size());
        QMessageBox::about(this, "Результат", resStr);
        emit backEvent();
    } else {
        setQuestion(questionsCount);
    }
    qDebug() << "quizWgt(onRespondBtnClicked): btn clicked";

}
