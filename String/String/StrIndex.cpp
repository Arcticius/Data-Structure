#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"


/*算法思想：
串的简单模式匹配Brute-Force算法：
从主串S的第pos个字符开始，和模式串T的第一个字符开始比较.
若相等，则继续比较后续字符. 
若不相等，则回溯至主串S的第pos+1个字符，随后重新与模式串T比较，直到全部匹配为止.
实现时设置i、j、start三个指示器.
·	i指向主串S中当前比较的字符，起始指向S的首字符，此后每比较一步，后移一个位置，
一趟匹配失败时，回溯至该趟比较起点的下一位置.
·	j指向子串T中当前比较的字符，起始指向T的首字符，此后每比较一步，后移一个位置，
一趟匹配失败时，回溯至T的首字符处.
·	start记录每趟比较时在主串S中的起点，每趟比较后，后移一个位置以确认下一位置.
*/
int StrIndex(SString s, int pos, SString t)
{
	int i, j, start;

	if (t.len == 0) //模式串为空串时，是任意串的匹配串
		return 0;

	start = pos; i = start; j = 0; //主串从pos开始，模式串从0开始
	while (i < s.len && j < t.len)
		if (s.ch[i] == t.ch[j]) //当前对应字符相等时推进
		{
			i++;
			j++;
		}
		else	//当前对应字符不等时回溯
		{
			start++;
			i = start; //主串从start+1开始
			j = 0; //模式串从0开始
		}

	if (j >= t.len) //匹配成功时，返回匹配起始位置
		return start;
	else //匹配失败时，返回-1
		return -1;
}