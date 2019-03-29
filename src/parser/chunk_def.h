#pragma once

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>

#include <parser/ast.h>
#include <parser/ast_adapted.h>
#include <parser/chunk.h>

namespace lac
{
	namespace parser
	{
		namespace x3 = boost::spirit::x3;
		namespace ascii = x3::ascii;
		using ascii::char_;
		using ascii::string;
		using x3::_attr;
		using x3::_pass;
		using x3::alnum;
		using x3::alpha;
		using x3::double_;
		using x3::eol;
		using x3::eps;
		using x3::get;
		using x3::hex;
		using x3::lexeme;
		using x3::lit;
		using x3::omit;
		using x3::raw;
		using x3::with;

		// clang-format off
		struct keyword_ : x3::symbols<std::string>
		{
			keyword_()
			{
				add
					("and", "and")
					("break", "break")
					("do", "do")
					("else", "else")
					("elseif", "elseif")
					("end", "end")
					("false", "false")
					("for", "for")
					("function", "function")
					("goto", "goto")
					("if", "if")
					("in", "in")
					("local", "local")
					("nil", "nil")
					("not", "not")
					("or", "or")
					("repeat", "repeat")
					("return", "return")
					("then", "then")
					("true", "true")
					("until", "until")
					("while", "while");
			}
		} keyword;

		struct binaryOperator_ : x3::symbols<ast::Operation>
		{
			binaryOperator_()
			{
				using Op = ast::Operation;
				add
					("+", Op::add)
					("-", Op::sub)
					("*", Op::mul)
					("/", Op::div)
					("//", Op::idiv)
					("%", Op::mod)
					("^", Op::pow)
					("&", Op::band)
					("|", Op::bor)
					("~", Op::bxor)
					("<<", Op::shl)
					(">>", Op::shr)
					("..", Op::concat)
					("<", Op::lt)
					("<=", Op::le)
					(">", Op::gt)
					(">=", Op::ge)
					("==", Op::eq)
					("~=", Op::ineq)
					("and", Op::band)
					("or", Op::bor);
			}
		} binaryOperator;

		struct unaryOperator_ : x3::symbols<ast::Operation>
		{
			using Op = ast::Operation;
			unaryOperator_()
			{
				add
					("-", Op::unm)
					("#", Op::len)
					("~", Op::bnot)
					("not", Op::bnot);
			}
		} unaryOperator;

		struct expressionConstant_ : x3::symbols<ast::ExpressionConstant>
		{
			expressionConstant_()
			{
				using EC = ast::ExpressionConstant;
				add
					("nil", EC::nil)
					("false", EC::False)
					("true", EC::True)
					("...", EC::dots);
			}
		} expressionConstant;
		// clang-format on

		const x3::rule<class name, std::string> name = "name";
		const x3::rule<class namesList, std::vector<std::string>> namesList = "namesList";

		const x3::rule<class openLongBracket> openLongBracket = "openLongBracket";
		const x3::rule<class closeLongBacket> closeLongBacket = "closeLongBacket";
		const x3::rule<class longLiteralString, std::string> longLiteralString = "longLiteralString";
		const x3::rule<class literalString, std::string> literalString = "literalString";

		const x3::rule<class numeral, double> numeral = "numeral";
		const x3::rule<class numeralAsString, std::string> numeralAsString = "numeralAsString";

		const x3::rule<class shortComment, std::string> shortComment = "shortComment";
		const x3::rule<class longComment, std::string> longComment = "longComment";
		const x3::rule<class comment, std::string> comment = "comment";

		const x3::rule<class fieldByExpression, ast::FieldByExpression> fieldByExpression = "fieldByExpression";
		const x3::rule<class fieldByAssignment, ast::FieldByAssignment> fieldByAssignment = "fieldByAssignment";
		const x3::rule<class field, ast::Field> field = "field";
		const x3::rule<class fieldsList, ast::FieldsList> fieldsList = "fieldsList";
		const x3::rule<class tableConstructor, ast::TableConstructor> tableConstructor = "tableConstructor";

