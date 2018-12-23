#ifndef CHARACTERSHEETWRITER_H
#define CHARACTERSHEETWRITER_H

#include <QStringList>
#include <QFile>
#include <QIODevice>
#include <QTextStream>


class charactersheetwriter
{
public:
    charactersheetwriter();
    void writeToFile(QFile *file, QStringList options);
};

#endif // CHARACTERSHEETWRITER_H
