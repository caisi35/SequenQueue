/*
    **                                                                  **
    **               作者：黄彩思                                       **
    **               班级：大数据171                                    **
    **               系统名称：医院看病候诊系统2.0                      **
    **               版本信息：5.0                                      **
    **               开发时间：2019-03-22                               **
    **
*/



#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

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


void main()                                                           //main function
{
    void menu();                                                       //menu function
    void ESQ(SequenQueue * Q, int i);                                  //入队函数
    void DSQ(SequenQueue * Q, int * i);                                 //出队函数
    void SQ_L(SequenQueue * Q);                                           //队列长度

    struct SequenQueue *Q=Init_SequenQueue();                            //create queue.initiation queue
    struct SequenQueue *Q2=Init_SequenQueue();                          //create queue2.initiation queue2.

    elemtype z=1;                                                       //设置系统无限循环成立条件
    elemtype ye=0;                                                      //系统菜单的选择
    elemtype j=1;                                                       //入队元素
    elemtype k=0;                                                       //出对元素
    elemtype l=0;                                                       //选择挂号的优先级判断

    while(z)
    {
        menu();
        scanf("%d",&ye);
        switch(ye)
        {
            case 1:
                printf("请输入您挂号的优先级1-2（按任意取消）:");
                scanf("%d",&l);
                if(l==1)
                {
                    Enter_SequenQueue(Q,j);
                    j=j+1;
                    printf("您当前排在优先级为1的第%d位。\n",SequenQueue_Length(Q));
                    printf("当前排队的人数为%d人，其中：\n优先级1的：%d人\n优先级2的：%d人\n\n",SequenQueue_Length(Q)+SequenQueue_Length(Q2),SequenQueue_Length(Q),SequenQueue_Length(Q2));
                }
                else if(l==2)
                {
                    Enter_SequenQueue(Q2,j);
                    j=j+1;
                    printf("您当前排在优先级为2的第%d位。\n",SequenQueue_Length(Q2));
                    printf("当前排队的人数为%d人，其中：\n优先级1的：%d人\n优先级2的：%d人\n\n",SequenQueue_Length(Q)+SequenQueue_Length(Q2),SequenQueue_Length(Q),SequenQueue_Length(Q2));
                }
                else break;
                break;                                                                                  //in queue function
            case 2:
                if(SequenQueue_Empty(Q)&&SequenQueue_Empty(Q2))                                        //判断是否有人排队
                    {
                        printf("当前无人排队\n\n");
                    }
                else if(SequenQueue_Empty(Q2))
                {
                    GetFront_SequenQueue(Q,&k);
                    printf("现需要诊断的是优先级为1的：%d号\n\n",k);
                    Delete_SequenQueue(Q,&k);
                }
                else
                {
                    GetFront_SequenQueue(Q2,&k);
                    printf("现需要诊断的是优先级为2的：%d号\n\n",k);
                    Delete_SequenQueue(Q2,&k);
                }
                break;
            case 3:
                printf("当前排队的人数为%d人，其中：\n优先级1的：%d人\n优先级2的：%d人\n\n",SequenQueue_Length(Q)+SequenQueue_Length(Q2),SequenQueue_Length(Q),SequenQueue_Length(Q2));
                break;
            case 4:
                z=0;
                printf("\n*********** see you again! ***********\n\n");
                break;
            default :
                printf("your input error!Please re-enter.\n");
        }
        if(SequenQueue_Empty(Q)&&SequenQueue_Empty(Q2))                                        //判断是否有人排队，若无人则清空已诊断出队了的人数
            {
                j=1;
                k=0;
            }
    }
}

void menu()                                                                                         //menu function
{
    printf("*************************************************************\n");
    printf("**********************   1.排队挂号   ***********************\n");
    printf("**********************   2.医生就诊   ***********************\n");
    printf("**********************   3.当前人数   ***********************\n");
    printf("**********************   4.退出系统   ***********************\n");
    printf("*************************************************************\n");
    printf("Please enter your choice:");
}
