/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:10:51 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/15 13:16:05 by ljohnson         ###   ########lyon.fr   */
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

//debug
# define LINE __LINE__
# define FILE __FILE__
# define FUNC __PRETTY_FUNCTION__

/* ************************************************************************** */
/* FT_PRINT_MSG FUNCTION OVERLOADS */
/* ************************************************************************** */
class	Debug : public std::exception
{
	protected:
		static unsigned int	level;

	public:
		virtual char const*	what() const throw();

		template<typename T1, typename T2, typename T3, typename T4>
		static void	info(T1 const* t1, T2 const* t2, T3 const* t3, T4 const* t4) throw();
};

/* ************************************************************************** */
/* FT_PRINT_MSG FUNCTION OVERLOADS */
/* ************************************************************************** */
void	ft_print_msg(std::string const& message);
void	ft_print_msg(char const* style, char const* color, std::string const& message);

template<typename T>
T	ft_print_msg(std::string const& message, T const val);

template<typename T>
T	ft_print_msg(char const* style, char const* color, std::string const& message, T const val);

#include <Debug.tpp>