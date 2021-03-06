// This file is a part of toml++ and is subject to the the terms of the MIT license.
// Copyright (c) 2019-2020 Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/tomlplusplus/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
/*

	This example demonstrates how to parse TOML from a file and
	re-serialize it (print it out) to stdout.

*/
#include <iostream>
#include <fstream>
#include "utf8_console.h"

#define TOML_UNRELEASED_FEATURES 1
#include <toml++/toml.h>

using namespace std::string_view_literals;

int main(int argc, char** argv)
{
	std::ios_base::sync_with_stdio(false);
	init_utf8_console();

	auto path = std::string{ argc > 1 ? argv[1] : "example.toml" };
	try
	{
		const auto tbl = toml::parse_file(path);
		std::cout << tbl << std::endl;
	}
	catch (const toml::parse_error& err)
	{
		std::cerr << err << std::endl;
		return 1;
	}
	return 0;
}
