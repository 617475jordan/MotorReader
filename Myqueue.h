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
	int                                 *m_pCircleQ;//Ϊ�������������
	int                                 m_iHead;//����ͷ������Ϊ�������ֻ����Ϊһ������
	int                                 m_iTail;//����β
};

