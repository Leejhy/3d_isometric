/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhylee <junhylee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:24:20 by junhylee          #+#    #+#             */
/*   Updated: 2024/01/18 22:16:00 by junhylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	simple_check(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		file_error();
	while (str[i])
		i++;
	if (str[i - 1] != 'f')
		file_error();
}

int	ft_line_cnt(char *file_name)
{
	int		fd;
	int		row;
	char	*tmp_line;

	fd = open(file_name, O_RDWR);
	if (fd < 0)
		ft_error(errno);
	while (1)
	{
		tmp_line = get_next_line(fd);
		if (!tmp_line)//eof
			break ;
		row++;//호출 했는데 eof면 끝
		if (!is_nl(tmp_line))//마지막줄
			break ;
		free(tmp_line);
	}
	if (tmp_line != NULL)
		free(tmp_line);
	close(fd);
	return (row);
}

char	**parsing(char *file_name)
{
	int	fd;
	int	line_cnt;
	int	**map;

	simple_check(file_name);
	ft_split(file_name);//여기 안에서 에러처리됨 다음줄이 실행되면 무조건 에러 아닌것
	line_cnt = ft_line_cnt(file_name);
	if (line_cnt == 0)
		map_error();
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		ft_error(errno);
	map = read_map(fd, line_cnt);
	return (map);
	//read부분~
}
