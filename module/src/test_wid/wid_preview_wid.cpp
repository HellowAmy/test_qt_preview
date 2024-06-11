
#include "wid_preview_wid.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

wid_preview_wid::wid_preview_wid(QWidget *parent) : QWidget(parent)
{
    this->resize(700,300);

    QPushButton *butt = new QPushButton(tr("butt 1"),this);
    butt->resize(300,300);
    butt->show();

    QPushButton *butt2 = new QPushButton(tr("butt2"),this);
    butt2->move(200,200);

    QPushButton *butt3 = new QPushButton(tr("butt3"),this);
    butt3->move(100,200);

    QPushButton *butt4 = new QPushButton(tr("butt4"),this);
    butt4->move(350,0);
    butt4->resize(400,100);
    butt4->setStyleSheet(R"(
        QPushButton {
            background-color: #4CAFff;
            color: white;
            font: bold 13px;
            border-radius: 20px;
            border: 9px solid #ffAF66;
            padding: 10px 20px;
            margin: 9px;
        }
        
        QPushButton:hover {
            background-color: #453349;
        }
        
        QPushButton:pressed {
            background-color: #f03941;
        }
        
        QPushButton:disabled {
            background-color: #a5a5a5;
            color: #d3d3d3;
            border: 2px solid #a5a5a5;
        }
    )");

    QLabel *lab = new QLabel(this);
    // lab->setFrameShape(QFrame::Box);
    lab->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *lay_main = new QHBoxLayout(this);
    lay_main->setContentsMargins(0,0,0,0);
    lay_main->addWidget(lab);
    
    {
        QPushButton *butt1 = new QPushButton(tr("butt 1"),this);
        QPushButton *butt2 = new QPushButton(tr("butt 2"),this);
        QPushButton *butt3 = new QPushButton(tr("butt 3"),this);
        QHBoxLayout *lay = new QHBoxLayout;
        lay->addWidget(butt1);
        lay->addWidget(butt2);
        lay->addWidget(butt3);
        lay_main->addLayout(lay);
    }

    connect(butt,&QPushButton::clicked,[=](){
        _num++;
        lab->setText(QString::number(_num));
    });
}

wid_preview_wid::~wid_preview_wid()
{
}

// wid_preview_wid *wid = new wid_preview_wid;
// wid_preview_wid2 *wid2 = new wid_preview_wid2;

QWidget *get_wid()
{
    return new wid_preview_wid;
}

QWidget *get_wid2()
{
    return new wid_preview_wid2;
}

wid_preview_wid2::wid_preview_wid2(QWidget *parent) : QWidget(parent)
{
    this->resize(500,500);

    QPushButton *butt = new QPushButton(tr("butt 3"),this);
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
