#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addPluginButton_clicked();

    void on_pluginsList_currentRowChanged(int currentRow);

private:
    void populatePluginsList();
    Ui::MainWindow *ui;
    QList<QObject*> plugins;
};

#endif // MAINWINDOW_H
