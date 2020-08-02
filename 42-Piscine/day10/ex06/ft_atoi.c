/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchantel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:26:45 by lchantel          #+#    #+#             */
/*   Updated: 2020/02/11 15:58:52 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int index;
	int sign;
	int result;

	result = 0;
	sign = 1;
	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 &&
				str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	if (str[index] == '0' && str[index + 1] == '0')
		index++;
	while (str[index] != '\0' && str[index] >= 48 &&
			str[index] <= 57)
	{
		result = result * 10 + (str[index] - 48);
		index++;
	}
	return (result * sign);
}
