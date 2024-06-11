
#ifndef HANDLE_LOAD_LIBRAY_H
#define HANDLE_LOAD_LIBRAY_H

#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QThreadPool>
#include <QProcess>
#include <QLabel>

#include <vector>
#include <functional>
#include <iostream>
#include <dlfcn.h>
#include <unistd.h>

// 加载动态库
struct handle_load_libray
{
    using Twid = QWidget*(*)();

    handle_load_libray() {}
    ~handle_load_libray() 
    {
        if(_lib_handle != nullptr)
        {
            dlclose(_lib_handle); 
            _lib_handle = nullptr;
        }
    }

    bool load_lib(QString libf)
    {
        if(_lib_wid != nullptr)
        {
            delete _lib_wid;
            _lib_wid = nullptr;
        }
        if(_lib_handle != nullptr)
        {
            dlclose(_lib_handle); 
            _lib_handle = nullptr;
        }
        _lib_handle = dlopen(libf.toStdString().c_str(),RTLD_LAZY);
        return _lib_handle != nullptr;
    }
    
    bool load_wid(QString fn)
    {
        if(_lib_wid != nullptr)
        {
            delete _lib_wid;
            _lib_wid = nullptr;
        }
        
        if(_lib_handle)
        {
            Twid fn_wid = (Twid)dlsym(_lib_handle,fn.toStdString().c_str());
            if(dlerror() == nullptr)
            {
                _lib_wid = fn_wid();
                return true;
            }
        }
        return false;
    }

    void *_lib_handle = nullptr;
    QWidget *_lib_wid = nullptr;
};

// 编译源文件成动态库
class handle_build_code : public QObject
{
    Q_OBJECT
public:
    handle_build_code(QWidget *parent = nullptr);

    ~handle_build_code();

    void build_code_th(QString path,QString cmd,std::function<void(bool)> fn);


signals:
    void sn_build_finish(bool succeed);

protected:
    std::function<void(bool)> _fn_cb = nullptr;
};

// 获取导出窗口
class item_tab_lib : public QObject
{
    Q_OBJECT
public:
    enum en_load_status
    {
        e_start,
        e_build_finish,
        e_load_finish,
        e_add_finish,
        e_error,
    };

    enum en_load_type
    {
        e_first_load,
        e_reload,
    };

public:
    item_tab_lib(QObject *parent = nullptr);

    void build_lib(en_load_type type);

    QScrollArea *make_area();

    en_load_type get_load_type();


signals:
    void sn_load_status(int);

public:
    en_load_type _load_type; 
    bool _is_time_update = false;
    bool _is_save_update = true;
    bool _is_draw_frame = true;
    qreal _time_update = 1000;
    QString _str_build_path;
    QString _str_build_cmd;
    QString _str_so_path;
    QString _str_so_export;
    QString _str_tab_title;

    handle_load_libray _lib_load;
    handle_build_code _lib_build;
    std::vector<QString> _vec_watch_file;

    QLabel *_lab_draw_frame = nullptr;
    QScrollArea *_area = nullptr;
};

#endif // HANDLE_LOAD_LIBRAY_H
