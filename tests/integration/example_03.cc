/**
 * \file tests/integration/example_03.cc
 * \brief GUI example using a custom model with random images.
 *
 * The example does not use the list delegate (GroupListDelegate).
 *
 */

#include <grouplistwidget/grouplistwidget-config.h>

#include "../testhelpers.h"
#include "../../grouplistwidget/grouplistwidget.h"
#include "../../grouplistwidget/groupmodel.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>

/* ------------------------------------------------------------------------- */
int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a model
    QStandardItemModel * model = new QStandardItemModel (4, 4);
    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            QStandardItem *item = new QStandardItem (
                        QString("row %1, column %2")
                        .arg (row).arg (column));
            model->setItem (row, column, item);
        }
        model->item(row, 0)->setData (
                    createRandomShapedPix (120, 320), Qt::DecorationRole);
    }

    // the widget to use that model
    GroupListWidget * widget = new GroupListWidget ();
    // the widget creates a model in constructor so use that
    GroupModel * m = widget->underModel ();
    // set the base (user)model inside that
    m->setBaseModel (model);
    // and turn on images
    m->setPixmapColumn (0);
    widget->show();

    int result = a.exec();
    delete widget; // all associated resources are freed
    return result;
}
/* ========================================================================= */
