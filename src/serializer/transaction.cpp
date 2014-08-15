/**
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
#include "precompile.hpp"
#include <sx/serializer/transaction.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/property_tree/ptree.hpp>
#include <bitcoin/bitcoin.hpp>
#include <sx/define.hpp>
#include <sx/prop_tree.hpp>
#include <sx/serializer/hex.hpp>
#include <sx/utility/utility.hpp>

using namespace bc;
using namespace po;
using namespace pt;

namespace sx {
namespace serializer {

transaction::transaction()
    : value_()
{
}

transaction::transaction(const std::string& hexcode)
{
    std::stringstream(hexcode) >> *this;
}

transaction::transaction(const data_chunk& value)
    : transaction((const std::string&)hex(value))
{
}

transaction::transaction(const tx_type& value)
    : value_(value)
{
}

transaction::transaction(const transaction& other)
    : transaction(other.value_)
{
}

tx_type& transaction::data()
{
    return value_;
}

transaction::operator const tx_type&() const
{
    return value_;
}

//transaction::operator const std::string() const
//{
//    std::stringstream result;
//    result << *this;
//    return result.str();
//}

transaction::operator const ptree() const
{
    return prop_tree(value_);
}

std::istream& operator>>(std::istream& input, transaction& argument)
{
    std::string hexcode;
    input >> hexcode;

    if (!deserialize_satoshi_item(argument.value_, hex(hexcode)))
        throw invalid_option_value(hexcode);

    return input;
}

std::ostream& operator<<(std::ostream& output, const transaction& argument)
{
    const auto bytes = serialize_satoshi_item(argument.value_);
    output << hex(bytes);
    return output;
}

} // sx
} // serializer