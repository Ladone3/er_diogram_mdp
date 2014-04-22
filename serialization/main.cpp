#include <QtCore/QCoreApplication>
#include <QDataStream>
#include <QByteArray>
#include <QFile>
#include <QString>
#include <QHash>
#include <QDebug>
#include <QString>
#include <string>
#include <iostream>
//http://habrahabr.ru/post/150827/
using namespace std;
class simpleClass
{
public:
    int c;
    QString h;
    //friend QDataStream &operator <<(QDataStream &stream,const simpleClass &sC);
    //friend QDataStream &operator >>(QDataStream &stream, simpleClass &sC);
};

/*inline QDataStream &operator <<(QDataStream &stream,const simpleClass &sC) // сериализуем;
{
    stream << sC.b;
    stream << sC.c;
    return stream;
}

inline QDataStream &operator >>(QDataStream &stream, simpleClass &sC) // десериализуем;
{
    stream >> sC.b;
    stream >> sC.c;
    return stream;
}

*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile appFile(QString("c:\\filename.data"));
    appFile.open(QFile::WriteOnly); // открываем файл для дозаписи;
    QDataStream inFile(&appFile); // передаем потоку указатель на QIODevice;
    /*QHash <int, int> hash; // инициализируем контейнер и чем нибудь заполним его;

    for(int i = 0; i < 64; i++)
    {
        if(!hash.contains(i)) // Проверяем есть ли ключ, если нет добовляем его;
        {
            simpleClass sC; // создали объект;
            sC.b=5;
            sC.c=i;
            hash.insert(sC.c,sC.b); // допавили в хеш;
        }
    }*/
    simpleClass sC; // создали объект;
    //sC.b="Hello";
    sC.c=2;
    sC.h="my name is Olga";
    inFile.setVersion(QDataStream::Qt_5_2); //  явно указываем версию Qt, для сериализации;
    //inFile << hash; // ура записано;
    inFile<<sC.h;
    inFile<<sC.c;
    appFile.flush(); // записываем весь буффер в файл;
    appFile.close();

     // теперь  прочитаем что  мы там записали;
    QFile readFile(QString("c:\\filename.data"));
    readFile.open(QFile::ReadOnly);
    QDataStream outFile(&readFile);
    outFile.setVersion(QDataStream::Qt_5_2);
    simpleClass cs;
   // QHash<int,int> readHash; // создаем аналогичный контейнер;
    //outFile >> readHash; // пишем в него из  потока;
    outFile>>cs.h;
    outFile>>cs.c;
   // cs.h=(const char*)cs.b;
        qDebug() << "Sum was " << cs.h; // смотрим что было;
        qDebug() << "Sum is "<< cs.c; // смотрим что стало;
    readFile.close();
    return a.exec();
}
