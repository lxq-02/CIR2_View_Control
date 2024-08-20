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
    QVector<QLabel*> dataLabels;  // �洢��ǩ���б�


public:
    DATARECV m_dataRecv;    // �������ݽṹ��
    DATASEND m_dataSend;    // �������ݽṹ��

    QList<QLabel*> recvLabels;
    QList<QLabel*> sendLabels;

    QList<QComboBox*> sendCombos;
    QList<QComboBox*> recvCombos;

};
