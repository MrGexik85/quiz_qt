#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    // central widget for mainWindow
    QWidget *centralWgt;
    // Layout and Buttons for main menu
    QVBoxLayout *pVlayout;
    QPushButton *pStartBtn;
    QPushButton *pAddQuestionsBtn;
    QPushButton *pDelQuestionsBtn;
    QPushButton *pStatisticsBtn;

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
