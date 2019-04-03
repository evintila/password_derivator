#include "passwordderivator.h"

#include <QCryptographicHash>

QString CPasswordDerivator::derive(const QString &site, const QString &username,
                 const QString &password, const QString &counter)
{
  // concatenate and hash the padded parameters
  QByteArray password_as_bytes = hash(pad(site) + pad(username) + pad(password) +
                                      pad(counter));
  // encode to base64 and trim the trailing equal
  // the size of the hash result is 32 bytes and the base64 encoding is 33 bytes
  return QString(password_as_bytes.toBase64(QByteArray::Base64Option::OmitTrailingEquals));
}

// pads the feed with its length in ASCII
QString CPasswordDerivator::pad(const QString &feed)
{
  return feed + QString::number(feed.length());
}

// hash the feed using SHA256
QByteArray CPasswordDerivator::hash(const QString &feed)
{
  return QCryptographicHash::hash(feed.toUtf8(), QCryptographicHash::Sha256);
}
