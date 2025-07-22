#include "utils.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QDebug>

QString getAssetPath(const QString& fileName) {
    QString appPath = QCoreApplication::applicationDirPath();
    QString assetPath = QDir::cleanPath(appPath + "/Assets/" + fileName);
    assetPath = QDir::toNativeSeparators(assetPath);

    if (!QFile::exists(assetPath)) {
        qWarning() << "File not found:" << assetPath;
    }

    return assetPath;
}
