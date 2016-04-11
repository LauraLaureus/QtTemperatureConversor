#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_clicked()
{
    bool ok = true;
    ui->fInput->text().toDouble(&ok);
    if(ok)
        convert();
    else
        ui->cOutput->setText("ERROR");
}


void MainWindow::on_clean_clicked()
{
    ui->cOutput->setText("");
    ui->fInput->setText("");
}

void MainWindow::convert(){
     bool ok = true;
    QString sdato = ui->fInput->text();
    double ddato = sdato.toDouble(&ok);
    double dresultado = (ddato -32.0)*5.0/9.0;
    QString sresultado = QString::number(dresultado);
    ui->cOutput->setText(sresultado);
}

void MainWindow::on_fInput_returnPressed()
{
    bool ok = true;
    ui->fInput->text().toDouble(&ok);
    if(ok)
        convert();
    else
        ui->cOutput->setText("ERROR");
}
