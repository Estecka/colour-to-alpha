/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:54:58 by abaur             #+#    #+#             */
/*   Updated: 2024/06/29 17:48:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iomanip>
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

	unsigned int code = std::stol(arg, NULL, 16);
	for (int i=0; i<4; ++i)
		result[i] = ((code >> 8*i) & 0xff)/ 255.0;

	return result;
}

static unsigned int ColourToCode(const RgbaDouble& colour){
	unsigned int code = 0;

	for (int i=0; i<4; ++i)
		code |= (0xff & (unsigned int)(colour[i] * 255)) << 8*i;

	return code;
}


int main(int argc, const char** argv){
	if (argc < 3){
		std::cerr << "Not enough arguments" << std::endl;
		return 1;
	}

	RgbaDouble bottom, top, result;
	ArgToColour(argv[1], bottom);
	ArgToColour(argv[2], top);
	ColourErase(bottom, top, result);
	std::cout
		<< "Top:      #" << std::hex << std::setfill('0') << std::setw(8) << ColourToCode(top)    << std::endl
		<< "Bottom:   #" << std::hex << std::setfill('0') << std::setw(8) << ColourToCode(bottom) << std::endl
		<< "Result:   #" << std::hex << std::setfill('0') << std::setw(8) << ColourToCode(result) << std::endl
		;


	if (argc < 4)
		return 0;

	RgbaDouble expected, diff;
	ArgToColour(argv[3], expected);
	for (int i=0; i<4; ++i)
		diff[i] = std::min(255.0, std::abs(result[i] - expected[i]));

	std::cout
		<< "Expected: #" << std::hex << std::setfill('0') << std::setw(8) << ColourToCode(expected) << std::endl
		<< "Diff:     #" << std::hex << std::setfill('0') << std::setw(8) << ColourToCode(diff)     << std::endl
		;
}
