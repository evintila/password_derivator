#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QClipboard>
#include <QCryptographicHash>

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
  counter += QString(counter.size());

  QString site = ui->site_lineEdit->text();
  site += QString(site.size());

  QString username = ui->username_lineEdit->text();
  username += QString(username.size());

  QString password = ui->password_lineEdit->text();
  password += QString(password.size());

  QString feed = counter + site + username + password;

  QString generated_password = QString((QCryptographicHash::hash(feed.toStdString().c_str(), QCryptographicHash::Keccak_256)).toBase64()); // @todo PAD before feeding

  QApplication::clipboard()->setText(generated_password);
}
