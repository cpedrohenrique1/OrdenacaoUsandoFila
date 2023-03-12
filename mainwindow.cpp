#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ordenar.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

static Pedro::Ordenar Ordem;

void MainWindow::on_BotaoCriar_clicked()
{
    try
    {
        Ordem.setVetor(ui->InputQuantidadeElementos->text().toInt());
        ui->SaidaArrayOriginal->setText(Ordem.acessarVetor());
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}

void MainWindow::on_BotaoOrdenar_clicked()
{
    try
    {
        Ordem.OrdenarFila(ui->InputRegra->currentText());
        ui->SaidaArrayOrdenado->setText(Ordem.acessarVetor());
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}
