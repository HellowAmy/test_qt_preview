
#ifndef WID_PREVIEW_WID_H
#define WID_PREVIEW_WID_H

#include <QWidget>

class wid_preview_wid : public QWidget
{
    Q_OBJECT
public:
    wid_preview_wid(QWidget *parent = nullptr);
    ~wid_preview_wid();

signals:

protected:

private:
    int _num = 5;

};

class wid_preview_wid2 : public QWidget
{
    Q_OBJECT
public:
    wid_preview_wid2(QWidget *parent = nullptr);
    ~wid_preview_wid2();

signals:

protected:

private:

};

extern "C" {

QWidget* get_wid();
QWidget* get_wid2();

} // extern "C"
#endif // WID_PREVIEW_WID_H
