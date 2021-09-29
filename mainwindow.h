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
    QPointer<MainMenuWgt> pMainMenuWgt;
    QPointer<QuizWgt> pQzWgt;
    QPointer<AddQuestionWgt> pAddQustionWgt;
    QPointer<DelQuestionWgt> pDelQuestionWgt;
    QPointer<StatisticsWgt> pStatisticsWgt;

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
