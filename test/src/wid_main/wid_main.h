
#ifndef WID_MAIN_H
#define WID_MAIN_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QFile>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QListWidget>

#include <vector>

class wid_main : public QWidget
{
    Q_OBJECT
public:
    wid_main(QWidget *parent = nullptr);
    ~wid_main();

signals:

protected:

private:

};


extern "C" {

QWidget* get_wid();

} // extern "C"

#endif // WID_MAIN_H
