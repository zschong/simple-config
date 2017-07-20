#ifndef __CONFIG_FEILD_H__
#define __CONFIG_FEILD_H__

#define get_field1(src, buf, len)	get_fieldn(src, 1, buf, len)
#define get_field2(src, buf, len)	get_fieldn(src, 2, buf, len)
#define get_field3(src, buf, len)	get_fieldn(src, 3, buf, len)
#define get_field4(src, buf, len)	get_fieldn(src, 4, buf, len)
#define get_field5(src, buf, len)	get_fieldn(src, 5, buf, len)
#define get_field6(src, buf, len)	get_fieldn(src, 6, buf, len)
#define get_field7(src, buf, len)	get_fieldn(src, 7, buf, len)
#define get_field8(src, buf, len)	get_fieldn(src, 8, buf, len)
#define get_field9(src, buf, len)	get_fieldn(src, 9, buf, len)

int get_fieldn(const char* src, const int n, char *buf, const int len);

#endif//__CONFIG_FEILD_H__
