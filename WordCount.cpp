#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *fp;
    int count = 0; // 统计数
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("文件为空!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // 统计单词
    {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("单词数=%d\n", count);
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数=%d", count);
    }
    fclose(fp); //关闭 
    return 0;
}


