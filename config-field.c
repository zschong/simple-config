#include <string.h>
#include "config-field.h"


int get_fieldn(const char* src, const int n, char *buf, const int len)
{
	if( src && buf && len > 0 )
	{
		int i = 0;
		int esc = 1;
		const char *beg = src;
		const char *end = src + strlen(src) - 1;
		while( beg != end )
		{
			if( esc == n )
			{
				break;
			}
			if( ':' == *beg++ )
			{
				esc++;
			}
		}
		if( n != esc )
		{
			return 0;
		}
		for(i = 0; i < len; i++)
		{
			if( *beg == 0 )
			{
				buf[i] = 0;
				return i;
			}
			if( *beg == ':' )
			{
				buf[i] = 0;
				return i;
			}
			buf[i] = *beg++;
		}
		buf[len-1] = 0;
		return len;
	}
	return -1;
}
