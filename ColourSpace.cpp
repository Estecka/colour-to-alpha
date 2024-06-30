/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ColourSpace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:47:39 by abaur             #+#    #+#             */
/*   Updated: 2024/06/30 02:10:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include <cmath>

#define GAMMA	(double)2.4

/**
 * Don't ask me how these things work. But thank you to that particular guy:
 * https://entropymine.com/imageworsener/srgbformula/
 * 
 * The one thing I do know is that the alpha channel is exempt from these kind
 * of conversions.
 */

void LinearToPerceptual(const RgbaDouble& src, RgbaDouble& dst){
	for (int i=0; i<3; ++i){
		if (src[i] <= 0.0031308)
			dst[i] = src[i] * 12.92;
		else
			dst[i] = std::pow(src[i], 1/GAMMA)*1.055 - 0.055 ;
	}
}

void PerceptualToLinear(const RgbaDouble& src, RgbaDouble& dst){
	for (int i=0; i<3; ++i){
		if (src[i] <= 0.04045)
			dst[i] = src[i]/12.92;
		else
			dst[i] = std::pow((src[i]+0.055)/1.055, GAMMA) ;
	}
}

