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