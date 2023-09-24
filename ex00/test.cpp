/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:25:08 by orakib            #+#    #+#             */
/*   Updated: 2023/09/23 20:52:20 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <unistd.h>
#include <iostream>


int	main(void) {
	system("./convert 1");
	sleep(1);
	std::cout << std::endl;
	system("./convert nan");
	sleep(1);
	std::cout << std::endl;
	system("./convert 1337.42f");
	sleep(1);
	std::cout << std::endl;
	system("./convert 42.42");
	sleep(1);
	std::cout << std::endl;
	system("./convert A");
}