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

//https://stackoverflow.com/questions/10443894/how-to-set-qgraphicsscene-view-to-a-specific-coordinate-system
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(this);
    scene->setSceneRect(-180, 180, 180, -180);
    view->setScene(scene);
    view->scale(1, -1);
    setCentralWidget(view);

    QBrush greenBrush(Qt::green);
     QBrush blueBrush(Qt::blue);
     QPen RedPen(Qt::red);
     QPen GreenPen(Qt::green);
     QPen pen(Qt::black);
     pen.setWidth(2);

     QGraphicsRectItem* rectangle = scene->addRect(-180, 180, 180, -180, pen);
//     QGraphicsEllipseItem* ellipse = scene->addEllipse(0, 80, 200, 60,
//    pen, blueBrush);
//     QGraphicsTextItem* text = scene->addText("Hello World!",
//    QFont("Times", 25));

     QRect middle = view->geometry();

     QGraphicsLineItem *line1 = scene->addLine(-180, 180, 180 ,-180);
     line1->setPen(GreenPen);
    QGraphicsLineItem *line2 = scene->addLine(360,360,0,0);
     line2->setPen(RedPen);

//     QGraphicsLineItem *line3 = scene->addLine(0,0, 1000,500, pen);



}

MainWindow::~MainWindow()
{
    delete ui;
}

