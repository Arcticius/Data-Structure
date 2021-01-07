#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"


/*�㷨˼�룺
���ļ�ģʽƥ��Brute-Force�㷨��
������S�ĵ�pos���ַ���ʼ����ģʽ��T�ĵ�һ���ַ���ʼ�Ƚ�.
����ȣ�������ȽϺ����ַ�. 
������ȣ������������S�ĵ�pos+1���ַ������������ģʽ��T�Ƚϣ�ֱ��ȫ��ƥ��Ϊֹ.
ʵ��ʱ����i��j��start����ָʾ��.
��	iָ������S�е�ǰ�Ƚϵ��ַ�����ʼָ��S�����ַ����˺�ÿ�Ƚ�һ��������һ��λ�ã�
һ��ƥ��ʧ��ʱ�����������˱Ƚ�������һλ��.
��	jָ���Ӵ�T�е�ǰ�Ƚϵ��ַ�����ʼָ��T�����ַ����˺�ÿ�Ƚ�һ��������һ��λ�ã�
һ��ƥ��ʧ��ʱ��������T�����ַ���.
��	start��¼ÿ�˱Ƚ�ʱ������S�е���㣬ÿ�˱ȽϺ󣬺���һ��λ����ȷ����һλ��.
*/
int StrIndex(SString s, int pos, SString t)
{
	int i, j, start;

	if (t.len == 0) //ģʽ��Ϊ�մ�ʱ�������⴮��ƥ�䴮
		return 0;

	start = pos; i = start; j = 0; //������pos��ʼ��ģʽ����0��ʼ
	while (i < s.len && j < t.len)
		if (s.ch[i] == t.ch[j]) //��ǰ��Ӧ�ַ����ʱ�ƽ�
		{
			i++;
			j++;
		}
		else	//��ǰ��Ӧ�ַ�����ʱ����
		{
			start++;
			i = start; //������start+1��ʼ
			j = 0; //ģʽ����0��ʼ
		}

	if (j >= t.len) //ƥ��ɹ�ʱ������ƥ����ʼλ��
		return start;
	else //ƥ��ʧ��ʱ������-1
		return -1;
}