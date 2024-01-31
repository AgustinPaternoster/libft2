#include "libft.h"


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    // char *s = "split  this for me";
    // char a = 'a';
    char **result = ft_split(argv[1],argv[2][0]);
    // char *s = "--ssss--sss--s-ss-s";
    // char **result = ft_split(argv[1],argv[2][0]);
    // printf("%s", result[0]);
    // for(int i = 0;i < 5;i++)
    //     printf("%s",result[i]);
    printf("%p",result[0]);

    return 0;

}