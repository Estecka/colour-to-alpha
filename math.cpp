/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:39:30 by abaur             #+#    #+#             */
/*   Updated: 2024/10/20 14:01:03 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

double lerp(double a, double b, double t){
	return a + (b-a)*t;
}

double remap(double iMin, double iMax, double oMin, double oMax, double n){
	return oMin + (oMax-oMin)*(n-iMin)/(iMax-iMin);
}
