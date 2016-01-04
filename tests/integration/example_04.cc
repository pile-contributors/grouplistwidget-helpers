/**
 * \file tests/integration/example_04.cc
 * \brief GUI example using a
 *
 * The example DOES use the list delegate (GroupListDelegate).
 *
 */

#include <grouplistwidget/grouplistwidget-config.h>

#include "../testhelpers.h"
#include "../../grouplistwidget/grouplistwidget.h"
#include "../../grouplistwidget/groupmodel.h"
#include "../../grouplistwidget/grouplistdelegate.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>

/* ------------------------------------------------------------------------- */
int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a model
    QStandardItemModel * model = createEmployeModel ();

    // the widget to use that model
    GroupListWidget * widget = new GroupListWidget ();

    // use some of the data as additional labels
    // column 0 is added by the constructor and can be changed
    // using setLabel ()
    widget->underModel ()->addlabel (1);
    widget->underModel ()->addlabel (2);
    widget->underModel ()->addlabel (3);
    widget->underModel ()->addlabel (4);

    // use this  delegate for list items
    widget->setListDelegate (new GroupListDelegate ());

    // we're going to show icons

    widget->setPixmapSize (20);
    widget->underModel ()->setPixmapColumn (0);
    widget->underModel ()->setBaseModel (model);

    widget->show ();

    int result = a.exec();
    delete widget; // all associated resources are freed
    return result;
}
/* ========================================================================= */
