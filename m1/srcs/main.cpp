/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:17:39 by ljohnson          #+#    #+#             */
/*   Updated: 2023/05/22 12:27:18 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <Debug.hpp>

void	test_fnc()
{
	Debug::info(LINE, FILE, "third param", "This is a test");
	Debug::detail(FILE, LINE, FUNC);
}

int	main(void)
{
	Debug::start(4);
	Debug::print_msg(RESET, RED, "This is a red test");
	std::cout << Debug::print_msg(RESET, YELLOW, "This is a yellow test with int", 42) << std::endl;
	Debug::print_msg(BOLD, BLUE, "This is a bold blue test");
	std::cout << Debug::print_msg(BOLD, PURPLE, "This is a bold purple test with string", "lol") << std::endl;
	Debug::print_msg(FAINT, GREEN, "This is a faint green test");
	std::cout << Debug::print_msg(UNDERLINE, CYAN, "This is a underline cyan test with NULL", NULL) << std::endl;
	Debug::print_msg(RESET, WHITE, "This is a white test");
	std::cout << Debug::print_msg(ITALIC, BLACK, "This is a italic black test with float", 14.4f) << std::endl;
	Debug::print_msg("This is a normal message");
	std::cout << Debug::print_msg("This is a normal message with an int return val", 42) << std::endl;
	std::cout << Debug::print_msg("This is a normal message with a string return val", "test value") << std::endl;
	std::cout << Debug::print_msg("This is a normal message with a NULL return val", NULL) << std::endl;

	Debug::info("t1 string", 42, NULL, 14.4f);
	test_fnc();
	return (0);
}