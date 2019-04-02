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
  void on_generate_pushButton_clicked();

  void on_site_lineEdit_returnPressed();

  void on_username_lineEdit_returnPressed();

  void on_password_lineEdit_returnPressed();

  void on_counter_lineEdit_returnPressed();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
