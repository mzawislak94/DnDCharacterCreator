#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPdfWriter>
#include <QPageLayout>
#include <QIODevice>
#include <QFile>
#include <string>
using namespace std;

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList races = {"Dragonborn", "Dwarf", "Elf", "Half-Elf", "Half-Orc", "Halfling", "Gnome", "Tiefling"};
    ui->raceComboBox->addItems(races);
    QStringList classes = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"};
    ui->classComboBox->addItems(classes);

    if(ui->allOptionsRadioButton->isChecked())
    {
        QStringList races = {"Dragonborn", "Dwarf", "Elf", "Half-Elf", "Half-Orc", "Halfling", "Gnome", "Tiefling"};
        ui->raceComboBox->addItems(races);
        QStringList classes = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"};
        ui->classComboBox->addItems(classes);
    }
    sheet = new charactersheetwriter();
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getRace()
{
    QString race = ui->raceComboBox->currentText();
    return race;
}

void MainWindow::setSubraceComoBox()
{
    QString race = getRace();
    if (race == "Dragonborn")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Dwarf")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Elf")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Half-Elf")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Half-Orc")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Halfling")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Gnome")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
    else if (race == "Tiefling")
    {
        QStringList subraces = {};
        ui->subraceComboBox->addItems(subraces);
    }
}

QString MainWindow::getSubrace()
{
    QString subrace = ui->subraceComboBox->currentText();
    return subrace;
}

QString MainWindow::getClass()
{
    QString Class = ui->classComboBox->currentText();
    return Class;
}

void MainWindow::on_raceComboBox_currentTextChanged()
{
    setSubraceComoBox();
}

/**
 * @brief MainWindow::getRaceDetails
 * will set race variables based on
 */
QStringList MainWindow::getRaceDetails()
{
    QString race = getRace();
    QStringList raceDetails;
    if (race == "Dragonborn")
    {
        raceDetails << "hello";
    }
    else if (race == "Dwarf")
    {

    }
    else if (race == "Elf")
    {

    }
    else if (race == "Half-Elf")
    {

    }
    else if (race == "Half-Orc")
    {

    }
    else if (race == "Halfling")
    {

    }
    else if (race == "Gnome")
    {

    }
    else if (race == "Tiefling")
    {

    }
    return raceDetails;
}

QStringList MainWindow::getClassDetails()
{
    QString Class = getClass();
    QStringList classDetails;

    if (Class == "Barbarian")
    {
        classDetails << "hi";
    }
    else if (Class == "Bard")
    {

    }
    else if (Class == "Cleric")
    {

    }
    else if (Class == "Druid")
    {

    }
    else if (Class == "Fighter")
    {

    }
    else if (Class == "Monk")
    {

    }
    else if (Class == "Ranger")
    {

    }
    else if (Class == "Rogue")
    {

    }
    else if (Class == "Sorcerer")
    {

    }
    else if (Class == "Warlock")
    {

    }
    else if (Class == "Wizard")
    {

    }
    return classDetails;
}

QString MainWindow::getFilename()
{
    QString filename = "C:\\Users\\zawis\\Documents\\data.txt";
    return filename;
}

void MainWindow::on_generateButton_clicked()
{
    QString filename = getFilename();
    file->rename(filename);
    QStringList classDetails = getClassDetails();
    QStringList raceDetails = getRaceDetails();
    qInfo() << "classDetails is populated";

    QStringList options;
    options << raceDetails << classDetails;
    qInfo() << "options is populated";
    sheet->writeToFile(file, options);
}
