#include "handle_load_libray.h"

item_tab_lib::item_tab_lib(QObject * parent) : QObject(parent)
{

}

void item_tab_lib::build_lib(en_load_type type)
{
    _load_type = type;
    emit sn_load_status(e_start);

    _lib_build.build_code_th(_str_build_path,_str_build_cmd,[=](bool succeed){
        if(succeed == false) 
        {
            emit sn_load_status(e_error);
            return ;
        }

        emit sn_load_status(e_build_finish);

        if(_lib_load.load_lib(_str_so_path) == false)
        {
            emit sn_load_status(e_error);
            return ;
        }
        if(_lib_load.load_wid(_str_so_export) == false)
        {
            emit sn_load_status(e_error);
            return ;
        }

        emit sn_load_status(e_load_finish);
    });
}

QScrollArea *item_tab_lib::make_area()
{
    QScrollArea *area = new QScrollArea;
    area->setContentsMargins(0,0,0,0);
    area->setAutoFillBackground(true);
    area->setWidget(_lib_load._lib_wid);
    return area;
}

item_tab_lib::en_load_type item_tab_lib::get_load_type()
{
    return _load_type;
}

handle_build_code::handle_build_code(QWidget *parent) : QObject(parent)
{
    connect(this,&handle_build_code::sn_build_finish,this,[=](bool succeed){
        if(_fn_cb) _fn_cb(succeed);
    },Qt::QueuedConnection);
}

handle_build_code::~handle_build_code()
{
}

void handle_build_code::build_code_th(QString path, QString cmd, std::function<void(bool)> fn)
{
    _fn_cb = fn;
    QThreadPool::globalInstance()->start([=](){
        bool succeed = false;
        QProcess ps;
        ps.setWorkingDirectory(path);
        ps.start(cmd);

        succeed = ps.waitForFinished();
        int ret = ps.exitCode();
        if(succeed && ret >= 0) succeed = true;

        emit sn_build_finish(succeed);
    });
}