#ifndef _BASIC_H_
#define _BASIC_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 
#include <conio.h>


using namespace std;

typedef struct card
{
    int value;
    char suit;
} Card;

void cardColor(Card card);
void printCard(Card card);		//��ӡ������
void newGame(Card cards[]);		//���������� 
void printCards(Card cards[], int n, char *name);  //��ӡ����
int availableCards(Card card, Card playerCards[], int available[],int n); //��ǰ�ɴ���� 
int cardScore(Card card);		// �����ƶ�Ӧ�ķ�ֵ
void removeCard(Card cards[], int index);	//ɾ��һ����
void clearScr(int num);						//ʵʱ��ʾ���ڼ����� 



#endif
