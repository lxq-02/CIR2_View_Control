#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CIR_Control.h"
#include "struct.h"
#include <QLabel>

class CIR_Control : public QMainWindow
{
    Q_OBJECT

public:
    CIR_Control(QWidget *parent = nullptr);
    ~CIR_Control();

    void updateRecv(DATARECV data);
    void updateSend();

private:
    Ui::CIR_ControlClass ui;

private:
    QVector<QLabel*> dataLabels;  // 存储标签的列表


public:
    DATARECV m_dataRecv;    // 接收数据结构体
    DATASEND m_dataSend;    // 发送数据结构体

    QList<QLabel*> recvLabels;
    QList<QLabel*> sendLabels;

    QList<QComboBox*> sendCombos;
    QList<QComboBox*> recvCombos;

};
