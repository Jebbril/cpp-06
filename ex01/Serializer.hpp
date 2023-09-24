/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 21:01:50 by orakib            #+#    #+#             */
/*   Updated: 2023/09/24 15:04:52 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

class	Serializer {
	private:
		Serializer();
		Serializer(const Serializer &object);
		Serializer	&operator=(const Serializer &object);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data	*deserialize(uintptr_t raw);
};

#endif