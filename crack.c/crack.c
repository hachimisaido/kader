#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<crypt.h>
#define _xopen_source
#include<unistd.h>
int main(int argc,char* argv[])
{
if(argc!=2)
{
    printf("usage:./crack hash\n");
    return 1;
}
if(!brute_force (argv[1]))
{
    return 1;
}
}
bool brute_force (char* given_hash)
{
    char* all="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char collect[5];
    char salt[3];salt[0]=given_hash[0];salt[1]=given_hash[1];salt[2]='\0';
    for(int i=0;i<26+26;i++)
    {
        collect[0]=all[i];
        collect[1]='\0';
        char* new_hash=crypt(collect,salt);
        if(strcmp(new_hash,given_hash)==0)
        {
            printf("saltched:%s,%s clear:%s\n",new_hash,given_hash,collect);
            return true;
        }
    }
    for(int i=0;i<26+26;i++)
    {
        collect[0]=all[i];
        for(int j=0;j<26+26;j++)
        {
            collect[1]=all[j];
            collect[2]='\0';
            char* new_hash=crypt(collect,salt);
            if(strcmp(new_hash,given_hash)==0)
            {
                printf("saltched:%s %s clear:%s\n",new_hash,given_hash,collect);
                return 0;
            }
        }
    }
for(int i=0;i<26+26;i++)
{
    collect[0]=all[i];
    for(int j=0;j<26+26;j++)
    {
        collect[1]=all[j];
        for(int k=0;k<26+26;k++)
        {
            collect[2]=all[k];
            collect[3]='\0';
        char* new_hash=crypt(collect,salt);
        if(strcmp(new_hash,given_hash)==0)
        {
            printf("saltched:%s %s clear:%s\n",new_hash,given_hash,collect);
            return true;
        }
    }
}

}
for(int i=0;i<26+26;i++)
{
    collect[0]=all[i];
    for(int j=0;j<26+26;j++)
    {
        collect[1]=all[j];
        for(int k=0;k<26+26;k++)
        {
            collect[2]=all[k];
            for(int l=0;l<26+26;l++)
            {
                collect[3]=all[l];
                collect[4]='\0';
                char *new_hash=crypt(collect,salt);
                if(strcmp(new_hash,given_hash)==0)
                {
                    printf("saltched:%s %s clear:%s\n",new_hash,given_hash,collect);
                    return true;

                }
            }
        }
    }
}
}
