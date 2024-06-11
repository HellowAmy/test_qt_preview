
#ifndef WID_LOGIN_H
#define WID_LOGIN_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class wid_login : public QWidget
{
    Q_OBJECT
public:
    wid_login(QWidget *parent = nullptr);
    ~wid_login();

signals:

protected:

private:

};


extern "C" {

QWidget* get_wid();

} // extern "C"

#endif // WID_LOGIN_H
