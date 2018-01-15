#ifndef SCANNINGPAGE_H
#define SCANNINGPAGE_H

#include "diskutils.h"

#include <QWidget>
#include <QLabel>
#include <QPointer>
#include <QPushButton>

#include <DSpinner>

DWIDGET_USE_NAMESPACE

class ScanningPage : public QWidget
{
    Q_OBJECT

public:
    explicit ScanningPage(QWidget *parent = nullptr);

    void setDiskUtils(QPointer<DiskUtils> &diskUtils) { m_diskUtils = diskUtils; }

public slots:
    void startScan();

signals:
    void scanDone() const;

private slots:
    void onScanFinsihed(const QString &errorPartion);
    void repairPartion(const QString &errorPartion);

private:
    QPointer<DiskUtils> m_diskUtils;
    DSpinner *m_spinner;
    QLabel *m_icon;
    QLabel *m_centerTips;
    QLabel *m_bottomTips;
    QPushButton *m_cancel;
    QPushButton *m_repair;
};

#endif // SCANNINGPAGE_H
