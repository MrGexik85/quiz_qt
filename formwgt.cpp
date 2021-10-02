#include "formwgt.h"

FormWgt::FormWgt(QWidget *parent) : QWidget(parent)
{
    QLabel *questLabel = new QLabel("Вопрос:", this);
    QLineEdit *pQuestionLine = new QLineEdit(this);
    QHBoxLayout *questionLayout = new QHBoxLayout(nullptr);
    questionLayout->addWidget(questLabel);
    questionLayout->addWidget(pQuestionLine);


    QRadioButton *pAnswBtn_1 = new QRadioButton(this);
    QLineEdit *pAnswLine_1 = new QLineEdit(this);
    QHBoxLayout *answLayout_1 = new QHBoxLayout(nullptr);
    answLayout_1->addWidget(pAnswBtn_1);
    answLayout_1->addWidget(pAnswLine_1);

    QRadioButton *pAnswBtn_2 = new QRadioButton(this);
    QLineEdit *pAnswLine_2 = new QLineEdit(this);
    QHBoxLayout *answLayout_2 = new QHBoxLayout(nullptr);
    answLayout_2->addWidget(pAnswBtn_2);
    answLayout_2->addWidget(pAnswLine_2);

    QRadioButton *pAnswBtn_3 = new QRadioButton(this);
    QLineEdit *pAnswLine_3 = new QLineEdit(this);
    QHBoxLayout *answLayout_3 = new QHBoxLayout(nullptr);
    answLayout_3->addWidget(pAnswBtn_3);
    answLayout_3->addWidget(pAnswLine_3);

    QRadioButton *pAnswBtn_4 = new QRadioButton(this);
    QLineEdit *pAnswLine_4 = new QLineEdit(this);
    QHBoxLayout *answLayout_4 = new QHBoxLayout(nullptr);
    answLayout_4->addWidget(pAnswBtn_4);
    answLayout_4->addWidget(pAnswLine_4);

    QVBoxLayout *mainLayout = new QVBoxLayout(nullptr);
    mainLayout->addLayout(questionLayout);
    mainLayout->addLayout(answLayout_1);
    mainLayout->addLayout(answLayout_2);
    mainLayout->addLayout(answLayout_3);
    mainLayout->addLayout(answLayout_4);

    this->setLayout(mainLayout);

    qDebug() << "formWgt(constructor): Success";
}

FormWgt::~FormWgt() {
    qDebug() << "formWgt(destructor): Success";
}
