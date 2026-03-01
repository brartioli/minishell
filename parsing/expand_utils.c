
#include "minishell.h"

int	get_var_name_len(char *var_name)
{
	int	len;

	len = 0;
	while(var_name[len] && (ft_isalnum(var_name[len]) || var_name[len] == '_'))
		len++;
	return (len);
}

char *extract_var_name(char *start)
{
    int len;
    
    len = get_var_name_len(start);
    if (len == 0)
        return (NULL);
    return (ft_substr(start, 0, len));
}
