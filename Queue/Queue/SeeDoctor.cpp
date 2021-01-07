#include <stdio.h>
#include <stdlib.h>
#include "seqqueue.h"

void SeeDoctor()
{
	SeqQueue Q; 
	int flag, n;
	char command;

	InitQueue(&Q);

	flag = 1;
	while (flag)
	{
		printf("\nPlease enter the command: ");
		scanf_s("%c", &command);
		getchar();

		switch (command)
		{
			case 'a':
				printf("\nMedical record number: ");
				scanf_s("%d", &n);
				getchar();
				EnterQueue(&Q, n);
				break;
			case 'n':
				if (!(Q.front == Q.rear))
				{
					DeleteQueue(&Q, &n);
					printf("\nPatient number %d, please see your doctor. ",n);
				}
				else
					printf("\nNo patient is waiting.");
				break;
			case 'q':
				printf("\nStop registering today. The following patients are seen in turn: \n");
				while (!(Q.front == Q.rear))
				{
					DeleteQueue(&Q, &n);
					printf("%d ", n);
				}
				flag = 0;
				break;
			default:
				printf("\nInvalid command!");
		}
	}
}