/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ColourSpace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:47:39 by abaur             #+#    #+#             */
/*   Updated: 2024/06/29 23:04:03 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"
#include <cmath>

#define GAMMA	2.2

/**
 * Don't ask me how these things work. For all I know I might even have gotten
 * the names mixed up.
 * 
 * The one thing I do know is that the alpha channel is exempt from these kind
 * of conversions channel is excluded from the conversion.
 */

void LinearToPerceptual(const RgbaDouble& src, RgbaDouble& dst){
	for (int i=0; i<3; ++i)
		dst[i] = std::pow(src[i], 1/GAMMA);
}

void PerceptualToLinear(const RgbaDouble& src, RgbaDouble& dst){
	for (int i=0; i<3; ++i)
		dst[i] = std::pow(src[i], GAMMA);
}

