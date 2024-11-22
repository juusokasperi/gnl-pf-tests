/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:58:03 by jrinta-           #+#    #+#             */
/*   Updated: 2024/11/22 12:38:13 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../get_next_line.h"
#include "string.h"
#include "colors.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
	}
	return (0);
}

int	test_gnl(int fd)
{
	char *next_line;
	int	lines = 1;
	while (1)
	{
		if ((next_line = get_next_line(fd)))
			printf("%s%d->%s%s", KYEL, lines++, KNRM, next_line);
		if (!next_line)
			break ;
		free(next_line);
	}
	free(next_line);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("%s------------------------------\n", KYEL);
		printf("-----       Usage:       -----\n%s", KNRM);
		printf("%s------------------------------\n", KYEL);

		printf("%s <file_to_read>\t// Reads the given file\n", argv[0]);
		printf("%s inv\t\t\t// Attempts to read an invalid file descriptor\n", argv[0]);
		printf("%s stdin\t\t\t// Reads from std input\n\n", argv[0]);
		printf("%s------------------------------\n", KYEL);
		printf("%s- Some files to try reading: -\n%s", KYEL, KNRM);
		printf("%s------------------------------\n", KYEL);
		printf("multiple_long_lines.txt multiple_short_lines.txt multiple_empty_lines.txt\n");
		printf("empty.txt giant_line.txt giant_line_nl.txt\n");
		printf("%s------------------------------\n%s", KYEL, KNRM);
		return (1);
	}
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "stdin", 5) == 0 && strlen(argv[1]) == 5)
			return (test_gnl(0));
		else if (ft_strncmp(argv[1], "inv", 3) == 0 && strlen(argv[1]) == 3)
			return (test_gnl(42));
		else
			return (test_gnl(open(argv[1], O_RDONLY)));
	}
	else
		return (printf("Error: Too many aruments. Read instructions by running \"%s\".\n", argv[0]));
}
