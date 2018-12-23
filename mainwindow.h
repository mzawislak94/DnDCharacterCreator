#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "charactersheetwriter.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPdfWriter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QString getRace();
    QString getSubrace();
    QString getClass();
    QString getFilename();
    void setSubraceComoBox();
    QStringList getRaceDetails();
    QStringList getClassDetails();
    ~MainWindow();
    QPdfWriter *pdf;
    charactersheetwriter *sheet;
    QFile *file;


private:
    Ui::MainWindow *ui;

public slots:
    void on_generateButton_clicked();

signals:
    void clicked();

private slots:
    void on_raceComboBox_currentTextChanged();
};

#endif // MAINWINDOW_H
