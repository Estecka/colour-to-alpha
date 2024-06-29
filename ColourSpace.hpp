/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ColourSpace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:47:11 by abaur             #+#    #+#             */
/*   Updated: 2024/06/29 20:53:21 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.hpp"

double LinearToPerceptual(double);
double PerceptualToLinear(double);

void LinearToPerceptual(const RgbaDouble& src, RgbaDouble& dst);
void PerceptualToLinear(const RgbaDouble& src, RgbaDouble& dst);
