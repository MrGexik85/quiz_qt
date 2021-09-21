#ifndef MAINMENULAYOUT_H
#define MAINMENULAYOUT_H

#include <QtWidgets>

class MainMenuLayout : public QVBoxLayout
{
    Q_OBJECT
private:
    QPushButton *pStartBtn = nullptr;
    QPushButton *pAddQuestionsBtn = nullptr;
    QPushButton *pDelQuestionsBtn = nullptr;
    QPushButton *pStatisticsBtn = nullptr;

    bool initMainMenu();
public:
    MainMenuLayout(QWidget *parent = nullptr);
    ~MainMenuLayout();

    friend class MainWindow;
};

#endif // MAINMENULAYOUT_H
