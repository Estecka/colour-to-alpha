/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:54:58 by abaur             #+#    #+#             */
/*   Updated: 2024/06/27 23:04:05 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct Rgba32 {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

static union {
	struct Rgba32 channels;
	unsigned char bytes[4];
};

int main(int argc, const char** argv){
}
