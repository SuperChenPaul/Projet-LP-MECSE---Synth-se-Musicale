/*
 * Copyright (c) 2019, ARM Limited, All Rights Reserved
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

#include "mbed.h"
#include "TLSSocket.h"
#include "greentea-client/test_env.h"
#include "unity/unity.h"
#include "utest.h"
#include "tls_tests.h"

using namespace utest::v1;

#if defined(MBEDTLS_SSL_CLI_C)

void TLSSOCKET_HANDSHAKE_INVALID()
{
    const int https_port = 443;
    SKIP_IF_TCP_UNSUPPORTED();

#if (MBED_CONF_NSAPI_DEFAULT_STACK == NANOSTACK || (MBED_CONF_NSAPI_DEFAULT_STACK == LWIP && defined(MBED_CONF_LWIP_PPP_IPV6_ENABLED)))
    SocketAddress address;
    nsapi_error_t result = NetworkInterface::get_default_instance()->gethostbyname("expired.badssl.com", &address);
    if (result != NSAPI_ERROR_OK) {
        TEST_SKIP_MESSAGE(" badssl.com not supported IP6 AAA records");
    }
#endif
    TLSSocket sock;
    TEST_ASSERT_EQUAL(NSAPI_ERROR_OK, sock.open(NetworkInterface::get_default_instance()));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_OK, sock.set_root_ca_cert(tls_global::cert));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("expired.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("wrong.host.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("self-signed.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("untrusted-root.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("revoked.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("pinning-test.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_AUTH_FAILURE, sock.connect("sha1-intermediate.badssl.com", https_port));
    TEST_ASSERT_EQUAL(NSAPI_ERROR_OK, sock.close());
}

#endif // defined(MBEDTLS_SSL_CLI_C)
