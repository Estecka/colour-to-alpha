/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:54:58 by abaur             #+#    #+#             */
/*   Updated: 2024/06/29 22:57:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "colours.hpp"
#include "ColourSpace.hpp"

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


static void PrintColour(std::ostream& output, const RgbaDouble& colour){
	output << '#' << std::hex << std::setfill('0') << std::setw(8) << ColourToCode(colour);
}

static std::stringstream line1, line2;
static void Flush(){
	std::cerr << line1.str() << std::endl 
	          << line2.str() << std::endl
	          ;
}

static void CompareResult(std::ostream& output, RgbaDouble& result, const char* expected_arg){
	RgbaDouble expected, diff;
	ArgToColour(expected_arg, expected);

	for (int i=0; i<4; ++i)
		diff[i] = std::min(255.0, std::abs(result[i] - expected[i]));

	output << ' ';
	PrintColour(output, expected);
	output << ' ';
	PrintColour(output, diff);
}


int main(int argc, const char** argv){
	if (argc < 3){
		std::cerr << "Not enough arguments" << std::endl;
		return 1;
	}


	RgbaDouble bottom, top;
	ArgToColour(argv[1], bottom);
	ArgToColour(argv[2], top);
	line1 << "Top:    "; PrintColour(line1, top   );
	line2 << "Bottom: "; PrintColour(line2, bottom);


	RgbaDouble pResult, lResult;

	ColourErase(bottom, top, pResult);

	PerceptualToLinear(bottom, bottom);
	PerceptualToLinear(top, top);
	ColourErase(bottom, top, lResult);
	LinearToPerceptual(lResult, lResult);

	line1 << "  Perceptual: "; PrintColour(line1, pResult);
	line2 << "  Linear:     "; PrintColour(line2, lResult);

	if (argc >= 4) CompareResult(line1, pResult, argv[3]);
	if (argc >= 5) CompareResult(line2, lResult, argv[4]);

	Flush();
}
