
#include "wid_preview_wid.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

wid_preview_wid::wid_preview_wid(QWidget *parent) : QWidget(parent)
{
    this->resize(700,200);

    QPushButton *butt = new QPushButton(tr("butt 1"),this);
    butt->resize(300,100);
    butt->show();

    QPushButton *butt2 = new QPushButton(tr("butt2"),this);
    butt2->move(200,200);

    QPushButton *butt3 = new QPushButton(tr("butt3"),this);
    butt3->move(100,200);

    QPushButton *butt4 = new QPushButton(tr("butt4"),this);
    butt4->move(0,50);
    butt4->resize(400,100);
    butt4->setStyleSheet(R"(
        QPushButton {
            background-color: #4CAF50;
            color: white;
            font: bold 14px;
            border-radius: 10px;
            border: 2px solid #4CAF50;
            padding: 10px 20px;
            margin: 5px;
        }
        
        QPushButton:hover {
            background-color: #45a049;
        }
        
        QPushButton:pressed {
            background-color: #3e8e41;
        }
        
        QPushButton:disabled {
            background-color: #a5a5a5;
            color: #d3d3d3;
            border: 2px solid #a5a5a5;
        }
    )");

    QLabel *lab = new QLabel(this);
    lab->setFrameShape(QFrame::Box);
    lab->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *lay_main = new QHBoxLayout(this);
    lay_main->setContentsMargins(0,0,0,0);
    lay_main->addWidget(lab);

    // {
    //     QPushButton *butt1 = new QPushButton(tr("butt 1"),this);
    //     QPushButton *butt2 = new QPushButton(tr("butt 2"),this);
    //     QHBoxLayout *lay = new QHBoxLayout;
    //     lay->addWidget(butt1);
    //     lay->addWidget(butt2);
    //     lay_main->addLayout(lay);
    // }

    connect(butt,&QPushButton::clicked,[=](){
        static int i=0; i++;
        lab->setText(QString::number(i));
    });
}

wid_preview_wid::~wid_preview_wid()
{
}

wid_preview_wid *wid = new wid_preview_wid;
wid_preview_wid2 *wid2 = new wid_preview_wid2;

QWidget *get_wid()
{
    return wid;
}

QWidget *get_wid2()
{
    return wid2;
}

wid_preview_wid2::wid_preview_wid2(QWidget *parent) : QWidget(parent)
{
    this->resize(500,200);

    QPushButton *butt = new QPushButton(tr("butt 11"),this);
    butt->resize(300,100);
    butt->show();

    QLabel *lab = new QLabel(this);
    lab->setFrameShape(QFrame::Box);
    lab->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *lay_main = new QHBoxLayout(this);
    lay_main->setContentsMargins(0,0,0,0);
    lay_main->addWidget(lab);

}

wid_preview_wid2::~wid_preview_wid2()
{

}
