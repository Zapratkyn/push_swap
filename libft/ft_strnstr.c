/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:51:47 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 14:14:32 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	char	*hs;
	char	*nd;

	i = 0;
	hs = (char *)haystack;
	nd = (char *)needle;
	if (nd[i] == '\0')
		return (0);
	while (hs[i])
	{
		k = 0;
		while ((hs[i + k] == nd[k]) && (k < len))
		{
			if (nd[k + 1] == '\0')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}
