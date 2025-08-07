#ifndef HOME_WORKWID_H
#define HOME_WORKWID_H

#include <QWidget>
#include "config.h"
#include "test_thread.h"
#include "test_safety.h"
#include "mainface/face_volinsul.h"
#include "mainface/face_power.h"
#include "testwebsocket.h"
#include "power_corethread.h"
#include <QLabel>
#include <QPainter>
#include "people_safety.h"

class VerticalLabel : public QLabel
{
public:
    VerticalLabel(const QString& text, QWidget* parent = nullptr)
        : QLabel(text, parent)
    {
        setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    }

protected:
    void paintEvent(QPaintEvent* event) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::TextAntialiasing);

        QFont font;
        font.setPointSize(12);
        font.setLetterSpacing(QFont::AbsoluteSpacing, 0);
        font.setWordSpacing(0);
        painter.setFont(font);

        painter.translate(width(), 0);
        painter.rotate(90);

        QRect rect(0, 0, height(), width());
        painter.drawText(rect, Qt::AlignCenter, text());
    }
};

namespace Ui {
class Home_WorkWid;
}

class Home_WorkWid : public QWidget
{
    Q_OBJECT

public:
    explicit Home_WorkWid(QWidget *parent = nullptr);
    ~Home_WorkWid();

signals:
    void startSig(int);
    void clearStartEleSig();
    void testBarSig(int);
    void powerOffSig();
protected slots:
    void timeoutDone();
    void overSlot();
    void updateWidSlot(int id);
    void polarSlot(QString str);
    void StatusSlot(bool ret);
    void SafeSlot();
    void SafeStop();

protected:
    void initLayout();
    void insertText();
    void setTextColor();
    void AcwStatus(bool ret);
    void GndStatus(bool ret);
    void FuncStatus(bool ret);
    QString getTime();
    void updateWid();
    void updateTime();
    void updateResult();
    void updateSig();
    bool initSerial();
    bool initSerialVol();
    bool initSerialGND();
    void initWid();
    void startTest();
    void overTest();
    void ItemStatus();
    bool checkUesr();
    void initTypeComboBox();
signals:
    void noloadHomeSig(int ret);

private slots:
    void insertTextslots(QString str,bool res);
    void on_vol_insulBtn_clicked();
    void on_groundBtn_clicked();
    // void on_clearBtn_clicked();
    void on_codeEit_textChanged(const QString &arg1); 
    void on_comBox_currentIndexChanged(int index);
    void PingSlot();
    void JudgSlots();
    void on_funcBtn_clicked();

    void on_snprintBtn_clicked();

    void on_safeSnEit_textChanged(const QString &arg1);

    void on_powerOffBtn_clicked();

private:
    Ui::Home_WorkWid *ui;

    uint mId, mFirst;
    QTimer *timer;
    sDevData * mDev;
    sProgress *mPro;
    sDevData * eDev;
    sProgress *ePro;
    sCfgItem *mCfgm;
    sDataPacket *mPacket;
    datapacket_English *mPacketEng;

    Test_Thread *mThread;
    Face_Power *mPower;
    Test_safety *mSafetyThread;
    Face_Volinsul *mVolInsul;
    Home_LoopTabWid *mLineTabWid;

    sTestConfigItem  *mItem;

    Power_CoreThread *mPowThread;
    Power_Logs *mLogs;
    Home_DataWid *mData;
    RtuRw *mModbus;
    Power_DevRead *mPowDev;

    People_judg *mJudg;
    People_Safety *mSafePeo;
    Sn_DevId *mDevSn;
};

extern bool Breaker;
#endif // HOME_WORKWID_H
