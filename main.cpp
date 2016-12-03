#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "zlib128-dll/include/zlib.h"

int main()
{
    char from_str[] = "zlib compress and uncompress";
    uLong from_len = strlen(from_str) + 1;	/* 需要把字符串的结束符'\0'也一并处理 */

    uLong to_len;
    to_len = compressBound(from_len);	/* 压缩后的长度是不会超过to_len的 */
    char* to_str = nullptr;
    if((to_str = (char*)malloc(sizeof(char) * to_len)) == NULL)
    {
        printf("no enough memory!\n");
        return -1;
    }
    if(compress((Byte*)to_str, &to_len, (Byte*)from_str, from_len) != Z_OK)
    {
        printf("compress failed!\n");
        return -1;
    }
    char *re_str=new char[1000];
    if(uncompress((Byte*)re_str, &from_len, (Byte*)to_str, to_len) != Z_OK)
    {
        printf("uncompress failed!\n");
        return -1;
    }
    /* 打印结果，并释放内存 */
    printf("%s\n", to_str);
    printf("%s\n", re_str);
    if(to_str != NULL)
    {
        free(to_str);
        to_str = NULL;
    }
    delete re_str;
    return 0;
}
//ZEXTERN int ZEXPORT compress OF((Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen));
//ZEXTERN int ZEXPORT uncompress OF((Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen));

//尚待完成的

//将待压缩的字符串分段进行压缩  并在文件中记录  对原始记录的分段方式 对压缩后大小的记录
//字符串压缩方式与gzip是否可以兼容

//压缩文件的例子
