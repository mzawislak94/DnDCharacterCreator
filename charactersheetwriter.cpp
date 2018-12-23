#include "charactersheetwriter.h"

charactersheetwriter::charactersheetwriter()
{

}

void  charactersheetwriter::writeToFile(QFile *file, QStringList options)
{
    if (NULL != file->open(QIODevice::Append))
    {
        QTextStream out(file);
        for (int i = 0; i < options.length(); i++)
        {
            out << options[i];
        }
        file->close();
    }
}
