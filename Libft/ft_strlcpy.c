/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:20:11 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 14:24:15 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			size_src;

	size_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (size_src);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
