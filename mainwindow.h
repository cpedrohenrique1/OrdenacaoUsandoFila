#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ordenar.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BotaoCriar_clicked();

    void on_BotaoOrdenar_clicked();

private:
    Ui::MainWindow *ui;
    Pedro::Ordenar *objetoVetor;
};
#endif // MAINWINDOW_H
