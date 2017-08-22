#include "stdafx.h"
#include "MotorReader.h"

MotorReader::MotorReader()
{
}


MotorReader::~MotorReader()
{
}
bool MotorReader::initial(int m_iPort, int m_iBaudRate)
{
	return  m_asynCom.open(m_iPort, m_iBaudRate);
}
void MotorReader::runFrame()
{
	m_iMessageLength = 0;
	int  m_iCircleQueLen = 0;
	int nlen = m_asynCom.read((char*)m_ucharBuffer, m_iszBufferLen);
	while (nlen&&m_iCircleQueLen<m_iThresholdValue)
	{
		if (nlen > 4)
			m_iMessageLength = nlen;
		else if (nlen <= 4)
		{
			for (int i = 0; i < nlen; i++)
			{
				int m_iTmpValue = (int)m_ucharBuffer[i];
				m_pCircleQue->InQueue(m_iTmpValue);
				/**********测试代码*******************/
				//m_pCircleQue->InQueue(170);
				//m_pCircleQue->InQueue(187);  

			}
		}
		//nlen = 4;  测试用
		nlen = m_asynCom.read((char*)m_ucharBuffer, m_iszBufferLen);
		m_iCircleQueLen = m_pCircleQue->queue_length();
	}

	/***************是否需要对队列里面进行判断****************************/
	if (m_iCircleQueLen >= m_iThresholdValue)
	{
		m_pCircleQue->queue_traverse();
	}

	else if (m_iCircleQueLen <= m_iCircleQueLen)
	{
		for (int i = m_iMessageLength - 3; i >= 1; i--)
		{
			int m_iTmpHighPositionValue = (int)m_ucharBuffer[i];
			int m_iTmpLowPositionValue = (int)m_ucharBuffer[i - 1];

			if (m_iTmpHighPositionValue == 187 && m_iTmpLowPositionValue == 170)
			{
				m_iLowPositionValue = (int)m_ucharBuffer[i + 1];
				m_iHighPositionValue = (int)m_ucharBuffer[i + 2];
				if (m_iLowPositionValue == 1)
				{
					m_iHighPositionValue = m_iHighPositionValue + 256;
				}
				cout << "m_iLowPositionValue:" << m_iLowPositionValue << " " << "m_iHighPositionValue:" << m_iHighPositionValue << endl;
				break;
			}
		}
	}
}

bool    MotorReader::end()
{
	if (m_pCircleQue!=NULL)
	    delete m_pCircleQue;
	m_pCircleQue = NULL;
	return true;
}

