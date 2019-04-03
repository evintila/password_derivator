#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QClipboard>
#include <QIntValidator>

#include "passwordderivator.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->password_lineEdit->setEchoMode(QLineEdit::Password);
  ui->counter_lineEdit->setValidator( new QIntValidator(0, 999, this) );
}

MainWindow::~MainWindow()
{
  // clear the clipboard when exiting?
  //QApplication::clipboard()->clear();

  delete ui;
}

void MainWindow::on_generate_pushButton_clicked()
{
  // get the parameters provided by the user
  QString counter = ui->counter_lineEdit->text();
  QString site = ui->site_lineEdit->text();
  QString username = ui->username_lineEdit->text();
  QString password = ui->password_lineEdit->text();

  // derive the password from the parameters
  QString derived_password = CPasswordDerivator::derive(site, username, password, counter);

  // put the derived password in the clipboard
  QApplication::clipboard()->setText(derived_password);
}

void MainWindow::on_site_lineEdit_returnPressed()
{
  // move the focus to the next text input field
  this->focusNextChild();
}

void MainWindow::on_username_lineEdit_returnPressed()
{
  this->focusNextChild();
}

void MainWindow::on_password_lineEdit_returnPressed()
{
  this->focusNextChild();
}

void MainWindow::on_counter_lineEdit_returnPressed()
{
  this->focusNextChild();
}
