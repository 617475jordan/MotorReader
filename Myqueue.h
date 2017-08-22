#pragma once
class Myqueue
{
public:
	Myqueue(int queue_capacity);
	~Myqueue();
	bool                                isQueueEmpty()const;//�ж϶����Ƿ�Ϊ��
	bool                                isQueueFull()const;//�ж϶����Ƿ�Ϊ��
	void                                clear_queue();//��ն���
	int                                 queue_length()const;//�õ����г���
	bool                                InQueue(int  element);//���
	bool                                DeQueue();//����
	int                                 queue_traverse();//��������
private:
	int                                 m_iQueueCapacity;//���е�����
	int                                 m_iQueueLength;//���е�ʵ�ʳ���
	int                                *CircleQ;//Ϊ�������������
	int                                 q_head;//����ͷ������Ϊ�������ֻ����Ϊһ������
	int                                 q_tail;//����β
};

