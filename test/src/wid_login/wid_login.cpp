
#include "wid_login.h"

wid_login::wid_login(QWidget *parent) : QWidget(parent)
{
    {
        this->setWindowTitle(tr("登录窗口"));
        this->resize(300,200);

        QVBoxLayout *lay_main = new QVBoxLayout(this);
        {
            QLabel *lab = new QLabel(this);
            lab->setText("欢迎登录图书馆");
            lab->setAlignment(Qt::AlignCenter);

            QVBoxLayout *lay = new QVBoxLayout;
            lay->addWidget(lab);
            lay_main->addLayout(lay);
        }
        {
            QLineEdit *ed_ac = new QLineEdit(this);
            ed_ac->setPlaceholderText(tr("请输入账号"));

            QLineEdit *ed_pwd = new QLineEdit(this);
            ed_pwd->setPlaceholderText(tr("请输入密码"));

            QVBoxLayout *lay = new QVBoxLayout;
            lay->addWidget(ed_ac);
            lay->addWidget(ed_pwd);
            lay_main->addLayout(lay);
        }
        {
            QCheckBox *ck_pwd = new QCheckBox(this);
            ck_pwd->setText(tr("记住密码"));

            QVBoxLayout *lay = new QVBoxLayout;
            lay->addWidget(ck_pwd);
            lay_main->addLayout(lay);
        }
        {
            QPushButton *but_login = new QPushButton(this);
            but_login->setText(tr("登录"));

            QVBoxLayout *lay = new QVBoxLayout;
            lay->addWidget(but_login);
            lay_main->addLayout(lay);
        }
        {
            QLabel *lab_tips = new QLabel(this);
            lab_tips->setText(tr("提示：登录窗口"));

            QVBoxLayout *lay = new QVBoxLayout;
            lay->addWidget(lab_tips);
            lay_main->addLayout(lay);
        }
    }
}

wid_login::~wid_login()
{
}

QWidget *get_wid()
{
    return new wid_login;
}
