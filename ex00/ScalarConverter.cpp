/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:04:24 by orakib            #+#    #+#             */
/*   Updated: 2023/09/23 20:37:16 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::c = 0;
int		ScalarConverter::i = 0;
float	ScalarConverter::f = 0.0f;
double	ScalarConverter::d = 0.0;

const char	*ScalarConverter::EmptyParam::what() const throw() {
	return ("Exception thrown : You entered an empty string");
}

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &object) {
	(void)object;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &object) {
	(void)object;
	return (*this);
}

ScalarConverter::~ScalarConverter() {

}

bool	ScalarConverter::isChar(std::string param) {
	if (param.length() == 1 && ((param[0] >= 0 && param[0] < 48)
		|| (param[0] > 57)))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string param) {
	int	i = 0;

	if (param[i] == '+' || param[i] == '-')
		i++;
	while (param[i]) {
		if (!std::isdigit(param[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string param) {
	int	i = 0;
	int	point = 0;

	if (param == "nanf" || param == "+inff" || param == "-inff")
		return (true);
	if (param[i] == '+' || param[i] == '-')
		i++;
	while (param[i] && param[i + 1]) {
		if (param[i] == '.') {
			point++;
			i++;
			continue;
		}
		if (!std::isdigit(param[i]))
			return (false);
		i++;
	}
	if (point > 1 || param[i] != 'f')
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(std::string param) {
	int	i = 0;
	int	point = 0;

	if (param == "nan" || param == "+inf" || param == "-inf")
		return (true);
	if (param[i] == '+' || param[i] == '-')
		i++;
	while (param[i]) {
		if (param[i] == '.') {
			point++;
			i++;
			continue;
		}
		if (!std::isdigit(param[i]))
			return (false);
		i++;
	}
	if (point > 1)
		return (false);
	return (true);
}

void	ScalarConverter::toChar(std::string param) {
	c = param[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if (c < 32 || c >= 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::toInt(std::string param) {
	std::stringstream(param) >> i;
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
	if (c < 32 || c >= 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::toFloat(std::string param) {
	if (param == "nanf" || param == "+inff" || param == "-inff") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << param << std::endl;
		param.erase(param.length() - 1);
		std::cout << "double: " << param << std::endl;
		return;
	}
	param.erase(param.length() - 1);
	std::stringstream(param) >> f;
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
	if (c < 32 || c >= 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::toDouble(std::string param) {
	if (param == "nan" || param == "+inf" || param == "-inf") {
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << param + "f" << std::endl;
		std::cout << "double: " << param << std::endl;
		return;
	}
	std::stringstream(param) >> d;
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
	if (c < 32 || c >= 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convert(std::string param) {
	if (param.empty())
		throw EmptyParam();
	if (isChar(param))
		toChar(param);
	else if (isInt(param))
		toInt(param);
	else if (isFloat(param))
		toFloat(param);
	else if (isDouble(param))
		toDouble(param);
	else
		std::cout << "Literal passed does not match any type !" << std::endl;
}