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
  QApplication::clipboard()->clear();

  delete ui;
}

void MainWindow::on_generate_pushButton_clicked()
{
  QString counter = ui->counter_lineEdit->text();
  QString site = ui->site_lineEdit->text();
  QString username = ui->username_lineEdit->text();
  QString password = ui->password_lineEdit->text();

  QString generated_password = CPasswordDerivator::generate(site, username, password, counter);

  QApplication::clipboard()->setText(generated_password);
}

void MainWindow::on_site_lineEdit_returnPressed()
{
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
