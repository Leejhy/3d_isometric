/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:30:59 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/26 18:47:30 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	xyz_frees(t_xyz **xyz, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(xyz[i]);
		i++;
	}
	free(xyz);
}
