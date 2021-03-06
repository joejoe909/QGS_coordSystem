#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPen>
#include <QScreen>
#include <QDebug>

//https://stackoverflow.com/questions/10443894/how-to-set-qgraphicsscene-view-to-a-specific-coordinate-system
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(this);

    //

    //  get screen resolution
    //  calculate the values for setsceneRect ...follow on...

    //  This will get you physical specs
    screens = QGuiApplication::screens();
    numOfScreens = screens.size();

    currentScreen = QGuiApplication::screenAt(geometry().center());
    qDebug() << "On screen: " << currentScreen->availableGeometry();

    // End

    //
    // This will get you parent geometry that our QGraphicsView will need to calculate
    // the values we pass to scene->setSceneRect();
    //

    QRect geo = this->geometry();

    //End

   // scene->setSceneRect(-1080, 540, 2160, 1080); //2160 is the width not the right coordinate.
    view->setScene(scene);
    view->scale(1, -1);
    setCentralWidget(view);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen RedPen(Qt::red);
    QPen GreenPen(Qt::green);
    QPen pen(Qt::black);
    pen.setWidth(1);

    //   QGraphicsRectItem* rectangle = scene->addRect(-900, -900, 900, 900, pen);
    //   QGraphicsEllipseItem* ellipse = scene->addEllipse(0, 80, 200, 60,
    //   pen, blueBrush);
    //   QGraphicsTextItem* text = scene->addText("Hello World!",
    //   QFont("Times", 25));

     QRect middle = view->geometry();
     qDebug() << middle;

     QGraphicsLineItem *line1 = scene->addLine(0,1000,0,-1000);
     line1->setPen(GreenPen);
     QGraphicsLineItem *line2 = scene->addLine(-2000,0,2000,0);
     line2->setPen(RedPen);

     QGraphicsLineItem *line3 = scene->addLine(0, 0, 2000,1000, pen);

    //adding more stuff later

     qDebug() << line3;

}

MainWindow::~MainWindow()
{
    delete ui;
}

