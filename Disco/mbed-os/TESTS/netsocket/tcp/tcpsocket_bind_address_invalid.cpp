/*
 * Copyright (c) 2018, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined(MBED_CONF_RTOS_PRESENT)

#include "greentea-client/test_env.h"
#include "mbed.h"
#include "tcp_tests.h"
#include "TCPSocket.h"
#include "unity/unity.h"
#include "utest.h"

using namespace utest::v1;

void TCPSOCKET_BIND_ADDRESS_INVALID()
{
    SKIP_IF_TCP_UNSUPPORTED();
    TCPSocket *sock = new TCPSocket;
    if (!sock) {
        TEST_FAIL();
        return;
    }
    TEST_ASSERT_EQUAL(NSAPI_ERROR_OK, sock->open(NetworkInterface::get_default_instance()));
    nsapi_error_t bind_result = NSAPI_ERROR_OK;
    if (get_ip_version() == NSAPI_IPv4) {
        bind_result = sock->bind("190.2.3.4", 1024);
    } else if (get_ip_version() == NSAPI_IPv6) {
        bind_result = sock->bind("fe80::ff01", 1024);
    } else {
        TEST_FAIL_MESSAGE("This stack is neither IPv4 nor IPv6");
    }
    if (bind_result == NSAPI_ERROR_UNSUPPORTED) {
        TEST_IGNORE_MESSAGE("bind() not supported");
    } else {
        TEST_ASSERT_EQUAL(NSAPI_ERROR_PARAMETER, bind_result);
    }

    delete sock;
}
#endif // defined(MBED_CONF_RTOS_PRESENT)