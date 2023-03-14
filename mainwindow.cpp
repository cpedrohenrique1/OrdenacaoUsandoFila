#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete objetoVetor;
    objetoVetor = nullptr;
    delete ui;
}

void MainWindow::on_BotaoCriar_clicked()
{
    try
    {
        objetoVetor = new Pedro::Ordenar(ui->InputQuantidadeElementos->text().toInt());
        ui->SaidaArrayOriginal->setText(objetoVetor->acessarVetor());
    }
    catch (QString& erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}

void MainWindow::on_BotaoOrdenar_clicked()
{
    try
    {
        if (ui->InputRegra->currentText() == "Crescente")
        {
            objetoVetor->OrdenarCrescente();
        }
        else
        {
            objetoVetor->OrdenarDecrescente();
        }
        ui->SaidaArrayOrdenado->setText(objetoVetor->acessarVetor());
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}
