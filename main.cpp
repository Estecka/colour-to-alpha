/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:54:58 by abaur             #+#    #+#             */
/*   Updated: 2024/06/29 16:15:03 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <string>
#include <stdexcept>

#include "colours.hpp"

typedef double RgbaDouble[4];

/**
** Parse a string formatted as #AARRGGBB or #RRGGBB
** Leading # is optional.
*/
static RgbaDouble& ArgToColour(const char* arg, RgbaDouble& result){
	if (*arg =='#')
		++arg;

	unsigned int code = std::stoi(arg);
	for (int i=0; i<4; ++i){
		result[i] = ((code >> i) & 0xff) / 255.0;
	}

	return result;
}



int main(int argc, const char** argv){
	if (argc < 3){
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}

	RgbaDouble bottom, top, result;
	ArgToColour(argv[1], bottom);
	ArgToColour(argv[2], top);
	ColourErase(bottom, top, result);


}
