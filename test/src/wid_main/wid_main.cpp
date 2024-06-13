
#include "wid_main.h"

wid_main::wid_main(QWidget *parent) : QWidget(parent)
{
    {
        QString qss = "/home/cong/open/test_qt/test_qt_preview/test/qss/StyleDefault.qss";
        QFile file(qss);
        if(file.open(QIODevice::ReadOnly))
        {
            QString sqss = file.readAll();
            this->setStyleSheet(sqss);
            file.close();
        }
    }
    {
        this->setWindowTitle(tr("图书馆"));
        this->resize(600,400);

        QVBoxLayout *lay_main = new QVBoxLayout(this);
        {
            QLabel *lab = new QLabel(this);
            lab->setAlignment(Qt::AlignCenter);
            lab->setText("欢迎登录图书馆首页");

            QHBoxLayout *lay = new QHBoxLayout;
            lay->addWidget(lab);
            lay_main->addLayout(lay);
        }
        {
            std::vector<QString> vec_fiction {
                "天龙八部","红楼梦","三国演义"
            };
            std::vector<QString> vec_history {
                "史记","上下五千年","资治通鉴"
            };
            std::vector<QString> vec_literature {
                "朝花夕拾","骆驼祥子","悲惨世界"
            };

            QRadioButton *_rd_fiction = new QRadioButton(tr("小说类"),this);
            QRadioButton *_rd_history = new QRadioButton(tr("历史类"),this);
            QRadioButton *_rd_literature = new QRadioButton(tr("文学类"),this);

            QListWidget *_lswid = new QListWidget(this);

            auto fn_change_ls = [=](){
                _lswid->clear();

                std::vector<QString> vec;
                if(_rd_fiction->isChecked()) vec = vec_fiction;
                else if(_rd_history->isChecked()) vec = vec_history;
                else if(_rd_literature->isChecked()) vec = vec_literature;
                
                for(int i=0;i<vec.size();i++)
                {
                    _lswid->addItem(vec[i]);
                }
            };

            connect(_rd_fiction,&QRadioButton::clicked,[=](){
                fn_change_ls();
            });
            connect(_rd_history,&QRadioButton::clicked,[=](){
                fn_change_ls();
            });
            connect(_rd_literature,&QRadioButton::clicked,[=](){
                fn_change_ls();
            });

            QVBoxLayout *layl = new QVBoxLayout;
            layl->addWidget(_rd_fiction);
            layl->addWidget(_rd_history);
            layl->addWidget(_rd_literature);

            QHBoxLayout *layr = new QHBoxLayout;
            layr->addWidget(_lswid);

            QHBoxLayout *laym = new QHBoxLayout;
            laym->addLayout(layl);
            laym->addLayout(layr);
            lay_main->addLayout(laym);
        }
        {
            QPushButton *but_download = new QPushButton(tr("下载"),this);
            but_download->setMinimumHeight(50);

            connect(but_download,&QPushButton::clicked,[=](){
                
                QDialog dig;

                QLabel lab(&dig);
                lab.setText("下载成功");
                lab.setAlignment(Qt::AlignCenter);
                QHBoxLayout lay(&dig);
                lay.addWidget(&lab);

                dig.resize(300,200);
                dig.setWindowTitle(tr("下载提示"));
                dig.exec();
            });

            QHBoxLayout *lay = new QHBoxLayout;
            lay->addWidget(but_download);
            lay_main->addLayout(lay);
        }
    }
}

wid_main::~wid_main()
{
}

QWidget *get_wid()
{
    return new wid_main;
}
