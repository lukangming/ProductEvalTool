/*
 *
 *  Created on: 2021年1月1日
 *      Author: Lzy
 */
#include "home_looptabwid.h"

Home_LoopTabWid::Home_LoopTabWid(QWidget *parent) : ComTableWid(parent)
{
    initWid();
    mDev = sDataPacket::bulid()->getDev();
    mItem = Cfg::bulid()->item;
    mData = &(mDev->line);
}

void Home_LoopTabWid::initWid()
{
    header << tr("电流") << tr("电压") << tr("有功功率")  << tr("功率因数") << tr("电能") << tr("温度");
    initTableWid(header, 9, "回路数据列表");
    mBusData = get_share_mem();
}

void Home_LoopTabWid::appendItem(sBoxData *box)
{
    sObjectData *dev = &(box->data);
    if(box->loopNum > 3) {
        for(int i=0; i<box->loopNum; ++i) {
            QStringList listStr;

            listStr << QString::number(dev->cur.value[i]/COM_RATE_CUR,'f',3);
            listStr << QString::number(dev->vol.value[i]/COM_RATE_VOL,'f',1);
            listStr << QString::number(dev->pow.value[i]/COM_RATE_POW,'f',3);
            listStr << QString::number(dev->pf[i]/COM_RATE_PF,'f',2);
            listStr << QString::number(dev->ele[i]/COM_RATE_ELE,'f',2);
            if(i<4) listStr << QString::number(box->env.tem.value[i]/COM_RATE_TEM,'f',1);

            setTableRow(i, listStr);
            // if(i<4) setItemColor(i, 5, box->env.tem.status[i]);

            // setItemColor(i, 0, dev->cur.status[i]);
            // setItemColor(i, 1, dev->vol.status[i]);
            // setItemColor(i, 2, dev->pow.status[i]);
        }
    }else if(box->loopNum == 3) {
        for(int i=0; i<box->loopNum + 1; ++i) {
            QStringList listStr;
            if(i == 3) {
                listStr << " "<< " "<< " "<< " "<< " ";
                listStr << QString::number(box->env.tem.value[i]/COM_RATE_TEM,'f',1);
            }else{
                listStr << QString::number(dev->cur.value[i]/COM_RATE_CUR,'f',3);
                listStr << QString::number(dev->vol.value[i]/COM_RATE_VOL,'f',1);
                listStr << QString::number(dev->pow.value[i]/COM_RATE_POW,'f',3);
                listStr << QString::number(dev->pf[i]/COM_RATE_PF,'f',2);
                listStr << QString::number(dev->ele[i]/COM_RATE_ELE,'f',2);
                listStr << QString::number(box->env.tem.value[i]/COM_RATE_TEM,'f',1);
            }

            setTableRow(i, listStr);
            // setItemColor(i, 5, box->env.tem.status[i]);

            // setItemColor(i, 0, dev->cur.status[i]);
            // setItemColor(i, 1, dev->vol.status[i]);
            // setItemColor(i, 2, dev->pow.status[i]);
        }
    }
}

void Home_LoopTabWid::timeoutDone()
{
    clearTable();
    // initTableWid(header, mBusData->box[mItem->addr-1].loopNum, "回路数据列表");
    if((mBusData->box[mItem->addr-1].loopNum) &&(mBusData->box[mItem->addr-1].loopNum < 10)) {
        appendItem(&(mBusData->box[mItem->addr-1]));
    }
}
