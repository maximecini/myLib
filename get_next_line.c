/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:03:16 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/12/14 13:26:59 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *buffer)
{
	int		size_line;
	char	*dest;
	int		i;

	i = 0;
	 if (!buffer)  // Vérification NULL ajoutée ici
        return (NULL);
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	size_line = i;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] && i < size_line)
	{
		dest[i] = buffer[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*read_file(int fd, char *res)
{
	int		byte_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(res), NULL);
		if (byte_read == 0)
			break;
		buffer[byte_read] = '\0';
		res = ft_strjoin_gnl(res, buffer);
		if(!res)
			return  free(buffer),NULL;
	}
	free(buffer);
	return (res);
}

static char	*ft_next_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*dest;
	int		lengt_buffer;

	i = 0;
	 if (!buffer)  
        return (NULL);
	if(!ft_strchr(buffer, '\n'))
		return free(buffer), NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return free(buffer),(NULL);
	
	lengt_buffer = ft_strlen(buffer) - i;
	dest = malloc((lengt_buffer + 1) * sizeof(char));
	if (!dest)
		return free(buffer),(NULL);
	i++;
	j = 0;
	while (buffer[i])
		dest[j++] = buffer[i++];
	dest[j] = '\0';
	free(buffer);
	return (dest);
}

/**
 * @brief Lit une ligne depuis un fichier ou un flux donné.
 *
 * La fonction `get_next_line` lit une ligne depuis un fichier ou un 
 * flux spécifié par son descripteur de fichier. Une ligne est définie comme 
 * une séquence de caractèresterminée par un caractère de saut de ligne (`\n`) 
 * ou par la fin du fichier (EOF).
 * Elle gère un buffer interne pour conserver l'état de lecture entre plusieurs appels.
 *
 * @param fd Le descripteur de fichier à lire. Il peut s'agir d'un descripteur obtenu
 *           via `open()` ou des descripteurs standards comme `0` (stdin).
 *
 * @return Une chaîne de caractères contenant la ligne lue (incluant le caractère '\n'
 *         si présent), allouée dynamiquement. Si la fin du fichier est atteinte et
 *         qu'aucune donnée n'est lue, retourne `NULL`. En cas d'erreur (descripteur
 *         invalide, échec de l'allocation, etc.), retourne également `NULL`.
 *
 * @note L'utilisateur est responsable de libérer la mémoire allouée pour chaque ligne
 *       avec `free()`. La macro `BUFFER_SIZE` doit être définie pour déterminer la 
 * 		 taille
 *       du tampon interne utilisé lors de la lecture.
 *
 * @note Cette fonction n'est pas thread-safe en raison de l'utilisation d'un buffer 
 *       statique partagé entre les appels.
 *
 * @note En cas de fichier ou flux sans `\n`, la dernière ligne sera retournée sans ce 
 *       caractère.
 *
 * @attention Si `BUFFER_SIZE` n'est pas défini ou est défini à une valeur <= 0, 
 *            return NULL
 **/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_buffer(buffer);
	return (line);
}
// int	main(void)
// {
// 	char	*line;
// 	int		fd1;

// 	fd1 = open("one_line_no_nl.txt", O_RDONLY);
// 	// line = get_next_line(49);
// 	// printf("line: <%s>\n",line);
// 	// free(line);
// 	line = get_next_line(fd1);
// 	printf("line: <%s>\n",line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("line: <%s>\n",line);
// 	free(line);

// 	close(fd1);
// 	return (0);
// }
