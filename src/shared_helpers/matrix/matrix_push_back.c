/* ************************************************************************** */
/* */
/* ::: :::::::: */
/* matrix_push_back.c :+: :+: :+: */
/* +:+ +:+ +:+ */
/* By: otait-ta <otait-ta@student.42.fr> +#+ +:+ +#+ */
/* +#+#+#+#+#+ +#+ */
/* Created: 2023/05/04 11:40:42 by otait-ta #+# #+# */
/* Updated: 2023/05/04 11:44:13 by otait-ta ### ########.fr */
/* */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void matrix_push_back(char **final_tokens, char **sub_tokens)
{
	int		final_tokens_len;
	int		sub_tokens_len;
	char	**new_final_tokens;
	int		i;
	(void)sub_tokens;
	// ft_putnbr_fd(1,1);
	final_tokens_len = count_matrix(final_tokens);
	sub_tokens_len = count_matrix(sub_tokens);
	ft_putstr_fd(sub_tokens[1],1);
	new_final_tokens = malloc(sizeof(char *) * (final_tokens_len + sub_tokens_len + 1));
	i = 0;
	while (i < final_tokens_len)
	{
		new_final_tokens[i] = final_tokens[i];
		i++;
	}
	i = 0;
	while (i < sub_tokens_len)
	{
		new_final_tokens[final_tokens_len + i] = sub_tokens[i];
		i++;
	}
	new_final_tokens[final_tokens_len + sub_tokens_len] = NULL;
	free(final_tokens);
	final_tokens = new_final_tokens;
}
