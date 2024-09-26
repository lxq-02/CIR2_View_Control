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
        << new QLabel(QStringLiteral("软件显示隐藏："))
        << new QLabel(QStringLiteral("TopBtn1："))
        << new QLabel(QStringLiteral("TopBtn2："))
        << new QLabel(QStringLiteral("TopBtn3："))
        << new QLabel(QStringLiteral("TopBtn4："))
        << new QLabel(QStringLiteral("TopBtn5："))
        << new QLabel(QStringLiteral("TopBtn6："))
        << new QLabel(QStringLiteral("TopBtn7："))
        << new QLabel(QStringLiteral("TopBtn8："))
        << new QLabel(QStringLiteral("LeftBtn1："))
        << new QLabel(QStringLiteral("LeftBtn2："))
        << new QLabel(QStringLiteral("LeftBtn3："))
        << new QLabel(QStringLiteral("LeftBtn4："))
        << new QLabel(QStringLiteral("LeftBtn5："))
        << new QLabel(QStringLiteral("MidBtnCancelNum："))
        << new QLabel(QStringLiteral("MidBtnConfirm："))
        << new QLabel(QStringLiteral("MidBtnAirpressCheck："))
        << new QLabel(QStringLiteral("MidBtn1："))
        << new QLabel(QStringLiteral("MidBtn2："))
        << new QLabel(QStringLiteral("MidBtn3："))
        << new QLabel(QStringLiteral("MidBtn4："))
        << new QLabel(QStringLiteral("MidBtn5："))
        << new QLabel(QStringLiteral("MidBtn6："))
        << new QLabel(QStringLiteral("MidBtn7："))
        << new QLabel(QStringLiteral("MidBtn8："))
        << new QLabel(QStringLiteral("MidBtn9："))
        << new QLabel(QStringLiteral("MidBtnStart："))
        << new QLabel(QStringLiteral("MidBtn0："))
        << new QLabel(QStringLiteral("MidBtnHash："))
        << new QLabel(QStringLiteral("MidBtnCall："))			    
        << new QLabel(QStringLiteral("MidBtnSwitch："))			
        << new QLabel(QStringLiteral("MidBtnHangUp："))			
        << new QLabel(QStringLiteral("MidBtnSettings："))		    
        << new QLabel(QStringLiteral("MidBtnup："))				
        << new QLabel(QStringLiteral("MidBtnInterface："))		
        << new QLabel(QStringLiteral("MidBtnLeft："))			   
        << new QLabel(QStringLiteral("MidBtnConfirm："))		   
        << new QLabel(QStringLiteral("MidBtnRight："))			
        << new QLabel(QStringLiteral("MidBtnSearch："))		  
        << new QLabel(QStringLiteral("MidBtnDown："))			  
        << new QLabel(QStringLiteral("MidBtnBackspace："))		
        << new QLabel(QStringLiteral("MidBtnPrint："))			
        << new QLabel(QStringLiteral("MidBtnShuntingRequest：")) 
        << new QLabel(QStringLiteral("MidBtnExit："));

    for (int i = 0; i < sendLabels.size(); i++)
    {
        sendCombos << new QComboBox();
    }

    // 初始化每个组合框的选项为 0 和 1
    for (auto combo : sendCombos) {
        combo->addItem("0");
        combo->addItem("1");
    }

    for (int i = 2; i < 1201; i++)
    {
        QString str = QStringLiteral("%1").arg(i);
        sendCombos[2]->addItem(str);
    }
    for (int i = 2; i < 6; i++)
    {
        QString str = QStringLiteral("%1").arg(i);
        sendCombos[8]->addItem(str);
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
    QVBoxLayout* topLayout = new QVBoxLayout();
    QVBoxLayout* leftLayout = new QVBoxLayout();
    QVBoxLayout* midLayout = new QVBoxLayout();
    QVBoxLayout* rightLayout = new QVBoxLayout();

    for (int i = 0; i < recvLabels.size(); ++i) {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(recvLabels[i]);
        hLayout->addWidget(recvCombos[i]);
        recvLayout->addLayout(hLayout);
    }

    for (int i = 0; i < 12; ++i) 
    {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(sendLabels[i]);
        hLayout->addWidget(sendCombos[i]);
        sendLayout->addLayout(hLayout);
    }
    for (int i = 12; i < 20; ++i)
    {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(sendLabels[i]);
        hLayout->addWidget(sendCombos[i]);
        topLayout->addLayout(hLayout);
    }
    for (int i = 20; i < 25; ++i)
    {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(sendLabels[i]);
        hLayout->addWidget(sendCombos[i]);
        leftLayout->addLayout(hLayout);
    }
    for (int i = 25; i < 40; ++i)
    {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(sendLabels[i]);
        hLayout->addWidget(sendCombos[i]);
        midLayout->addLayout(hLayout);
    }
    for (int i = 40; i < 55; ++i)
    {
        QHBoxLayout* hLayout = new QHBoxLayout();
        hLayout->addWidget(sendLabels[i]);
        hLayout->addWidget(sendCombos[i]);
        rightLayout->addLayout(hLayout);
    }

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addLayout(sendLayout);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(midLayout);
    mainLayout->addLayout(rightLayout);
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

    m_dataSend.MC_TOPBTN1 = sendCombos[12]->currentIndex();
    m_dataSend.MC_TOPBTN2 = sendCombos[13]->currentIndex();
    m_dataSend.MC_TOPBTN3 = sendCombos[14]->currentIndex();
    m_dataSend.MC_TOPBTN4 = sendCombos[15]->currentIndex();
    m_dataSend.MC_TOPBTN5 = sendCombos[16]->currentIndex();
    m_dataSend.MC_TOPBTN6 = sendCombos[17]->currentIndex();
    m_dataSend.MC_TOPBTN7 = sendCombos[18]->currentIndex();
    m_dataSend.MC_TOPBTN8 = sendCombos[19]->currentIndex();

    m_dataSend.MC_LEFTBTN_AIRDISCHARGE = sendCombos[20]->currentIndex();
    m_dataSend.MC_LEFTBTN_EMERGENCYCALL = sendCombos[21]->currentIndex();
    m_dataSend.MC_LEFTBTN_WARNING = sendCombos[22]->currentIndex();
    m_dataSend.MC_LEFTBTN_MAINCONTROL = sendCombos[23]->currentIndex();
    m_dataSend.MC_LEFTBTN_RESET = sendCombos[24]->currentIndex();

    m_dataSend.MC_MIDBTN_CANCELNUM = sendCombos[25]->currentIndex();
    m_dataSend.MC_MIDBTN_CONFIRM = sendCombos[26]->currentIndex();
    m_dataSend.MC_MIDBTN_AIRPRESSCHECK = sendCombos[27]->currentIndex();
    m_dataSend.MC_MIDBTN_1 = sendCombos[28]->currentIndex();
    m_dataSend.MC_MIDBTN_2 = sendCombos[29]->currentIndex();
    m_dataSend.MC_MIDBTN_3 = sendCombos[30]->currentIndex();
    m_dataSend.MC_MIDBTN_4 = sendCombos[31]->currentIndex();
    m_dataSend.MC_MIDBTN_5 = sendCombos[32]->currentIndex();
    m_dataSend.MC_MIDBTN_6 = sendCombos[33]->currentIndex();
    m_dataSend.MC_MIDBTN_7 = sendCombos[34]->currentIndex();
    m_dataSend.MC_MIDBTN_8 = sendCombos[35]->currentIndex();
    m_dataSend.MC_MIDBTN_9 = sendCombos[36]->currentIndex();
    m_dataSend.MC_MIDBTN_STAR = sendCombos[37]->currentIndex();
    m_dataSend.MC_MIDBTN_0 = sendCombos[38]->currentIndex();
    m_dataSend.MC_MIDBTN_HASH = sendCombos[39]->currentIndex();

    m_dataSend.MC_RIGHTBTN_CALL = sendCombos[40]->currentIndex();
    m_dataSend.MC_RIGHTBTN_SWITCH = sendCombos[41]->currentIndex();
    m_dataSend.MC_RIGHTBTN_HANGUP = sendCombos[42]->currentIndex();
    m_dataSend.MC_RIGHTBTN_SETTINGS = sendCombos[43]->currentIndex();
    m_dataSend.MC_RIGHTBTN_UP = sendCombos[44]->currentIndex();
    m_dataSend.MC_RIGHTBTN_INTERFACE = sendCombos[45]->currentIndex();
    m_dataSend.MC_RIGHTBTN_LEFT = sendCombos[46]->currentIndex();
    m_dataSend.MC_RIGHTBTN_CONFIRM = sendCombos[47]->currentIndex();
    m_dataSend.MC_RIGHTBTN_RIGHT = sendCombos[48]->currentIndex();
    m_dataSend.MC_RIGHTBTN_SEARCH = sendCombos[49]->currentIndex();
    m_dataSend.MC_RIGHTBTN_DOWN = sendCombos[50]->currentIndex();
    m_dataSend.MC_RIGHTBTN_BACKSPACE = sendCombos[51]->currentIndex();
    m_dataSend.MC_RIGHTBTN_PRINT = sendCombos[52]->currentIndex();
    m_dataSend.MC_RIGHTBTN_SHUNTINGREQUEST = sendCombos[53]->currentIndex();
    m_dataSend.MC_RIGHTBTN_EXIT = sendCombos[54]->currentIndex();
}
