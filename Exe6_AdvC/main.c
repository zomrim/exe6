#include <stdio.h>

int pack4Chars2Int(char c1, char c2, char c3, char c4);
int checkEvenParity(short input);

void main(){
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	int num_a = pack4Chars2Int(a, b, c, d);
	short num_b = 24;
	num_a = checkEvenParity(num_b);
	printf("%d", num_a);
}

int pack4Chars2Int(char c1, char c2, char c3, char c4)
{
	int tmp1, tmp2;
	tmp1 = c2<<8;
	tmp1 |= c1;
	tmp2 = c4<<8;
	tmp2 |= c3;
	tmp1 |= tmp2 << 16;
	return tmp1;
}

int checkEvenParity(short input)
{
	int counter = 0;
	unsigned short mask = 1;
	for (int i = 0; i < 16; i++, mask <<= 1)
	{
		if (input & mask)
			counter += 1;
	}
	if (!(counter % 2))
		return 1;
	else return 0;
}
