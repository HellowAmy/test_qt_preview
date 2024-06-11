
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QLibrary>
#include <QTabWidget>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QPalette>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QCheckBox>
#include <QLabel>
#include <QTimer>
#include <QThreadPool>
#include <QProcess>
#include <QProgressBar>

#include <vector>
#include <set>
#include <iostream>

#include "Fmd5.h"
#include "handle_load_libray.h"
#include "win_add_tab_dig/win_add_tab_dig.h"

class main_window : public QWidget
{
    Q_OBJECT

public:
    enum en_load_type
    {
        e_add_tab,
        e_reload,
    };

public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

signals:    
    void sn_build_finish(bool succeed,int type);

protected:


private:
    void set_prog_status(int status);
    item_tab_lib *init_item_tab();
    item_tab_lib* get_cur_item();
    void reload_cur_item();

    void set_item_config(item_tab_lib *item,int index);
    bool install_lib(QString path);

private:
    QPushButton *_butt_add_tab = nullptr;
    QPushButton *_butt_reload = nullptr;
    QLabel *_lab_tips = nullptr;
    QProgressBar *_prog_load = nullptr;

    QTabWidget *_tab_wid = nullptr;
    QTimer *_timer_update = nullptr;
    QTimer *_timer_watch = nullptr;

    std::vector<QString> _vec_watch_file;
    std::vector<std::string> _vec_watch_file_md5;
    std::vector<item_tab_lib*> _vec_lib_item;
    std::set<QString> _st_repeat_lib;
};
#endif // MAIN_WINDOW_H
