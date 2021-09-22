#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "mainmenuwgt.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:  
    MainMenuWgt *pMainMenuWgt = nullptr; // Layout for main menu

    void setStartMenuWgt();
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
