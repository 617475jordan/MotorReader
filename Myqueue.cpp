#include "stdafx.h"
#include "Myqueue.h"
#include <opencv_all.h>

Myqueue::Myqueue(int queue_capacity)
{
	m_iQueueCapacity = queue_capacity;
	clear_queue();
	CircleQ = new int[queue_capacity];
}


Myqueue::~Myqueue()
{
}
void Myqueue::clear_queue()//清空队列
{
	q_head = q_tail = 0;
	m_iQueueLength = 0;
}
bool Myqueue::isQueueEmpty()const//判断队列是否为空
{
	return m_iQueueLength == 0 ? true : false;
}
int Myqueue::queue_length()const//得到队列长度
{
	return m_iQueueLength;
}
bool Myqueue::isQueueFull()const//判断队列是否为满
{
	return (m_iQueueCapacity == m_iQueueLength) ? true : false;
}

bool Myqueue::DeQueue()//出队
{
	if (isQueueEmpty())
		return false;
	else
	{
		q_head = (q_head++) % m_iQueueCapacity;//对队列的容量取余，体现环形队列的特点
		m_iQueueLength--;
		return true;
	}
}
bool Myqueue::InQueue(int element)//入队
{
	if (isQueueFull())
	{
		cout << "the queue is full,failed to insert a num" << endl;
		return false;
	}
	else
	{
		CircleQ[q_tail] = element;
		q_tail = (q_tail++) % m_iQueueCapacity;//从队尾入队
		m_iQueueLength++;
		return true;
	}
}
int   Myqueue::queue_traverse()//遍历队列
{
	int m_iTmpFlag = -1;

	if (isQueueEmpty() != true)
	{
		for (int i = q_head + m_iQueueLength - 3; i >= q_head + 1; i--)//注意q_head只是一个整数，i应该小于它与队长的和
		{
			int m_iTmpHighPositionValue = CircleQ[i%m_iQueueCapacity];
			int m_iTmpLowPositionValue = CircleQ[(i-1)%m_iQueueCapacity];
			//cout << CircleQ[i%m_iQueueCapacity] << " ";//仍是对容量取余

			if (m_iTmpHighPositionValue == 187 && m_iTmpLowPositionValue == 170)
			{
				m_iTmpFlag = i;
				int m_iLowPositionValue = CircleQ[i%m_iQueueCapacity + 1];
				int m_iHighPositionValue = CircleQ[i%m_iQueueCapacity + 2];
				if (m_iLowPositionValue == 1)
				{
					m_iHighPositionValue = m_iHighPositionValue + 256;
				}
				break;
			}
		}
		if (m_iTmpFlag > 0)
		{
			for (int i = 0; i < q_head + m_iQueueLength - 3 - m_iTmpFlag; i++)
			{
				DeQueue();
			}
		}
	}
	return 0;
}

