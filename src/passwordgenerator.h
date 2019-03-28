#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QString>
#include <QByteArray>

class CPasswordGenerator
{
public:
  static QString generate(const QString &site, const QString &username,
                          const QString &password, const QString &counter);

private:
  static QString    pad(const QString &feed);
  static QByteArray hash(const QString &feed);
};

#endif // PASSWORDGENERATOR_H
