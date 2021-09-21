#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    // central widget for mainWindow
    QWidget *centralWgt = NULL;
    // Layout and Buttons for main menu
    QVBoxLayout *pVLayoutMain = NULL;
    QPushButton *pStartBtn = NULL;
    QPushButton *pAddQuestionsBtn = NULL;
    QPushButton *pDelQuestionsBtn = NULL;
    QPushButton *pStatisticsBtn = NULL;

    bool initStartMenu();
    void showStartMenu();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartClicked();
    void onAddClicked();
    void onDelClicked();
    void onStatisticsClicked();
};
#endif // MAINWINDOW_H
