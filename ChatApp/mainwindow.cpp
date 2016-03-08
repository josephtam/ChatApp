#include "mainwindow.h"
#include "ui_mainwindow.h"

QPushButton *sendButton;
QTextEdit   *inputTextEdit;
QListWidget *displayListWidget;
QListWidget *usersListWidget;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sendButton          = ui->sendButton;
    inputTextEdit       = ui->inputTextEdit;
    displayListWidget   = ui->displayListWidget;
    usersListWidget     = ui->usersListWidget;

    // Disable send button by default
    sendButton->setEnabled(false);

    // Associate a slot function to be called in the event that there is a change
    // in inputTextEdit text field
    connect(inputTextEdit, SIGNAL(textChanged()), this, SLOT(slotTextChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot function: Displays text from the inputTextEdit onto the displayListWidget
void MainWindow::on_sendButton_clicked()
{
    QString msg = inputTextEdit->toPlainText();
    inputTextEdit->setText("");
    new QListWidgetItem(msg, displayListWidget);
}

// Slot function: Enables/disables the sendButton if there is/isn't text in the inputTextEdit
void MainWindow::slotTextChanged()
{
    sendButton->setEnabled(!(inputTextEdit->toPlainText().isEmpty()));
}

// Displays c style string to the displayListWidget
void MainWindow::writeToDisplay(char *s)
{
    new QListWidgetItem(tr("test"), displayListWidget);
    new QListWidgetItem(s, displayListWidget);
}

// Displays c style string to the usersListWidget
void MainWindow::writeToUsersList(char *s)
{
    new QListWidgetItem(s, usersListWidget);
}
