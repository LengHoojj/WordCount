#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc ��ʾ��������, *argv[]ָ������, ÿһ��ָ��ָ��һ���ַ���
    FILE *fp;
    int count = 0; // ͳ����
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("�ļ�Ϊ��!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // ͳ�Ƶ���
    {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("������=%d\n", count);
    }
    else if (argv[1][1] == 'c') // ͳ���ַ�
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("�ַ���=%d", count);
    }
    fclose(fp); //�ر� 
    return 0;
}


