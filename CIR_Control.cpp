#include "CIR_Control.h"
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include "SMTNet/SMTnet.h"
#include <QTimer>
#include <QDebug>

CIR_Control::CIR_Control(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->resize(800, 500);

    // �������ݵı�ǩ��ѡ���
    sendLabels << new QLabel(QStringLiteral("��Դ��"))
        << new QLabel(QStringLiteral("��β״̬��"))
        << new QLabel(QStringLiteral("��ǰ��ѹֵ��"))
        << new QLabel(QStringLiteral("��ѹ��ѯ��"))
        << new QLabel(QStringLiteral("����ģʽ��"))
        << new QLabel(QStringLiteral("��·ID��"))
        << new QLabel(QStringLiteral("��ѹ������"))
        << new QLabel(QStringLiteral("��ر�����"))
        << new QLabel(QStringLiteral("����������"))
        << new QLabel(QStringLiteral("��β�ŷ�״̬ȷ�ϣ�"))
        << new QLabel(QStringLiteral("���Ϻ�����"))
        << new QLabel(QStringLiteral("�����ʾ���أ�"));

    sendCombos << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox();

    // ��ʼ��ÿ����Ͽ��ѡ��Ϊ 0 �� 1
    for (auto combo : sendCombos) {
        combo->addItem("0");
        combo->addItem("1");
    }

    // �������ݵı�ǩ��ѡ���
    recvLabels << new QLabel(QStringLiteral("����״̬��"))
        << new QLabel(QStringLiteral("��ѹ��ѯ��"))
        << new QLabel(QStringLiteral("��β�ŷ磺"))
        << new QLabel(QStringLiteral("����������"))
        << new QLabel(QStringLiteral("�������а�ť��"));

    recvCombos << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox();

    // ��ʼ��ÿ����Ͽ��ѡ��Ϊ 0 �� 1
    for (auto combo : recvCombos) {
        combo->addItem("0");
        combo->addItem("1");
    }

    // ���÷��ͱ�ǩ���»��߿���ʽ
    for (auto label : sendLabels) {
        label->setStyleSheet("QLabel { border-bottom: 2px solid black; }");
    }

    QVBoxLayout* recvLayout = new QVBoxLayout();
    QVBoxLayout* sendLayout = new QVBoxLayout();

    for (int i = 0; i < recvLabels.size(); ++i) {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(recvLabels[i]);
        hLayout->addWidget(recvCombos[i]);
        recvLayout->addLayout(hLayout);
    }

    for (int i = 0; i < sendLabels.size(); ++i) {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(sendLabels[i]);
        hLayout->addWidget(sendCombos[i]);
        sendLayout->addLayout(hLayout);
    }

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addLayout(sendLayout);
    mainLayout->addLayout(recvLayout);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // ��ʼ����������ͨ��
    InitSmtNet(17);

    // ���ö�ʱ������������ͨ��
    QTimer* timer = new QTimer(this);
    // ������ʱ��
    timer->start(500);

    DATARECV dataTemp = { 1 };
    connect(timer, &QTimer::timeout, [=]() {
        // Ŀ����ı�ʶ ���յ��ַ�����char*)      �ַ�����С
        while (SMTRecvPtr(10, (char*)&dataTemp, sizeof(DATARECV)) > 0)
        {
            m_dataRecv = dataTemp;  // �����λ������
        }

        updateRecv(m_dataRecv);
        updateSend();

    // ���½���״̬�������ź�
    SMTSendPtr(10, (char*)&m_dataSend, sizeof(DATASEND));
        });
}

CIR_Control::~CIR_Control()
{
    UnSmtNet();
}

void CIR_Control::updateRecv(DATARECV data)
{
    recvCombos[0]->setCurrentIndex(data.CM_MASTER);
    recvCombos[1]->setCurrentIndex(data.CM_AIRCHECK);
    recvCombos[2]->setCurrentIndex(data.CM_AIRDISCHARGE);
    recvCombos[3]->setCurrentIndex(data.CM_WARN);
    recvCombos[4]->setCurrentIndex(data.CM_EMERCALL);
}

void CIR_Control::updateSend()
{
    m_dataSend.MC_POWER = sendCombos[0]->currentIndex();
    m_dataSend.MC_STATE = sendCombos[1]->currentIndex();
    m_dataSend.MC_AIRP = sendCombos[2]->currentIndex();
    m_dataSend.MC_AIRCHECK = sendCombos[3]->currentIndex();
    m_dataSend.MC_MODE = sendCombos[4]->currentIndex();
    m_dataSend.MC_LINE = sendCombos[5]->currentIndex();
    m_dataSend.MC_AIRWARN = sendCombos[6]->currentIndex();
    m_dataSend.MC_POWERWARN = sendCombos[7]->currentIndex();
    m_dataSend.MC_LBJWARN = sendCombos[8]->currentIndex();
    m_dataSend.MC_AIRDISCHARGE = sendCombos[9]->currentIndex();
    m_dataSend.MC_MALFUNCTION = sendCombos[10]->currentIndex();
    m_dataSend.MC_SHOWorHIDE = sendCombos[11]->currentIndex();
}
