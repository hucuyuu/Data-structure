#include <stdio.h>
#include <string.h>
#define MaxStrSize    256
typedef struct {
	char	ch[MaxStrSize];
	int	length;
} SeqString;

int next[MaxStrSize]; // next[]
int sum_pattern;
int sum_kmp;

int Index(SeqString s, SeqString t)
// pattern matching
{
	int i, j;

	for (i = 1, j = 1; i <= s.length && j <= t.length;)
	{
		sum_pattern++;
		if (s.ch[i-1] == t.ch[j-1]) {
			i++, j++;
		}else{
			i = i-j+2;
			j = 1;
		}
	}
	if (j > t.length) {
		return (i-t.length); // bE
	}else{
		return (0);
	}
}


int Index_kmp(SeqString s, SeqString t)
// kmp
{
	int i = 1, j = 1;

	while (i <= s.length && j <= t.length)
	{
		sum_kmp++;
		if ((j == 0) || (s.ch[i-1] == t.ch[j-1])) {
			++i, ++j;
		}else{
			j = next[j];
		}
	}
	if (j > t.length) {
		return (i-t.length);
	}else {
		return (0);
	}
}


void get_next(SeqString t)
{
	int i = 1, j = 0;

	next[1] = 0;

	while (i < t.length)
	{
		sum_kmp++;
		if ((j == 0) || (t.ch[i-1] == t.ch[j-1])) {
			/* code */
			++i;
			++j;
			next[i] = j;
		}else{
			j = next[j];
		}
	}
}


void out_string(SeqString *s)
{
	int i;

	for (i = 0; i < s->length; i++)
	{
		putchar(s->ch[i]);
	}
}


int main(int argc, char const *argv[])
{
	SeqString str_s, str_t;


	strcpy(str_s.ch, "acacbacbabca");
	str_s.length = 12;
	strcpy(str_t.ch, "acbab");
	str_t.length = 5;
	next[1] = 0;
	get_next(str_t);
	// for (int i = 1; i <= str_t.length; i++)
	// {
	// 	printf("%d ", next[i]);
	// }
	// printf("\n");
	printf("%d\n", Index(str_s, str_t));
	printf("sum_pattern:%d\n", sum_pattern);
	printf("%d\n", Index_kmp(str_s, str_t));
	printf("sum_kmp:%d\n", sum_kmp);
	return (0);
}
