#include <stdio.h>

int main(int argc, char **argv)
{
	// http://baike.baidu.com/link?url=6O9ui_is89veW7pifmxreEe2plOwqB-z68LLiAACKvR6Zu-Yx8KRqt_27fkoTjjO
	/* -2
	*  10010
	*  11101
	*  11110
	*/
	// refer to http://wenku.baidu.com/link?url=MpQaNOmuy5rrK6uu9MvvN6aVL1HjjJsZt1HVoihc9UZlUhaxsbD3Bep2jKdeSFizI6EzVppQwGbw6LpqDWjVoNPKdTbya7xUcZWM0qLj3wK
	printf("%s enter.\n", __func__);
	//%m.nd
	printf("%3d,%8d,%8.6d\n", 1250, 1250, 1250);
	//%m.nf, default  n: 6
	printf("%11f,%10.2f,%10.4f,%.2f,%f\n", 
		123.456, 123.456, 123.456, 123.456, 123.456);
	//%m.ne, default n: 6
	printf("%10e,%10.4e,%.3e\n", 123.456, 123.456, 123.456);
	printf("%15e,%10.4e,%.3e\n", 0.123456, 0.123456, 0.123456);

	printf("%04d,%06d,%03d\n", 1250, 1250, 1250);
	
	//%m.ns
	printf("%3s,%15s,%10.5s,%.8s\n", "abc", "defghij", "klmnopqrst", "uvwxyz");
	// align left 
	printf("%-10.2f,%-5.2f\n", 123.456, 1.23456e2);
	// long/short: l/h
	printf("%d,%8ld,%ld\n", 7000, 70000l, 70000l);
	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(short int) = %d\n", sizeof(short int));
	printf("sizeof(long int) = %d\n", sizeof(long int));
	printf("sizeof(long long int) = %d\n", sizeof(long long int));
	int a = 0x7fffffff;
	printf("max int(0x7fffffff) = %d\n", a);
	printf("int(0xffffffff) = %d\n", 0xffffffff);
	printf("int(0xffff0000) = %d\n", 0xffff0000);
	printf("short(0xffffffff) = %hd\n", 0xffffffff);
	printf("short(0xffff0000) = %hd\n", 0xffff0000);
	printf("unsigned int(0xffffffff) = %u\n", 0xffffffff);
	long long b = 0xffffffff;
	printf("long long int(0xffffffff) = %lld\n", b);

	printf("%x,%o,%d\n", -1, -1, -1);

	// -01234(Oct) ?=  -668, prifix with 0 indicate Oct,  -01234 = 1000 0000 0000 0000 0000 0010 1001 1100 37777776544 = 1111 1111 1111 1111 1111 1101 0110 0100
	printf("%o, %o, %lo\n", -01234, 01234u, 0123ul);
	// 37777775456(11 111 111 111 111 111 111 101 100 101 110) =1111 1111 1111 1111 1111 1011 0010 1110 = -1234 ==>(original)1000 0000 0000 0000 0000 0100 1101 0010
	printf("%o, %o, %lo\n", -1234, 01234u, 0123ul);

	// -0x6A3B = 1111 1111 1111 1111 1001 0101 1100 0101
	printf("%x,%x,%lx\n", -0x6A3B, 0x6A2Bu, 0x6A2Bul);

	printf("%o,%x,%d\n", 0177, 0177, 0177);

	printf("%o,%8x,%d\n", 0xABC, 0xABC, 0xABC);

	printf("%u,%u,%u\n", 65533u, 65534u, 65535u);
	printf("%hd,%hd,%hd\n", 65533u, 65534u, 65535u);

	// 1000 0000 0000 0000 = -32768 or 1000 0000 = -32768
	printf("%hu\n", -32768);

	printf("%hd\n", 65535u);
	return 0;
}
