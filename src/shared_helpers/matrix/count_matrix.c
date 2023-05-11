#include "../../../includes/minishell.h"

int count_matrix(char **arr)
{
    int count;

    count = 0;
    if (!arr)
        return 0;
    while (*arr != NULL)
    {
        count++;
        arr++;
    }
    return count;
}
