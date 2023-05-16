/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:13:25 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/16 12:29:20 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Debug.hpp>

void	Debug::start(unsigned int level) throw()
{
	Debug::level = level;
	Debug::time = 0;
	Debug::bp_time = 0;
	Debug::bp_count = 0;
}

/* ************************************************************************** */
/* PRINT_MSG MODULE */
/* ************************************************************************** */
void	Debug::print_msg(char const* style, char const* color, std::string const& message) throw()
{
	std::cerr << style << color;
	std::cerr << message;
	std::cerr << RESET << std::endl;
}

void	Debug::print_msg(std::string const& message) throw()
{
	std::cerr << message << std::endl;
}

/* ************************************************************************** */
/* INFORMATION MODULE */
/* ************************************************************************** */
void	Debug::detail(std::string const& file, int const& line, std::string const& function) throw()
{
	std::cerr << "Details from function: " << YELLOW << BOLD;
	std::cerr << function << RESET << std::endl;
	std::cerr << "File: " << YELLOW << BOLD << file << RESET << std::endl;
	std::cerr << "Line: " << YELLOW << BOLD << line << RESET << std::endl;
}

/* ************************************************************************** */
/* TIME MODULE */
/* ************************************************************************** */
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
	std::cerr << "Time elapsed since start: " << CYAN;
	std::cerr << (s_time.tv_sec * 1000000 + s_time.tv_usec) - Debug::time << RESET << std::endl;
}

/* ************************************************************************** */
/* BREAKPOINT MODULE */
/* ************************************************************************** */
void	Debug::bp_start() throw()
{
	struct timeval	s_time;

	Debug::bp_time = s_time.tv_sec * 1000000 + s_time.tv_usec;
	Debug::bp_count = 0;
	Debug::bp_map.clear();
	Debug::bp_info.clear();
}

void	Debug::bp_end() throw()
{
	Debug::bp_map.clear();
	Debug::bp_info.clear();
	std::cerr << RED << BOLD << Debug::bp_count << RESET;
	std::cerr << " breakpoints cleared." << std::endl;
	Debug::bp_count = 0;
	Debug::bp_time = 0;
}

void	Debug::bp(std::string const& str) throw()
{
	struct timeval	s_time;

	Debug::bp_map[Debug::bp_count] = (s_time.tv_sec * 1000000 + s_time.tv_usec) - Debug::bp_time;
	Debug::bp_info[Debug::bp_count] = str;
	std::cerr << "Breakpoint #" << Debug::bp_count << " set at ";
	std::cerr << CYAN << Debug::bp_map[Debug::bp_count] << RESET << std::endl;
	std::cerr << "Function: " << YELLOW << BOLD << str << RESET << std::endl;
	Debug::bp_count++;
}

