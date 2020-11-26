/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <lchantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:03:20 by lchantel          #+#    #+#             */
/*   Updated: 2020/11/26 16:03:30 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(void)
{
	//t_bitmap_pic_info	pic_1;
	t_bitmap_pic_info	pic_2;
	/*int		read_bitmap_file(char *filename, bitmap_pic_info *img_info);*/
	//read_bitmap_file("./frst_screen.bmp", &pic_1);
	read_bitmap_file("/home/lchantel/Desktop/frst_screen_0.bmp", &pic_2);
	return (0);
}
