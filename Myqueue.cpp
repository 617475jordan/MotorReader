#include "stdafx.h"
#include "Myqueue.h"
#include <opencv_all.h>

Myqueue::Myqueue(int queue_capacity)
{
	m_iQueueCapacity = queue_capacity;
	clear_queue();
	m_pCircleQ = new int[queue_capacity];
}


Myqueue::~Myqueue()
{
}
void Myqueue::clear_queue()//��ն���
{
	m_iHead = m_iTail = 0;
	m_iQueueLength = 0;
}
bool Myqueue::isQueueEmpty()const//�ж϶����Ƿ�Ϊ��
{
	return m_iQueueLength == 0 ? true : false;
}
int Myqueue::queue_length()const//�õ����г���
{
	return m_iQueueLength;
}
bool Myqueue::isQueueFull()const//�ж϶����Ƿ�Ϊ��
{
	return (m_iQueueCapacity == m_iQueueLength) ? true : false;
}

bool Myqueue::DeQueue()//����
{
	if (isQueueEmpty())
		return false;
	else
	{
		m_iHead = (m_iHead++) % m_iQueueCapacity;//�Զ��е�����ȡ�࣬���ֻ��ζ��е��ص�
		m_iQueueLength--;
		return true;
	}
}
bool Myqueue::InQueue(int element)//���
{
	if (isQueueFull())
	{
		cout << "the queue is full,failed to insert a num" << endl;
		return false;
	}
	else
	{
		m_pCircleQ[m_iTail] = element;
		m_iTail = (m_iTail++) % m_iQueueCapacity;//�Ӷ�β���
		m_iQueueLength++;
		return true;
	}
}
int   Myqueue::queue_traverse()//��������
{
	int m_iTmpFlag = -1;

	if (isQueueEmpty() != true)
	{
		for (int i = m_iHead + m_iQueueLength - 3; i >= m_iHead + 1; i--)//ע��q_headֻ��һ��������iӦ��С������ӳ��ĺ�
		{
			int m_iTmpHighPositionValue = m_pCircleQ[i%m_iQueueCapacity];
			int m_iTmpLowPositionValue = m_pCircleQ[(i-1)%m_iQueueCapacity];
			//cout << CircleQ[i%m_iQueueCapacity] << " ";//���Ƕ�����ȡ��

			if (m_iTmpHighPositionValue == 187 && m_iTmpLowPositionValue == 170)
			{
				m_iTmpFlag = i;
				int m_iLowPositionValue = m_pCircleQ[i%m_iQueueCapacity + 1];
				int m_iHighPositionValue = m_pCircleQ[i%m_iQueueCapacity + 2];
				if (m_iLowPositionValue == 1)
				{
					m_iHighPositionValue = m_iHighPositionValue + 256;
				}
				break;
			}
		}
		if (m_iTmpFlag > 0)
		{
			for (int i = 0; i < m_iHead + m_iQueueLength - 3 - m_iTmpFlag; i++)
			{
				DeQueue();
			}
		}
	}
	return 0;
}

