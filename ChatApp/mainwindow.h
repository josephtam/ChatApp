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
    void writeToDisplay(char *s);
    void writeToUsersList(char *s);

private slots:
    void on_sendButton_clicked();
    void slotTextChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
