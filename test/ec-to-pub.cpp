/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test_suite.hpp>
#include <sx/sx.hpp>
#include "command.hpp"

SX_USING_NAMESPACES()

// This is a namespace for tests by class/file__method/function.
BOOST_AUTO_TEST_SUITE(ec_to_pub__invoke)

BOOST_AUTO_TEST_CASE(ec_to_pub__invoke__compressed__okay_output)
{
    // $ sx ec-to-pub secret
    SX_DECLARE_COMMAND(ec_to_pub);
    command.set_uncompressed_option(false);
    command.set_secret_argument({ "secret" });
    SX_REQUIRE_OKAY(command.invoke(input, output, error));
    SX_REQUIRE_OUTPUT("");
}

BOOST_AUTO_TEST_CASE(ec_to_pub__invoke__uncompressed__okay_output)
{
    // $ sx ec-to-pub secret -u
    SX_DECLARE_COMMAND(ec_to_pub);
    command.set_uncompressed_option(true);
    command.set_secret_argument({ "secret" });
    SX_REQUIRE_OKAY(command.invoke(input, output, error));
    SX_REQUIRE_OUTPUT("");
}

BOOST_AUTO_TEST_SUITE_END()