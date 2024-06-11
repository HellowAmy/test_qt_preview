
#ifndef WIN_ADD_TAB_DIG_H
#define WIN_ADD_TAB_DIG_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QDebug>
#include <QFileInfo>
#include <QRadioButton>

#include <set>

#include "handle_load_libray.h"

class win_add_tab_dig : public QDialog
{
    Q_OBJECT
public:
    win_add_tab_dig(QWidget *parent = nullptr);
    ~win_add_tab_dig();

    void load_item_data(item_tab_lib *item);
    void save_item_data();
    

signals:

protected:

private:
    QLineEdit *_edit_build_path = nullptr;
    QLineEdit *_edit_build_cmd = nullptr;

    QLineEdit *_edit_so_path = nullptr;
    QLineEdit *_edit_so_export = nullptr;

    QLineEdit *_edit_tab_title = nullptr;
    QLineEdit *_edit_update_time = nullptr;
    
    QRadioButton *_rd_timer_update = nullptr;
    QRadioButton *_rd_save_update = nullptr;
    QCheckBox *_ck_draw_frame = nullptr;
    QListWidget *_lswid_save = nullptr;

    QPushButton *_butt_confirm = nullptr;

    item_tab_lib *_item = nullptr;
};
#endif // WIN_ADD_TAB_DIG_H
