/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:04:15 by orakib            #+#    #+#             */
/*   Updated: 2023/09/23 20:02:52 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <iomanip>

class ScalarConverter {
	private:
		static char		c;
		static int		i;
		static float	f;
		static double	d;
		ScalarConverter();
		ScalarConverter(const ScalarConverter &object);
		ScalarConverter	&operator=(const ScalarConverter &object);
		~ScalarConverter();
	public:
		static bool	isChar(std::string param);
		static bool	isInt(std::string param);
		static bool	isFloat(std::string param);
		static bool	isDouble(std::string param);
		static void	toChar(std::string param);
		static void	toInt(std::string param);
		static void	toFloat(std::string param);
		static void	toDouble(std::string param);
		static void	convert(std::string param);
		class	EmptyParam : public std::exception {
			virtual const char* what() const throw();
		};
};


#endif