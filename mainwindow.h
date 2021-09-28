#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "mainmenuwgt.h"
#include "quizwgt.h"
#include "addquestionwgt.h"
#include "delquestionwgt.h"
#include "statisticswgt.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:  
    MainMenuWgt *pMainMenuWgt = nullptr;
    QuizWgt *pQzWgt = nullptr;
    AddQuestionWgt *pAddQustionWgt = nullptr;
    DelQuestionWgt *pDelQuestionWgt = nullptr;
    StatisticsWgt *pStatisticsWgt = nullptr;

    QString statsFile;
    QString questionsFile;

    void setStartMenuWgt();
    bool checkFilesExistOrCreate(QString &path_file);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartClicked();
    void onAddClicked();
    void onDelClicked();
    void onStatisticsClicked();

    void setMainMenu();
};
#endif // MAINWINDOW_H
