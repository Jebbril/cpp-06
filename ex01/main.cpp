/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:29:19 by orakib            #+#    #+#             */
/*   Updated: 2023/09/24 14:39:36 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data		*d1 = new Data;
	Data		*d2;
	uintptr_t	adr;

	d1->index = 5;
	d1->file = 'C';
	adr = Serializer::serialize(d1);
	std::cout << "adresse value : " << adr << std::endl;
	d2 = Serializer::deserialize(adr);
	std::cout << "index value : " << d2->index << std::endl;
	std::cout << "file value : " << d2->file << std::endl;
	delete d2;
}