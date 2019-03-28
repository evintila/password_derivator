#include "passwordgenerator.h"

#include <QCryptographicHash>

QString CPasswordGenerator::generate(const QString &site, const QString &username,
                 const QString &password, const QString &counter)
{
  QByteArray password_as_bytes = hash(pad(site) + pad(username) + pad(password) +
                                      pad(counter));
  return QString(password_as_bytes.toBase64(QByteArray::Base64Option::OmitTrailingEquals));
}

QString CPasswordGenerator::pad(const QString &feed)
{
  return feed + QString(feed.length());
}

QByteArray CPasswordGenerator::hash(const QString &feed)
{
  return QCryptographicHash::hash(feed.toStdString().c_str(), QCryptographicHash::Sha3_256);
}
