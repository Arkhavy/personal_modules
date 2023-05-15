/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:12:08 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/15 11:25:43 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <debug.hpp>

template<typename T>
T	ft_print_msg(char const* style, char const* color, std::string const& message, T const val)
{
	std::cerr << style << color;
	std::cerr << message;
	std::cerr << RESET << std::endl;
	return (val);
}

template<typename T>
T	ft_print_msg(std::string const& message, T const val)
{
	std::cerr << message << std::endl;
	return (val);
}