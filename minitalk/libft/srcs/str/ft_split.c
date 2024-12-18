/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:22:15 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/02 19:06:15 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	LIBRARY: N/A
**	SYNOPSIS: separate a string into substrings delimited by a character
**
**	DESCRIPTION:
** 	Allocates (with malloc) and returns an array of strings obtained by
**	splitting 's' using the character 'c' as a delimiter. The array must end
**	with a NULL pointer.
**
**	RETURN VALUE:
**	The array of new strings resulting from the split.
**	Or NULL if the allocation fails.
*/

#include "../../includes/libft.h"

static	size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (count);
}

static	size_t	count_letter(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static	char	*ft_strdup_s(const char *s, char c)
{
	size_t	i;
	size_t	len;
	char	*dup;

	i = 0;
	len = count_letter(s, c);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static	void	*free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arrs;

	arrs = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arrs)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			arrs[j] = ft_strdup_s(s + i, c);
			if (arrs[j] == NULL)
				return (free_strs(arrs));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	arrs[j] = NULL;
	return (arrs);
}

/*
#include <stdio.h>
int main(void)
{
    char **arrs;
    char *str = " Hello... The,New - = +  Future.e ! ";
    char charset = ' ';
    int i = 0;
    arrs = ft_split(str, charset);
    if (!arrs)
        return (1);
    while (arrs[i] != NULL)
    {
        printf("%s\n", arrs[i]);
        free(arrs[i]);
        i++;
    }
    free(arrs);
    return (0);
}
*/