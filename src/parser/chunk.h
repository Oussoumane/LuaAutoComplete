#pragma once

#include <parser/ast.h>
#include <parser/positions.h>

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>

namespace lac
{
	namespace parser
	{
		namespace x3 = boost::spirit::x3;
		using chunk_type = x3::rule<struct chunk, ast::Block>;
		BOOST_SPIRIT_DECLARE(chunk_type);
	} // namespace parser

	parser::chunk_type chunkRule();

	// This skips comments and spaces
	bool parseString(std::string_view view, pos::Positions<std::string_view::const_iterator>& positions, ast::Block& block);
} // namespace lac
