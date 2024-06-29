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

#define ALPHA	3

/**
 * Reproduction of Gimp's "Colour Erase" blending mode.
 * The  blending mode  does effectively  the  same job as  its "Colour to Alpha"
 * filter, but takes a few less parameters.
 * 
 * Colour erase is the inverse  operation of the Normal/Behind blending Mode. In
 * broad strokes, if normal blending can be defined as:  
 * 	`lerp(bottom, top, topAlpha) = result`  
 * then we're looking to solve:  
 * 	`lerp (bottom, result, 1/topAlpha) = top`
 * 
 * Remember  that  this equation  uses  the  layer names  from  Normal blending!
 * 'Bottom' and 'result' in Normal  correspond to  the 'top' and 'bottom' layers
 * in Colour Erase (bottom becomes top!); only those two values are known.
 * 'Top' in  Normal corresponds  to the 'result' in  Colour Erase; `topAlpha` in
 * the  equation  is  unknown, so  the  first  step  will be  to figure out  the
 * resulting opacity.
 * 
 * @implnote While gimp  supports  out-of-gamut  colours, I don't know  what the
 * expected behaviour would be  for these. Here, all channels of all colours are
 * assumed to be comprised between 0 and 1 (inclusive).
 * This code remains nonetheless protected against all divisions by 0.
 * 
 * @param bottom	The colour of the bottom layer.
 * @param top   	The colour of the top layer.
 * @param result	Outputs the resulting color.
 * @return `result`
 */
RgbaDouble& ColourErase(const RgbaDouble& bottom, const RgbaDouble& top, RgbaDouble& result)
{
	result[ALPHA] = 0;
	for (int i=0; i<3; ++i){
		double direction = (bottom[i] < top[i]) ? 0 : 1;

		if (top[i] != direction){
			double alpha = remap(top[i],direction, 0,1, bottom[i]);
			if (alpha > result[ALPHA])
				result[ALPHA] = alpha;
		}
	}

	// If Top  has some transparency, attenuate the effect of the filter. Higher
	// top opacity  leads  to  lower result opacity, so  multiply the complement
	// instead of multiplying directly.
	result[ALPHA] = 1 - ( top[ALPHA] * (1-result[ALPHA]) );

	// Finally compute the resulting RGB.
	// Linearly extrapolate from Top toward Bottom. 
	// If the result is fully transparent, Gimp preserves the original RGB.
	for (int i=0; i<3; ++i)
	if  (result[ALPHA] != 0)
		result[i] = lerp(top[i], bottom[i], 1/result[ALPHA]);
	else
		result[i] = bottom[i];

	// Bottom's opacity has no effect on the resulting RGB, so apply it last.
	result[ALPHA] *= bottom[ALPHA];

	return result;
}
