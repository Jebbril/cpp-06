/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:08:41 by orakib            #+#    #+#             */
/*   Updated: 2023/09/24 18:20:58 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	Base	*ret;

	std::srand((unsigned) std::time(NULL));
    int     i = std::rand();
	if (i % 3 == 0) {
		ret = new A;
	}
	else if (i % 2 == 0) {
		ret = new B;
	}
	else {
		ret = new C;
	}
	return (ret);
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Type is A" << std::endl;
	}
	else if (dynamic_cast<B *>(p)) {
		std::cout << "Type is B" << std::endl;
	}
	else if (dynamic_cast<C *>(p)) {
		std::cout << "Type is C" << std::endl;
	}
	else {
		std::cout << "Type Unknown" << std::endl;
	}
}

void	identify(Base &p) {
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type is A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Type is B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Type is C" << std::endl;
	}
	catch(const std::exception& e) {}
}

int	main(void) {
	Base	b;

	try
	{
		Base *test = generate();
		identify(test);
		delete test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		A a;
		Base &aref = a;
		B b;
		Base &bref = b;
		C c;
		Base &cref = c;
		identify(aref);
		identify(bref);
		identify(cref);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}