#pragma once

// 发送的各种数据
typedef struct _tagDATASEND
{
	int MC_POWER;		//电源（0-黑屏；1-上电）
	int	MC_STATE;		//列尾状态（0—未连接；1—已连接）
	int MC_AIRP;		//当前风压值（>=0KPA）0-1200
	int MC_AIRCHECK;	//风压查询 0无1查询 播报当前风压语音
	int MC_MODE;		//工作模式（0-自动；1-手动）
	int MC_LINE;		//线路ID（0-线路1，1-线路2）
	int	MC_AIRWARN;		//风压报警	0无1报警	播报当前风压报警语音
	int	MC_POWERWARN;	//电池报警 	0无1报警	播报电量报警语音
	int MC_LBJWARN;		//防护报警 0无1-5对应报警信息 语音播报对应信息
	int	MC_AIRDISCHARGE;//列尾排风状态确认0 无1结束  语音播报风压注意
	int MC_MALFUNCTION;	//故障黑屏0无1黑屏
	int	MC_SHOWorHIDE;	//软件显示隐藏 0 隐藏 1显示

	int MC_TOPBTN1;
	int MC_TOPBTN2;
	int MC_TOPBTN3;
	int MC_TOPBTN4;
	int MC_TOPBTN5;
	int MC_TOPBTN6;
	int MC_TOPBTN7;
	int MC_TOPBTN8;

	int MC_LEFTBTN_AIRDISCHARGE;	// 列为排风
	int MC_LEFTBTN_EMERGENCYCALL;	// 紧急呼叫
	int MC_LEFTBTN_WARNING;			// 报警
	int MC_LEFTBTN_MAINCONTROL;		// 主控
	int MC_LEFTBTN_RESET;			// 复位

	int MC_MIDBTN_CANCELNUM;		// 列尾消号
	int MC_MIDBTN_CONFIRM;			// 列尾确认
	int MC_MIDBTN_AIRPRESSCHECK;	// 风压查询
	int MC_MIDBTN_1;				// 数字1
	int MC_MIDBTN_2;				// 数字2
	int MC_MIDBTN_3;				// 数字3
	int MC_MIDBTN_4;				// 数字4
	int MC_MIDBTN_5;				// 数字5
	int MC_MIDBTN_6;				// 数字6
	int MC_MIDBTN_7;				// 数字7
	int MC_MIDBTN_8;				// 数字8
	int MC_MIDBTN_9;				// 数字9
	int MC_MIDBTN_STAR;				// 字符*
	int MC_MIDBTN_0;				// 数字0
	int MC_MIDBTN_HASH;				// 字符#

	int MC_RIGHTBTN_CALL;			// 呼叫
	int MC_RIGHTBTN_SWITCH;			// 切换
	int MC_RIGHTBTN_HANGUP;			// 挂断
	int MC_RIGHTBTN_SETTINGS;		// 设置
	int MC_RIGHTBTN_UP;				// 向上↑
	int MC_RIGHTBTN_INTERFACE;		// 界面
	int MC_RIGHTBTN_LEFT;			// 向左←
	int MC_RIGHTBTN_CONFIRM;		// 确认
	int MC_RIGHTBTN_RIGHT;			// 向右→
	int MC_RIGHTBTN_SEARCH;		// 查询
	int MC_RIGHTBTN_DOWN;			// 向下↓
	int MC_RIGHTBTN_BACKSPACE;		// 回格
	int MC_RIGHTBTN_PRINT;			// 打印
	int MC_RIGHTBTN_SHUNTINGREQUEST;// 调车请求
	int MC_RIGHTBTN_EXIT;			// 推出
}DATASEND;

// 接收的各种数据
typedef struct _tagDATARECV
{
	int	CM_MASTER;		//主控状态 0：副控 1 ：主控
	int	CM_AIRCHECK;	//风压查询 0无	1查询按下
	int	CM_AIRDISCHARGE;//列尾排风 0无	1排位确认
	int	CM_WARN;		//防护报警 0无	1报警
	int	CM_EMERCALL;	//紧急呼叫按钮0无	1按下
}DATARECV;