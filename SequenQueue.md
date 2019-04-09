# -
用C语音及数组队列实现有优先级的排队系统

typedef int elemtype;
typedef struct SequenQueue		                                    //顺序队列的类型定义
{
	elemtype data[MAXSIZE];
	int front;
	int rear;
}SequenQueue;

SequenQueue * Init_SequenQueue()	                                //初始化队列
{
	SequenQueue * Q;
	Q=(SequenQueue *)malloc(sizeof(SequenQueue));
	if(Q!=NULL)
	{
		Q->front=0;
		Q->rear=0;
	}
	return Q;
}

int SequenQueue_Empty(SequenQueue * Q)	                            //队列判空
{
	if(Q->front==Q->rear)	return 1;
	else			return 0;
}

int SequenQueue_Full(SequenQueue * Q)	                            //队列判满
{
	if((Q->rear+1)%MAXSIZE==Q->front)	return 1;
	else				return 0;
}

int SequenQueue_Length(SequenQueue * Q)	                            //队列长度
{
	return((Q->rear-Q->front+MAXSIZE)%MAXSIZE);
}

int Enter_SequenQueue(SequenQueue * Q,elemtype x)                   	//入队
{
	if(SequenQueue_Full(Q))	return 0;
	Q->data[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return 1;
}

int Delete_SequenQueue(SequenQueue * Q,elemtype * x)	                //出队
{
	if(Q->front==Q->rear)	return 0;
	else
	{
		*x=Q->data[Q->front];
		Q->front=(Q->front+1)%MAXSIZE;
		return 1;
	}
}

int GetFront_SequenQueue(SequenQueue * Q,elemtype *x)                       	//取队头元素
{
	if(Q->front==Q->rear)	return 0;
	else
	{
	    *x=Q->data[Q->front];
		return 1;
	}
}
