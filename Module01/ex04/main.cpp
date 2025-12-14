/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogs <dogs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 11:09:49 by dogs              #+#    #+#             */
/*   Updated: 2025/12/14 11:49:23 by dogs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string replaceAll(const std::string& input, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return input;
    std::string result;
    result.reserve(input.size());

    std::size_t pos = 0;
    std::size_t found = input.find(s1, pos);

    while(found != std::string::npos)
    {
        result.append(input, pos, found - pos);
        result.append(s2);
        pos = found + s1.size();
        found = input.find(s1, pos);
    }

    result.append(input, pos, std::string::npos);
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr   << "Usage: " << argv[0]
                    << "<filename> <s1> <s2>\n";
        return 1;
    }
    std::string filename = argv[1];
    std::ifstream infile(filename.c_str());
    std::ofstream outfile((filename + ".replace").c_str());

    if (!infile)
    {
        std::cerr << "Failed to open file: " << filename << "\n";
        return 1;
    }
    if (!outfile)
    {
        std::cerr   << "Failed to create output file: "
                    << filename << ".replace\n";
        return 1;
    }

    std::string line;
    while(std::getline(infile, line))
        outfile << replaceAll(line, argv[2], argv[3]) << "\n";
    return (0);
}