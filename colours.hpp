/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:23:58 by abaur             #+#    #+#             */
/*   Updated: 2024/06/28 16:39:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/**
 * Index 0 to 2 correspond to the RGB channels, in no particular order.
 * Index 3 is the Alpha channel
 */
typedef double RgbaDouble[4];

RgbaDouble& ColourErase(const RgbaDouble& bottom, const RgbaDouble top, RgbaDouble& result);
