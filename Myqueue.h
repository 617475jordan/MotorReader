#pragma once
class Myqueue
{
public:
	Myqueue(int queue_capacity);
	~Myqueue();
	bool                                isQueueEmpty()const;//判断队列是否为空
	bool                                isQueueFull()const;//判断队列是否为满
	void                                clear_queue();//清空队列
	int                                 queue_length()const;//得到队列长度
	bool                                InQueue(int  element);//入队
	bool                                DeQueue();//出队
	int                                 queue_traverse();//遍历队列
private:
	int                                 m_iQueueCapacity;//队列的容量
	int                                 m_iQueueLength;//队列的实际长度
	int                                *CircleQ;//为队列申请的数组
	int                                 q_head;//队列头，这里为方便起见只设置为一个整数
	int                                 q_tail;//队列尾
};

