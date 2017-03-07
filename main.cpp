#include "basic.h"
#include "ai.h"

int main()
{
    srand((unsigned)time(NULL));
    int i, n, mode, playerScore1, index = 0, playerScore2, choose, valid, 
	meWins = 0, player2Wins1 = 0,player2Wins2 = 0, player1Wins = 0,rest1,
	rest2,prev_value,enter,flag;
    char suit;
    Card cards[52];
    Card player1[5];
    int available1[5];
    Card player2[5];
    int available2[5];
    Card card;  
	Card preCard; 
	  
	
    while(1)
    { 
        newGame(cards);
        card.value = -1;
        playerScore1 = 0;
        playerScore2 = 0;

        // ��¼����λ��
        index = 0;
        //���ƻس��� 
        enter = 7;
        rest1 = 5;
        rest2 = 5;
    	clearScr(index);
    	printf("\t\t\t\t  ��ѡ����Ϸ�˵�\n\n\n");
    	printf("\t\t\t\t   1���˻���ս\n\n");
    	printf("\t\t\t\t   2��������ս\n\n"); 
    	printf("\t\t\t\t   3����Ϸ����\n\n"); 
    	printf("\t\t\t\t   4���˳���Ϸ\n\n\n"); 
		printf("(������1/2/3/4):"); 
		scanf("%d",&mode);
		
		if(mode == 4) break;
		
		if(mode != 1 && mode != 2 && mode != 3 && mode != 4) continue;
		
        for(i = 0; i < 5; i++)
        {
            player1[i] = cards[index++];
            player2[i] = cards[index++];
        }
        
    	clearScr(index);

        while((index < 52 || rest1 !=0 || rest2 !=0)  && mode != 3)
        {
            if(mode == 1)
            {
                // �˻���ս
                n = availableCards(card, player1, available1,rest1);
                valid = 0;
                if(n > 0)
                {
                    // �û�ѡ��һ���ƴ��
                    while(!valid)
                    {
                    	flag = 0;
                    	for(i = 0;i < enter;i++) printf("\n");
            			printCards(player1, rest1, "��������");
                        printf("��ѡ��һ���ƴ�������������,��ǰ�ɳ�  ");
                        for(i = 0; i < n; i++)
                        {
                        	if(i != n - 1) printf("%d/",available1[i] + 1);
                        	else printf("%d",available1[i] + 1);
                        }
                        printf(",ѡ������Ϊ���ƣ���");
                        scanf("%d", &choose);
                        choose -= 1;
                        enter = 7;
                        // ����������Ƿ��ںϷ�������
                        for(i = 0; i < n; i++)
                        {
                            if(choose == available1[i])
                            {
                            	flag = 1;
                                valid = 1;
                                prev_value = card.value;
                                card = player1[choose];
                                preCard = card;
                                removeCard(player1, choose);
                                if(index < 52)
                                {
                                	player1[4] = cards[index++];	
                                }
								else rest1--;
								if(index < 52) clearScr(index + 1);
                                else clearScr(index);
                                if(card.value == 11 || prev_value == card.value)
                                {
                                    while(1)
                                    {
                                    	clearScr(index - 1);
                                    	enter = 7;
    									for(i = 0;i < enter;i++) printf("\n");
    									printCards(player1, rest1, "��������");
                                        printf("������ı�Ļ�ɫ:1.���� 2.÷�� 3.���� 4.����:");
                                        scanf("%d", &choose);
                                    	if(index < 52) clearScr(index + 1);
                                		else clearScr(index);
                                        choose -=1; 
                                        if(0 <= choose && choose <= 3)
                                        {
                                            if(choose == 0)
                                            {
                                                suit = 'd';
                                            }
                                            else if(choose == 1)
                                            {
                                                suit = 'c';
                                            }
                                            else if(choose == 2)
                                            {
                                                suit = 'h';
                                            }
                                            else if(choose == 3)
                                            {
                                                suit = 's';
                                            }

                                            break;
                                        }
                                        else continue;
                                    }
									card.suit = suit;
									
									printf("������ɫ�ı�Ϊ ");
									cardColor(card);
									enter--;
									printf("\n");
								}
								printf("�������");
                                printCard(preCard);
    							printf("\n");
    							enter--;
                                break;
                            }
                        }
                    	if(flag == 0)
                    	{
                    		preCard = player1[choose];
                        	if(0 <= choose && choose < rest1)
                        	{
                            	valid = 1;
                            	// �ӷ�
                            	playerScore2 += cardScore(player1[choose]);
                            	removeCard(player1, choose);
 								if(index < 52)
                            	{
                                	player1[4] = cards[index++];	
                            	}
								else rest1--;
								enter = 7;
                            	if(index < 52) clearScr(index + 1);
                            	else clearScr(index);
                            	printf("��������");
                            	printCard(preCard);
    							printf("\n");
                            	enter--;
                        	}
                        	else
                        	{
                        		clearScr(index);
                    			printf("���Ʋ��ɳ��������³���!\n");
                        		enter--;
                        	}
                    	}
                    }
                }
                else
                {
                    // ѡ��һ���ƶ���
                    while(!valid)
                    {
                    	for(i = 0;i < enter;i++) printf("\n");
            			printCards(player1, rest1, "��������");
                        printf("��ѡ��һ���ƶ�����");
                        scanf("%d", &choose);
                        choose -= 1;
                        preCard = player1[choose];
                        if(0 <= choose && choose < rest1)
                        {
                            valid = 1;
                            // �ӷ�
                            playerScore2 += cardScore(player1[choose]);
                            removeCard(player1, choose);
 							if(index < 52)
                            {
                                player1[4] = cards[index++];	
                            }
							else rest1--;
							enter = 7;
                            if(index < 52) clearScr(index + 1);
                            else clearScr(index);
                            printf("��������");
                            printCard(preCard);
    						printf("\n");
                            enter--;
                        }
                        else
                        {
                        	enter = 7;
                        	clearScr(index);
                        	printf("���Ʋ����ڣ������¶�����\n");
                        	enter--;
						}
					}
				}
            }
            else if(mode == 2)
            {
            	for(i = 0;i < enter;i++) printf("\n");
            	printCards(player1, rest1, "��������");
            	Sleep(2000);
                n = availableCards(card, player1, available1,rest1);
				if(index < 52) clearScr(index + 2);
                else clearScr(index);
				enter = 7; 
				
                if(n > 0)
                {
                    choose = rand() % n;
					prev_value = card.value;
                    card = player1[available1[choose]];
                    preCard = card;
					removeCard(player1, available1[choose]);
 					if(index < 52)
                    {
                        player1[4] = cards[index++];	
                    }
					else rest1--;
					printf("�������: ");
					printCard(preCard);
    				printf("\n");
    				enter--;
                    if(card.value == 11 || prev_value == card.value)
                    {
                        card.suit = getBestSuit(player1);
						printf("��������ɫ��Ϊ ");
						cardColor(card);
						printf("\n");
						enter--;
					}
                }
                else
                {
                    choose = minScore(player1,rest1);
                    printf("����������");
                    playerScore2 += cardScore(player1[choose]);
                    preCard = player1[choose];
 					if(index < 52)
                    {
                        player1[4] = cards[index++];	
                    }
					else rest1--;
                    printCard(preCard);
    				printf("\n");
    				enter--;
                }
                
            }

            // ����ѡ��
            n = availableCards(card, player2, available2,rest2);

            if(n > 0)
            {
                choose = rand() % n;
                printf("���Ĵ��: ");
				prev_value = card.value;
                card = player2[available2[choose]];
                preCard = card;
				removeCard(player2, available2[choose]);
 				if(index < 52)
                {
                    player2[4] = cards[index++];	
                }
				else rest2--;
				printCard(preCard);
    			printf("\n");
				enter--; 
                if(card.value == 11 || prev_value == card.value)
                {
                    card.suit = getBestSuit(player2);
					printf("���Ľ���ɫ��Ϊ ");
					cardColor(card);
					printf("\n"); 
					enter--;
                }

            }
            else
            {
                choose = minScore(player2,rest2);
                printf("���Ķ���: ");
                //�ӷ�
                playerScore1 += cardScore(player2[choose]);
                preCard = player2[choose];
                removeCard(player2, choose);
 				if(index < 52)
                {
                	player2[4] = cards[index++];	
                }
				else rest2--;
                printCard(preCard);
    			printf("\n");
                enter--;
            }
        }

		
		if(mode != 3)
		{
			clearScr(index);
			printf("\n\n��Ϸ���:\n\n");
        	if(mode == 1)
        	{
        		printf("���ĵ÷֣�%d\n\n", playerScore1);
        		printf("���ĵ÷�: %d\n\n", playerScore2);
        		if(playerScore1 > playerScore2)
        		{
            		printf("��ϲ�����������ʤ��  ^_^Y\n");
            		meWins++;
        		}
        		else if(playerScore2 > playerScore1)
        		{
            		printf("���ź���������˵���  T_T!\n");
            		player2Wins1++;
        		}
       	 	else
        		{
            		printf("���Ϊƽ��!     =_=\n");
        		}
        	}
        	else
			{
        		printf("�����÷֣�%d\n", playerScore1);
        		printf("���ĵ÷�: %d\n", playerScore2);	
				if(playerScore1 > playerScore2)
        		{
            		printf("������ʤ\n");
            		player1Wins++;
        		}
        		else if(playerScore2 > playerScore1)
        		{
            		printf("���Ļ�ʤ\n");
            		player2Wins2++;
        		}
       	 	else
        		{
            		printf("ƽ��\n");
        		}		
			} 

        	valid = 0;
        	while(!valid)
        	{
            	printf("\n\n\n\n1.������Ϸ 2.�˳���");
            	scanf("%d", &choose);
            	if(choose == 1 || choose == 2)
            	{
                	valid = 1;
            	}
        	}

        	// ѡ���˳�
        	if(choose == 2)
        	{
            	break;
        	}
    	}
		else
		{
			clearScr(index - 10);
			printf("\t\t\t\t��Ϸ�������£�\n\n");
			printf("[1] ʹ��һ���˿��ƣ���52���ƣ���Ҫ��С���� ��λ��ҡ�\n\n");
			printf("[2] ��Ϸ��ʼ����λ��ҽ�����һ���ƣ�ֱ��ÿλ������ж���4���ơ��˺����1��\n");
			printf("һ���ƣ�������5���ƣ�Ȼ�������ѡ��һ���ƴ�������2����һ���ƣ�������5���ƣ���\n");
			printf("����ѡ��һ���ƴ����һ������£�ÿλ����ڳ���ʱ������5���ơ�\n\n");
			printf("[3] ����ʱ���������ѡ�񣺲���ɫ����ɫ�ͷ�����\n\n");
			printf("[4] ��ɫ����ɫ��ָ���ҡ����ҡ�÷�������顣�������ƹ����ж������е�ǰ��ɫ������\n");
			printf("��Ϸ��ʼ���һ���ƵĻ�ɫ���ǵ�ǰ��ɫ�����û����ҽ��б�ɫ����ǰ��ɫ�����ֲ���\n\n");
			printf("[5] ����ɫ�����磬���1��һ�ź���3�����2��Ҫ����������Ҳ��һ�ź��ҵ��ƣ������\n");
			printf("��Q������һ������ǰ�Ļ�ɫ��Ȼ�Ǻ��ҡ�\n\n");
			printf("[6] ��ɫ�� ���磬���1��һ�ź���3�����2��Ҫ����������Ҳ��һ�ź��ҵ��ơ�������\n");
			printf("��2����û�к��ҵ��ƣ���/����������������������¿��Ա�ɫ��\n");
			printf("\t��a��������⻨ɫ��J��\n");
			printf("\t��b����Է��������һ����ͬ�����ֵ��ơ�\n\n");
			printf("[7] ������������2��û�к��ң�Ҳ�޷���ɫ�����������ѡһ���Ʒ���������ֵ��Ϊ��\n");
			printf("��1�ĵ÷֡����2�������ƶ����1���ɼ�����֮��Ȼ����Ϸ������ɹ���˫�������ơ�\n\n");
			printf("[8] �Ƶ���ֵ��2��10����ֵ�ֱ���2��10��Q��12�֣�K��0�֣�A��1�֡�J�Ǳ�ɫ�ơ�\n\n");
			printf("[9] ʤ��������52���ƶ��������겢���ꡣ���1�����Ƶ��ܷ�ֵ�����2������Ϸ�ĵ�\n");
			printf("�֣���֮��Ȼ���÷ֶ���ʤ��\n\n");
			printf("\n�����������");
     		COORD coord;
			coord.X=0;
			coord.Y=0;
    		HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
     		SetConsoleCursorPosition(hout,coord);
			while(!kbhit());  //��û�м����� 
			getch(); 
		}		
	}
	
	clearScr(index);
	
	if(meWins != 0 || player2Wins1 !=0 || player2Wins2 !=0 ||player1Wins !=0)
	{
   		printf("ս��ͳ��:\n\n\n");
    	if(meWins != 0 || player2Wins1 !=0)
    	{
        	printf("��ʤ������%d��\n", meWins);
    		printf("����Ӯ����%d��\n\n\n", player2Wins1);	
    	}
    	if(player2Wins2 !=0 ||player1Wins !=0)
    	{
        	printf("����Ӯ������%d��\n", player1Wins);
    		printf("����Ӯ������%d��\n", player2Wins2);	
    	}			
	}
	Sleep(5000);
    return 0;
}
