
#include "main_window.h"

#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QTabWidget>
#include <QGroupBox>




main_window::main_window(QWidget *parent) : QWidget(parent)
{
#if 0
{
    test_1();
    return ;
}
#endif

    {
        int wid_min_high = 30;
        this->setWindowTitle(tr("预览窗口"));
        this->resize(1200,700);

        _timer_update = new QTimer(this);
        _timer_watch = new QTimer(this);

        QVBoxLayout *lay_main = new QVBoxLayout(this);
        {
            _butt_add_tab = new QPushButton(tr("添加窗口"),this);
            _butt_add_tab->setMinimumHeight(wid_min_high);

            _butt_reload = new QPushButton(tr("刷新预览"),this);
            _butt_reload->setMinimumHeight(wid_min_high);

            _lab_tips = new QLabel(this);
            _lab_tips->setFrameShape(QFrame::Box);
            _lab_tips->setMinimumWidth(150);
            _lab_tips->setMinimumHeight(wid_min_high);

            _prog_load = new QProgressBar(this);
            _prog_load->setMinimumHeight(wid_min_high);
            _prog_load->setValue(0);

            QHBoxLayout *lay = new QHBoxLayout;
            lay->addWidget(_butt_add_tab);
            lay->addWidget(_butt_reload);
            lay->addWidget(_lab_tips);
            lay->addWidget(_prog_load);
            lay_main->addLayout(lay);
        }
        {
            _tab_wid = new QTabWidget(this);
            _tab_wid->setContentsMargins(0,0,0,0);

            QHBoxLayout *lay = new QHBoxLayout;
            lay->addWidget(_tab_wid);
            lay_main->addLayout(lay);
        }
    }
    {
        connect(_butt_add_tab,&QPushButton::clicked,[=](){

            item_tab_lib *item = init_item_tab();
            win_add_tab_dig dig;

            item->_str_build_path = "/home/cong/open/test_qt/test_qt_preview/module/bash";
            item->_str_build_cmd = "sh makeso.sh";
            item->_str_so_path = "/home/cong/open/test_qt/test_qt_preview/module/lib/libhellow1.so";
            item->_str_so_export = "get_wid";
            item->_str_tab_title = "windows_1";
            item->_vec_watch_file.push_back("/home/cong/open/test_qt/test_qt_preview/module/src/test_wid/wid_preview_wid.cpp");


            dig.load_item_data(item);
            if(dig.exec() == QDialog::Accepted)
            {
                if(install_lib(item->_str_so_path))
                {
                    item->build_lib(item_tab_lib::e_first_load);
                }
                else 
                {
                    set_prog_status(item_tab_lib::e_error);
                    _lab_tips->setText(tr("动态库重复"));
                }
            }
            else 
            {
                item->deleteLater();
            }
        });

        connect(_butt_reload,&QPushButton::clicked,[=](){
            reload_cur_item();
        });

        connect(_timer_update,&QTimer::timeout,[=](){
            auto it = get_cur_item();
            if(it != nullptr && it->_time_update > 0)
            {
                reload_cur_item();
            }
        });

        connect(_timer_watch,&QTimer::timeout,[=](){
            
            for(int i=0;i<_vec_watch_file.size();i++)
            {
                std::string md5 = Fmd5::file_to_md5(_vec_watch_file[i].toStdString());
                if(_vec_watch_file_md5[i] != md5)
                {
                    qDebug()<<"change file: "<<_vec_watch_file[i];
                    _vec_watch_file_md5[i] = md5;
                    reload_cur_item();
                    break;
                }
            }
        });

        connect(_tab_wid,&QTabWidget::currentChanged,[=](int index) {
            auto it = get_cur_item();
            set_item_config(it,index);
        });
        connect(_tab_wid,&QTabWidget::tabBarDoubleClicked,[=](int index) {
            item_tab_lib *it = _vec_lib_item[index];

            win_add_tab_dig dig;
            dig.load_item_data(it);
            if(dig.exec() == QDialog::Accepted)
            {
                it->build_lib(item_tab_lib::e_reload);
            }
        });
    }
}

main_window::~main_window()
{
}

