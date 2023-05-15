/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:13:25 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/15 14:50:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Debug.hpp>

char const*	Debug::what() const throw() {return ("Generic what message from Debug class");}

void	Debug::print_msg(char const* style, char const* color, std::string const& message) throw()
{
	std::cerr << style << color;
	std::cerr << message;
	std::cerr << RESET << std::endl;
}

void	Debug::print_msg(std::string const& message) throw() {std::cerr << message << std::endl;}

void	Debug::detail(std::string const& file, int const& line, std::string const& function) throw()
{
	std::cerr << "Details from function: " << YELLOW << BOLD;
	std::cerr << function << RESET << std::endl;
	std::cerr << "File: " << YELLOW << BOLD << file << RESET << std::endl;
	std::cerr << "Line: " << YELLOW << BOLD << line << RESET << std::endl;
}

void	Debug::start_time() throw()
{
	struct timeval	s_time;

	gettimeofday(&s_time, NULL);
	Debug::time = s_time.tv_sec * 1000000 + s_time.tv_usec;
}

void	Debug::end_time() throw()
{
	struct timeval	s_time;

	gettimeofday(&s_time, NULL);
	std::cerr << "Time elapsed since start: " << CYAN << BOLD;
	std::cerr << (s_time.tv_sec * 1000000 + s_time.tv_usec) - Debug::time << RESET << std::endl;
}