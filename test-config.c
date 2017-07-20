#include "config-file.h"
#include "config-field.h"

void show_fields(const char *s, int n);


int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char *file = "config";

	if( argc > 1 )
	{
		file = argv[1];
	}
	fp = config_open(file);
	while(1)
	{
		char buf[32] = {0};
		if( config_readline(fp, buf, sizeof(buf)) < 1 )
		{
			break;
		}
		show_fields(buf, 9);
	}
	return 0;
}
void show_fields(const char *s, int n)
{
	int i = 1;
	char buf[32] = {0};

	for(i = 1; i <= n; i++)
	{
		if( get_fieldn(s, i, buf, sizeof(buf)) > 0 )
		{
			printf("%s ", buf);
		}
	}
	printf("\n");
}
