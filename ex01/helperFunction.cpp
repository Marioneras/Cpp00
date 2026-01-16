/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunction.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberthou <mberthou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:24:05 by mberthou          #+#    #+#             */
/*   Updated: 2025/12/03 18:24:05 by mberthou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	isNumber(const std::string &s) {
	return (std::ranges::all_of(s.begin(), s.end(),
		[](char c) { return isdigit(c) != 0; }));
}