void main_window::set_prog_status(int status)
{
    if(status == item_tab_lib::e_start)
    {
        _prog_load->setValue(25);
        _lab_tips->setText(tr("开始构建"));
    }
    else if(status == item_tab_lib::e_build_finish)
    {
        _prog_load->setValue(50);
        _lab_tips->setText(tr("构建完成"));
    }
    else if(status == item_tab_lib::e_load_finish)
    {
        _prog_load->setValue(75);
        _lab_tips->setText(tr("载入完成"));
    }
    else if(status == item_tab_lib::e_add_finish)
    {
        _prog_load->setValue(100);
        _lab_tips->setText(tr("载入成功"));
        qDebug()<<"preview succeed";
    }
    else if(status == item_tab_lib::e_error)
    {
        _prog_load->setValue(0);
        _lab_tips->setText(tr("预览失败"));
        qDebug()<<"preview failed";
    }
}

item_tab_lib * main_window::init_item_tab()
{
    item_tab_lib *item = new item_tab_lib(this);

    QObject::connect(item,&item_tab_lib::sn_load_status,item,[=](int status){
        set_prog_status(status);
        if(status == item_tab_lib::e_load_finish)
        {
            if(item->get_load_type() == item_tab_lib::e_first_load)
            {
                QScrollArea *area = item->make_area();

                _tab_wid->addTab(area,item->_str_tab_title);
                item->_area = area;

                _vec_lib_item.push_back(item);
                _st_repeat_lib.emplace(item->_str_so_path);

                set_prog_status(item_tab_lib::e_add_finish);
                set_item_config(item,_tab_wid->count()-1);
            }
            else if(item->get_load_type() == item_tab_lib::e_reload)
            {
                int index = _tab_wid->currentIndex();
                item_tab_lib *it = _vec_lib_item[index];
                if(it && it->_area && it->_lib_load._lib_wid)
                {
                    it->_area->setWidget(it->_lib_load._lib_wid);
                    set_prog_status(item_tab_lib::e_add_finish);
                    set_item_config(it,index);
                }
            }
        }
    });
    return item;
}

item_tab_lib *main_window::get_cur_item()
{
    int index = _tab_wid->currentIndex();
    if(index >= 0 && index < _vec_lib_item.size())
    {
        item_tab_lib *item = _vec_lib_item[index];
        return item;
    }
    return nullptr;
}

void main_window::reload_cur_item()
{
    item_tab_lib *it = get_cur_item();
    if(it != nullptr)
    {
        it->build_lib(item_tab_lib::e_reload);
    }
}

void main_window::set_item_config(item_tab_lib *item,int index)
{
    if(item == nullptr) return ;

    // 开启定时更新
    _timer_update->stop();
    if(item->_time_update > 0 && item->_is_time_update) 
    {
        _timer_update->start(item->_time_update);
    }

    // 开启保存检测
    _timer_watch->stop();
    if(item->_time_update > 0 && item->_is_save_update && item->_vec_watch_file.size() > 0) 
    {
        _vec_watch_file_md5.clear();
        _vec_watch_file = item->_vec_watch_file;

        for(auto &a:_vec_watch_file)
        {
            std::string md5 = Fmd5::file_to_md5(a.toStdString());
            _vec_watch_file_md5.push_back(md5);
        }

        _timer_watch->start(item->_time_update);
    }

    // 开启窗口描边
    if(item->_lab_draw_frame == nullptr)
    {
        item->_lab_draw_frame = new QLabel;
        item->_lab_draw_frame->setFrameShape(QFrame::Box);
        item->_lab_draw_frame->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
    item->_lab_draw_frame->setParent(item->_area);
    item->_lab_draw_frame->resize(item->_lib_load._lib_wid->size());
    item->_lab_draw_frame->move(1,1);

    if(item->_is_draw_frame) item->_lab_draw_frame->show();
    else item->_lab_draw_frame->hide();
    
    // 设置切换窗口文本
    _tab_wid->setTabText(index,item->_str_tab_title);
}

bool main_window::install_lib(QString path)
{
    auto it  = _st_repeat_lib.find(path);
    if(it == _st_repeat_lib.end())
    {
        _st_repeat_lib.emplace(path);
        return true;
    }
    return false;
}


