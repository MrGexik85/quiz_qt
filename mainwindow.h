#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "mainmenulayout.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    // Central widget for mainWindow
    QWidget *centralWgt = nullptr;
    // Layout for main menu
    MainMenuLayout *pMainMenuLayout = nullptr;

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
