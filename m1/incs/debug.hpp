/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:10:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/15 11:40:47 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

//colors
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

//styles
# define BOLD		"\033[1m"
# define FAINT		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

# define ERASE		"\033[2K\r"
# define RESET		"\033[0m"

/* ************************************************************************** */
/* FT_PRINT_MSG FUNCTION OVERLOADS */
/* ************************************************************************** */
void	ft_print_msg(std::string const& message);
void	ft_print_msg(char const* style, char const* color, std::string const& message);

template<typename T>
T	ft_print_msg(std::string const& message, T const val);

template<typename T>
T	ft_print_msg(char const* style, char const* color, std::string const& message, T const val);


#include <debug.tpp>