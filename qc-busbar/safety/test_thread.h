#ifndef TEST_THREAD_H
#define TEST_THREAD_H

#include <QThread>
#include <QTimer>
#include "power_devctrl.h"
#include "face_Volinsul.h"

class Test_Thread  : public QThread
{Q_OBJECT
signals:
    void message(const QString& info);
    void progress(int present);
    void messageSig();

public:
    Test_Thread(QObject* par);
    ~Test_Thread();

    void startThread();
    void run();
    void stopThread();
    void doSomething();

    void timeoutDone();

private:
    QTimer *timer;
    sProgress *mPro;
    sDataPacket *mPacket;
    Test_TransThread *mTrans;
    Power_DevRead *mRead;
    sTestConfigItem  *mItem;
};

extern int mStep;
extern bool Breaker;
#endif // TEST_THREAD_H
