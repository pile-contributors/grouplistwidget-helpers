#include <grouplistwidget/grouplistwidget-config.h>

#include "../testhelpers.h"
#include "../../grouplistwidget/grouplistwidget.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>

int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a model
    QStandardItemModel * model = new QStandardItemModel (4, 4);
    for (int row = 0; row < 8; ++row) {
        for (int column = 0; column < 4; ++column) {
            QString s_value;
            if (column == 0) {
                s_value = QString("row %1, column %2")
                        .arg (row).arg (column);
            } else {
                s_value = QString("column %1").arg (column);
            }
            QStandardItem *item = new QStandardItem (s_value);
            model->setItem (row, column, item);
        }
    }

    // the widget to use that model
    GroupListWidget * widget = new GroupListWidget ();
    widget->setBaseModel (model);
    widget->show();

    int result = a.exec();
    delete widget; // all associated resources are freed
    return result;
}
