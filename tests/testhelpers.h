/* ========================================================================= */
/* ------------------------------------------------------------------------- */
/*!
  file         testhelpers.h
  date         December 2015
  author       Nicu Tofan

  Helper header that gets included in all test files.

*//*

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Please read COPYING and README files in root folder
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
/* ------------------------------------------------------------------------- */
/* ========================================================================= */
//
//
//
//
/*  INCLUDES    ------------------------------------------------------------ */

#include <string.h>

/*  INCLUDES    ============================================================ */
//
//
//
//
/*  DEFINITIONS    --------------------------------------------------------- */

#define EXPECT_NULL(__p__) EXPECT_TRUE(__p__ == NULL)
#define EXPECT_NNULL(__p__) EXPECT_FALSE(__p__ == NULL)
#define EXPECT_OK(__x__) EXPECT_EQ(__x__, FUNC_OK)


/*  DEFINITIONS    ========================================================= */
//
//
//
//
/*  DATA    ---------------------------------------------------------------- */

#include <QPixmap>
#include <QPainter>
#include <QSize>
#include <QStandardItemModel>

/*  DATA    ================================================================ */
//
//
//
//
/*  FUNCTIONS    ----------------------------------------------------------- */


/* ------------------------------------------------------------------------- */
int randInInterval (int first, int last)
{
    return qrand() % ((last + 1) - first) + first;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
QPixmap createRandomPix (QSize sz)
{
    QPixmap pix (sz);
    QPainter paint (&pix);

    int r = randInInterval(0, 255);
    int g = randInInterval(0, 255);
    int b = randInInterval(0, 255);

    paint.setPen (QColor(r, g, b));
    paint.setBrush (QBrush (QColor (255-r, 255-g, 255-b)));
    QRect rimg (0,0,sz.width(),sz.height());
    paint.drawRect (rimg);
    paint.drawText (rimg, QString::number(r*1000000 + g * 1000 + b));

    return pix;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
QPixmap createRandomShapedPix (int szmin, int szmax)
{
    return createRandomPix (
                QSize (
                    randInInterval (szmin, szmax),
                    randInInterval (szmin, szmax)));
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
QPixmap createRandomSmiley (int sz)
{
    QPixmap pix (sz, sz);
    QPainter paint (&pix);
    --sz;

    int r = randInInterval(0, 255);
    int g = randInInterval(0, 255);
    int b = randInInterval(0, 255);

    paint.setPen (QColor(r, g, b));
    paint.setBrush (QBrush (QColor (255-r, 255-g, 255-b)));
    QRect rimg (0, 0, sz, sz);
    paint.drawRect (rimg);

    sz -= 4;
    paint.setBrush (Qt::yellow);
    paint.drawEllipse (rimg.center(), sz/2, sz/2);

    paint.setBrush (Qt::red);
    paint.drawEllipse (QPoint(sz / 3, sz / 3), sz/8, sz/8);
    paint.drawEllipse (QPoint(3*sz / 4, sz / 3), sz/8, sz/8);

    paint.drawArc (QRect(1.5*sz/6, sz/3, 3.5*sz/6, sz / 2), 0, -180*16);

    return pix;
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
QPixmap createRandomShapedPix ()
{
    return createRandomShapedPix(1, 255);
}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void createEmploye (
        QStandardItemModel * model, const QString first_name,
        const QString second_name, int age, bool sex, const QString & job)
{
    int row = model->rowCount();

    QStandardItem *item = new QStandardItem (
                QString("%1 %2").arg (first_name).arg(second_name));
    item->setData (createRandomSmiley (32), Qt::DecorationRole);
    item->setData (QString(
                       "<dl>"
                       "<dt><b>First name:</b></dt><dd>%1</dd>"
                       "<dt><b>Second name:</b></dt><dd>%2</dd>"
                       "<dt><b>Age</b></dt><dd>%3 years</dd>"
                       "<dt><b>Sex:</b></dt><dd>%4</dd>"
                       "<dt><b>Job:</b></dt><dd>%5</dd>"
                       "</dl>")
                   .arg (first_name)
                   .arg (second_name)
                   .arg (age)
                   .arg (sex ? "Female" : "Male")
                   .arg (job),
                   Qt::ToolTipRole);

    model->setItem (row, 0, item);

    model->setItem (row, 1, new QStandardItem (first_name));
    model->setItem (row, 2, new QStandardItem (second_name));

    item = new QStandardItem ();
    item->setData (age, Qt::EditRole);
    model->setItem (row, 3, item);

    model->setItem (row, 4, new QStandardItem (sex ? "Female" : "Male"));
    model->setItem (row, 5, new QStandardItem (job));


}
/* ========================================================================= */

/* ------------------------------------------------------------------------- */
void setEmployeModel (
        QStandardItemModel * model)
{
    model->setHorizontalHeaderLabels(QStringList()
                                     << "Full Name"
                                     << "First Name"
                                     << "Second Name"
                                     << "Age"
                                     << "Sex"
                                     << "Job");
            /*
    model->setHeaderData (0, Qt::Horizontal, "Full Name", Qt::DisplayRole);
    model->setHeaderData (1, Qt::Horizontal, "First Name", Qt::DisplayRole);
    model->setHeaderData (2, Qt::Horizontal, "Second Name", Qt::DisplayRole);
    model->setHeaderData (3, Qt::Horizontal, "Age", Qt::DisplayRole);
    model->setHeaderData (4, Qt::Horizontal, "Sex", Qt::DisplayRole);
    model->setHeaderData (5, Qt::Horizontal, "Job", Qt::DisplayRole);*/
}
/* ========================================================================= */


/*  FUNCTIONS    =========================================================== */
//
//
//
//
/* ------------------------------------------------------------------------- */
/* ========================================================================= */


