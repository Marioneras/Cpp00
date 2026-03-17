/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:06:03 by mberthou          #+#    #+#             */
/*   Updated: 2025/11/17 19:59:04 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

int main(int argc, char** argv) {

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++) {
			std::string s = argv[i];

			transform(s.begin(), s.end(), s.begin(), ::toupper);
			if (i < argc - 1)
				std::cout << s << " ";
			else
				std::cout << s << std::endl;
		}
	}
    return 0;
}
