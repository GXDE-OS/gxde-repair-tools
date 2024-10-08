#include "permissionsrepairthread.h"

#include <QDebug>

PermissionsRepairThread::PermissionsRepairThread(QObject *parent)
    : QThread(parent)
{

}

void PermissionsRepairThread::run()
{
    const QString sh = "/usr/lib/gxde-repair-tools/plugins/permissions-repair/permissions-repair.sh";

    bool failed = false;

    for (const auto &info : m_toolsProxy->diskInfos())
    {
        if (!info.osName.contains("deepin", Qt::CaseInsensitive) &&
            !info.osName.contains("gxde", Qt::CaseInsensitive) &&
            !info.osName.contains("GXDE", Qt::CaseInsensitive))
            continue;

        QStringList users;
        for (const auto user : info.userList)
            users << user.name;

        const auto &r = m_toolsProxy->execAsChrootSynchronous(info.mountPoint, sh, users);

        failed |= r.exitCode;
    }

    emit commandFinished(!failed);
}
