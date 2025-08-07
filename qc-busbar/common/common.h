#ifndef COMMON_H
#define COMMON_H
#include "msgbox.h"
#include "config.h"

bool cm_pingNet(const QString& ip);
bool cm_isDigitStr(const QString &src);
bool cm_isIPaddress(const QString& ip);

QString cm_pathOfData(const QString& name);
QString cm_ByteArrayToHexStr(const QByteArray &array);
QString cm_ByteArrayToUcharStr(const QByteArray &array);


#endif // COMMON_H
