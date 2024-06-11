
#include "win_add_tab_dig.h"

win_add_tab_dig::win_add_tab_dig(QWidget *parent) : QDialog(parent)
{
    {
        this->setWindowTitle(tr("动态库预览配置窗口"));

        QVBoxLayout *lay_main = new QVBoxLayout(this);
        {
            QGroupBox *box = new QGroupBox(tr("构建动态库"),this);

            _edit_build_path = new QLineEdit(box);
            _edit_build_path->setPlaceholderText(tr("脚本路径"));

            _edit_build_cmd = new QLineEdit(box);
            _edit_build_cmd->setPlaceholderText(tr("构建命令"));

            QVBoxLayout *lay = new QVBoxLayout(box);
            lay->addWidget(_edit_build_path);
            lay->addWidget(_edit_build_cmd);
            lay_main->addWidget(box);
        }
        {
            QGroupBox *box = new QGroupBox(tr("加载动态库"),this);

            _edit_so_path = new QLineEdit(box);
            _edit_so_path->setPlaceholderText(tr("动态库路径"));

            _edit_so_export = new QLineEdit(box);
            _edit_so_export->setPlaceholderText(tr("导出函数"));

            QVBoxLayout *lay = new QVBoxLayout(box);
            lay->addWidget(_edit_so_path);
            lay->addWidget(_edit_so_export);
            lay_main->addWidget(box);
        }
        {
            QGroupBox *box = new QGroupBox(tr("监控文件"),this);
            _lswid_save = new QListWidget(box);

            QLineEdit *edit_path = new QLineEdit(box);
            edit_path->setPlaceholderText(tr("添加自动保存监控文件路径"));

            QPushButton *butt_add = new QPushButton(tr("添加"),box);

            connect(butt_add,&QPushButton::clicked,[=](){
                _lswid_save->addItem(edit_path->text());
                edit_path->setText("");
            });

            connect(_lswid_save,&QListWidget::itemDoubleClicked,[=](QListWidgetItem *item){
                _lswid_save->removeItemWidget(item);
                delete item;
            });

            QHBoxLayout *layu = new QHBoxLayout;
            layu->addWidget(edit_path);
            layu->addWidget(butt_add);

            QVBoxLayout *lay = new QVBoxLayout(box);
            lay->addLayout(layu);
            lay->addWidget(_lswid_save);
            lay_main->addWidget(box);
        }
        {
            QGroupBox *box = new QGroupBox(tr("操作选项"),this);

            _edit_tab_title = new QLineEdit(box);
            _edit_tab_title->setPlaceholderText(tr("窗口标题"));

            _edit_update_time = new QLineEdit(box);
            _edit_update_time->setPlaceholderText(tr("定时间隔"));

            _rd_timer_update = new QRadioButton(tr("定时更新"),box);
            _rd_save_update = new QRadioButton(tr("保存更新"),box);
            _rd_save_update->setChecked(true);

            _ck_draw_frame = new QCheckBox(tr("绘制边框"),box);


            _butt_confirm = new QPushButton(tr("保存更改"),box);

            QHBoxLayout *layu = new QHBoxLayout;
            layu->addWidget(_edit_tab_title);
            layu->addWidget(_edit_update_time);

            QHBoxLayout *layd = new QHBoxLayout;
            layd->addWidget(_rd_timer_update);
            layd->addWidget(_rd_save_update);
            layd->addWidget(_ck_draw_frame);


            QVBoxLayout *lay = new QVBoxLayout(box);
            lay->addLayout(layu);
            lay->addLayout(layd);
            lay->addWidget(_butt_confirm);
            lay_main->addWidget(box);
        }
    }
    {
        connect(_butt_confirm,&QPushButton::clicked,[=](){
            save_item_data();
            emit accept();
        });
    }
}

win_add_tab_dig::~win_add_tab_dig()
{
}

void win_add_tab_dig::load_item_data(item_tab_lib *item)
{
    if(item == nullptr) return ;

    _item = item;
    _edit_build_path->setText(item->_str_build_path);
    _edit_build_cmd->setText(item->_str_build_cmd);
    _edit_so_path->setText(item->_str_so_path);
    _edit_so_export->setText(item->_str_so_export);
    _edit_tab_title->setText(item->_str_tab_title);
    _edit_update_time->setText(QString::number(item->_time_update));

    _rd_timer_update->setChecked(item->_is_time_update);
    _ck_draw_frame->setChecked(item->_is_draw_frame);

    for(int i=0;i<item->_vec_watch_file.size();i++)
    {
        QString file = item->_vec_watch_file[i];
        _lswid_save->addItem(file);
    }
}

void win_add_tab_dig::save_item_data()
{
    if(_item == nullptr) return ;

    _item->_is_time_update = _rd_timer_update->isChecked();
    _item->_is_save_update = _rd_save_update->isChecked();
    _item->_is_draw_frame = _ck_draw_frame->isChecked();
    _item->_time_update = _edit_update_time->text().toUInt();
    _item->_str_build_path = _edit_build_path->text();
    _item->_str_build_cmd = _edit_build_cmd->text();
    _item->_str_so_path = _edit_so_path->text();
    _item->_str_so_export = _edit_so_export->text();
    _item->_str_tab_title = _edit_tab_title->text();

    {
        std::set<QString> st_file;
        for(int i=0;i<_lswid_save->count();i++)
        {
            auto item = _lswid_save->item(i);   
            QString filename = item->text();
            st_file.emplace(filename);

        }
        std::vector<QString> vec_filename;
        for(auto &a:st_file)
        {
            QFileInfo info(a);
            if(info.exists())
            {
                vec_filename.push_back(a);
            }
        }
        _item->_vec_watch_file = vec_filename;
    }

}
