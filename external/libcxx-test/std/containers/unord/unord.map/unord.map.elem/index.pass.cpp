/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_map>

// template <class Key, class T, class Hash = hash<Key>, class Pred = equal_to<Key>,
//           class Alloc = allocator<pair<const Key, T>>>
// class unordered_map

// mapped_type& operator[](const key_type& k);
// mapped_type& operator[](key_type&& k);

#include <unordered_map>
#include <string>
#include <cassert>
#include "libcxx_tc_common.h"

#include "test_macros.h"
#include "MoveOnly.h"

#if TEST_STD_VER >= 11
#include "container_test_types.h"
#endif

int tc_libcxx_containers_unord_map_elem_index(void)
{
    {
        typedef std::unordered_map<int, std::string> C;
        typedef std::pair<int, std::string> P;
        P a[] =
        {
            P(1, "one"),
            P(2, "two"),
            P(3, "three"),
            P(4, "four"),
            P(1, "four"),
            P(2, "four"),
        };
        C c(a, a + sizeof(a)/sizeof(a[0]));
        TC_ASSERT_EXPR(c.size() == 4);
        c[1] = "ONE";
        TC_ASSERT_EXPR(c.at(1) == "ONE");
        c[11] = "eleven";
        TC_ASSERT_EXPR(c.size() == 5);
        TC_ASSERT_EXPR(c.at(11) == "eleven");
    }
#if TEST_STD_VER >= 11
    {
        typedef std::unordered_map<MoveOnly, std::string> C;
        typedef std::pair<int, std::string> P;
        P a[] =
        {
            P(1, "one"),
            P(2, "two"),
            P(3, "three"),
            P(4, "four"),
            P(1, "four"),
            P(2, "four"),
        };
        C c(a, a + sizeof(a)/sizeof(a[0]));
        TC_ASSERT_EXPR(c.size() == 4);
        c[1] = "ONE";
        TC_ASSERT_EXPR(c.at(1) == "ONE");
        c[11] = "eleven";
        TC_ASSERT_EXPR(c.size() == 5);
        TC_ASSERT_EXPR(c.at(11) == "eleven");
    }

#endif
    TC_SUCCESS_RESULT();
    return 0;
}