		const x3::rule<class parametersList, ast::ParametersList> parametersList = "parametersList";
		const x3::rule<class arguments, ast::Arguments> arguments = "arguments";
		const x3::rule<class functionBody, ast::FunctionBody> functionBody = "functionBody";
		const x3::rule<class functionCall, ast::FunctionCall> functionCall = "functionCall";
		const x3::rule<class functionCallEnd, ast::FunctionCallEnd> functionCallEnd = "functionCallEnd";
		const x3::rule<class functionDefinition, ast::FunctionBody> functionDefinition = "functionDefinition";
		const x3::rule<class functionNameMember, ast::FunctionNameMember> functionNameMember = "functionNameMember";
		const x3::rule<class functionName, ast::FunctionName> functionName = "functionName";

		const x3::rule<class bracketedExpression, ast::BracketedExpression> bracketedExpression = "bracketedExpression";
		const x3::rule<class tableIndexExpression, ast::TableIndexExpression> tableIndexExpression = "tableIndexExpression";
		const x3::rule<class tableIndexName, ast::TableIndexName> tableIndexName = "tableIndexName";
		const x3::rule<class prefixExpression, ast::PrefixExpression> prefixExpression = "prefixExpression";
		const x3::rule<class postPrefix, ast::PostPrefix> postPrefix = "postPrefix";
		const x3::rule<class variable, ast::Variable> variable = "variable";
		const x3::rule<class variableFunctionCall, ast::VariableFunctionCall> variableFunctionCall = "variableFunctionCall";
		const x3::rule<class variablePostfix, ast::VariablePostfix> variablePostfix = "variablePostfix";
		const x3::rule<class variablesList, ast::VariablesList> variablesList = "variablesList";

		const x3::rule<class unaryOperation, ast::UnaryOperation> unaryOperation = "unaryOperation";
		const x3::rule<class binaryOperation, ast::BinaryOperation> binaryOperation = "binaryOperation";
		const x3::rule<class simpleExpression, ast::Operand> simpleExpression = "simpleExpression";
		const x3::rule<class expression, ast::Expression> expression = "expression";
		const x3::rule<class expressionsList, ast::ExpressionsList> expressionsList = "expressionsList";

		const x3::rule<class assignmentStatement, ast::AssignmentStatement> assignmentStatement = "assignmentStatement";
		const x3::rule<class labelStatement, ast::LabelStatement> labelStatement = "labelStatement";
		const x3::rule<class gotoStatement, ast::GotoStatement> gotoStatement = "gotoStatement";
		const x3::rule<class breakStatement, ast::BreakStatement> breakStatement = "breakStatement";
		const x3::rule<class doStatement, ast::DoStatement> doStatement = "doStatement";
		const x3::rule<class whileStatement, ast::WhileStatement> whileStatement = "whileStatement";
		const x3::rule<class repeatStatement, ast::RepeatStatement> repeatStatement = "repeatStatement";
		const x3::rule<class ifStatement, ast::IfStatement> ifStatement = "ifStatement";
		const x3::rule<class elseIfStatement, ast::IfStatement> elseIfStatement = "elseIfStatement";
		const x3::rule<class ifThenElseStatement, ast::IfThenElseStatement> ifThenElseStatement = "ifThenElseStatement";
		const x3::rule<class numericalForStatement, ast::NumericalForStatement> numericalForStatement = "numericalForStatement";
		const x3::rule<class genericForStatement, ast::GenericForStatement> genericForStatement = "genericForStatement";
		const x3::rule<class functionDeclarationStatement, ast::FunctionDeclarationStatement> functionDeclarationStatement = "functionDeclarationStatement";
		const x3::rule<class localFunctionDeclarationStatement, ast::LocalFunctionDeclarationStatement> localFunctionDeclarationStatement = "localFunctionDeclarationStatement";
		const x3::rule<class localAssignmentStatement, ast::LocalAssignmentStatement> localAssignmentStatement = "localAssignmentStatement";

		const x3::rule<class returnStatement, ast::ReturnStatement> returnStatement = "returnStatement";
		const x3::rule<class statement, ast::Statement> statement = "statement";

