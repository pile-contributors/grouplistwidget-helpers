/**
 * \file tests/integration/example_02.cc
 * \brief GUI example using a custom model presenting employees
 *
 * The model features a dynamically generated icon for each item.
 *
 * The example does not use the list delegate (GroupListDelegate).
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
class GroupDerivedModel : public GroupModel {

public:

    //! Default constructor.
    GroupDerivedModel (
            QAbstractItemModel *model = NULL) :
        GroupModel(model)
    {
    }

    //! Destructor.
    virtual ~GroupDerivedModel() {}

    //! Sets the user model.
    virtual void
    setBaseModel (
            QAbstractItemModel * model) {
        GroupModel::setBaseModel (model);
    }

    //! Retreive user model.
    virtual QAbstractItemModel *
    baseModel () const {
        return GroupModel::baseModel ();
    }

    //! Take ownership of user model.
    QAbstractItemModel *
    takeBaseModel() {
        return GroupModel::takeBaseModel ();
    }

}; // GroupDerivedModel
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel * model = createEmployeModel ();

    GroupDerivedModel * internal_model = new GroupDerivedModel();
    internal_model->setPixmapColumn (0);
    internal_model->setBaseModel (model);

    // the widget to use that model
    GroupListWidget * widget = new GroupListWidget ();
    widget->setUnderModel (internal_model);

    widget->show();

    int result = a.exec();
    delete widget; // all associated resources are freed
    return result;
}
/* ========================================================================= */
