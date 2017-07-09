#include <QCoreApplication>
extern "C"{
#include <E:\john\matlabcoder\codegen\dll\Tikhonov\Tikhonov.h>
#include <E:\john\AIRtools\codegen\dll\landwebercode\landwebercode.h>
}
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <iostream>

void readtxt(double *content,const QString name)
{
    QFile senfile(name);
    if (!senfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return ;

    QTextStream outsenfile(&senfile);
    outsenfile.skipWhiteSpace();
    outsenfile.seek(0);
//    QString nouse;
    int i=0;
    while(!outsenfile.atEnd())
    {

            outsenfile>>content[i];
            i++;
//            nouse=outsenfile.readLine();
    }
    senfile.close();
}
void writetxt(double*f,int *fsize,const QString name)
{

    QFile file(name);
    file.open(QIODevice::ReadOnly);//  | QIODevice::Text|QIODevice::Truncate))
    QTextStream in(&file);
    file.close();//new

    file.open(QIODevice::Truncate);
    file.close();

    file.open(QIODevice::WriteOnly);

    for(int i=0;i<fsize[0];i++) {
        for(int j=0;j<fsize[1];j++)
        {

            in<<f[i+j*fsize[0]]<<"\r\n";
        }
    }

    file.close();
}

int main(int argc, char *argv[])
{



    double L[60*400]={0};
    double b[60]={0};
    int k=2000;
    double x0[400]={0};
    double f[400]={0};
    int fsize[2]={400,1};
    readtxt(L,"./L.txt");
    readtxt(b,"./b.txt");

    Tikhonov(L,b,k,x0,f,fsize);
    writetxt(f,fsize,"./f0706.txt");
    QCoreApplication a(argc, argv);
    return a.exec();
}
