#include "formwgt.h"

FormWgt::FormWgt(QWidget *parent) : QWidget(parent)
{
    QLabel *questLabel = new QLabel("Вопрос:", this);
    pQuestionLine = new QLineEdit(this);
    QHBoxLayout *questionLayout = new QHBoxLayout(nullptr);
    questionLayout->addWidget(questLabel);
    questionLayout->addWidget(pQuestionLine);

    QVBoxLayout *mainLayout = new QVBoxLayout(nullptr);
    mainLayout->addLayout(questionLayout);
    mainLayout->addLayout(createNewAnswField());
    mainLayout->addLayout(createNewAnswField());
    mainLayout->addLayout(createNewAnswField());
    mainLayout->addLayout(createNewAnswField());

    this->setLayout(mainLayout);

    qDebug() << "formWgt(constructor): Success";
}

FormWgt::~FormWgt() {
    qDebug() << "formWgt(destructor): Success";
}

QLayout* FormWgt::createNewAnswField() {
    /*
     * Init radio button and lineEdit, add to answBtns and answInputs vectors
     * add to layout and return
     *
     *
     *  return: QLayout*
    */

    QRadioButton *pAnswBtn = new QRadioButton(this);
    answBtns.push_back(pAnswBtn);

    QLineEdit *pAnswLine = new QLineEdit(this);
    answInputs.push_back(pAnswLine);

    QHBoxLayout *pLayout = new QHBoxLayout(nullptr);
    pLayout->addWidget(pAnswBtn);
    pLayout->addWidget(pAnswLine);

    qDebug() << "formWgt(createNewAnswField): Success";
    return pLayout;
}

void FormWgt::clearFields() {
    /*
     * Set empty input fields
     *
     * return: void
    */
    pQuestionLine->clear();
    for(int i = 0; i < answInputs.size(); i++) {
        answInputs[i]->clear();
    }
    qDebug() << "formWgt(clearFields): Success clear";
}

QStringList FormWgt::getAnsws() {
    /*
     *  get string list, contained answers text
     *
     *  return: QStringList
    */
    QStringList res;
    for(int i = 0; i < answInputs.size(); i++) {
        res << answInputs[i]->text();
    }
    qDebug() << "formWgt(getAnsws): Succes, returned - " << res;
    return res;
}

QVector<bool> FormWgt::getRightAnsw() {
    /*
     *  Get vecotor: false - wrong answer, true - right answer
     *
     * return: QVector<bool>
    */
    QVector<bool> res;
    for(int i = 0; i < answBtns.size(); i++) {
        res.push_back(answBtns[i]->isChecked());
    }

    qDebug() << "formWgt(getRightAnsw): Success, returned - " << res;
    return res;
}

QString FormWgt::getQuestionString() {
    /*
     *  Get data from Questions LineEdit and return it
     *
     *  return: QString
    */
    QString res = pQuestionLine->text();
    qDebug() << "formWgt(getQuestionString): return string - " << res;
    return res;
}

bool FormWgt::isFieldsValid() {
    /*
     *  Check that fields is not empty and form reade to get data
     *
     *  return: bool (form ready to get fields data)
    */
    if(pQuestionLine->text() == "") {
        qDebug() << "formWgt(isFieldsValid): Question input field is empty";
        return false;
    }

    bool radioValid = false;
    for(int i = 0; i < answInputs.size(); i++) {
        radioValid |= answBtns[i]->isChecked();
        if(answInputs[i]->text() == ""){
            qDebug() << "formWgt(isFieldsValid): Answer input field is empty";
            return false;
        }
    }
    if(radioValid == false) {
        qDebug() << "formWgt(isFieldsValid): Answer radion btn is empty";
    } else {
        qDebug() << "formWgt(isFieldsValid): Success";
    }
    return radioValid;
}


