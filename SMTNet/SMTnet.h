//SMTnet.h : 头文件


#pragma once


#ifndef _SMTNET_H
#define _SMTNET_H


//导入网络通信动态链接库引入库文件
#pragma comment (lib, "SMTNet/SMTnet.lib")


/*
**SMTNet API
**函数说明:
**InitSmtNet ->读取配置文件config.dat.根据配置文件中定义的端口和IP地址进行socket的初始化工作。
**			 ->$uDelay   :延时时间
**			 ->$dwUser	 :父窗口句柄
**			 ->说明：该函数需要在工程的初始化函数中调用一次。
**				调用该函数会默认启动一个精准定时器，定时器id为999
**SMTSendPtr ->返回实际发送的数据包 返回值为-1 说明该函数调用失败。
**			 ->$nTargetID:目标机的标识
**			 ->$outBuff  :输出缓冲区内容，任意数据类型
**			 ->$outSize	 :输出缓冲区大小。
**			 ->说明		 :该函数把指定数据发送到目标计算机上,数据类型没有限制，需要在循环中每周期调用。
**SMTRecvPtr ->同上	
**UnSmtNet() ->关闭打开的套接字，释放申请的内存资源，关闭定时器，一般在程序退出端调用。
*/


extern "C" __declspec(dllexport)  int InitSmtNet(int uDelay, void* dwUser =0);		//初始化网络数据通信函数
extern "C" __declspec(dllexport)  void UnSmtNet();		//结束网络数据通信函数
extern "C" __declspec(dllexport)  int SMTSendPtr(int nTargetID, char* outBuff, int outSize);		//发送网络数据函数
extern "C" __declspec(dllexport)  int SMTRecvPtr(int nTargetID, char* inBuff, int inSize);		//接收网络数据函数


#endif
