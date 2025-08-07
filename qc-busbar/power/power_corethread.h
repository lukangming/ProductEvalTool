#ifndef POWER_CORETHREAD_H
#define POWER_CORETHREAD_H
#include "power_devctrl.h"
// #include "json_pack.h"
#include "testconfig.h"
#include "people_judg.h"
#include "safety/test_transthread.h"

class Power_CoreThread : public Power_Object
{
    Q_OBJECT
public:
    explicit Power_CoreThread(QObject *parent = nullptr);
    void clearStartEleSlot();
    bool printer();
    void initTestTrans(Test_TransThread *test);
    Test_TransThread *mTrans;
<<<<<<< Updated upstream
=======

public slots:
    void powerOffSlot();
>>>>>>> Stashed changes
protected slots:
    void initFunSlot();

signals:
    void noLoadSig();
    void refreshTableSig();
    void TipSig(QString str);
    void finshSig(bool ret);
    void JudgSig();
    void ImageSig(int value);

    //void updateTableObjSig(sObjData obj, int loopNum);

private slots:
    void noloadHomeSlot(int ret);

public slots:
//    void clearStartEleSlot();
    void getNumAndIndexSlot(int curnum);
    void getDelaySlot();
protected:
    void run();
    void workDown();
    bool initDev();
    void StartErrRange();
    void EnvErrRange();
    bool VolErrRange();
    bool CurErrRange();
    void InsertErrRange();
    void BaseErrRange();
    bool eleErrRange(int i);
    bool eleErrRange0(int i);


    bool volAlarmErr(int i);
    bool curAlarmErr(int i);
    bool powAlarmErr(int i);
    bool lineVolAlarmErr(int i);
    bool checkAlarmErr();
    bool envAlarmErr();
    bool hzAlarmErr();
    bool totalPowAlarmErr();
    bool zeroLineCurAlarmErr();
    bool residualAlarmErr();

    bool volAlarmWrite(int i);
    bool curAlarmWrite(int i);
    bool writeAlarmTh();

    bool factorySet();
    void workResult(bool);

    bool checkVersion();
    bool checkEnvVersion();
    bool checkVolErrRange();
    bool checkLoadErrRange();
    bool volLoadErrRange(int i);
    bool curLoadErrRange(int i);
    bool powLoadErrRange(int i);

    bool stepVolTest();
    bool Vol_ctrlOne();
    bool Vol_ctrlTwo();
    bool Vol_ctrlThree();
    bool stepLoadTest();
    bool BreakerTest();

    QString changeMode(int index);
    void autoSetAddress();
    QString trans(int index);


    bool VolCurCtrl(sObjData *,int id);
    bool VolCurCtrlSigle(sObjData *,int id);
    void clearObjVolCur(sObjData *);
    bool checkVolCurErr(sObjData *);
    bool tryReadVolCur(sObjData *,int id);
    bool tryReadVolCurSig(sObjData *,int id);

    bool BasicTypeBreakTest(sObjData *);
    bool handleBasicType();
private:
    Power_Logs *mLogs;
    Power_DevRead *mRead;
    Power_DevCtrl *mCtrl;
    QString mMacStr;
    int mRet;
    int mCurBoxNum;
    sTestConfigItem  *mCfg;
    RtuRw *mModbus;
    Dev_Source *mSource;
    People_judg *mJudg;
    // uchar loopNum;
    Dev_SiRtu *mSiRtu;
    Power_ErrRange *mErr;
    sCfgItem *mItem;
};

double calculateAverageWithoutHighestAndLowest(QVector<ushort> &numbers);
#endif // POWER_CORETHREAD_H
