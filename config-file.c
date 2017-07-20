#include <sys/stat.h>
#include <fcntl.h>
#include "config-file.h"


FILE* config_open(const char *filename)
{
	if( filename )
	{
		return fopen(filename, "r+");
	}
	return NULL;
}

int config_readline(FILE *fp, char *buf, int len)
{
	int datalen = 0;
	int oldpos = 0;
	int readlen = 0;
	int lineoff = 0;

	if( NULL == fp || NULL == buf )
	{
		return -1;
	}
	oldpos = ftell(fp);
	while( datalen < len )
	{
		char c = 0;
		const int ret = fread(&c, 1, 1, fp);
		if( ret != 1 )
		{
			return ret;
		}
		readlen++;
		if( isalpha(c) )
		{
			buf[datalen++] = c;
		}
		else if( isdigit(c) )
		{
			buf[datalen++] = c;
		}
		else
		{
			switch( c )
			{
				case ':':
				case '.':
				case '-':
				case '_':
					buf[datalen++] = c;
					break;
			}
		}

		if( '\n' == c || '\r' == c )
		{
			if( datalen > 0 )
			{
				lineoff = 1;
				break;
			}
		}
	}//while()
	if( lineoff )
	{
		buf[datalen] = 0;
		return readlen;
	}
	//buf size is too small to place a line 
	if( readlen > 0 )
	{
		fseek(fp, readlen, SEEK_SET);
	}
	return readlen;
}
int config_writeline(FILE *fp, const char *data, int len)
{
	int i = 0;

	if( NULL == fp || NULL == data || len < 1 )
	{
		return -1;
	}
	for(i = 0; i < len; i++)
	{
		if( isalpha( data[i] ) )
		{
			continue;
		}
		if( isdigit( data[i] ) )
		{
			continue;
		}
		switch( data[i] )
		{
			case ':':
			case '\n':
			case '\r':
			case '\t':
			case '.':
			case ' ':
				continue;
		}
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	return fwrite(data, len, 1, fp);
}
int config_close(FILE *fp)
{
	fflush(fp);
	return fclose(fp);
}
