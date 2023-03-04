
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "seqlist.h"

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	unsigned int *node; //unsigned int array[capacity]
}TSeqList;


SeqList* SeqList_Create_01(int capacity)
{
	TSeqList *ret = NULL;
	if (capacity < 0)
	{
		return NULL;
	}
	ret = (TSeqList *)malloc(sizeof(TSeqList));
	if (ret == NULL)
	{
		return NULL;
	}
	memset(ret, 0, sizeof(sizeof(TSeqList)));
	ret->node = (unsigned int *)malloc(sizeof(unsigned int )*capacity);
	if (ret ->node == NULL)
	{
		return NULL;
	}
	memset(ret->node, 0, sizeof(unsigned int )*capacity);
	ret->capacity = capacity;
	ret->length = 0;
	return ret;
}

SeqList* SeqList_Create(int capacity)
{
	TSeqList *ret = NULL;
	if (capacity < 0)
	{
		return NULL;
	}
	ret = (TSeqList *)malloc(sizeof(TSeqList) + sizeof(unsigned int )*capacity );
	if (ret == NULL)
	{
		return NULL;
	}
	memset(ret, 0, sizeof(sizeof(TSeqList)) + sizeof(unsigned int )*capacity );
	ret->node = (unsigned int *)(ret +1); //ret�����sizeof��TSeqList��
	ret->capacity = capacity;
	ret->length = 0;
	return ret;
}

void SeqList_Destroy(SeqList* list)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}

//�������� ����������Ϊ��
void SeqList_Clear(SeqList* list)
{
	TSeqList *tList = NULL; 
	if (list == NULL)
	{
		return ;
	}
	tList  = (TSeqList *)list;
	tList->length = 0;
	return ;
}

int SeqList_Length(SeqList* list)
{
	TSeqList *tList = NULL; 
	if (list == NULL)
	{
		return ;
	}
	
	return tList->length;
}

//���Ա�����������Ա����ǲ�һ����
int SeqList_Capacity(SeqList* list)
{
	TSeqList *tList = NULL; 
	if (list == NULL)
	{
		return ;
	}

	return tList->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i = 0;
	TSeqList *tList = NULL; 
	tList  = (TSeqList *)list;

	if (list == NULL || node == NULL) 
	{
		return -1;
	}

	//λ�ô����ж�
	if (pos<0 || pos>=tList->capacity)
	{
		return -1;
	}

	//�Ż����ݴ�����
	if (pos >=tList->length)
	{
		pos = tList->length;
	}

	//�����㷨
	//��posλ�ô���ʼ������������Ԫ�����˺���
	for(i=tList->length; i>pos; i--)
	{
		//��ǰ��Ԫ��������
		tList->node[i] = tList->node[i-1];
	}
	//ѭ�������Ժ�pos�����ǣ�Ҫ�����λ��
	tList->node[pos] = (unsigned int)node;
	tList->length ++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	return 0;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	return NULL;
}