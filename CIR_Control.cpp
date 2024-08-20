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

    // 发送数据的标签和选择框
    sendLabels << new QLabel(QStringLiteral("电源："))
        << new QLabel(QStringLiteral("列尾状态："))
        << new QLabel(QStringLiteral("当前风压值："))
        << new QLabel(QStringLiteral("风压查询："))
        << new QLabel(QStringLiteral("工作模式："))
        << new QLabel(QStringLiteral("线路ID："))
        << new QLabel(QStringLiteral("风压报警："))
        << new QLabel(QStringLiteral("电池报警："))
        << new QLabel(QStringLiteral("防护报警："))
        << new QLabel(QStringLiteral("列尾排风状态确认："))
        << new QLabel(QStringLiteral("故障黑屏："))
        << new QLabel(QStringLiteral("软件显示隐藏："));

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

    // 初始化每个组合框的选项为 0 和 1
    for (auto combo : sendCombos) {
        combo->addItem("0");
        combo->addItem("1");
    }

    // 接收数据的标签和选择框
    recvLabels << new QLabel(QStringLiteral("主控状态："))
        << new QLabel(QStringLiteral("风压查询："))
        << new QLabel(QStringLiteral("列尾排风："))
        << new QLabel(QStringLiteral("防护报警："))
        << new QLabel(QStringLiteral("紧急呼叫按钮："));

    recvCombos << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox()
        << new QComboBox();

    // 初始化每个组合框的选项为 0 和 1
    for (auto combo : recvCombos) {
        combo->addItem("0");
        combo->addItem("1");
    }

    // 设置发送标签的下画线框样式
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

    // 初始化网络数据通信
    InitSmtNet(17);

    // 设置定时器，进行数据通信
    QTimer* timer = new QTimer(this);
    // 启动定时器
    timer->start(500);

    DATARECV dataTemp = { 1 };
    connect(timer, &QTimer::timeout, [=]() {
        // 目标机的标识 接收的字符串（char*)      字符串大小
        while (SMTRecvPtr(10, (char*)&dataTemp, sizeof(DATARECV)) > 0)
        {
            m_dataRecv = dataTemp;  // 获得上位机数据
        }

        updateRecv(m_dataRecv);
        updateSend();

    // 更新接收状态，发送信号
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