		const x3::rule<class block, ast::Block> block = "block";
		const x3::rule<class chunk, std::string> chunk = "chunk";

		// Names
		const auto name_def = lexeme[((alpha | char_('_'))
									  >> *(alnum | char_('_')))
									 - keyword];

		const auto namesList_def = name % ',';

		// Short literal strings
		auto quotedString = [](char c) {
			return lit(c)
				   >> *(('\\' >> char_(c)) // Escaped quote
						| (char_ - c))     // Any character but the quote
				   >> c;
		};

		// Long literal strings
		struct long_bracket_tag
		{
		};
		auto set_bracket = [](auto& ctx) { get<long_bracket_tag>(ctx) = _attr(ctx); };
		auto is_bracket = [](auto& ctx) { _pass(ctx) = (x3::get<long_bracket_tag>(ctx) == _attr(ctx)); };
		const auto openLongBracket_def = '[' >> (*char_('='))[set_bracket] >> '[';
		const auto closeLongBacket_def = ']' >> (*char_('='))[is_bracket] >> ']';
		const auto longLiteralString_def = with<long_bracket_tag>(std::string())
			[omit[openLongBracket]
			 >> *(char_ - closeLongBacket)
			 >> omit[closeLongBacket]];

		// Literal strings
		const auto literalString_def = lexeme[quotedString('\'')
											  | quotedString('"')
											  | longLiteralString];

		// Numerals
		const auto numeral_def = (lit("0x") >> hex)
								 | (lit("0X") >> hex)
								 | double_;
		const auto numeralAsString_def = raw[numeral];

		// Comments
		const auto shortComment_def = "--" >> lexeme[*(char_ - eol)] >> -eol;
		const auto longComment_def = with<long_bracket_tag>(std::string())
			["--"
			 >> omit[openLongBracket]
			 >> lexeme[*(char_ - closeLongBacket)]
			 >> omit[closeLongBacket]];
		const auto comment_def = longComment | shortComment;

		// A skipper that ignore whitespace and comments
		const x3::rule<class skipper> skipper = "skipper";

		const auto skipper_def = ascii::space
								 | omit[shortComment]
								 | omit[longComment];

		//*** Complete syntax of Lua ***
		// Table and fields
		const auto fieldByExpression_def = '[' >> expression >> lit(']') >> lit('=') >> expression;
		const auto fieldByAssignment_def = name >> '=' >> expression;
		const auto field_def = fieldByExpression
							   | fieldByAssignment
							   | expression;

		const auto fieldSeparator = lit(',') | lit(';');
		const auto fieldsList_def = field >> *(fieldSeparator >> field) >> -fieldSeparator;

		const auto tableConstructor_def = '{' >> -fieldsList >> '}';

		// Functions
		const auto funcVarargs = lit("...") >> x3::attr(true);
		const auto parametersList_def = (namesList >> -(lit(',') >> funcVarargs))
										| (x3::attr(ast::NamesList{}) >> funcVarargs);

		const auto emptyArguments = lit('(') >> lit(')') >> x3::attr(ast::EmptyArguments());
		const auto argumentsExpressions = '(' >> expressionsList >> ')';
		const auto arguments_def = emptyArguments
								   | argumentsExpressions
								   | tableConstructor
								   | literalString;

		const auto functionBody_def = '(' >> -parametersList >> ')' >> block >> lit("end");

		const auto functionDefinition_def = lit("function") >> functionBody;

		const auto functionCall_def = variable >> functionCallEnd;

		const auto functionCallEnd_def = -(':' >> name) >> arguments;

		const auto functionNameMember_def = ':' >> name;

		const auto functionName_def = name >> *('.' >> name) >> -functionNameMember;

		// Variables
		const auto bracketedExpression_def = '(' >> expression >> ')';
		const auto tableIndexExpression_def = '[' >> expression >> ']';
		const auto tableIndexName_def = '.' >> name;
		const auto prefixExpression_def = (bracketedExpression
										   | name)
										  >> *postPrefix;

		const auto postPrefix_def = tableIndexExpression
									| tableIndexName
									| functionCallEnd;

