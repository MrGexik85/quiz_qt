#ifndef MAINMENUWGT_H
#define MAINMENUWGT_H

#include <QtWidgets>

class MainMenuWgt : public QWidget
{
    Q_OBJECT
private:
    QPushButton *pStartBtn = nullptr;
    QPushButton *pAddQuestionsBtn = nullptr;
    QPushButton *pDelQuestionsBtn = nullptr;
    QPushButton *pStatisticsBtn = nullptr;

    QVBoxLayout *pLayout = nullptr;

    bool initButtons();
    bool initLayout();
public:
    explicit MainMenuWgt(QWidget *parent = nullptr);
    ~MainMenuWgt();

    friend class MainWindow;
signals:

};

#endif // MAINMENUWGT_H
