#pragma once

// ���͵ĸ�������
typedef struct _tagDATASEND
{
	int MC_POWER;		//��Դ��0-������1-�ϵ磩
	int	MC_STATE;		//��β״̬��0��δ���ӣ�1�������ӣ�
	int MC_AIRP;		//��ǰ��ѹֵ��>=0KPA��0-1200
	int MC_AIRCHECK;	//��ѹ��ѯ 0��1��ѯ ������ǰ��ѹ����
	int MC_MODE;		//����ģʽ��0-�Զ���1-�ֶ���
	int MC_LINE;		//��·ID��0-��·1��1-��·2��
	int	MC_AIRWARN;		//��ѹ����	0��1����	������ǰ��ѹ��������
	int	MC_POWERWARN;	//��ر��� 	0��1����	����������������
	int MC_LBJWARN;		//�������� 0��1-5��Ӧ������Ϣ ����������Ӧ��Ϣ
	int	MC_AIRDISCHARGE;//��β�ŷ�״̬ȷ��0 ��1����  ����������ѹע��
	int MC_MALFUNCTION;	//���Ϻ���0��1����
	int	MC_SHOWorHIDE;	//�����ʾ���� 0 ���� 1��ʾ

	int MC_TOPBTN1;
	int MC_TOPBTN2;
	int MC_TOPBTN3;
	int MC_TOPBTN4;
	int MC_TOPBTN5;
	int MC_TOPBTN6;
	int MC_TOPBTN7;
	int MC_TOPBTN8;

	int MC_LEFTBTN_AIRDISCHARGE;	// ��Ϊ�ŷ�
	int MC_LEFTBTN_EMERGENCYCALL;	// ��������
	int MC_LEFTBTN_WARNING;			// ����
	int MC_LEFTBTN_MAINCONTROL;		// ����
	int MC_LEFTBTN_RESET;			// ��λ

	int MC_MIDBTN_CANCELNUM;		// ��β����
	int MC_MIDBTN_CONFIRM;			// ��βȷ��
	int MC_MIDBTN_AIRPRESSCHECK;	// ��ѹ��ѯ
	int MC_MIDBTN_1;				// ����1
	int MC_MIDBTN_2;				// ����2
	int MC_MIDBTN_3;				// ����3
	int MC_MIDBTN_4;				// ����4
	int MC_MIDBTN_5;				// ����5
	int MC_MIDBTN_6;				// ����6
	int MC_MIDBTN_7;				// ����7
	int MC_MIDBTN_8;				// ����8
	int MC_MIDBTN_9;				// ����9
	int MC_MIDBTN_STAR;				// �ַ�*
	int MC_MIDBTN_0;				// ����0
	int MC_MIDBTN_HASH;				// �ַ�#

	int MC_RIGHTBTN_CALL;			// ����
	int MC_RIGHTBTN_SWITCH;			// �л�
	int MC_RIGHTBTN_HANGUP;			// �Ҷ�
	int MC_RIGHTBTN_SETTINGS;		// ����
	int MC_RIGHTBTN_UP;				// ���ϡ�
	int MC_RIGHTBTN_INTERFACE;		// ����
	int MC_RIGHTBTN_LEFT;			// �����
	int MC_RIGHTBTN_CONFIRM;		// ȷ��
	int MC_RIGHTBTN_RIGHT;			// ���ҡ�
	int MC_RIGHTBTN_SEARCH;		// ��ѯ
	int MC_RIGHTBTN_DOWN;			// ���¡�
	int MC_RIGHTBTN_BACKSPACE;		// �ظ�
	int MC_RIGHTBTN_PRINT;			// ��ӡ
	int MC_RIGHTBTN_SHUNTINGREQUEST;// ��������
	int MC_RIGHTBTN_EXIT;			// �Ƴ�
}DATASEND;

// ���յĸ�������
typedef struct _tagDATARECV
{
	int	CM_MASTER;		//����״̬ 0������ 1 ������
	int	CM_AIRCHECK;	//��ѹ��ѯ 0��	1��ѯ����
	int	CM_AIRDISCHARGE;//��β�ŷ� 0��	1��λȷ��
	int	CM_WARN;		//�������� 0��	1����
	int	CM_EMERCALL;	//�������а�ť0��	1����
}DATARECV;