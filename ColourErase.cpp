/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ColourErase.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:26:09 by abaur             #+#    #+#             */
/*   Updated: 2024/06/28 16:48:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"
#include "colours.hpp"

// The index of the alpha channel in RgbaDouble
#define ALPHA	3

/**
 * Reproduction of Gimp's "Colour Erase" blending mode.
 * 
 * See the Readme for an exhaustive walkthrough of the math.
 * 
 * @implnote  Although Gimp supports out-of-gamut colours, I don't know what the
 * expected behaviour  would be for these. Here, all channels of all colours are
 * assumed to be comprised between 0 and 1 (inclusive).
 * This code remains nonetheless  protected against all divisions by 0, and will
 * not crash when fed with outlandish values.
 * 
 * @param bottom	The colour of the bottom layer.
 * @param top   	The colour of the top layer.
 * @param result	Outputs the resulting color.
 * @return `result`
 */
RgbaDouble& ColourErase(const RgbaDouble& bottom, const RgbaDouble& top, RgbaDouble& result)
{
	// Compute the resulting Alpha based on input RGB.
	result[ALPHA] = 0;
	for (int i=0; i<3; ++i){
		// Find which extreme each of the resulting RGB channels tends toward.
		double direction = (bottom[i] < top[i]) ? 0 : 1;

		if (top[i] != direction){
			// Find a candidate Alpha based on each channel alone.
			double alpha = remap(top[i],direction, 0,1, bottom[i]);
			// Elect the highest Alpha as the correct one.
			if (alpha > result[ALPHA])
				result[ALPHA] = alpha;
		}
	}

	// Clamp Alpha to [0-1].
	// (It's already guaranteed to not be negative at this point.)
	if (result[ALPHA] > 1)
		result[ALPHA] = 1;

	// Apply Top opacity
	result[ALPHA] = lerp(1, result[ALPHA], top[ALPHA]);

	// Compute resulting RGB based on resulting Alpha
	for (int i=0; i<3; ++i)
	if  (result[ALPHA] != 0)
		result[i] = lerp(top[i], bottom[i], 1/result[ALPHA]);
	else
		result[i] = bottom[i];

	// Apply Bottom opacity
	result[ALPHA] *= bottom[ALPHA];

	return result;
}
