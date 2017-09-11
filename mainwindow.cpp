#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString> //Bookstore for the use of text strings
#include<cmath>  //Library for use of mathematical functions
#include "QDoubleSpinBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Connections
    connect(ui->Calcular,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borra,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::funcion(double c){
    return(667.38/c*(1-exp(-0.146843*c)))-40;//returns the drag function

}
void MainWindow::metodo(){
    QString temp,temp2,temp3; //Temporary use text strings
    double x1=ui->X1->value(); //Retrieves the X1 value of the spinbox
    double err=ui->Error->value(); //Retrieve the value of the spinbox error
    double xr=0.0;
    double ea=100.0;
    while(ea>err){
        xr=funcion(x1); //The function value is calculated at point X1
        ea=100*std::abs(xr-x1)/xr; //The error is calculated
        x1=xr; //we give the value of xr to x1 so that x1 is the current one and xr is xri + 1

    }
    temp.append("Raiz=").append(temp2.setNum(xr)).append("\nError=").append(temp3.setNum(ea));
    ui->Texto->setText(temp); //The text is presented

}
void MainWindow::borrar(){
    ui->X1->setValue(0.0);  //Spinbox is deleted
    ui->Error->setValue(0.0);
    ui->Texto->clear(); //Text is deleted
}