		const auto variable_def = (bracketedExpression
								   | name)
								  >> *variablePostfix;

		const auto variableFunctionCall_def = functionCallEnd >> variablePostfix; // Should not stop with a function call

		const auto variablePostfix_def = tableIndexExpression
										 | tableIndexName
										 | variableFunctionCall;

		const auto variablesList_def = variable % ',';

		// Expressions
		const auto simpleExpression_def = expressionConstant
										  | unaryOperation
										  | numeral
										  | literalString
										  | tableConstructor
										  | functionDefinition
										  | prefixExpression;

		const auto unaryOperation_def = unaryOperator >> expression;
		const auto binaryOperation_def = binaryOperator >> expression;
		const auto expression_def = simpleExpression >> -binaryOperation;

		const auto expressionsList_def = expression >> *(',' >> expression);

		// Statements
		const auto emptyStatement = lit(';') >> x3::attr(ast::EmptyStatement{});
		const auto assignmentStatement_def = variablesList >> '=' >> expressionsList;
		const auto labelStatement_def = "::" >> name >> "::";
		const auto gotoStatement_def = "goto" >> name;
		const auto breakStatement_def = "break" >> x3::attr(ast::BreakStatement{});
		const auto doStatement_def = "do" >> block >> "end";
		const auto whileStatement_def = "while" >> expression >> "do" >> block >> "end";
		const auto repeatStatement_def = "repeat" >> block >> "until" >> expression;
		const auto ifStatement_def = "if" >> expression >> "then" >> block;
		const auto elseIfStatement_def = "elseif" >> expression >> "then" >> block;
		const auto ifThenElseStatement_def = ifStatement
											 >> *(elseIfStatement)
											 >> -("else" >> block)
											 >> "end";
		const auto numericalForStatement_def = "for" >> name >> '=' >> expression
											   >> ',' >> expression >> -(',' >> expression)
											   >> "do" >> block >> "end";
		const auto genericForStatement_def = "for" >> namesList >> "in" >> expressionsList >> "do" >> block >> "end";
		const auto functionDeclarationStatement_def = "function" >> functionName >> functionBody;
		const auto localFunctionDeclarationStatement_def = "local" >> lit("function") >> name >> functionBody;
		const auto localAssignmentStatement_def = "local" >> namesList >> -('=' >> expressionsList);

		const auto statement_def = emptyStatement
								   | assignmentStatement
								   | functionCall
								   | labelStatement
								   | gotoStatement
								   | breakStatement
								   | doStatement
								   | whileStatement
								   | repeatStatement
								   | ifThenElseStatement
								   | numericalForStatement
								   | genericForStatement
								   | functionDeclarationStatement
								   | localFunctionDeclarationStatement
								   | localAssignmentStatement;

		const auto returnStatement_def = "return" >> -expressionsList >> -lit(';');

		// Blocks
		const auto block_def = *statement >> -returnStatement;
		const auto chunk_def = name; //block

		BOOST_SPIRIT_DEFINE(name, namesList,
							openLongBracket, closeLongBacket,
							longLiteralString, literalString,
							numeral, numeralAsString,
							shortComment, longComment, comment,
							skipper,
							fieldByExpression, fieldByAssignment, field, fieldsList, tableConstructor,
							parametersList, arguments,
							functionBody, functionCall, functionCallEnd,
							functionDefinition, functionNameMember, functionName,
							bracketedExpression, tableIndexExpression, tableIndexName,
							prefixExpression, postPrefix,
							variable, variableFunctionCall, variablePostfix, variablesList,
							unaryOperation, binaryOperation,
							simpleExpression, expression, expressionsList,
							assignmentStatement, localAssignmentStatement,
							labelStatement, gotoStatement, breakStatement, doStatement,
							whileStatement, repeatStatement,
							ifStatement, elseIfStatement, ifThenElseStatement,
							numericalForStatement, genericForStatement,
							functionDeclarationStatement, localFunctionDeclarationStatement,
							returnStatement, statement,
							block, chunk);
	} // namespace parser

	parser::chunk_type chunkRule()
	{
		return parser::chunk;
	}
} // namespace lac
