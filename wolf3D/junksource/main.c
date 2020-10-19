/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wealdboar <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 03:05:23 by wealdboar         #+#    #+#             */
/*   Updated: 2020/10/18 21:28:53 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/maze3d.h"

int	main(void)
{
	//t_bitmap_pic_info	pic_1;
	t_bitmap_pic_info	pic_2;
	/*int		read_bitmap_file(char *filename, bitmap_pic_info *img_info);*/
	//read_bitmap_file("./frst_screen.bmp", &pic_1);
	read_bitmap_file("/home/lchantel/Desktop/frst_screen_0.bmp", &pic_2);
	return (0);
}
