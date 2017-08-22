#pragma once
#include <CommonUtil.h>
#include "Myqueue.h"
class MotorReader
{
public:
	MotorReader();
	~MotorReader();
	bool                            initial(int nPort, int nBaudRate);
	void                            runFrame();
	int		                        getCurrentPosition();
	bool                            end();
private:
	_asyn_com                       m_asynCom;            /*“Ï≤ΩÕ®–≈*/
	int                             m_iMessageLength;
	int                             m_iLowPositionValue, m_iHighPositionValue;
	int                             m_iThresholdValue = 20;
#define                             m_iszBufferLen  1024
	unsigned char                   m_ucharBuffer[m_iszBufferLen];
#define                             m_iQueueCapacity  20
	Myqueue                         *m_pCircleQue = new Myqueue(m_iQueueCapacity);
};

