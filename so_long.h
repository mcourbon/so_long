/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:55:16 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/18 13:43:24 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define NOT_RECTANGLE "Error,\nYour map should be rectangle."
# define NOT_WALLED "Error,\nYour map is not walled."
# define NOT_CEP "Error,\nYour map contains missing or duplicate datas."
# define NOT_VALID "Error,\nYour map must contain only 0, 1, C, E, M, and P."
# define NOT_BER "Error,\nYour map do not have extension .ber."
# define NOT_SOLVABLE "Error,\nYour map is unsolvable."
# define VICTORY "Amazing !\nYou find the treasure !"
# define DEFEAT "Argh...\nBetter luck next time !"

# define KEY_Q 113
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define ARROW_LEFT 65361

typedef struct s_mob
{
	int		mob_x;
	int		mob_y;
	void	*img_mob;
}	t_mob;

typedef struct s_so_long
{
	char	**map;
	void	*mlx;
	void	*win;

	void	*img_grass;
	void	*img_wall;

	void	*img_player;
	void	*img_player_front;
	void	*img_player_right;
	void	*img_player_back;
	void	*img_player_left;

	void	*img_mob_front;
	void	*img_mob_right;
	void	*img_mob_back;
	void	*img_mob_left;

	void	*img_exit;
	void	*img_exit_close;
	void	*img_exit_open;

	void	*img_collect;
	void	*img_collect_right;
	void	*img_collect_left;

	int		map_w;
	int		map_h;

	int		img_w;
	int		img_h;

	int		player_x;
	int		player_y;

	int		nb_collect;
	int		nb_p;
	int		nb_exit;

	int		moves;
	int		nb_mobs;

	t_mob	*mobs;
}	t_so_long;

/*	Mobs	*/
int		check_mobs(char **map);
int		check_nb_mobs(t_so_long *so_long);
void	draw_mobs(t_so_long *so_long, int x, int y, int mob_index);
int		draw_map_mobs(t_so_long *so_long);
void	update_mob_w(t_so_long *so_long, int i);
void	update_mob_d(t_so_long *so_long, int i);
void	update_mob_s(t_so_long *so_long, int i);
void	update_mob_a(t_so_long *so_long, int i);

/*	Parsing	*/
int		check_is_map(t_so_long *so_long);
int		check_solution(char *file);
char	**read_map(char *file_map);

/*	Player	*/
void	update_player_w(t_so_long *so_long);
void	update_player_d(t_so_long *so_long);
void	update_player_s(t_so_long *so_long);
void	update_player_a(t_so_long *so_long);

/*	Source	*/
void	draw_img(t_so_long *so_long, void *img, int x, int y);
int		draw_map(t_so_long *so_long);
void	free_map(char **map);
int		game_exit(t_so_long *so_long);
int		game_load(t_so_long *so_long);
int		update_movements(t_so_long *so_long);
void	game_update(t_so_long *so_long);

/*	Utils	*/
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

/*	Gnl	*/
int		check_nbread_and_linebreak(char *str, int nb_read);
char	*read_file(int fd, char *backup);
char	*get_a_line(char *backup);
char	*get_next_line_start(char *backup);
char	*get_next_line(int fd);
int		get_index_linebreak(char *str);
int		get_len_line(char *str);
void	*ft_memcpy_gnl(void *dest, void *src, size_t size);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
