#include <iostream>
#include <fstream>
#include "meshtalparser.h"
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QStringList>

using namespace std;
QStringList MeshtalParser::parse_file(QString fileName= ":/examples/assets/example1.csv"){
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QStringList stringData;
       while (!inputFile.atEnd())
       {
          QString line = inputFile.readLine();
          stringData.append(line);
       }
       inputFile.close();
       return stringData;
    }else{
        qDebug() << "Could not read file";
        return QStringList("Hi");
    }
}
