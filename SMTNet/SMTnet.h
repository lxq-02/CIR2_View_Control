//SMTnet.h : ͷ�ļ�


#pragma once


#ifndef _SMTNET_H
#define _SMTNET_H


//��������ͨ�Ŷ�̬���ӿ�������ļ�
#pragma comment (lib, "SMTNet/SMTnet.lib")


/*
**SMTNet API
**����˵��:
**InitSmtNet ->��ȡ�����ļ�config.dat.���������ļ��ж���Ķ˿ں�IP��ַ����socket�ĳ�ʼ��������
**			 ->$uDelay   :��ʱʱ��
**			 ->$dwUser	 :�����ھ��
**			 ->˵�����ú�����Ҫ�ڹ��̵ĳ�ʼ�������е���һ�Ρ�
**				���øú�����Ĭ������һ����׼��ʱ������ʱ��idΪ999
**SMTSendPtr ->����ʵ�ʷ��͵����ݰ� ����ֵΪ-1 ˵���ú�������ʧ�ܡ�
**			 ->$nTargetID:Ŀ����ı�ʶ
**			 ->$outBuff  :������������ݣ�������������
**			 ->$outSize	 :�����������С��
**			 ->˵��		 :�ú�����ָ�����ݷ��͵�Ŀ��������,��������û�����ƣ���Ҫ��ѭ����ÿ���ڵ��á�
**SMTRecvPtr ->ͬ��	
**UnSmtNet() ->�رմ򿪵��׽��֣��ͷ�������ڴ���Դ���رն�ʱ����һ���ڳ����˳��˵��á�
*/


extern "C" __declspec(dllexport)  int InitSmtNet(int uDelay, void* dwUser =0);		//��ʼ����������ͨ�ź���
extern "C" __declspec(dllexport)  void UnSmtNet();		//������������ͨ�ź���
extern "C" __declspec(dllexport)  int SMTSendPtr(int nTargetID, char* outBuff, int outSize);		//�����������ݺ���
extern "C" __declspec(dllexport)  int SMTRecvPtr(int nTargetID, char* inBuff, int inSize);		//�����������ݺ���


#endif
