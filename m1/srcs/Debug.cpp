/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:13:25 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/15 13:09:30 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Debug.hpp>

void	ft_print_msg(char const* style, char const* color, std::string const& message)
{
	std::cerr << style << color;
	std::cerr << message;
	std::cerr << RESET << std::endl;
}

void	ft_print_msg(std::string const& message)
{
	std::cerr << message << std::endl;
}

char const*	Debug::what() const throw() {return ("Generic what message from Debug class");}