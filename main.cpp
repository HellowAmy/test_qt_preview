#include <QApplication>
#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <iostream>
#include <QDateTime>
#include <QThreadPool>

#include "window/main_window.h"
#include "handle_load_libray.h"


#include "Fmd5.h"

using namespace std;

void test_1()
{
    QThreadPool::globalInstance()->setMaxThreadCount(4);
    QThreadPool::globalInstance()->start([](){
        QProcess ps;
        ps.setWorkingDirectory("/home/cong/open/test_qt/test_qt_preview/module/bash");
        auto t1 = QDateTime::currentSecsSinceEpoch();
        ps.start("sh makeso.sh");
        bool ok = ps.waitForFinished();
        

        // ps.start ("cmake",QStringList()<<"--build"<<".");
        // ok = ps.waitForFinished();

        auto t2 = QDateTime::currentSecsSinceEpoch();
        qDebug()<<ok<<"|"<<t2-t1<<"|"<<ps.exitCode();
    });



    qDebug()<<"===2";
    while (true)
    {
        sleep(1000);
    }
    
}

void test_2()
{
    // Fmd5 md5;
    // bool ok = md5.init();
    {
        std::string s = Fmd5::str_to_md5("hellow");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex();
    }
    {
        std::string s = Fmd5::str_to_md5("hellow");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex();
    }
    {
        std::string s = Fmd5::str_to_md5("hellow1");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex();
    }
    {
        std::string s = Fmd5::str_to_md5("hellow2");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex();
    }
    {
        std::string s = Fmd5::file_to_md5("hellow2");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex(); 
    }
    {
        std::string s = Fmd5::file_to_md5("/home/cong/open/test_qt/test_qt_preview/util/handle_load_libray.cpp");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex(); 
    }
    {
        std::string s = Fmd5::file_to_md5("/home/cong/open/test_qt/test_qt_preview/util/handle_load_libray.cpp");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex(); 
    }
    {
        std::string s = Fmd5::file_to_md5("/home/cong/open/test_qt/test_qt_preview/wid/handle_load_libray.cpp");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex(); 
    }
    {
        std::string s = Fmd5::file_to_md5("/home/cong/open/test_qt/test_qt_preview/util/handle_load_libray.h");
        qDebug()<<QByteArray(s.c_str(),s.size()).toHex(); 
    }
}

int run_main_app(int argc, char *argv[])
{
    QApplication a(argc,argv);

    main_window w;
    w.show();

    return a.exec();
}

int exit_main_app(int run_value)
{
    cout<<"exit run value : "<<run_value<<endl;
    return run_value;
}

int perse_arg(int argc, char *argv[])
{
    cout<<"perse_arg : "<<argc<<endl;
    for(int i=0;i<argc;i++)
    {
        cout<<"arg: "<<string(argv[i])<<endl;
    }
    return argc;
}

/*
需求：
1、构建路径
2、构建参数
3、so路径、导出函数
4、tab多个切换
5、定时检测更新
6、刷新按钮
7、展示框

重点：
1.主动载入程序需要添加 -rdynamic 编译选项
2.被载入动态库需要添加 -fPIC 编译选项
*/

int main(int argc, char *argv[])
{

#if 0
    qDebug()<<"begin";
    test_2();
    qDebug()<<"end";

    return 0;
#endif


    perse_arg(argc,argv);

    int run_value = run_main_app(argc,argv);

    return exit_main_app(run_value);
}