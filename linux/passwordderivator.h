#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QString>
#include <QByteArray>

class CPasswordDerivator
{
public:
  // derives a password from the input parameters
  static QString derive(const QString &site, const QString &username,
                          const QString &password, const QString &counter);

private:
  static QString    pad(const QString &feed);
  static QByteArray hash(const QString &feed);
};

#endif // PASSWORDGENERATOR_H
