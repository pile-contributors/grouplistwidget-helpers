#include <grouplistwidget/grouplistwidget-config.h>

#include "../testhelpers.h"
#include "../../grouplistwidget/grouplistwidget.h"
#include "../../grouplistwidget/groupmodel.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>


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




int main (int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a model
    QStandardItemModel * model = new QStandardItemModel ();
    setEmployeModel (model);

    createEmploye (model, "John", "Smith", 24, false, "Security");
    createEmploye (model, "Michiko", "Bernard ", 27, true, "Mechanic");
    createEmploye (model, "Mistie", "Lucian ", 25, true, "Mechanic");
    createEmploye (model, "Tawanna", "Bushway ", 24, true, "Security");
    createEmploye (model, "Ashlie", "Rampton ", 45, true, "Security");
    createEmploye (model, "Erich", "Pitkin ", 53, false, "Mechanic");
    createEmploye (model, "Dexter", "Kinchen ", 32, false, "Mechanic");
    createEmploye (model, "Aleta", "Valliere ", 24, true, "Driver");
    createEmploye (model, "Meridith", "Bohling ", 24, true, "Mechanic");
    createEmploye (model, "Gertude", "Honore ", 45, true, "Driver");
    createEmploye (model, "Dorthey", "Hysmith ", 35, true, "Mechanic");
    createEmploye (model, "Odilia", "Bronson ", 24, true, "Mechanic");
    createEmploye (model, "Annita", "Taitt ", 73, true, "Security");
    createEmploye (model, "Les", "Quackenbush ", 24, false, "Security");
    createEmploye (model, "Hanna", "Infantino ", 18, true, "Driver");
    createEmploye (model, "Malinda", "Springs ", 24, true, "Mechanic");
    createEmploye (model, "Claudia", "Lingle ", 73, true, "Driver");
    createEmploye (model, "Lory", "Weatherhead ", 20, true, "Mechanic");
    createEmploye (model, "Cammy", "Chaisson ", 24, true, "Mechanic");
    createEmploye (model, "Gene", "Petrucci ", 18, false, "Security");
    createEmploye (model, "Kaleigh", "Brockman ", 24, true, "Driver");

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
