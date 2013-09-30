#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *names1[] = {
	"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
	"yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

char *names2[] = {
	"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
	"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
	"eznab", "canac", "ahau"
};

int main(void)
{
	int i,j,num;
	int day, year;
	int epoch;
	char mon[1024];
	int mon2;

	scanf("%d", &num);
	printf("%d\n", num);

	for(i=0; i<num; i++) {
		scanf("%d. %s %d", &day, mon, &year);
		mon2=-1;
		for(j=0; j<19; j++) {
			if (!strcmp(mon, names1[j])) {
				mon2=j;
				break;
			}
		}
		if (mon2==-1) {
			abort();
		}
		epoch = year*365 + 20*mon2 + day;
		printf("%d %s %d\n", ((epoch%260)%13)+1, names2[(epoch%260)%20], epoch/260);
	}
	return 0;
}
