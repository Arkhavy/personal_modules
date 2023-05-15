/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:12:08 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/15 13:17:13 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Debug.hpp>

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

template<typename T1, typename T2, typename T3, typename T4>
void	Debug::info(T1 const* t1, T2 const* t2, T3 const* t3, T4 const* t4) throw()
{
	std::cerr << RED << BOLD << "From function: " << __builtin_FUNCTION() << RESET << std::endl;
	switch (Debug::level)
	{
		case 1:
		{
			if (t1 != NULL)
				std::cerr << "value T1: " << t1 << std::endl; 
			break;
		}
		case 2:
		{
			if (t2 != NULL)
				std::cerr << "value T2: " << t2 << std::endl; 
			break;
		}
		case 3:
		{
			if (t3 != NULL)
				std::cerr << "value T3: " << t3 << std::endl; 
			break;
		}
		case 4:
		{
			if (t4 != NULL)
				std::cerr << "value T4: " << t4 << std::endl; 
			break;
		}
		default:
			std::cerr << "Default message sent from Debug::info" << std::endl;
	}
}